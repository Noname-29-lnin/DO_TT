// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VinsertionSort.h for the primary calling header

#include "VinsertionSort__pch.h"
#include "VinsertionSort___024root.h"

VL_INLINE_OPT void VinsertionSort___024root___ico_sequent__TOP__0(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->insertionSort__DOT__n_state = ((4U & (IData)(vlSelf->insertionSort__DOT__state))
                                            ? ((2U 
                                                & (IData)(vlSelf->insertionSort__DOT__state))
                                                ? 0U
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelf->insertionSort__DOT__state))
                                                    ? 0U
                                                    : 2U))
                                            : ((2U 
                                                & (IData)(vlSelf->insertionSort__DOT__state))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelf->insertionSort__DOT__state))
                                                    ? 
                                                   (((0xfU 
                                                      > (IData)(vlSelf->insertionSort__DOT__j)) 
                                                     & (vlSelf->insertionSort__DOT__arr
                                                        [
                                                        (7U 
                                                         & (IData)(vlSelf->insertionSort__DOT__j))] 
                                                        > (IData)(vlSelf->insertionSort__DOT__key)))
                                                     ? 3U
                                                     : 4U)
                                                    : 
                                                   ((8U 
                                                     > (IData)(vlSelf->insertionSort__DOT__i))
                                                     ? 3U
                                                     : 5U))
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelf->insertionSort__DOT__state))
                                                    ? 2U
                                                    : 
                                                   ((IData)(vlSelf->i_start)
                                                     ? 1U
                                                     : 0U))));
}

void VinsertionSort___024root___eval_ico(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VinsertionSort___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VinsertionSort___024root___eval_triggers__ico(VinsertionSort___024root* vlSelf);

bool VinsertionSort___024root___eval_phase__ico(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VinsertionSort___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        VinsertionSort___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VinsertionSort___024root___eval_act(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval_act\n"); );
}

VL_INLINE_OPT void VinsertionSort___024root___nba_sequent__TOP__0(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vdlyvval__o_data__v0;
    __Vdlyvval__o_data__v0 = 0;
    CData/*0:0*/ __Vdlyvset__o_data__v0;
    __Vdlyvset__o_data__v0 = 0;
    CData/*7:0*/ __Vdlyvval__o_data__v1;
    __Vdlyvval__o_data__v1 = 0;
    CData/*7:0*/ __Vdlyvval__o_data__v2;
    __Vdlyvval__o_data__v2 = 0;
    CData/*7:0*/ __Vdlyvval__o_data__v3;
    __Vdlyvval__o_data__v3 = 0;
    CData/*7:0*/ __Vdlyvval__o_data__v4;
    __Vdlyvval__o_data__v4 = 0;
    CData/*7:0*/ __Vdlyvval__o_data__v5;
    __Vdlyvval__o_data__v5 = 0;
    CData/*7:0*/ __Vdlyvval__o_data__v6;
    __Vdlyvval__o_data__v6 = 0;
    CData/*7:0*/ __Vdlyvval__o_data__v7;
    __Vdlyvval__o_data__v7 = 0;
    CData/*3:0*/ __Vdly__insertionSort__DOT__i;
    __Vdly__insertionSort__DOT__i = 0;
    CData/*2:0*/ __Vdlyvdim0__insertionSort__DOT__arr__v0;
    __Vdlyvdim0__insertionSort__DOT__arr__v0 = 0;
    CData/*7:0*/ __Vdlyvval__insertionSort__DOT__arr__v0;
    __Vdlyvval__insertionSort__DOT__arr__v0 = 0;
    CData/*0:0*/ __Vdlyvset__insertionSort__DOT__arr__v0;
    __Vdlyvset__insertionSort__DOT__arr__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__insertionSort__DOT__arr__v1;
    __Vdlyvdim0__insertionSort__DOT__arr__v1 = 0;
    CData/*7:0*/ __Vdlyvval__insertionSort__DOT__arr__v1;
    __Vdlyvval__insertionSort__DOT__arr__v1 = 0;
    CData/*0:0*/ __Vdlyvset__insertionSort__DOT__arr__v1;
    __Vdlyvset__insertionSort__DOT__arr__v1 = 0;
    CData/*7:0*/ __Vdlyvval__insertionSort__DOT__arr__v2;
    __Vdlyvval__insertionSort__DOT__arr__v2 = 0;
    CData/*0:0*/ __Vdlyvset__insertionSort__DOT__arr__v2;
    __Vdlyvset__insertionSort__DOT__arr__v2 = 0;
    CData/*7:0*/ __Vdlyvval__insertionSort__DOT__arr__v3;
    __Vdlyvval__insertionSort__DOT__arr__v3 = 0;
    CData/*7:0*/ __Vdlyvval__insertionSort__DOT__arr__v4;
    __Vdlyvval__insertionSort__DOT__arr__v4 = 0;
    CData/*7:0*/ __Vdlyvval__insertionSort__DOT__arr__v5;
    __Vdlyvval__insertionSort__DOT__arr__v5 = 0;
    CData/*7:0*/ __Vdlyvval__insertionSort__DOT__arr__v6;
    __Vdlyvval__insertionSort__DOT__arr__v6 = 0;
    CData/*7:0*/ __Vdlyvval__insertionSort__DOT__arr__v7;
    __Vdlyvval__insertionSort__DOT__arr__v7 = 0;
    CData/*7:0*/ __Vdlyvval__insertionSort__DOT__arr__v8;
    __Vdlyvval__insertionSort__DOT__arr__v8 = 0;
    CData/*7:0*/ __Vdlyvval__insertionSort__DOT__arr__v9;
    __Vdlyvval__insertionSort__DOT__arr__v9 = 0;
    CData/*0:0*/ __Vdlyvset__insertionSort__DOT__arr__v10;
    __Vdlyvset__insertionSort__DOT__arr__v10 = 0;
    // Body
    __Vdly__insertionSort__DOT__i = vlSelf->insertionSort__DOT__i;
    __Vdlyvset__o_data__v0 = 0U;
    __Vdlyvset__insertionSort__DOT__arr__v0 = 0U;
    __Vdlyvset__insertionSort__DOT__arr__v1 = 0U;
    __Vdlyvset__insertionSort__DOT__arr__v2 = 0U;
    __Vdlyvset__insertionSort__DOT__arr__v10 = 0U;
    if (vlSelf->i_rst_n) {
        if ((4U & (IData)(vlSelf->insertionSort__DOT__state))) {
            if ((1U & (~ ((IData)(vlSelf->insertionSort__DOT__state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelf->insertionSort__DOT__state))) {
                    __Vdlyvval__o_data__v0 = vlSelf->insertionSort__DOT__arr
                        [0U];
                    __Vdlyvset__o_data__v0 = 1U;
                    __Vdlyvval__o_data__v1 = vlSelf->insertionSort__DOT__arr
                        [1U];
                    __Vdlyvval__o_data__v2 = vlSelf->insertionSort__DOT__arr
                        [2U];
                    __Vdlyvval__o_data__v3 = vlSelf->insertionSort__DOT__arr
                        [3U];
                    __Vdlyvval__o_data__v4 = vlSelf->insertionSort__DOT__arr
                        [4U];
                    __Vdlyvval__o_data__v5 = vlSelf->insertionSort__DOT__arr
                        [5U];
                    __Vdlyvval__o_data__v6 = vlSelf->insertionSort__DOT__arr
                        [6U];
                    __Vdlyvval__o_data__v7 = vlSelf->insertionSort__DOT__arr
                        [7U];
                } else {
                    __Vdly__insertionSort__DOT__i = 
                        (0xfU & ((IData)(1U) + (IData)(vlSelf->insertionSort__DOT__i)));
                    __Vdlyvval__insertionSort__DOT__arr__v0 
                        = vlSelf->insertionSort__DOT__key;
                    __Vdlyvset__insertionSort__DOT__arr__v0 = 1U;
                    __Vdlyvdim0__insertionSort__DOT__arr__v0 
                        = (7U & ((IData)(1U) + (IData)(vlSelf->insertionSort__DOT__j)));
                }
            }
            if ((2U & (IData)(vlSelf->insertionSort__DOT__state))) {
                vlSelf->o_done = 0U;
            } else if ((1U & (IData)(vlSelf->insertionSort__DOT__state))) {
                vlSelf->o_done = 1U;
            }
        } else {
            if ((2U & (IData)(vlSelf->insertionSort__DOT__state))) {
                if ((1U & (IData)(vlSelf->insertionSort__DOT__state))) {
                    if ((vlSelf->insertionSort__DOT__arr
                         [(7U & (IData)(vlSelf->insertionSort__DOT__j))] 
                         > (IData)(vlSelf->insertionSort__DOT__key))) {
                        __Vdlyvval__insertionSort__DOT__arr__v1 
                            = vlSelf->insertionSort__DOT__arr
                            [(7U & (IData)(vlSelf->insertionSort__DOT__j))];
                        __Vdlyvset__insertionSort__DOT__arr__v1 = 1U;
                        __Vdlyvdim0__insertionSort__DOT__arr__v1 
                            = (7U & ((IData)(1U) + (IData)(vlSelf->insertionSort__DOT__j)));
                        vlSelf->insertionSort__DOT__j 
                            = (0xfU & ((IData)(vlSelf->insertionSort__DOT__j) 
                                       - (IData)(1U)));
                    }
                } else {
                    vlSelf->insertionSort__DOT__key 
                        = vlSelf->insertionSort__DOT__arr
                        [(7U & (IData)(vlSelf->insertionSort__DOT__i))];
                    vlSelf->insertionSort__DOT__j = 
                        (0xfU & ((IData)(vlSelf->insertionSort__DOT__i) 
                                 - (IData)(1U)));
                }
            } else if ((1U & (IData)(vlSelf->insertionSort__DOT__state))) {
                __Vdly__insertionSort__DOT__i = 1U;
                __Vdlyvval__insertionSort__DOT__arr__v2 
                    = vlSelf->i_data[0U];
                __Vdlyvset__insertionSort__DOT__arr__v2 = 1U;
                __Vdlyvval__insertionSort__DOT__arr__v3 
                    = vlSelf->i_data[1U];
                __Vdlyvval__insertionSort__DOT__arr__v4 
                    = vlSelf->i_data[2U];
                __Vdlyvval__insertionSort__DOT__arr__v5 
                    = vlSelf->i_data[3U];
                __Vdlyvval__insertionSort__DOT__arr__v6 
                    = vlSelf->i_data[4U];
                __Vdlyvval__insertionSort__DOT__arr__v7 
                    = vlSelf->i_data[5U];
                __Vdlyvval__insertionSort__DOT__arr__v8 
                    = vlSelf->i_data[6U];
                __Vdlyvval__insertionSort__DOT__arr__v9 
                    = vlSelf->i_data[7U];
            }
            if ((1U & (~ ((IData)(vlSelf->insertionSort__DOT__state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelf->insertionSort__DOT__state)))) {
                    vlSelf->o_done = 0U;
                }
            }
        }
        vlSelf->insertionSort__DOT__state = vlSelf->insertionSort__DOT__n_state;
    } else {
        __Vdly__insertionSort__DOT__i = 1U;
        vlSelf->insertionSort__DOT__j = 0U;
        vlSelf->insertionSort__DOT__key = 0U;
        __Vdlyvset__insertionSort__DOT__arr__v10 = 1U;
        vlSelf->o_done = 0U;
        vlSelf->insertionSort__DOT__state = 0U;
    }
    vlSelf->insertionSort__DOT__i = __Vdly__insertionSort__DOT__i;
    if (__Vdlyvset__o_data__v0) {
        vlSelf->o_data[0U] = __Vdlyvval__o_data__v0;
        vlSelf->o_data[1U] = __Vdlyvval__o_data__v1;
        vlSelf->o_data[2U] = __Vdlyvval__o_data__v2;
        vlSelf->o_data[3U] = __Vdlyvval__o_data__v3;
        vlSelf->o_data[4U] = __Vdlyvval__o_data__v4;
        vlSelf->o_data[5U] = __Vdlyvval__o_data__v5;
        vlSelf->o_data[6U] = __Vdlyvval__o_data__v6;
        vlSelf->o_data[7U] = __Vdlyvval__o_data__v7;
    }
    if (__Vdlyvset__insertionSort__DOT__arr__v0) {
        vlSelf->insertionSort__DOT__arr[__Vdlyvdim0__insertionSort__DOT__arr__v0] 
            = __Vdlyvval__insertionSort__DOT__arr__v0;
    }
    if (__Vdlyvset__insertionSort__DOT__arr__v1) {
        vlSelf->insertionSort__DOT__arr[__Vdlyvdim0__insertionSort__DOT__arr__v1] 
            = __Vdlyvval__insertionSort__DOT__arr__v1;
    }
    if (__Vdlyvset__insertionSort__DOT__arr__v2) {
        vlSelf->insertionSort__DOT__arr[0U] = __Vdlyvval__insertionSort__DOT__arr__v2;
        vlSelf->insertionSort__DOT__arr[1U] = __Vdlyvval__insertionSort__DOT__arr__v3;
        vlSelf->insertionSort__DOT__arr[2U] = __Vdlyvval__insertionSort__DOT__arr__v4;
        vlSelf->insertionSort__DOT__arr[3U] = __Vdlyvval__insertionSort__DOT__arr__v5;
        vlSelf->insertionSort__DOT__arr[4U] = __Vdlyvval__insertionSort__DOT__arr__v6;
        vlSelf->insertionSort__DOT__arr[5U] = __Vdlyvval__insertionSort__DOT__arr__v7;
        vlSelf->insertionSort__DOT__arr[6U] = __Vdlyvval__insertionSort__DOT__arr__v8;
        vlSelf->insertionSort__DOT__arr[7U] = __Vdlyvval__insertionSort__DOT__arr__v9;
    }
    if (__Vdlyvset__insertionSort__DOT__arr__v10) {
        vlSelf->o_data[0U] = 0U;
        vlSelf->o_data[1U] = 0U;
        vlSelf->o_data[2U] = 0U;
        vlSelf->o_data[3U] = 0U;
        vlSelf->o_data[4U] = 0U;
        vlSelf->o_data[5U] = 0U;
        vlSelf->o_data[6U] = 0U;
        vlSelf->o_data[7U] = 0U;
        vlSelf->insertionSort__DOT__arr[0U] = 0U;
        vlSelf->insertionSort__DOT__arr[1U] = 0U;
        vlSelf->insertionSort__DOT__arr[2U] = 0U;
        vlSelf->insertionSort__DOT__arr[3U] = 0U;
        vlSelf->insertionSort__DOT__arr[4U] = 0U;
        vlSelf->insertionSort__DOT__arr[5U] = 0U;
        vlSelf->insertionSort__DOT__arr[6U] = 0U;
        vlSelf->insertionSort__DOT__arr[7U] = 0U;
    }
    vlSelf->insertionSort__DOT__n_state = ((4U & (IData)(vlSelf->insertionSort__DOT__state))
                                            ? ((2U 
                                                & (IData)(vlSelf->insertionSort__DOT__state))
                                                ? 0U
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelf->insertionSort__DOT__state))
                                                    ? 0U
                                                    : 2U))
                                            : ((2U 
                                                & (IData)(vlSelf->insertionSort__DOT__state))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelf->insertionSort__DOT__state))
                                                    ? 
                                                   (((0xfU 
                                                      > (IData)(vlSelf->insertionSort__DOT__j)) 
                                                     & (vlSelf->insertionSort__DOT__arr
                                                        [
                                                        (7U 
                                                         & (IData)(vlSelf->insertionSort__DOT__j))] 
                                                        > (IData)(vlSelf->insertionSort__DOT__key)))
                                                     ? 3U
                                                     : 4U)
                                                    : 
                                                   ((8U 
                                                     > (IData)(vlSelf->insertionSort__DOT__i))
                                                     ? 3U
                                                     : 5U))
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelf->insertionSort__DOT__state))
                                                    ? 2U
                                                    : 
                                                   ((IData)(vlSelf->i_start)
                                                     ? 1U
                                                     : 0U))));
}

void VinsertionSort___024root___eval_nba(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VinsertionSort___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void VinsertionSort___024root___eval_triggers__act(VinsertionSort___024root* vlSelf);

bool VinsertionSort___024root___eval_phase__act(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VinsertionSort___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VinsertionSort___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VinsertionSort___024root___eval_phase__nba(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VinsertionSort___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VinsertionSort___024root___dump_triggers__ico(VinsertionSort___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VinsertionSort___024root___dump_triggers__nba(VinsertionSort___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VinsertionSort___024root___dump_triggers__act(VinsertionSort___024root* vlSelf);
#endif  // VL_DEBUG

void VinsertionSort___024root___eval(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            VinsertionSort___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../../02_rtl/insertionSort.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VinsertionSort___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VinsertionSort___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../../02_rtl/insertionSort.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VinsertionSort___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../../02_rtl/insertionSort.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VinsertionSort___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VinsertionSort___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VinsertionSort___024root___eval_debug_assertions(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->i_clk & 0xfeU))) {
        Verilated::overWidthError("i_clk");}
    if (VL_UNLIKELY((vlSelf->i_rst_n & 0xfeU))) {
        Verilated::overWidthError("i_rst_n");}
    if (VL_UNLIKELY((vlSelf->i_start & 0xfeU))) {
        Verilated::overWidthError("i_start");}
}
#endif  // VL_DEBUG
