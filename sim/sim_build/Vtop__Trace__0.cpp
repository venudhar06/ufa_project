// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+2,(vlSelfRef.sw_write_en));
    bufp->chgCData(oldp+3,(vlSelfRef.sw_write_addr),8);
    bufp->chgQData(oldp+4,(vlSelfRef.sw_write_data),64);
    bufp->chgBit(oldp+6,(vlSelfRef.in_valid));
    bufp->chgQData(oldp+7,(vlSelfRef.in_data),64);
    bufp->chgBit(oldp+9,(vlSelfRef.in_last));
    bufp->chgBit(oldp+10,(vlSelfRef.match_valid));
    bufp->chgQData(oldp+11,(vlSelfRef.match_action),64);
    bufp->chgBit(oldp+13,(vlSelfRef.smartnic_top__DOT__clk));
    bufp->chgBit(oldp+14,(vlSelfRef.smartnic_top__DOT__rst_n));
    bufp->chgBit(oldp+15,(vlSelfRef.smartnic_top__DOT__sw_write_en));
    bufp->chgCData(oldp+16,(vlSelfRef.smartnic_top__DOT__sw_write_addr),8);
    bufp->chgQData(oldp+17,(vlSelfRef.smartnic_top__DOT__sw_write_data),64);
    bufp->chgBit(oldp+19,(vlSelfRef.smartnic_top__DOT__in_valid));
    bufp->chgQData(oldp+20,(vlSelfRef.smartnic_top__DOT__in_data),64);
    bufp->chgBit(oldp+22,(vlSelfRef.smartnic_top__DOT__in_last));
    bufp->chgBit(oldp+23,(vlSelfRef.smartnic_top__DOT__match_valid));
    bufp->chgQData(oldp+24,(vlSelfRef.smartnic_top__DOT__match_action),64);
    bufp->chgBit(oldp+26,(vlSelfRef.smartnic_top__DOT__parser_out_valid));
    bufp->chgIData(oldp+27,(vlSelfRef.smartnic_top__DOT__src_ip),32);
    bufp->chgIData(oldp+28,(vlSelfRef.smartnic_top__DOT__dst_ip),32);
    bufp->chgSData(oldp+29,(vlSelfRef.smartnic_top__DOT__src_port),16);
    bufp->chgSData(oldp+30,(vlSelfRef.smartnic_top__DOT__dst_port),16);
    bufp->chgCData(oldp+31,(vlSelfRef.smartnic_top__DOT__protocol),8);
    bufp->chgCData(oldp+32,(vlSelfRef.smartnic_top__DOT__lookup_addr),8);
    bufp->chgBit(oldp+33,(vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__clk));
    bufp->chgBit(oldp+34,(vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__rst_n));
    bufp->chgBit(oldp+35,(vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__write_en));
    bufp->chgCData(oldp+36,(vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__write_addr),8);
    bufp->chgQData(oldp+37,(vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__write_data),64);
    bufp->chgBit(oldp+39,(vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__req_valid));
    bufp->chgCData(oldp+40,(vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__req_addr),8);
    bufp->chgBit(oldp+41,(vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__resp_valid));
    bufp->chgQData(oldp+42,(vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__resp_data),64);
    bufp->chgBit(oldp+44,(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__clk));
    bufp->chgBit(oldp+45,(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__rst_n));
    bufp->chgBit(oldp+46,(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__in_valid));
    bufp->chgQData(oldp+47,(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__in_data),64);
    bufp->chgBit(oldp+49,(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__in_last));
    bufp->chgBit(oldp+50,(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__out_valid));
    bufp->chgIData(oldp+51,(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__src_ip),32);
    bufp->chgIData(oldp+52,(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__dst_ip),32);
    bufp->chgSData(oldp+53,(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__src_port),16);
    bufp->chgSData(oldp+54,(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__dst_port),16);
    bufp->chgCData(oldp+55,(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__protocol),8);
    bufp->chgCData(oldp+56,(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__state),2);
    bufp->chgCData(oldp+57,(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__next_state),2);
    bufp->chgIData(oldp+58,(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_src_ip),32);
    bufp->chgIData(oldp+59,(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_dst_ip),32);
    bufp->chgSData(oldp+60,(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_src_port),16);
    bufp->chgSData(oldp+61,(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_dst_port),16);
    bufp->chgCData(oldp+62,(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_protocol),8);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
