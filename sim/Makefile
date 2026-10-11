# Simulation Setup for Cocotb & Verilator
SIM ?= verilator
TOPLEVEL_LANG ?= verilog

# SystemVerilog RTL Source Files
VERILOG_SOURCES += $(PWD)/../rtl/packet_parser.sv
VERILOG_SOURCES += $(PWD)/../rtl/sram_lookup.sv
VERILOG_SOURCES += $(PWD)/../rtl/smartnic_top.sv

# Top-level SystemVerilog Module
TOPLEVEL = smartnic_top

# Run Phase 2 and Phase 3 Test Suites Sequentially
MODULE = test_smartnic,test_smartnic_phase3,test_smartnic_perf
EXTRA_ARGS += --trace --trace-structs

# Include Cocotb Simulation Rules
include $(shell cocotb-config --makefiles)/Makefile.sim
