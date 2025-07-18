// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VinsertionSort.h for the primary calling header

#include "VinsertionSort__pch.h"
#include "VinsertionSort___024root.h"

VL_ATTR_COLD void VinsertionSort___024root___eval_static(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval_static\n"); );
}

VL_ATTR_COLD void VinsertionSort___024root___eval_final(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VinsertionSort___024root___dump_triggers__stl(VinsertionSort___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VinsertionSort___024root___eval_phase__stl(VinsertionSort___024root* vlSelf);

VL_ATTR_COLD void VinsertionSort___024root___eval_settle(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VinsertionSort___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb_insertionSort.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VinsertionSort___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VinsertionSort___024root___dump_triggers__stl(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void VinsertionSort___024root___act_comb__TOP__0(VinsertionSort___024root* vlSelf);

VL_ATTR_COLD void VinsertionSort___024root___eval_stl(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VinsertionSort___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void VinsertionSort___024root___eval_triggers__stl(VinsertionSort___024root* vlSelf);

VL_ATTR_COLD bool VinsertionSort___024root___eval_phase__stl(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VinsertionSort___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        VinsertionSort___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VinsertionSort___024root___dump_triggers__act(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_insertionSort.i_clk or negedge tb_insertionSort.i_rst_n)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([changed] tb_insertionSort.o_done)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VinsertionSort___024root___dump_triggers__nba(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_insertionSort.i_clk or negedge tb_insertionSort.i_rst_n)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([changed] tb_insertionSort.o_done)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VinsertionSort___024root___ctor_var_reset(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_insertionSort__DOT__i_clk = VL_RAND_RESET_I(1);
    vlSelf->tb_insertionSort__DOT__i_rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_insertionSort__DOT__i_start = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_insertionSort__DOT__i_data[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_insertionSort__DOT__o_data[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_insertionSort__DOT__o_done = VL_RAND_RESET_I(1);
    vlSelf->tb_insertionSort__DOT__DUT__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->tb_insertionSort__DOT__DUT__DOT__n_state = VL_RAND_RESET_I(2);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_insertionSort__DOT__DUT__DOT__arr[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_insertionSort__DOT__DUT__DOT__key = VL_RAND_RESET_I(8);
    vlSelf->tb_insertionSort__DOT__DUT__DOT__i = VL_RAND_RESET_I(4);
    vlSelf->tb_insertionSort__DOT__DUT__DOT__j = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigprevexpr___TOP__tb_insertionSort__DOT__i_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_insertionSort__DOT__i_rst_n__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_insertionSort__DOT__o_done__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
}
