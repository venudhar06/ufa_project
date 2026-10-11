"""
sw/smartnic_drv.py - SmartNIC Host Driver & Control Plane MMIO API
-------------------------------------------------------------------
Provides host-side control plane abstraction to program 5-tuple flow 
lookup rules into the hardware SRAM table over MMIO interfaces.

Integrated Core CS Principles:
  - DSA: O(1) CRC32 5-tuple hashing & bitwise folding
  - OS: Memory-Mapped I/O (MMIO) kernel-bypass writes over PCIe BAR space
  - DBMS: Single-cycle atomic KV store transactions
"""

import zlib
import struct


class SmartNICDriver:
    """Host Driver class for controlling smartnic_top hardware via MMIO signals."""

    def __init__(self, dut, clock):
        """
        Initialize the driver with the Design Under Test (DUT) instance.
        :param dut: Cocotb handle to top-level module (smartnic_top)
        :param clock: Signal handle for system clock
        """
        self.dut = dut
        self.clock = clock
        self.table_size = 256  # 256 SRAM entries

    @staticmethod
    def compute_5tuple_hash(src_ip: str, dst_ip: str, src_port: int, dst_port: int, protocol: int) -> int:
        """
        [DSA Concept: O(1) Hash Function]
        Calculates an 8-bit SRAM lookup index (0..255) from a 13-byte 5-tuple flow key 
        using CRC32 hashing and bitwise folding.
        """
        src_ip_bytes = bytes([int(x) for x in src_ip.split('.')])
        dst_ip_bytes = bytes([int(x) for x in dst_ip.split('.')])
        
        # Pack 5-tuple header fields into binary payload (13 bytes)
        payload = struct.pack("!4s4sHHB", src_ip_bytes, dst_ip_bytes, src_port, dst_port, protocol)
        
        # Calculate CRC32 hash and fold into 8-bit index space (0..255)
        crc32_val = zlib.crc32(payload)
        index = (crc32_val ^ (crc32_val >> 8) ^ (crc32_val >> 16) ^ (crc32_val >> 24)) & 0xFF
        return index

    async def write_rule(self, addr: int, action_data: int):
        """
        [OS Concept: MMIO BAR Transaction] [DBMS Concept: Single-Cycle Atomic Write]
        Executes a synchronous MMIO write cycle to write action_data into SRAM.
        :param addr: SRAM entry address (0x00 to 0xFF)
        :param action_data: 64-bit rule action payload
        """
        if not (0 <= addr < self.table_size):
            raise ValueError(f"[OS Exception] Address 0x{addr:X} out of bounds (0..255)")

        await self.clock
        # Assert MMIO control lines
        self.dut.sw_write_en.value = 1
        self.dut.sw_write_addr.value = addr
        self.dut.sw_write_data.value = action_data

        await self.clock
        # De-assert MMIO lines (prevents dirty writes)
        self.dut.sw_write_en.value = 0
        self.dut.sw_write_addr.value = 0
        self.dut.sw_write_data.value = 0

    async def add_flow_rule(self, src_ip: str, dst_ip: str, src_port: int, dst_port: int, protocol: int, action_data: int) -> int:
        """[DBMS Concept: Upsert Entry in Hardware KV Store]"""
        index = self.compute_5tuple_hash(src_ip, dst_ip, src_port, dst_port, protocol)
        await self.write_rule(index, action_data)
        return index

    async def invalidate_rule(self, addr: int):
        """[DBMS Concept: Delete Key from Hardware Index]"""
        await self.write_rule(addr, 0x0)

    async def clear_all_rules(self):
        """[DBMS Concept: Full Table Purge / Sanitize Operation]"""
        for addr in range(self.table_size):
            await self.write_rule(addr, 0x0)
