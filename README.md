# UFA SmartNIC & NS2 Simulation Suite
# High-Performance SmartNIC Offload Accelerator

A hardware-software co-designed SmartNIC engine built to offload network packet parsing and 5-tuple rule lookups from the host CPU.

## System Architecture
+------------------------------------+
                              |            smartnic_top            |
                              |                                    |

Raw Packet Data ---> [in_data] --> |  +------------------------------+  |
|  |        packet_parser         |  |
|  | (FSM Header Extraction Engine)|  |
|  +--------------+---------------+  |
|                 | (5-Tuple Field)  |
|                 v                  |
|  +------------------------------+  |
Software Rules ---> [sw_write] ->|  |         sram_lookup          |  |
|  |   (Single-Cycle Rule Table) |  |
|  +--------------+---------------+  |
|                 |                  |
+-----------------|------------------+
v
[match_action output]


## Hardware RTL Modules (Phase 1 Complete)

* **`rtl/sram_lookup.sv`**: A 256-entry, 64-bit wide SRAM memory array. Supports dual-port operational logic—allowing software writes (`sw_write_en`) for updating routing tables while executing hardware single-cycle read lookups.
* **`rtl/packet_parser.sv`**: A Finite State Machine (FSM) that decapsulates streaming network packet bytes to extract 5-tuple headers (Source IP, Dest IP, Source Port, Dest Port, Protocol) in 3 clock cycles.
* **`rtl/smartnic_top.sv`**: Top-level hardware module integrating the packet parser output directly into the SRAM lookup address logic to form an end-to-end lookup pipeline.

## Repository Structure

ufa_project/
├── rtl/               # SystemVerilog Hardware Logic
│   ├── sram_lookup.sv
│   ├── packet_parser.sv
│   └── smartnic_top.sv
├── sim/               # Verification Suite (Cocotb & Verilator)
├── sw/                # Driver & MMIO Registers
└── README.md
## Technology Stack

* **Hardware Description:** SystemVerilog
* **Verification:** Cocotb (Python) & Verilator
* **Software Interface:** C / Python MMIO


