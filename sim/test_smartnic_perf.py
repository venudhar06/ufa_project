import cocotb
from cocotb.triggers import RisingEdge, ClockCycles
from cocotb.clock import Clock

@cocotb.test()
async def test_smartnic_performance(dut):
    """Phase 4: Latency Profiling & Stress Test Benchmark"""
    
    # 1. Start 100 MHz Clock (10 ns period)
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    
    # Reset hardware state
    dut.rst_n.value = 0
    dut.in_valid.value = 0
    dut.sw_write_en.value = 0
    await ClockCycles(dut.clk, 5)
    dut.rst_n.value = 1
    await ClockCycles(dut.clk, 2)
    
    # 2. Program Rule via MMIO Host Driver (Target Index 0x8D)
    dut.sw_write_en.value = 1
    dut.sw_write_addr.value = 0x8D
    dut.sw_write_data.value = 0xABCDEF1234567890
    await RisingEdge(dut.clk)
    dut.sw_write_en.value = 0
    await ClockCycles(dut.clk, 2)
    
    # 3. Burst Performance Test (10 Complete Packet Streams)
    num_packets = 10
    start_sim_time = cocotb.utils.get_sim_time(unit="ns")
    
    dut._log.info(f"[PERF] Injecting burst of {num_packets} complete 3-word packet frames...")
    
    latency_records = []
    
    for i in range(num_packets):
        inject_time = cocotb.utils.get_sim_time(unit="ns")
        
        # Word 1: Ethernet Header Part 1
        dut.in_valid.value = 1
        dut.in_data.value = 0x0011223344556677
        await RisingEdge(dut.clk)
        
        # Word 2: Ethernet Header Part 2
        dut.in_data.value = 0x8899800000000000
        await RisingEdge(dut.clk)
        
        # Word 3: IP Header Word containing Dest IP matching programmed SRAM rule (0x8D)
        dut.in_data.value = 0x4500003C0001008D
        await RisingEdge(dut.clk)
        dut.in_valid.value = 0
        
        # Wait for match output with safety timeout counter
        timeout = 0
        while dut.match_valid.value != 1 and timeout < 20:
            await RisingEdge(dut.clk)
            timeout += 1
            
        match_time = cocotb.utils.get_sim_time(unit="ns")
        latency = match_time - inject_time
        latency_records.append(latency)
        
        await ClockCycles(dut.clk, 2)

    end_sim_time = cocotb.utils.get_sim_time(unit="ns")
    total_duration = end_sim_time - start_sim_time
    avg_latency = sum(latency_records) / len(latency_records)
    
    # 4. Display Benchmark Results
    dut._log.info("=" * 60)
    dut._log.info("            PHASE 4 PERFORMANCE PROFILE RESULTS            ")
    dut._log.info("=" * 60)
    dut._log.info(f" Total Packets Processed : {num_packets}")
    dut._log.info(f" Total Elapsed Sim Time : {total_duration:.2f} ns")
    dut._log.info(f" Avg Latency per Packet : {avg_latency:.2f} ns ({int(avg_latency/10)} clock cycles)")
    dut._log.info("=" * 60)
