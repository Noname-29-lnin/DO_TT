// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VinsertionSort.h for the primary calling header

#include "VinsertionSort__pch.h"
#include "VinsertionSort___024root.h"

VlCoroutine VinsertionSort___024root___eval_initial__TOP__Vtiming__0(VinsertionSort___024root* vlSelf);
VlCoroutine VinsertionSort___024root___eval_initial__TOP__Vtiming__1(VinsertionSort___024root* vlSelf);

void VinsertionSort___024root___eval_initial(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval_initial\n"); );
    // Body
    VinsertionSort___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    VinsertionSort___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_insertionSort__DOT__i_clk__0 
        = vlSelf->tb_insertionSort__DOT__i_clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_insertionSort__DOT__i_rst_n__0 
        = vlSelf->tb_insertionSort__DOT__i_rst_n;
    vlSelf->__Vtrigprevexpr___TOP__tb_insertionSort__DOT__o_done__0 
        = vlSelf->tb_insertionSort__DOT__o_done;
}

VL_INLINE_OPT VlCoroutine VinsertionSort___024root___eval_initial__TOP__Vtiming__0(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->tb_insertionSort__DOT__i_clk = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "tb_insertionSort.sv", 
                                           11);
        vlSelf->tb_insertionSort__DOT__i_clk = (1U 
                                                & (~ (IData)(vlSelf->tb_insertionSort__DOT__i_clk)));
    }
}

VL_INLINE_OPT VlCoroutine VinsertionSort___024root___eval_initial__TOP__Vtiming__1(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    vlSelf->tb_insertionSort__DOT__i_rst_n = 0U;
    vlSelf->tb_insertionSort__DOT__i_start = 0U;
    vlSelf->tb_insertionSort__DOT__i_data[0U] = 0x37U;
    vlSelf->tb_insertionSort__DOT__i_data[1U] = 0xcU;
    vlSelf->tb_insertionSort__DOT__i_data[2U] = 0x63U;
    vlSelf->tb_insertionSort__DOT__i_data[3U] = 0x12U;
    vlSelf->tb_insertionSort__DOT__i_data[4U] = 0x43U;
    vlSelf->tb_insertionSort__DOT__i_data[5U] = 3U;
    vlSelf->tb_insertionSort__DOT__i_data[6U] = 0x2dU;
    vlSelf->tb_insertionSort__DOT__i_data[7U] = 0x15U;
    co_await vlSelf->__VdlySched.delay(0x4e20ULL, nullptr, 
                                       "tb_insertionSort.sv", 
                                       54);
    vlSelf->tb_insertionSort__DOT__i_rst_n = 1U;
    co_await vlSelf->__VdlySched.delay(0x4e20ULL, nullptr, 
                                       "tb_insertionSort.sv", 
                                       58);
    vlSelf->tb_insertionSort__DOT__i_start = 1U;
    while ((1U & (~ (IData)(vlSelf->tb_insertionSort__DOT__o_done)))) {
        co_await vlSelf->__VtrigSched_h4238c561__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] tb_insertionSort.o_done)", 
                                                           "tb_insertionSort.sv", 
                                                           62);
    }
    VL_WRITEF("Sorted Output:\no_data[0] = %0#\no_data[1] = %0#\no_data[2] = %0#\no_data[3] = %0#\no_data[4] = %0#\no_data[5] = %0#\no_data[6] = %0#\no_data[7] = %0#\n",
              8,vlSelf->tb_insertionSort__DOT__o_data
              [0U],8,vlSelf->tb_insertionSort__DOT__o_data
              [1U],8,vlSelf->tb_insertionSort__DOT__o_data
              [2U],8,vlSelf->tb_insertionSort__DOT__o_data
              [3U],8,vlSelf->tb_insertionSort__DOT__o_data
              [4U],8,vlSelf->tb_insertionSort__DOT__o_data
              [5U],8,vlSelf->tb_insertionSort__DOT__o_data
              [6U],8,vlSelf->tb_insertionSort__DOT__o_data
              [7U]);
    VL_FINISH_MT("tb_insertionSort.sv", 70, "");
}

VL_INLINE_OPT void VinsertionSort___024root___act_comb__TOP__0(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___act_comb__TOP__0\n"); );
    // Body
    vlSelf->tb_insertionSort__DOT__DUT__DOT__n_state 
        = ((2U & (IData)(vlSelf->tb_insertionSort__DOT__DUT__DOT__state))
            ? ((1U & (IData)(vlSelf->tb_insertionSort__DOT__DUT__DOT__state))
                ? 0U : ((vlSelf->tb_insertionSort__DOT__DUT__DOT__arr
                         [(7U & (IData)(vlSelf->tb_insertionSort__DOT__DUT__DOT__j))] 
                         > (IData)(vlSelf->tb_insertionSort__DOT__DUT__DOT__key))
                         ? 2U : 1U)) : ((1U & (IData)(vlSelf->tb_insertionSort__DOT__DUT__DOT__state))
                                         ? ((8U > (IData)(vlSelf->tb_insertionSort__DOT__DUT__DOT__i))
                                             ? 2U : 3U)
                                         : ((IData)(vlSelf->tb_insertionSort__DOT__i_start)
                                             ? 1U : 0U)));
}

void VinsertionSort___024root___eval_act(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval_act\n"); );
    // Body
    if ((6ULL & vlSelf->__VactTriggered.word(0U))) {
        VinsertionSort___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VinsertionSort___024root___nba_sequent__TOP__0(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__o_data__v0;
    __Vdlyvval__tb_insertionSort__DOT__o_data__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_insertionSort__DOT__o_data__v0;
    __Vdlyvset__tb_insertionSort__DOT__o_data__v0 = 0;
    CData/*3:0*/ __Vdly__tb_insertionSort__DOT__DUT__DOT__i;
    __Vdly__tb_insertionSort__DOT__DUT__DOT__i = 0;
    CData/*3:0*/ __Vdly__tb_insertionSort__DOT__DUT__DOT__j;
    __Vdly__tb_insertionSort__DOT__DUT__DOT__j = 0;
    CData/*7:0*/ __Vdly__tb_insertionSort__DOT__DUT__DOT__key;
    __Vdly__tb_insertionSort__DOT__DUT__DOT__key = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__o_data__v1;
    __Vdlyvval__tb_insertionSort__DOT__o_data__v1 = 0;
    CData/*0:0*/ __Vdlyvset__tb_insertionSort__DOT__o_data__v1;
    __Vdlyvset__tb_insertionSort__DOT__o_data__v1 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__o_data__v2;
    __Vdlyvval__tb_insertionSort__DOT__o_data__v2 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__o_data__v3;
    __Vdlyvval__tb_insertionSort__DOT__o_data__v3 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__o_data__v4;
    __Vdlyvval__tb_insertionSort__DOT__o_data__v4 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__o_data__v5;
    __Vdlyvval__tb_insertionSort__DOT__o_data__v5 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__o_data__v6;
    __Vdlyvval__tb_insertionSort__DOT__o_data__v6 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__o_data__v7;
    __Vdlyvval__tb_insertionSort__DOT__o_data__v7 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_insertionSort__DOT__DUT__DOT__arr__v0;
    __Vdlyvdim0__tb_insertionSort__DOT__DUT__DOT__arr__v0 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v0;
    __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v0;
    __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_insertionSort__DOT__DUT__DOT__arr__v1;
    __Vdlyvdim0__tb_insertionSort__DOT__DUT__DOT__arr__v1 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v1;
    __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v1 = 0;
    CData/*0:0*/ __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v1;
    __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v1 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v2;
    __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v2 = 0;
    CData/*0:0*/ __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v2;
    __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v2 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v3;
    __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v3 = 0;
    CData/*0:0*/ __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v3;
    __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v3 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v4;
    __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v4 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v5;
    __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v5 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v6;
    __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v6 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v7;
    __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v7 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v8;
    __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v8 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v9;
    __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v9 = 0;
    CData/*0:0*/ __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v10;
    __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v10 = 0;
    // Body
    __Vdly__tb_insertionSort__DOT__DUT__DOT__key = vlSelf->tb_insertionSort__DOT__DUT__DOT__key;
    __Vdly__tb_insertionSort__DOT__DUT__DOT__j = vlSelf->tb_insertionSort__DOT__DUT__DOT__j;
    __Vdly__tb_insertionSort__DOT__DUT__DOT__i = vlSelf->tb_insertionSort__DOT__DUT__DOT__i;
    __Vdlyvset__tb_insertionSort__DOT__o_data__v0 = 0U;
    __Vdlyvset__tb_insertionSort__DOT__o_data__v1 = 0U;
    __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v0 = 0U;
    __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v1 = 0U;
    __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v2 = 0U;
    __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v3 = 0U;
    __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v10 = 0U;
    if (vlSelf->tb_insertionSort__DOT__i_rst_n) {
        if ((2U & (IData)(vlSelf->tb_insertionSort__DOT__DUT__DOT__state))) {
            if ((1U & (IData)(vlSelf->tb_insertionSort__DOT__DUT__DOT__state))) {
                __Vdlyvval__tb_insertionSort__DOT__o_data__v0 
                    = vlSelf->tb_insertionSort__DOT__DUT__DOT__arr
                    [0U];
                __Vdlyvset__tb_insertionSort__DOT__o_data__v0 = 1U;
                __Vdly__tb_insertionSort__DOT__DUT__DOT__i = 1U;
                __Vdly__tb_insertionSort__DOT__DUT__DOT__j = 0U;
                __Vdly__tb_insertionSort__DOT__DUT__DOT__key = 0U;
                __Vdlyvval__tb_insertionSort__DOT__o_data__v1 
                    = vlSelf->tb_insertionSort__DOT__DUT__DOT__arr
                    [1U];
                __Vdlyvset__tb_insertionSort__DOT__o_data__v1 = 1U;
                __Vdlyvval__tb_insertionSort__DOT__o_data__v2 
                    = vlSelf->tb_insertionSort__DOT__DUT__DOT__arr
                    [2U];
                __Vdlyvval__tb_insertionSort__DOT__o_data__v3 
                    = vlSelf->tb_insertionSort__DOT__DUT__DOT__arr
                    [3U];
                __Vdlyvval__tb_insertionSort__DOT__o_data__v4 
                    = vlSelf->tb_insertionSort__DOT__DUT__DOT__arr
                    [4U];
                __Vdlyvval__tb_insertionSort__DOT__o_data__v5 
                    = vlSelf->tb_insertionSort__DOT__DUT__DOT__arr
                    [5U];
                __Vdlyvval__tb_insertionSort__DOT__o_data__v6 
                    = vlSelf->tb_insertionSort__DOT__DUT__DOT__arr
                    [6U];
                __Vdlyvval__tb_insertionSort__DOT__o_data__v7 
                    = vlSelf->tb_insertionSort__DOT__DUT__DOT__arr
                    [7U];
                vlSelf->tb_insertionSort__DOT__o_done = 1U;
            } else {
                __Vdly__tb_insertionSort__DOT__DUT__DOT__key 
                    = vlSelf->tb_insertionSort__DOT__DUT__DOT__arr
                    [(7U & (IData)(vlSelf->tb_insertionSort__DOT__DUT__DOT__i))];
                __Vdly__tb_insertionSort__DOT__DUT__DOT__j 
                    = (0xfU & ((IData)(vlSelf->tb_insertionSort__DOT__DUT__DOT__i) 
                               - (IData)(1U)));
                if ((vlSelf->tb_insertionSort__DOT__DUT__DOT__arr
                     [(7U & (IData)(vlSelf->tb_insertionSort__DOT__DUT__DOT__j))] 
                     > (IData)(vlSelf->tb_insertionSort__DOT__DUT__DOT__key))) {
                    __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v0 
                        = vlSelf->tb_insertionSort__DOT__DUT__DOT__arr
                        [(7U & (IData)(vlSelf->tb_insertionSort__DOT__DUT__DOT__j))];
                    __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v0 = 1U;
                    __Vdlyvdim0__tb_insertionSort__DOT__DUT__DOT__arr__v0 
                        = (7U & ((IData)(1U) + (IData)(vlSelf->tb_insertionSort__DOT__DUT__DOT__j)));
                    __Vdly__tb_insertionSort__DOT__DUT__DOT__j 
                        = (0xfU & ((IData)(vlSelf->tb_insertionSort__DOT__DUT__DOT__j) 
                                   - (IData)(1U)));
                } else {
                    __Vdly__tb_insertionSort__DOT__DUT__DOT__i 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelf->tb_insertionSort__DOT__DUT__DOT__i)));
                    __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v1 
                        = vlSelf->tb_insertionSort__DOT__DUT__DOT__key;
                    __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v1 = 1U;
                    __Vdlyvdim0__tb_insertionSort__DOT__DUT__DOT__arr__v1 
                        = (7U & ((IData)(1U) + (IData)(vlSelf->tb_insertionSort__DOT__DUT__DOT__j)));
                }
            }
        } else {
            if ((1U & (IData)(vlSelf->tb_insertionSort__DOT__DUT__DOT__state))) {
                __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v2 
                    = vlSelf->tb_insertionSort__DOT__i_data
                    [0U];
                __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v2 = 1U;
                __Vdly__tb_insertionSort__DOT__DUT__DOT__i = 1U;
                __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v3 
                    = vlSelf->tb_insertionSort__DOT__i_data
                    [1U];
                __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v3 = 1U;
                __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v4 
                    = vlSelf->tb_insertionSort__DOT__i_data
                    [2U];
                __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v5 
                    = vlSelf->tb_insertionSort__DOT__i_data
                    [3U];
                __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v6 
                    = vlSelf->tb_insertionSort__DOT__i_data
                    [4U];
                __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v7 
                    = vlSelf->tb_insertionSort__DOT__i_data
                    [5U];
                __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v8 
                    = vlSelf->tb_insertionSort__DOT__i_data
                    [6U];
                __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v9 
                    = vlSelf->tb_insertionSort__DOT__i_data
                    [7U];
            } else {
                __Vdly__tb_insertionSort__DOT__DUT__DOT__j = 0U;
                __Vdly__tb_insertionSort__DOT__DUT__DOT__i = 1U;
                __Vdly__tb_insertionSort__DOT__DUT__DOT__key = 0U;
            }
            if ((1U & (~ (IData)(vlSelf->tb_insertionSort__DOT__DUT__DOT__state)))) {
                vlSelf->tb_insertionSort__DOT__o_done = 0U;
            }
        }
        vlSelf->tb_insertionSort__DOT__DUT__DOT__state 
            = vlSelf->tb_insertionSort__DOT__DUT__DOT__n_state;
    } else {
        __Vdly__tb_insertionSort__DOT__DUT__DOT__j = 0U;
        __Vdly__tb_insertionSort__DOT__DUT__DOT__i = 0U;
        __Vdly__tb_insertionSort__DOT__DUT__DOT__key = 0U;
        __Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v10 = 1U;
        vlSelf->tb_insertionSort__DOT__o_done = 0U;
        vlSelf->tb_insertionSort__DOT__DUT__DOT__state = 0U;
    }
    vlSelf->tb_insertionSort__DOT__DUT__DOT__i = __Vdly__tb_insertionSort__DOT__DUT__DOT__i;
    vlSelf->tb_insertionSort__DOT__DUT__DOT__j = __Vdly__tb_insertionSort__DOT__DUT__DOT__j;
    vlSelf->tb_insertionSort__DOT__DUT__DOT__key = __Vdly__tb_insertionSort__DOT__DUT__DOT__key;
    if (__Vdlyvset__tb_insertionSort__DOT__o_data__v0) {
        vlSelf->tb_insertionSort__DOT__o_data[0U] = __Vdlyvval__tb_insertionSort__DOT__o_data__v0;
    }
    if (__Vdlyvset__tb_insertionSort__DOT__o_data__v1) {
        vlSelf->tb_insertionSort__DOT__o_data[1U] = __Vdlyvval__tb_insertionSort__DOT__o_data__v1;
        vlSelf->tb_insertionSort__DOT__o_data[2U] = __Vdlyvval__tb_insertionSort__DOT__o_data__v2;
        vlSelf->tb_insertionSort__DOT__o_data[3U] = __Vdlyvval__tb_insertionSort__DOT__o_data__v3;
        vlSelf->tb_insertionSort__DOT__o_data[4U] = __Vdlyvval__tb_insertionSort__DOT__o_data__v4;
        vlSelf->tb_insertionSort__DOT__o_data[5U] = __Vdlyvval__tb_insertionSort__DOT__o_data__v5;
        vlSelf->tb_insertionSort__DOT__o_data[6U] = __Vdlyvval__tb_insertionSort__DOT__o_data__v6;
        vlSelf->tb_insertionSort__DOT__o_data[7U] = __Vdlyvval__tb_insertionSort__DOT__o_data__v7;
    }
    if (__Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v0) {
        vlSelf->tb_insertionSort__DOT__DUT__DOT__arr[__Vdlyvdim0__tb_insertionSort__DOT__DUT__DOT__arr__v0] 
            = __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v0;
    }
    if (__Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v1) {
        vlSelf->tb_insertionSort__DOT__DUT__DOT__arr[__Vdlyvdim0__tb_insertionSort__DOT__DUT__DOT__arr__v1] 
            = __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v1;
    }
    if (__Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v2) {
        vlSelf->tb_insertionSort__DOT__DUT__DOT__arr[0U] 
            = __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v2;
    }
    if (__Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v3) {
        vlSelf->tb_insertionSort__DOT__DUT__DOT__arr[1U] 
            = __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v3;
        vlSelf->tb_insertionSort__DOT__DUT__DOT__arr[2U] 
            = __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v4;
        vlSelf->tb_insertionSort__DOT__DUT__DOT__arr[3U] 
            = __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v5;
        vlSelf->tb_insertionSort__DOT__DUT__DOT__arr[4U] 
            = __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v6;
        vlSelf->tb_insertionSort__DOT__DUT__DOT__arr[5U] 
            = __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v7;
        vlSelf->tb_insertionSort__DOT__DUT__DOT__arr[6U] 
            = __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v8;
        vlSelf->tb_insertionSort__DOT__DUT__DOT__arr[7U] 
            = __Vdlyvval__tb_insertionSort__DOT__DUT__DOT__arr__v9;
    }
    if (__Vdlyvset__tb_insertionSort__DOT__DUT__DOT__arr__v10) {
        vlSelf->tb_insertionSort__DOT__o_data[0U] = 0U;
        vlSelf->tb_insertionSort__DOT__o_data[1U] = 0U;
        vlSelf->tb_insertionSort__DOT__o_data[2U] = 0U;
        vlSelf->tb_insertionSort__DOT__o_data[3U] = 0U;
        vlSelf->tb_insertionSort__DOT__o_data[4U] = 0U;
        vlSelf->tb_insertionSort__DOT__o_data[5U] = 0U;
        vlSelf->tb_insertionSort__DOT__o_data[6U] = 0U;
        vlSelf->tb_insertionSort__DOT__o_data[7U] = 0U;
        vlSelf->tb_insertionSort__DOT__DUT__DOT__arr[0U] = 0U;
        vlSelf->tb_insertionSort__DOT__DUT__DOT__arr[1U] = 0U;
        vlSelf->tb_insertionSort__DOT__DUT__DOT__arr[2U] = 0U;
        vlSelf->tb_insertionSort__DOT__DUT__DOT__arr[3U] = 0U;
        vlSelf->tb_insertionSort__DOT__DUT__DOT__arr[4U] = 0U;
        vlSelf->tb_insertionSort__DOT__DUT__DOT__arr[5U] = 0U;
        vlSelf->tb_insertionSort__DOT__DUT__DOT__arr[6U] = 0U;
        vlSelf->tb_insertionSort__DOT__DUT__DOT__arr[7U] = 0U;
    }
}

void VinsertionSort___024root___eval_nba(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VinsertionSort___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((7ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VinsertionSort___024root___act_comb__TOP__0(vlSelf);
    }
}

void VinsertionSort___024root___timing_resume(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___timing_resume\n"); );
    // Body
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h4238c561__0.resume("@([changed] tb_insertionSort.o_done)");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void VinsertionSort___024root___timing_commit(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___timing_commit\n"); );
    // Body
    if ((! (4ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h4238c561__0.commit("@([changed] tb_insertionSort.o_done)");
    }
}

void VinsertionSort___024root___eval_triggers__act(VinsertionSort___024root* vlSelf);

bool VinsertionSort___024root___eval_phase__act(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VinsertionSort___024root___eval_triggers__act(vlSelf);
    VinsertionSort___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VinsertionSort___024root___timing_resume(vlSelf);
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
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VinsertionSort___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb_insertionSort.sv", 3, "", "NBA region did not converge.");
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
                VL_FATAL_MT("tb_insertionSort.sv", 3, "", "Active region did not converge.");
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
}
#endif  // VL_DEBUG
