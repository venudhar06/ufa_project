// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(sw_write_en,0,0);
    VL_IN8(sw_write_addr,7,0);
    VL_IN8(in_valid,0,0);
    VL_IN8(in_last,0,0);
    VL_OUT8(match_valid,0,0);
    CData/*0:0*/ smartnic_top__DOT__clk;
    CData/*0:0*/ smartnic_top__DOT__rst_n;
    CData/*0:0*/ smartnic_top__DOT__sw_write_en;
    CData/*7:0*/ smartnic_top__DOT__sw_write_addr;
    CData/*0:0*/ smartnic_top__DOT__in_valid;
    CData/*0:0*/ smartnic_top__DOT__in_last;
    CData/*0:0*/ smartnic_top__DOT__match_valid;
    CData/*0:0*/ smartnic_top__DOT__parser_out_valid;
    CData/*7:0*/ smartnic_top__DOT__protocol;
    CData/*7:0*/ smartnic_top__DOT__lookup_addr;
    CData/*0:0*/ smartnic_top__DOT__parser_inst__DOT__clk;
    CData/*0:0*/ smartnic_top__DOT__parser_inst__DOT__rst_n;
    CData/*0:0*/ smartnic_top__DOT__parser_inst__DOT__in_valid;
    CData/*0:0*/ smartnic_top__DOT__parser_inst__DOT__in_last;
    CData/*0:0*/ smartnic_top__DOT__parser_inst__DOT__out_valid;
    CData/*7:0*/ smartnic_top__DOT__parser_inst__DOT__protocol;
    CData/*1:0*/ smartnic_top__DOT__parser_inst__DOT__state;
    CData/*1:0*/ smartnic_top__DOT__parser_inst__DOT__next_state;
    CData/*7:0*/ smartnic_top__DOT__parser_inst__DOT__r_protocol;
    CData/*0:0*/ smartnic_top__DOT__lookup_inst__DOT__clk;
    CData/*0:0*/ smartnic_top__DOT__lookup_inst__DOT__rst_n;
    CData/*0:0*/ smartnic_top__DOT__lookup_inst__DOT__write_en;
    CData/*7:0*/ smartnic_top__DOT__lookup_inst__DOT__write_addr;
    CData/*0:0*/ smartnic_top__DOT__lookup_inst__DOT__req_valid;
    CData/*7:0*/ smartnic_top__DOT__lookup_inst__DOT__req_addr;
    CData/*0:0*/ smartnic_top__DOT__lookup_inst__DOT__resp_valid;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ smartnic_top__DOT__src_port;
    SData/*15:0*/ smartnic_top__DOT__dst_port;
    SData/*15:0*/ smartnic_top__DOT__parser_inst__DOT__src_port;
    SData/*15:0*/ smartnic_top__DOT__parser_inst__DOT__dst_port;
    SData/*15:0*/ smartnic_top__DOT__parser_inst__DOT__r_src_port;
    SData/*15:0*/ smartnic_top__DOT__parser_inst__DOT__r_dst_port;
    IData/*31:0*/ smartnic_top__DOT__src_ip;
    IData/*31:0*/ smartnic_top__DOT__dst_ip;
    IData/*31:0*/ smartnic_top__DOT__parser_inst__DOT__src_ip;
    IData/*31:0*/ smartnic_top__DOT__parser_inst__DOT__dst_ip;
    IData/*31:0*/ smartnic_top__DOT__parser_inst__DOT__r_src_ip;
    IData/*31:0*/ smartnic_top__DOT__parser_inst__DOT__r_dst_ip;
    IData/*31:0*/ __VactIterCount;
    VL_IN64(sw_write_data,63,0);
    VL_IN64(in_data,63,0);
    VL_OUT64(match_action,63,0);
    QData/*63:0*/ smartnic_top__DOT__sw_write_data;
    QData/*63:0*/ smartnic_top__DOT__in_data;
    QData/*63:0*/ smartnic_top__DOT__match_action;
    QData/*63:0*/ smartnic_top__DOT__parser_inst__DOT__in_data;
    QData/*63:0*/ smartnic_top__DOT__lookup_inst__DOT__write_data;
    QData/*63:0*/ smartnic_top__DOT__lookup_inst__DOT__resp_data;
    VlUnpacked<QData/*63:0*/, 256> smartnic_top__DOT__lookup_inst__DOT__memory;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr IData/*31:0*/ smartnic_top__DOT__lookup_inst__DOT__DATA_WIDTH = 0x00000040U;
    static constexpr IData/*31:0*/ smartnic_top__DOT__lookup_inst__DOT__ADDR_WIDTH = 8U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
