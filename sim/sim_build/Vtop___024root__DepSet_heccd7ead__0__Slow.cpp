// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/ubuntu/ufa_project/sim/../rtl/smartnic_top.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->sw_write_en = VL_RAND_RESET_I(1);
    vlSelf->sw_write_addr = VL_RAND_RESET_I(8);
    vlSelf->sw_write_data = VL_RAND_RESET_Q(64);
    vlSelf->in_valid = VL_RAND_RESET_I(1);
    vlSelf->in_data = VL_RAND_RESET_Q(64);
    vlSelf->in_last = VL_RAND_RESET_I(1);
    vlSelf->match_valid = VL_RAND_RESET_I(1);
    vlSelf->match_action = VL_RAND_RESET_Q(64);
    vlSelf->smartnic_top__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->smartnic_top__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->smartnic_top__DOT__sw_write_en = VL_RAND_RESET_I(1);
    vlSelf->smartnic_top__DOT__sw_write_addr = VL_RAND_RESET_I(8);
    vlSelf->smartnic_top__DOT__sw_write_data = VL_RAND_RESET_Q(64);
    vlSelf->smartnic_top__DOT__in_valid = VL_RAND_RESET_I(1);
    vlSelf->smartnic_top__DOT__in_data = VL_RAND_RESET_Q(64);
    vlSelf->smartnic_top__DOT__in_last = VL_RAND_RESET_I(1);
    vlSelf->smartnic_top__DOT__match_valid = VL_RAND_RESET_I(1);
    vlSelf->smartnic_top__DOT__match_action = VL_RAND_RESET_Q(64);
    vlSelf->smartnic_top__DOT__parser_out_valid = VL_RAND_RESET_I(1);
    vlSelf->smartnic_top__DOT__src_ip = VL_RAND_RESET_I(32);
    vlSelf->smartnic_top__DOT__dst_ip = VL_RAND_RESET_I(32);
    vlSelf->smartnic_top__DOT__src_port = VL_RAND_RESET_I(16);
    vlSelf->smartnic_top__DOT__dst_port = VL_RAND_RESET_I(16);
    vlSelf->smartnic_top__DOT__protocol = VL_RAND_RESET_I(8);
    vlSelf->smartnic_top__DOT__lookup_addr = VL_RAND_RESET_I(8);
    vlSelf->smartnic_top__DOT__parser_inst__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->smartnic_top__DOT__parser_inst__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->smartnic_top__DOT__parser_inst__DOT__in_valid = VL_RAND_RESET_I(1);
    vlSelf->smartnic_top__DOT__parser_inst__DOT__in_data = VL_RAND_RESET_Q(64);
    vlSelf->smartnic_top__DOT__parser_inst__DOT__in_last = VL_RAND_RESET_I(1);
    vlSelf->smartnic_top__DOT__parser_inst__DOT__out_valid = VL_RAND_RESET_I(1);
    vlSelf->smartnic_top__DOT__parser_inst__DOT__src_ip = VL_RAND_RESET_I(32);
    vlSelf->smartnic_top__DOT__parser_inst__DOT__dst_ip = VL_RAND_RESET_I(32);
    vlSelf->smartnic_top__DOT__parser_inst__DOT__src_port = VL_RAND_RESET_I(16);
    vlSelf->smartnic_top__DOT__parser_inst__DOT__dst_port = VL_RAND_RESET_I(16);
    vlSelf->smartnic_top__DOT__parser_inst__DOT__protocol = VL_RAND_RESET_I(8);
    vlSelf->smartnic_top__DOT__parser_inst__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->smartnic_top__DOT__parser_inst__DOT__next_state = VL_RAND_RESET_I(2);
    vlSelf->smartnic_top__DOT__parser_inst__DOT__r_src_ip = VL_RAND_RESET_I(32);
    vlSelf->smartnic_top__DOT__parser_inst__DOT__r_dst_ip = VL_RAND_RESET_I(32);
    vlSelf->smartnic_top__DOT__parser_inst__DOT__r_src_port = VL_RAND_RESET_I(16);
    vlSelf->smartnic_top__DOT__parser_inst__DOT__r_dst_port = VL_RAND_RESET_I(16);
    vlSelf->smartnic_top__DOT__parser_inst__DOT__r_protocol = VL_RAND_RESET_I(8);
    vlSelf->smartnic_top__DOT__lookup_inst__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->smartnic_top__DOT__lookup_inst__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->smartnic_top__DOT__lookup_inst__DOT__write_en = VL_RAND_RESET_I(1);
    vlSelf->smartnic_top__DOT__lookup_inst__DOT__write_addr = VL_RAND_RESET_I(8);
    vlSelf->smartnic_top__DOT__lookup_inst__DOT__write_data = VL_RAND_RESET_Q(64);
    vlSelf->smartnic_top__DOT__lookup_inst__DOT__req_valid = VL_RAND_RESET_I(1);
    vlSelf->smartnic_top__DOT__lookup_inst__DOT__req_addr = VL_RAND_RESET_I(8);
    vlSelf->smartnic_top__DOT__lookup_inst__DOT__resp_valid = VL_RAND_RESET_I(1);
    vlSelf->smartnic_top__DOT__lookup_inst__DOT__resp_data = VL_RAND_RESET_Q(64);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->smartnic_top__DOT__lookup_inst__DOT__memory[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
}
