SIM ?= verilator
TOPLEVEL_LANG ?= verilog

# Enable SystemVerilog 2012 parsing flags


VERILOG_SOURCES += $(PWD)/../rtl/sram_lookup.sv
VERILOG_SOURCES += $(PWD)/../rtl/packet_parser.sv
VERILOG_SOURCES += $(PWD)/../rtl/smartnic_top.sv

TOPLEVEL = smartnic_top
MODULE = test_smartnic
EXTRA_ARGS+=--trace --trace-structs

include $(shell cocotb-config --makefiles)/Makefile.sim
