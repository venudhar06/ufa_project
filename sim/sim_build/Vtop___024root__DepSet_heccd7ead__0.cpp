// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*1:0*/, 8> Vtop__ConstPool__TABLE_h02293e84_0;

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.match_valid = vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__resp_valid;
    vlSelfRef.smartnic_top__DOT__match_valid = vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__resp_valid;
    vlSelfRef.match_action = vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__resp_data;
    vlSelfRef.smartnic_top__DOT__match_action = vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__resp_data;
    vlSelfRef.smartnic_top__DOT__dst_ip = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_dst_ip;
    vlSelfRef.smartnic_top__DOT__parser_inst__DOT__dst_ip 
        = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_dst_ip;
    vlSelfRef.smartnic_top__DOT__parser_inst__DOT__src_ip 
        = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_src_ip;
    vlSelfRef.smartnic_top__DOT__src_ip = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_src_ip;
    vlSelfRef.smartnic_top__DOT__parser_inst__DOT__src_port 
        = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_src_port;
    vlSelfRef.smartnic_top__DOT__src_port = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_src_port;
    vlSelfRef.smartnic_top__DOT__parser_inst__DOT__dst_port 
        = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_dst_port;
    vlSelfRef.smartnic_top__DOT__dst_port = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_dst_port;
    vlSelfRef.smartnic_top__DOT__parser_inst__DOT__protocol 
        = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_protocol;
    vlSelfRef.smartnic_top__DOT__protocol = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_protocol;
    vlSelfRef.smartnic_top__DOT__sw_write_en = vlSelfRef.sw_write_en;
    vlSelfRef.smartnic_top__DOT__sw_write_addr = vlSelfRef.sw_write_addr;
    vlSelfRef.smartnic_top__DOT__sw_write_data = vlSelfRef.sw_write_data;
    vlSelfRef.smartnic_top__DOT__in_valid = vlSelfRef.in_valid;
    vlSelfRef.smartnic_top__DOT__in_data = vlSelfRef.in_data;
    vlSelfRef.smartnic_top__DOT__in_last = vlSelfRef.in_last;
    vlSelfRef.smartnic_top__DOT__lookup_addr = (0xffU 
                                                & vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_dst_ip);
    vlSelfRef.smartnic_top__DOT__parser_out_valid = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__out_valid;
    __Vtableidx1 = (((IData)(vlSelfRef.in_valid) << 2U) 
                    | (IData)(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__state));
    vlSelfRef.smartnic_top__DOT__parser_inst__DOT__next_state 
        = Vtop__ConstPool__TABLE_h02293e84_0[__Vtableidx1];
    vlSelfRef.smartnic_top__DOT__clk = vlSelfRef.clk;
    vlSelfRef.smartnic_top__DOT__rst_n = vlSelfRef.rst_n;
    vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__write_en 
        = vlSelfRef.smartnic_top__DOT__sw_write_en;
    vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__write_addr 
        = vlSelfRef.smartnic_top__DOT__sw_write_addr;
    vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__write_data 
        = vlSelfRef.smartnic_top__DOT__sw_write_data;
    vlSelfRef.smartnic_top__DOT__parser_inst__DOT__in_valid 
        = vlSelfRef.smartnic_top__DOT__in_valid;
    vlSelfRef.smartnic_top__DOT__parser_inst__DOT__in_data 
        = vlSelfRef.smartnic_top__DOT__in_data;
    vlSelfRef.smartnic_top__DOT__parser_inst__DOT__in_last 
        = vlSelfRef.smartnic_top__DOT__in_last;
    vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__req_addr 
        = vlSelfRef.smartnic_top__DOT__lookup_addr;
    vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__req_valid 
        = vlSelfRef.smartnic_top__DOT__parser_out_valid;
    vlSelfRef.smartnic_top__DOT__parser_inst__DOT__clk 
        = vlSelfRef.smartnic_top__DOT__clk;
    vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__clk 
        = vlSelfRef.smartnic_top__DOT__clk;
    vlSelfRef.smartnic_top__DOT__parser_inst__DOT__rst_n 
        = vlSelfRef.smartnic_top__DOT__rst_n;
    vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__rst_n 
        = vlSelfRef.smartnic_top__DOT__rst_n;
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    QData/*63:0*/ __VdlyVal__smartnic_top__DOT__lookup_inst__DOT__memory__v0;
    __VdlyVal__smartnic_top__DOT__lookup_inst__DOT__memory__v0 = 0;
    CData/*7:0*/ __VdlyDim0__smartnic_top__DOT__lookup_inst__DOT__memory__v0;
    __VdlyDim0__smartnic_top__DOT__lookup_inst__DOT__memory__v0 = 0;
    CData/*0:0*/ __VdlySet__smartnic_top__DOT__lookup_inst__DOT__memory__v0;
    __VdlySet__smartnic_top__DOT__lookup_inst__DOT__memory__v0 = 0;
    // Body
    __VdlySet__smartnic_top__DOT__lookup_inst__DOT__memory__v0 = 0U;
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.sw_write_en) {
            __VdlyVal__smartnic_top__DOT__lookup_inst__DOT__memory__v0 
                = vlSelfRef.sw_write_data;
            __VdlyDim0__smartnic_top__DOT__lookup_inst__DOT__memory__v0 
                = vlSelfRef.sw_write_addr;
            __VdlySet__smartnic_top__DOT__lookup_inst__DOT__memory__v0 = 1U;
        }
        if (vlSelfRef.smartnic_top__DOT__parser_out_valid) {
            vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__resp_data 
                = vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__memory
                [vlSelfRef.smartnic_top__DOT__lookup_addr];
        }
        if (((2U == (IData)(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__state)) 
             & (IData)(vlSelfRef.in_valid))) {
            vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_src_ip 
                = (IData)((vlSelfRef.in_data >> 0x20U));
            vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_dst_ip 
                = (IData)(vlSelfRef.in_data);
            vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_src_port = 0x50U;
            vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_dst_port = 0x1f90U;
            vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_protocol = 6U;
            vlSelfRef.smartnic_top__DOT__parser_inst__DOT__out_valid = 1U;
        } else if ((3U == (IData)(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__state))) {
            vlSelfRef.smartnic_top__DOT__parser_inst__DOT__out_valid = 0U;
        }
        vlSelfRef.smartnic_top__DOT__parser_inst__DOT__state 
            = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__next_state;
    } else {
        vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__resp_data = 0ULL;
        vlSelfRef.smartnic_top__DOT__parser_inst__DOT__out_valid = 0U;
        vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_src_ip = 0U;
        vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_dst_ip = 0U;
        vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_src_port = 0U;
        vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_dst_port = 0U;
        vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_protocol = 0U;
        vlSelfRef.smartnic_top__DOT__parser_inst__DOT__state = 0U;
    }
    vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__resp_valid 
        = ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.smartnic_top__DOT__parser_out_valid));
    if (__VdlySet__smartnic_top__DOT__lookup_inst__DOT__memory__v0) {
        vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__memory[__VdlyDim0__smartnic_top__DOT__lookup_inst__DOT__memory__v0] 
            = __VdlyVal__smartnic_top__DOT__lookup_inst__DOT__memory__v0;
    }
    vlSelfRef.match_valid = vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__resp_valid;
    vlSelfRef.smartnic_top__DOT__match_valid = vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__resp_valid;
    vlSelfRef.match_action = vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__resp_data;
    vlSelfRef.smartnic_top__DOT__match_action = vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__resp_data;
    vlSelfRef.smartnic_top__DOT__parser_inst__DOT__src_ip 
        = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_src_ip;
    vlSelfRef.smartnic_top__DOT__src_ip = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_src_ip;
    vlSelfRef.smartnic_top__DOT__parser_inst__DOT__src_port 
        = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_src_port;
    vlSelfRef.smartnic_top__DOT__src_port = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_src_port;
    vlSelfRef.smartnic_top__DOT__parser_inst__DOT__dst_port 
        = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_dst_port;
    vlSelfRef.smartnic_top__DOT__dst_port = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_dst_port;
    vlSelfRef.smartnic_top__DOT__parser_inst__DOT__protocol 
        = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_protocol;
    vlSelfRef.smartnic_top__DOT__protocol = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_protocol;
    vlSelfRef.smartnic_top__DOT__parser_out_valid = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__out_valid;
    vlSelfRef.smartnic_top__DOT__dst_ip = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_dst_ip;
    vlSelfRef.smartnic_top__DOT__parser_inst__DOT__dst_ip 
        = vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_dst_ip;
    vlSelfRef.smartnic_top__DOT__lookup_addr = (0xffU 
                                                & vlSelfRef.smartnic_top__DOT__parser_inst__DOT__r_dst_ip);
    vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__req_valid 
        = vlSelfRef.smartnic_top__DOT__parser_out_valid;
    vlSelfRef.smartnic_top__DOT__lookup_inst__DOT__req_addr 
        = vlSelfRef.smartnic_top__DOT__lookup_addr;
    __Vtableidx1 = (((IData)(vlSelfRef.in_valid) << 2U) 
                    | (IData)(vlSelfRef.smartnic_top__DOT__parser_inst__DOT__state));
    vlSelfRef.smartnic_top__DOT__parser_inst__DOT__next_state 
        = Vtop__ConstPool__TABLE_h02293e84_0[__Vtableidx1];
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/ubuntu/ufa_project/sim/../rtl/smartnic_top.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/ubuntu/ufa_project/sim/../rtl/smartnic_top.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/ubuntu/ufa_project/sim/../rtl/smartnic_top.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY(((vlSelfRef.sw_write_en & 0xfeU)))) {
        Verilated::overWidthError("sw_write_en");}
    if (VL_UNLIKELY(((vlSelfRef.in_valid & 0xfeU)))) {
        Verilated::overWidthError("in_valid");}
    if (VL_UNLIKELY(((vlSelfRef.in_last & 0xfeU)))) {
        Verilated::overWidthError("in_last");}
}
#endif  // VL_DEBUG
