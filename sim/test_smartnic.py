import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly

@cocotb.test()
async def test_smartnic_pipeline(dut):
    """Test SmartNIC rule programming and hardware packet lookup pipeline."""
    
    # 1. Start 10ns clock
    clock = Clock(dut.clk, 10, unit="ns")
    cocotb.start_soon(clock.start())

    # 2. Reset System & Initialize Inputs
    dut.rst_n.value = 0
    dut.sw_write_en.value = 0
    dut.sw_write_addr.value = 0
    dut.sw_write_data.value = 0
    dut.in_valid.value = 0
    dut.in_data.value = 0
    dut.in_last.value = 0

    for _ in range(2):
        await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)

    # 3. Program SRAM Rule (Addr: 0x90, Action: 0xDEADBEEFCAFE1234)
    dut._log.info("[TEST] Programming SRAM Rule into Address 0x90...")
    dut.sw_write_en.value = 1
    dut.sw_write_addr.value = 0x90
    dut.sw_write_data.value = 0xDEADBEEFCAFE1234
    await RisingEdge(dut.clk)
    
    dut.sw_write_en.value = 0
    await RisingEdge(dut.clk)

    # 4. Inject Streaming Ethernet & IP Packets (3-cycle FSM)
    # Cycle 1: IDLE -> PARSE_ETH (Word 1: 64-bit Ethernet MAC header)
    dut._log.info("[TEST] Injecting Ethernet Header Word 1...")
    dut.in_valid.value = 1
    dut.in_data.value = 0x1122334455667788
    await RisingEdge(dut.clk)

    # Cycle 2: PARSE_ETH -> PARSE_IP (Word 2: 64-bit EtherType header)
    dut._log.info("[TEST] Injecting Ethernet Header Word 2...")
    dut.in_data.value = 0x99AABBCCDDEEFF00
    await RisingEdge(dut.clk)

    # Cycle 3: PARSE_IP -> DONE (Word 3: 64-bit IP Header)
    # Top 32 bits [63:32] = Src IP (0x0A000001)
    # Bot 32 bits [31:0]  = Dst IP (0xC0A80190, lowest byte is 0x90)
    dut._log.info("[TEST] Injecting IP Header Word (Dest IP ending in 0x90)...")
    dut.in_data.value = 0x0A000001C0A80190
    dut.in_last.value = 1
    await RisingEdge(dut.clk)
    
    # De-assert packet input signals
    dut.in_valid.value = 0
    dut.in_last.value = 0

    # 5. Monitor match_valid & match_action output across clock cycles
    matched = False
    for _ in range(10):
        await RisingEdge(dut.clk)
        await ReadOnly()
        if dut.match_valid.value == 1:
            matched = True
            dut._log.info(f"[RESULT] match_valid = {dut.match_valid.value}")
            dut._log.info(f"[RESULT] match_action = {hex(dut.match_action.value)}")
            assert dut.match_action.value == 0xDEADBEEFCAFE1234, f"FAIL: Expected 0xDEADBEEFCAFE1234, got {hex(dut.match_action.value)}"
            break

    assert matched, "FAIL: match_valid was never asserted by hardware pipeline!"
