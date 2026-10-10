// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_smartnic_top);
    __Vhier.remove(&__Vscope_smartnic_top, &__Vscope_smartnic_top__lookup_inst);
    __Vhier.remove(&__Vscope_smartnic_top, &__Vscope_smartnic_top__parser_inst);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(51);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_smartnic_top.configure(this, name(), "smartnic_top", "smartnic_top", "smartnic_top", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_smartnic_top__lookup_inst.configure(this, name(), "smartnic_top.lookup_inst", "lookup_inst", "sram_lookup", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_smartnic_top__parser_inst.configure(this, name(), "smartnic_top.parser_inst", "parser_inst", "packet_parser", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_smartnic_top);
    __Vhier.add(&__Vscope_smartnic_top, &__Vscope_smartnic_top__lookup_inst);
    __Vhier.add(&__Vscope_smartnic_top, &__Vscope_smartnic_top__parser_inst);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"in_data", &(TOP.in_data), false, VLVT_UINT64,VLVD_IN|VLVF_PUB_RW,0,1 ,63,0);
        __Vscope_TOP.varInsert(__Vfinal,"in_last", &(TOP.in_last), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"in_valid", &(TOP.in_valid), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"match_action", &(TOP.match_action), false, VLVT_UINT64,VLVD_OUT|VLVF_PUB_RW,0,1 ,63,0);
        __Vscope_TOP.varInsert(__Vfinal,"match_valid", &(TOP.match_valid), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"rst_n", &(TOP.rst_n), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"sw_write_addr", &(TOP.sw_write_addr), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"sw_write_data", &(TOP.sw_write_data), false, VLVT_UINT64,VLVD_IN|VLVF_PUB_RW,0,1 ,63,0);
        __Vscope_TOP.varInsert(__Vfinal,"sw_write_en", &(TOP.sw_write_en), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_smartnic_top.varInsert(__Vfinal,"clk", &(TOP.smartnic_top__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_smartnic_top.varInsert(__Vfinal,"dst_ip", &(TOP.smartnic_top__DOT__dst_ip), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_smartnic_top.varInsert(__Vfinal,"dst_port", &(TOP.smartnic_top__DOT__dst_port), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_smartnic_top.varInsert(__Vfinal,"in_data", &(TOP.smartnic_top__DOT__in_data), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,63,0);
        __Vscope_smartnic_top.varInsert(__Vfinal,"in_last", &(TOP.smartnic_top__DOT__in_last), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_smartnic_top.varInsert(__Vfinal,"in_valid", &(TOP.smartnic_top__DOT__in_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_smartnic_top.varInsert(__Vfinal,"lookup_addr", &(TOP.smartnic_top__DOT__lookup_addr), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_smartnic_top.varInsert(__Vfinal,"match_action", &(TOP.smartnic_top__DOT__match_action), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,63,0);
        __Vscope_smartnic_top.varInsert(__Vfinal,"match_valid", &(TOP.smartnic_top__DOT__match_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_smartnic_top.varInsert(__Vfinal,"parser_out_valid", &(TOP.smartnic_top__DOT__parser_out_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_smartnic_top.varInsert(__Vfinal,"protocol", &(TOP.smartnic_top__DOT__protocol), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_smartnic_top.varInsert(__Vfinal,"rst_n", &(TOP.smartnic_top__DOT__rst_n), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_smartnic_top.varInsert(__Vfinal,"src_ip", &(TOP.smartnic_top__DOT__src_ip), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_smartnic_top.varInsert(__Vfinal,"src_port", &(TOP.smartnic_top__DOT__src_port), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_smartnic_top.varInsert(__Vfinal,"sw_write_addr", &(TOP.smartnic_top__DOT__sw_write_addr), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_smartnic_top.varInsert(__Vfinal,"sw_write_data", &(TOP.smartnic_top__DOT__sw_write_data), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,63,0);
        __Vscope_smartnic_top.varInsert(__Vfinal,"sw_write_en", &(TOP.smartnic_top__DOT__sw_write_en), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_smartnic_top__lookup_inst.varInsert(__Vfinal,"ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.smartnic_top__DOT__lookup_inst__DOT__ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_smartnic_top__lookup_inst.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.smartnic_top__DOT__lookup_inst__DOT__DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_smartnic_top__lookup_inst.varInsert(__Vfinal,"clk", &(TOP.smartnic_top__DOT__lookup_inst__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_smartnic_top__lookup_inst.varInsert(__Vfinal,"memory", &(TOP.smartnic_top__DOT__lookup_inst__DOT__memory), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,255 ,63,0);
        __Vscope_smartnic_top__lookup_inst.varInsert(__Vfinal,"req_addr", &(TOP.smartnic_top__DOT__lookup_inst__DOT__req_addr), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_smartnic_top__lookup_inst.varInsert(__Vfinal,"req_valid", &(TOP.smartnic_top__DOT__lookup_inst__DOT__req_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_smartnic_top__lookup_inst.varInsert(__Vfinal,"resp_data", &(TOP.smartnic_top__DOT__lookup_inst__DOT__resp_data), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,63,0);
        __Vscope_smartnic_top__lookup_inst.varInsert(__Vfinal,"resp_valid", &(TOP.smartnic_top__DOT__lookup_inst__DOT__resp_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_smartnic_top__lookup_inst.varInsert(__Vfinal,"rst_n", &(TOP.smartnic_top__DOT__lookup_inst__DOT__rst_n), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_smartnic_top__lookup_inst.varInsert(__Vfinal,"write_addr", &(TOP.smartnic_top__DOT__lookup_inst__DOT__write_addr), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_smartnic_top__lookup_inst.varInsert(__Vfinal,"write_data", &(TOP.smartnic_top__DOT__lookup_inst__DOT__write_data), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,63,0);
        __Vscope_smartnic_top__lookup_inst.varInsert(__Vfinal,"write_en", &(TOP.smartnic_top__DOT__lookup_inst__DOT__write_en), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_smartnic_top__parser_inst.varInsert(__Vfinal,"clk", &(TOP.smartnic_top__DOT__parser_inst__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_smartnic_top__parser_inst.varInsert(__Vfinal,"dst_ip", &(TOP.smartnic_top__DOT__parser_inst__DOT__dst_ip), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_smartnic_top__parser_inst.varInsert(__Vfinal,"dst_port", &(TOP.smartnic_top__DOT__parser_inst__DOT__dst_port), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_smartnic_top__parser_inst.varInsert(__Vfinal,"in_data", &(TOP.smartnic_top__DOT__parser_inst__DOT__in_data), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,0,1 ,63,0);
        __Vscope_smartnic_top__parser_inst.varInsert(__Vfinal,"in_last", &(TOP.smartnic_top__DOT__parser_inst__DOT__in_last), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_smartnic_top__parser_inst.varInsert(__Vfinal,"in_valid", &(TOP.smartnic_top__DOT__parser_inst__DOT__in_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_smartnic_top__parser_inst.varInsert(__Vfinal,"next_state", &(TOP.smartnic_top__DOT__parser_inst__DOT__next_state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_smartnic_top__parser_inst.varInsert(__Vfinal,"out_valid", &(TOP.smartnic_top__DOT__parser_inst__DOT__out_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_smartnic_top__parser_inst.varInsert(__Vfinal,"protocol", &(TOP.smartnic_top__DOT__parser_inst__DOT__protocol), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_smartnic_top__parser_inst.varInsert(__Vfinal,"r_dst_ip", &(TOP.smartnic_top__DOT__parser_inst__DOT__r_dst_ip), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_smartnic_top__parser_inst.varInsert(__Vfinal,"r_dst_port", &(TOP.smartnic_top__DOT__parser_inst__DOT__r_dst_port), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_smartnic_top__parser_inst.varInsert(__Vfinal,"r_protocol", &(TOP.smartnic_top__DOT__parser_inst__DOT__r_protocol), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_smartnic_top__parser_inst.varInsert(__Vfinal,"r_src_ip", &(TOP.smartnic_top__DOT__parser_inst__DOT__r_src_ip), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_smartnic_top__parser_inst.varInsert(__Vfinal,"r_src_port", &(TOP.smartnic_top__DOT__parser_inst__DOT__r_src_port), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_smartnic_top__parser_inst.varInsert(__Vfinal,"rst_n", &(TOP.smartnic_top__DOT__parser_inst__DOT__rst_n), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_smartnic_top__parser_inst.varInsert(__Vfinal,"src_ip", &(TOP.smartnic_top__DOT__parser_inst__DOT__src_ip), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_smartnic_top__parser_inst.varInsert(__Vfinal,"src_port", &(TOP.smartnic_top__DOT__parser_inst__DOT__src_port), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,15,0);
        __Vscope_smartnic_top__parser_inst.varInsert(__Vfinal,"state", &(TOP.smartnic_top__DOT__parser_inst__DOT__state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
    }
}
