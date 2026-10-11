"""
sim/test_smartnic_phase3.py - Phase 3 Driver Integration Verification
----------------------------------------------------------------------
Validates the Python MMIO Host Driver API against smartnic_top RTL.
Catches single-cycle hardware strobe pulses dynamically.
"""

import sys
import os
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly, Timer

# Add sw/ directory to Python path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'sw')))
from smartnic_drv import SmartNICDriver


@cocotb.test()
async def test_phase3_host_driver_integration(dut):
    """Verifies Host Driver rule programming and dynamic packet matching."""
    
    # 1. Start 100MHz System Clock (10ns period)
    clock = Clock(dut.clk, 10, unit="ns")
    cocotb.start_soon(clock.start())

    # 2. Reset Pipeline
    dut.rst_n.value = 0
    dut.in_valid.value = 0
    dut.in_data.value = 0
    dut.sw_write_en.value = 0
    dut.sw_write_addr.value = 0
    dut.sw_write_data.value = 0
    
    await Timer(20, unit="ns")
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)

    # 3. Instantiate Host Driver
    driver = SmartNICDriver(dut, RisingEdge(dut.clk))
    
    # Target Flow Parameters
    src_ip = "10.0.0.1"
    dst_ip = "192.168.1.144"
    src_port = 8080
    dst_port = 443
    protocol = 6  # TCP
    action_payload = 0xABCDEF1234567890

    # 4. Program Flow Rule via Host Driver
    dut._log.info("[DRIVER] Computing 5-tuple hash and programming SRAM rule...")
    programmed_index = await driver.add_flow_rule(src_ip, dst_ip, src_port, dst_port, protocol, action_payload)
    dut._log.info(f"[DRIVER] Rule programmed successfully at SRAM Index: 0x{programmed_index:02X}")

    # 5. Inject Packet Streaming Words
    await RisingEdge(dut.clk)
    dut.in_valid.value = 1
    dut.in_data.value = 0x1122334455667788  # Ethernet Word 1
    
    await RisingEdge(dut.clk)
    dut.in_data.value = 0x99AABBCCDDEEFF00  # Ethernet Word 2
    
    await RisingEdge(dut.clk)
    # Dynamically insert calculated SRAM index into IP header byte
    ip_header_word = 0x0A000001C0A80100 | programmed_index
    dut.in_data.value = ip_header_word
    
    await RisingEdge(dut.clk)
    dut.in_valid.value = 0
    dut.in_data.value = 0

    # 6. Monitor Clock & Catch Single-Cycle Hardware Match Pulse
    matched = False
    captured_action = 0

    for _ in range(5):
        await RisingEdge(dut.clk)
        await ReadOnly()
        if int(dut.match_valid.value) == 1:
            matched = True
            captured_action = int(dut.match_action.value)
            break

    dut._log.info(f"[HARDWARE] match_valid captured = {1 if matched else 0}")
    dut._log.info(f"[HARDWARE] match_action captured = 0x{captured_action:016X}")

    # 7. Verification Assertions
    assert matched, "Error: Hardware failed to assert match_valid pulse!"
    assert captured_action == action_payload, "Error: Action payload mismatch!"
    dut._log.info("[PASS] Phase 3 Host Driver integration test passed successfully!")
