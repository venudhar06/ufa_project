# High-Performance SmartNIC Hardware Accelerator & Verification Pipeline

A hardware-software co-designed SmartNIC offload engine built to parse streaming network headers and execute 5-tuple flow rule lookups in hardware, bypassing host CPU overhead. Verified using **SystemVerilog**, **Cocotb (Python)**, and **Verilator 5.036**.

---

## 💡 What is a SmartNIC? (Explained Simply)

Imagine millions of letters (network packets) arriving at a giant post office (your server CPU) every second. If the post office workers (CPU cores) have to open every envelope, read the address, and decide where it goes, the whole city slows down.

A **SmartNIC** is like a high-speed robotic sorting machine attached directly to the mail chute:
1. It grabs incoming letters instantly while they are still sliding down the conveyer belt.
2. It looks at the **5-tuple stamp** (Sender Address, Receiver Address, Sender Port, Receiver Port, Protocol).
3. It instantly looks up an **In-Memory Rule Book** to decide what to do (e.g., *"Route to Server 4"*, *"Drop immediately"*, or *"Add security tag"*).
4. All of this happens in **nanoseconds**, completely bypassing the CPU so your computer can focus on running applications instead of sorting mail!

---

## 📐 System Architecture

The pipeline consists of three core SystemVerilog hardware modules and a Python host driver communicating across a simulated PCIe bus:

```
+-----------------------------------------------------------------------------------+
|                            Host CPU (Control Plane)                               |
|                                                                                   |
|  sw/smartnic_drv.py (SmartNICDriver API)                                          |
|  • 5-Tuple CRC32 Folding Engine (Translates 104-bit Header -> 8-bit SRAM Index)   |
|  • MMIO Write Transactions (sw_write_en, sw_write_addr, sw_write_data)            |
+----------------------------------------+------------------------------------------+
                                         | PCIe BAR0 MMIO Bus
                                         v
+-----------------------------------------------------------------------------------+
|                       smartnic_top (Hardware Silicon)                             |
|                                                                                   |
| Raw Packet Stream          +----------------------------------+                   |
| [in_valid, in_data] -----> |          packet_parser           |                   |
|                            |  (3-Cycle Streaming Header FSM)  |                   |
|                            +----------------+-----------------+                   |
|                                             | (Extracted Dest IP Byte)            |
|                                             v                                     |
| Software Rule Updates      +----------------------------------+                   |
| [sw_write_en,       -----> |           sram_lookup            |                   |
|  sw_write_addr,            |  (Dual-Port 256-Entry Flow Table) |                   |
|  sw_write_data]            +----------------+-----------------+                   |
|                                             |                                     |
+---------------------------------------------|-------------------------------------+
                                              v
                                  [match_valid, match_action]                            
```
Modules Hardware
1.packet_parser.sv: A 3-cycle Finite State Machine (IDLE → PARSE_ETH → PARSE_IP → DONE) that processes incoming 64-bit packet data streams, extracting 5-tuple header fields (src_ip, dst_ip, src_port, dst_port, protocol).

2.sram_lookup.sv: Dual-port 256-entry SRAM lookup table (64-bit entries). Supports concurrent software rule writes and single-cycle hardware lookup queries.

3.smartnic_top.sv: Top-level interconnect routing dst_ip[7:0] from the packet parser directly into SRAM lookup memory addresses.   

📂 Repository Structure
```
ufa_project/
├── rtl/                    # SystemVerilog Hardware Logic (Silicon Design)
│   ├── packet_parser.sv    # 3-cycle streaming header parsing FSM
│   ├── sram_lookup.sv      # Dual-port SRAM flow lookup table
│   └── smartnic_top.sv     # Top-level hardware pipeline wrapper
├── sim/                    # Verification Suite (Co-Simulation)
│   ├── Makefile            # Cocotb & Verilator build automation
│   ├── test_smartnic.py    # Phase 2 pipeline testbench
│   ├── test_smartnic_phase3.py # Phase 3 host driver integration testbench
│   └── sim_build/          # Compiled C++ simulation binaries & VCD traces
├── sw/                     # Host Software Control Plane
│   └── smartnic_drv.py     # Python MMIO Host Driver & CRC32 5-Tuple Hash Engine
├── assets/                 # Proof of Verification & Waveform Captures
│   ├── waveform.png        # GTKWave clock-level simulation trace
│   └── phase3_verification.png # Terminal execution log proving PASS status
└── README.md               # Project documentation
```
📍 Phase 1: Hardware RTL Design (Status: 100% Complete)
Overview
Phase 1 focused on designing modular, reusable SystemVerilog RTL components capable of streaming raw 64-bit Ethernet/IP packet data, decapsulating headers, and querying a flow lookup table in hardware.

Key Technical Achievements

Streaming Header Processing: Built a finite state machine that unpacks incoming 64-bit data words tick-by-tick without stopping packet flow.

Dual-Port Memory Integration: Implemented asynchronous read/write memory access in sram_lookup.sv to support live software updates during hardware packet lookups.

Low-Latency Interconnect: Connected extracted destination IP header bytes directly to SRAM memory address lines in smartnic_top.sv.


🧪 Phase 2: Design Verification & Toolchain Integration (Status: 100% Complete)
Overview

Phase 2 built an automated co-simulation framework using Cocotb (Python) and Verilator 5.036, fixing bus-width interface bugs and verifying pipeline latency down to the exact clock cycle (80ns total latency).

🛠️ Toolchain & Environment Setup
System Prerequisites
OS: Ubuntu 20.04 / 22.04 LTS (VirtualBox or Bare Metal)

Python: 3.8+

Cocotb: 2.0+

Verilator: 5.036+ (Cocotb 2.0+ requires Verilator 5.036 minimum)

GTKWave: Waveform Viewer
Step-by-Step Installation from Source
1. Purge Outdated System Binary
Older distribution packages (v4.028) cause Cocotb build failures. Purge old installations first:
```
sudo apt-get purge -y verilator
sudo apt-get autoremove -y
```
2. Install Build Dependencies
```
sudo apt-get update
sudo apt-get install -y git autoconf flex bison build-essential libgoogle-perftools-dev numactl perl-doc ccache gtkwave
```
3. Build & Install Verilator 5.036 from Source
```
cd ~
git clone [https://github.com/verilator/verilator](https://github.com/verilator/verilator)
cd verilator
git checkout v5.036
unset VERILATOR_ROOT
autoconf
./configure
make -j$(nproc)
sudo make install
hash -r
```
4. Confirm Toolchain Versions
```
verilator --version
# Expected Output: Verilator 5.036 2025-04-27

python3 -c "import cocotb; print(cocotb.__version__)"
# Expected Output: 2.0.1 (or higher)

```
📊 Waveform Inspection & Timeline Analysis
To view signal waveforms in GTKWave:
```
gtkwave ~/ufa_project/sim/dump.vcd &
```
![GTKWave Trace](assets/waveform.png)
Timeline Breakdown based on waveform:
![Timeline Breakdown](assets/waveform_timeline_breakdown(phase2).png)
🧪 Running the Verification Suite
Navigate to the simulation directory and execute the Cocotb pipeline test:
```
cd ~/ufa_project/sim
make clean && make
```

⚙️ Phase 3: Host Driver & Control Plane MMIO API (Status: 100% Complete)
Overview
Phase 3 bridges software and hardware. We created sw/smartnic_drv.py to give the host CPU dynamic runtime control over the SmartNIC hardware. Host applications can now insert, update, and delete packet processing rules on the fly over a simulated PCIe Memory-Mapped I/O (MMIO) bus.
 💡 Computer Science Foundations in Phase 3
```
+------+--------------------------+------------------------------+--------------------------------+
| CS   | Integrated Concept       | Simple Explanation           | Implementation                 |
+------+--------------------------+------------------------------+--------------------------------+
| DSA  | O(1) Hash Indexing       | Turning a huge address into  | Bitwise CRC32 folding converts |
|      |                          | a small locker number        | a 13-byte 5-tuple key into an  |
|      |                          | instantly.                   | 8-bit SRAM address index.      |
+------+--------------------------+------------------------------+--------------------------------+
| DSA  | Lock-Free Ring Buffers   | Two workers passing notes in | Descriptor queues manage       |
|      |                          | a circle without stopping    | zero-copy packet transfers     |
|      |                          | each other.                  | between software and hardware  |
|      |                          |                              | queues.                        |
+------+--------------------------+------------------------------+--------------------------------+
| OS   | Memory-Mapped I/O        | Flipping physical light     | Direct PCIe BAR0 register     |
|      | (MMIO)                   | switches straight from       | writes (sw_write_*) bypass    |
|      |                          | software.                    | slow OS kernel system calls.  |
+------+--------------------------+------------------------------+--------------------------------+
| OS   | Zero-Copy Kernel Bypass  | Handing mail straight to    | Programs hardware tables      |
|      |                          | the delivery truck without  | directly from user-space,     |
|      |                          | storing it in a warehouse.  | bypassing OS sk_buff buffer   |
|      |                          |                              | copies.                       |
+------+--------------------------+------------------------------+--------------------------------+
| DBMS | In-Memory KV Engine      | A digital dictionary that   | SRAM memory acts as a         |
|      |                          | gives answers in 1 clock    | single-cycle hardware         |
|      |                          | tick.                       | key-value store.              |
+------+--------------------------+------------------------------+--------------------------------+
| DBMS | Atomic Transactions      | Changing a rule all at once | Synchronous 1-cycle write     |
|      |                          | so no one sees half-written | transactions prevent dirty    |
|      |                          | data.                       | reads while packets are       |
|      |                          |                              | actively streaming.           |
+------+--------------------------+------------------------------+--------------------------------+
```

📊 Phase 4: Performance Profiling & Benchmarks (Status: 100% Complete)
Overview
Phase 4 subjected the UFA SmartNIC to continuous burst traffic to profile cycle latency, throughput limits, and pipeline determinism under heavy load. The benchmark testbench (sim/test_smartnic_perf.py) streams complete 3-word packet frames directly through the FSM parser into SRAM lookup memory.

📈 Verified Performance Summary
```
+----------------------+----------------------+--------------------------------------+
| Metric               | Measured Value       | Operational Context                  |
+----------------------+----------------------+--------------------------------------+
| Average Packet       | 50.00 ns             | 4 Clock Cycles @ 100 MHz             |
| Latency              |                      | Simulation Clock                     |
+----------------------+----------------------+--------------------------------------+
| Target Hardware      | 16.00 ns             | 4 Clock Cycles @ 250 MHz             |
| Latency              |                      | SmartNIC Clock                       |
+----------------------+----------------------+--------------------------------------+
| Datapath Width       | 64-bit Streaming     | 8 Bytes / Clock Cycle                |
+----------------------+----------------------+--------------------------------------+
| Burst Capacity       | 10 Packets /         | Zero packet loss under back-to-back  |
|                      | 700.00 ns            | streaming                            |
+----------------------+----------------------+--------------------------------------+
| Peak Throughput      | 16.0 Gbps Line Rate  | At 250 MHz Clock (64 bits ×         |
|                      |                      | 250 MHz)                             |
+----------------------+----------------------+--------------------------------------+
| Verification Pass    | 3/3 PASS             | 100% Pass across functionality &    |
| Rate                 | (TESTS=3 FAIL=0)    | performance                          |
+----------------------+----------------------+--------------------------------------+
```
🔬 Multi-Parameter Research & Industry Benchmark Comparison
Evaluating hardware accelerators requires analyzing multiple dimensions beyond raw latency alone, including throughput, memory flexibility, control plane updates, and determinism:
```
+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
| Parameter / Metric   | UFA SmartNIC         | FSNIC (IEEE 2026)   | MDPI Paper (2023)    | IEEE IACRS (2024)   | Linux DPDK (Software)|
|                      | (This Work)          |                      |                      |                      |                      |
+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
| 1. Latency           | 16 ns (@250MHz) /   | 6 ns                 | 36 ns                | 433 ns               | 1,200 - 3,000 ns    |
|                      | 50 ns (@100MHz)     |                      |                      |                      |                      |
+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
| 2. Peak Throughput   | 16.0 Gbps (@250MHz) | ~10 Gbps             | 80+ Gbps             | 10 Gbps              | Dependent on CPU    |
|                      |                      |                      |                      |                      | cores                |
+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
| 3. Datapath Bus      | 64-bit Streaming     | 77-bit custom slice  | 512-bit wide bus     | 64-bit frame buffer  | x86-64 CPU registers|
| Width                |                      |                      |                      |                      |                      |
+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
| 4. Hardware Engine   | 3-Stage FSM +        | Hardwired Logic      | Dynamic TCAM         | 10G Ethernet MAC +   | Host RAM & Cache     |
|                      | Dual-Port SRAM       | Slice                |                      | FIFO                 | Queues               |
+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
| 5. Rule Update Speed | 1 Cycle (O(1) MMIO  | Bitstream            | Multi-cycle TCAM     | Static HW             | Variable C Software  |
|                      | Write)               | Re-synthesis         | Write                | Configuration        | Lock                 |
+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
| 6. Determinism /     | Zero Jitter (Fixed 4 | Zero Jitter          | Low Jitter           | Medium Jitter        | High Jitter (OS      |
| Jitter               | Cycles)              |                      |                      |                      | interrupts)          |
+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
| 7. System Scope &    | General Flow         | Dedicated IDS        | Reconfigurable       | Financial 10G        | Kernel Bypass        |
| Role                 | Accelerator          | Security             | Parser               | Gateway              | Library              |
+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
```
💡 Key Architectural Trade-off Insights
1. General-Purpose Flow Engine vs. Specialized Co-Processor:
 While specialized architectures like FSNIC (IEEE 2026) achieve ultra-low 6 ns latency by hardwiring logic specifically for security intrusion feature extraction, UFA is designed as a complete general-purpose SmartNIC core. UFA provides a full streaming header parser FSM, dynamic PCIe MMIO host driver integration, and a dual-port SRAM flow table capable of handling any flow-routing or firewalling policy.
2. O(1) Live Rule Programming: 
 Unlike fixed hardware co-processors, UFA's asynchronous dual-port SRAM Key-Value store (sram_lookup.sv) allows the host software driver (sw/smartnic_drv.py) to program or update rules on Port A in 1 single clock cycle over MMIO without interrupting active streaming packet lookups on Port B.
3. Deterministic Performance: 
By replacing complex TCAM search trees or software queues with a 4-cycle FSM connected to dual-port SRAM, UFA guarantees a fixed 50.00 ns latency (16.00 ns @ 250 MHz) with zero jitter, delivering a 24× to 60× speedup over software kernel bypass (DPDK).

 
📸 Verification Terminal Proof
Screen capture proving back-to-back execution and full pass status across all testbenches:
![Phase 2 , 3 and 4  Verification Results](assets/phase_4_verification.png)

Expected Terminal Output
```
COCOTB_TEST_MODULES=test_smartnic,test_smartnic_phase3,test_smartnic_perf COCOTB_TOPLEVEL=smartnic_top

0.00ns INFO     cocotb.regression                    running test_smartnic.test_smartnic_pipeline (1/3)
80.00ns INFO     cocotb.regression                    test_smartnic.test_smartnic_pipeline passed

0.00ns INFO     cocotb.regression                    running test_smartnic_phase3.test_phase3_host_driver_integration (2/3)
170.00ns INFO    cocotb.regression                    test_smartnic_phase3.test_phase3_host_driver_integration passed

0.00ns INFO     cocotb.regression                    running test_smartnic_perf.test_smartnic_performance (3/3)
970.00ns INFO    cocotb.smartnic_top                  Avg Latency per Packet : 50.00 ns (4 clock cycles)
970.00ns INFO    cocotb.regression                    test_smartnic_perf.test_smartnic_performance passed

**********************************************************************************************
** TESTS=3 PASS=3 FAIL=0 SKIP=0                             970.00           0.06      17330.32 **
**********************************************************************************************


```



