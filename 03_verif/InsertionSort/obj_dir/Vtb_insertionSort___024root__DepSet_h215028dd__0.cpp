// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_insertionSort.h for the primary calling header

#include "Vtb_insertionSort__pch.h"
#include "Vtb_insertionSort___024root.h"

VlCoroutine Vtb_insertionSort___024root___eval_initial__TOP__Vtiming__0(Vtb_insertionSort___024root* vlSelf);
VlCoroutine Vtb_insertionSort___024root___eval_initial__TOP__Vtiming__1(Vtb_insertionSort___024root* vlSelf);

void Vtb_insertionSort___024root___eval_initial(Vtb_insertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root___eval_initial\n"); );
    // Body
    Vtb_insertionSort___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_insertionSort___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_insertionSort__DOT__i_clk__0 
        = vlSelf->tb_insertionSort__DOT__i_clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_insertionSort__DOT__i_rst_n__0 
        = vlSelf->tb_insertionSort__DOT__i_rst_n;
    vlSelf->__Vtrigprevexpr___TOP__tb_insertionSort__DOT__o_done__0 
        = vlSelf->tb_insertionSort__DOT__o_done;
}

VL_INLINE_OPT VlCoroutine Vtb_insertionSort___024root___eval_initial__TOP__Vtiming__0(Vtb_insertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->tb_insertionSort__DOT__i_clk = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "tb_insertionSort.sv", 
                                           19);
        vlSelf->tb_insertionSort__DOT__i_clk = (1U 
                                                & (~ (IData)(vlSelf->tb_insertionSort__DOT__i_clk)));
    }
}

VL_INLINE_OPT VlCoroutine Vtb_insertionSort___024root___eval_initial__TOP__Vtiming__1(Vtb_insertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Init
    QData/*63:0*/ __Vtask_tb_insertionSort__DOT__print_array__0__arr;
    __Vtask_tb_insertionSort__DOT__print_array__0__arr = 0;
    QData/*63:0*/ __Vtask_tb_insertionSort__DOT__print_array__1__arr;
    __Vtask_tb_insertionSort__DOT__print_array__1__arr = 0;
    // Body
    VL_WRITEF("=== Testbench: Insertion Sort ===\n");
    vlSelf->tb_insertionSort__DOT__i_rst_n = 0U;
    vlSelf->tb_insertionSort__DOT__i_start = 0U;
    vlSelf->tb_insertionSort__DOT__i_data = 0ULL;
    co_await vlSelf->__VdlySched.delay(0x4e20ULL, nullptr, 
                                       "tb_insertionSort.sv", 
                                       50);
    vlSelf->tb_insertionSort__DOT__i_rst_n = 1U;
    co_await vlSelf->__VdlySched.delay(0x2710ULL, nullptr, 
                                       "tb_insertionSort.sv", 
                                       54);
    vlSelf->tb_insertionSort__DOT__i_data = 0xc050114030f1d01ULL;
    VL_WRITEF("Input data: \n");
    __Vtask_tb_insertionSort__DOT__print_array__0__arr 
        = vlSelf->tb_insertionSort__DOT__i_data;
    VL_WRITEF("%0# %0# %0# %0# %0# %0# %0# %0# \n",
              8,(0xffU & (IData)(__Vtask_tb_insertionSort__DOT__print_array__0__arr)),
              8,(0xffU & (IData)((__Vtask_tb_insertionSort__DOT__print_array__0__arr 
                                  >> 8U))),8,(0xffU 
                                              & (IData)(
                                                        (__Vtask_tb_insertionSort__DOT__print_array__0__arr 
                                                         >> 0x10U))),
              8,(0xffU & (IData)((__Vtask_tb_insertionSort__DOT__print_array__0__arr 
                                  >> 0x18U))),8,(0xffU 
                                                 & (IData)(
                                                           (__Vtask_tb_insertionSort__DOT__print_array__0__arr 
                                                            >> 0x20U))),
              8,(0xffU & (IData)((__Vtask_tb_insertionSort__DOT__print_array__0__arr 
                                  >> 0x28U))),8,(0xffU 
                                                 & (IData)(
                                                           (__Vtask_tb_insertionSort__DOT__print_array__0__arr 
                                                            >> 0x30U))),
              8,(0xffU & (IData)((__Vtask_tb_insertionSort__DOT__print_array__0__arr 
                                  >> 0x38U))));
    co_await vlSelf->__VdlySched.delay(0x2710ULL, nullptr, 
                                       "tb_insertionSort.sv", 
                                       68);
    vlSelf->tb_insertionSort__DOT__i_start = 1U;
    co_await vlSelf->__VdlySched.delay(0x2710ULL, nullptr, 
                                       "tb_insertionSort.sv", 
                                       70);
    vlSelf->tb_insertionSort__DOT__i_start = 0U;
    while ((1U & (~ (IData)(vlSelf->tb_insertionSort__DOT__o_done)))) {
        co_await vlSelf->__VtrigSched_h4238c561__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] tb_insertionSort.o_done)", 
                                                           "tb_insertionSort.sv", 
                                                           74);
    }
    VL_WRITEF("Sorted output: \n");
    __Vtask_tb_insertionSort__DOT__print_array__1__arr 
        = vlSelf->tb_insertionSort__DOT__o_data;
    VL_WRITEF("%0# %0# %0# %0# %0# %0# %0# %0# \n",
              8,(0xffU & (IData)(__Vtask_tb_insertionSort__DOT__print_array__1__arr)),
              8,(0xffU & (IData)((__Vtask_tb_insertionSort__DOT__print_array__1__arr 
                                  >> 8U))),8,(0xffU 
                                              & (IData)(
                                                        (__Vtask_tb_insertionSort__DOT__print_array__1__arr 
                                                         >> 0x10U))),
              8,(0xffU & (IData)((__Vtask_tb_insertionSort__DOT__print_array__1__arr 
                                  >> 0x18U))),8,(0xffU 
                                                 & (IData)(
                                                           (__Vtask_tb_insertionSort__DOT__print_array__1__arr 
                                                            >> 0x20U))),
              8,(0xffU & (IData)((__Vtask_tb_insertionSort__DOT__print_array__1__arr 
                                  >> 0x28U))),8,(0xffU 
                                                 & (IData)(
                                                           (__Vtask_tb_insertionSort__DOT__print_array__1__arr 
                                                            >> 0x30U))),
              8,(0xffU & (IData)((__Vtask_tb_insertionSort__DOT__print_array__1__arr 
                                  >> 0x38U))));
    co_await vlSelf->__VdlySched.delay(0x2710ULL, nullptr, 
                                       "tb_insertionSort.sv", 
                                       78);
    VL_FINISH_MT("tb_insertionSort.sv", 79, "");
}

void Vtb_insertionSort___024root___eval_act(Vtb_insertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtb_insertionSort___024root___nba_sequent__TOP__0(Vtb_insertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*2:0*/ __Vdly__tb_insertionSort__DOT__dut__DOT__state;
    __Vdly__tb_insertionSort__DOT__dut__DOT__state = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_insertionSort__DOT__dut__DOT__arr_temp__v0;
    __Vdlyvdim0__tb_insertionSort__DOT__dut__DOT__arr_temp__v0 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v0;
    __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v0;
    __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v0 = 0;
    IData/*31:0*/ __Vdly__tb_insertionSort__DOT__dut__DOT__i_sign;
    __Vdly__tb_insertionSort__DOT__dut__DOT__i_sign = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_insertionSort__DOT__dut__DOT__arr_temp__v1;
    __Vdlyvdim0__tb_insertionSort__DOT__dut__DOT__arr_temp__v1 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v1;
    __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v1 = 0;
    CData/*0:0*/ __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v1;
    __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v1 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v2;
    __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v2 = 0;
    CData/*0:0*/ __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v2;
    __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v2 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v3;
    __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v3 = 0;
    CData/*0:0*/ __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v3;
    __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v3 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v4;
    __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v4 = 0;
    CData/*0:0*/ __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v4;
    __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v4 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v5;
    __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v5 = 0;
    CData/*0:0*/ __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v5;
    __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v5 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v6;
    __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v6 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v7;
    __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v7 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v8;
    __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v8 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v9;
    __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v9 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v10;
    __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v10 = 0;
    CData/*7:0*/ __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v11;
    __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v11 = 0;
    // Body
    __Vdly__tb_insertionSort__DOT__dut__DOT__i_sign 
        = vlSelf->tb_insertionSort__DOT__dut__DOT__i_sign;
    __Vdly__tb_insertionSort__DOT__dut__DOT__state 
        = vlSelf->tb_insertionSort__DOT__dut__DOT__state;
    __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v0 = 0U;
    __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v1 = 0U;
    __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v2 = 0U;
    __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v3 = 0U;
    __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v4 = 0U;
    __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v5 = 0U;
    if (vlSelf->tb_insertionSort__DOT__i_rst_n) {
        if ((4U & (IData)(vlSelf->tb_insertionSort__DOT__dut__DOT__state))) {
            if ((2U & (IData)(vlSelf->tb_insertionSort__DOT__dut__DOT__state))) {
                if ((1U & (IData)(vlSelf->tb_insertionSort__DOT__dut__DOT__state))) {
                    vlSelf->tb_insertionSort__DOT__dut__DOT__unnamedblk2__DOT__i = 8U;
                    vlSelf->tb_insertionSort__DOT__o_data 
                        = ((0xffffffffff000000ULL & vlSelf->tb_insertionSort__DOT__o_data) 
                           | (IData)((IData)(((vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                                               [2U] 
                                               << 0x10U) 
                                              | ((vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                                                  [1U] 
                                                  << 8U) 
                                                 | vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                                                 [0U])))));
                    vlSelf->tb_insertionSort__DOT__o_done = 1U;
                    __Vdly__tb_insertionSort__DOT__dut__DOT__state = 0U;
                    vlSelf->tb_insertionSort__DOT__o_data 
                        = ((0xffff000000ffffffULL & vlSelf->tb_insertionSort__DOT__o_data) 
                           | ((QData)((IData)(((vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                                                [5U] 
                                                << 0x10U) 
                                               | ((vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                                                   [4U] 
                                                   << 8U) 
                                                  | vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                                                  [3U])))) 
                              << 0x18U));
                    vlSelf->tb_insertionSort__DOT__o_data 
                        = ((0xffffffffffffULL & vlSelf->tb_insertionSort__DOT__o_data) 
                           | ((QData)((IData)(((vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                                                [7U] 
                                                << 8U) 
                                               | vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                                               [6U]))) 
                              << 0x30U));
                } else {
                    __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v0 
                        = vlSelf->tb_insertionSort__DOT__dut__DOT__key;
                    __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v0 = 1U;
                    __Vdlyvdim0__tb_insertionSort__DOT__dut__DOT__arr_temp__v0 
                        = (7U & ((IData)(1U) + vlSelf->tb_insertionSort__DOT__dut__DOT__i_sign));
                    __Vdly__tb_insertionSort__DOT__dut__DOT__state = 4U;
                    __Vdly__tb_insertionSort__DOT__dut__DOT__i_sign 
                        = ((IData)(2U) + vlSelf->tb_insertionSort__DOT__dut__DOT__i_sign);
                }
            } else if ((1U & (IData)(vlSelf->tb_insertionSort__DOT__dut__DOT__state))) {
                if ((VL_LTES_III(32, 0U, vlSelf->tb_insertionSort__DOT__dut__DOT__i_sign) 
                     & ((IData)(vlSelf->tb_insertionSort__DOT__dut__DOT__key) 
                        < vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                        [(7U & vlSelf->tb_insertionSort__DOT__dut__DOT__i_sign)]))) {
                    __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v1 
                        = vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                        [(7U & vlSelf->tb_insertionSort__DOT__dut__DOT__i_sign)];
                    __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v1 = 1U;
                    __Vdlyvdim0__tb_insertionSort__DOT__dut__DOT__arr_temp__v1 
                        = (7U & ((IData)(1U) + vlSelf->tb_insertionSort__DOT__dut__DOT__i_sign));
                    __Vdly__tb_insertionSort__DOT__dut__DOT__i_sign 
                        = (vlSelf->tb_insertionSort__DOT__dut__DOT__i_sign 
                           - (IData)(1U));
                    __Vdly__tb_insertionSort__DOT__dut__DOT__state = 5U;
                } else {
                    __Vdly__tb_insertionSort__DOT__dut__DOT__state = 6U;
                }
            } else if (VL_GTS_III(32, 8U, vlSelf->tb_insertionSort__DOT__dut__DOT__i_sign)) {
                vlSelf->tb_insertionSort__DOT__dut__DOT__key 
                    = vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                    [(7U & vlSelf->tb_insertionSort__DOT__dut__DOT__i_sign)];
                __Vdly__tb_insertionSort__DOT__dut__DOT__state = 5U;
                __Vdly__tb_insertionSort__DOT__dut__DOT__i_sign 
                    = (vlSelf->tb_insertionSort__DOT__dut__DOT__i_sign 
                       - (IData)(1U));
            } else {
                __Vdly__tb_insertionSort__DOT__dut__DOT__state = 7U;
            }
        } else if ((2U & (IData)(vlSelf->tb_insertionSort__DOT__dut__DOT__state))) {
            if ((1U & (IData)(vlSelf->tb_insertionSort__DOT__dut__DOT__state))) {
                __Vdly__tb_insertionSort__DOT__dut__DOT__i_sign = 2U;
                __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v2 
                    = vlSelf->tb_insertionSort__DOT__dut__DOT__w_less_data;
                __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v2 = 1U;
                __Vdly__tb_insertionSort__DOT__dut__DOT__state = 4U;
                __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v3 
                    = vlSelf->tb_insertionSort__DOT__dut__DOT__w_greater_data;
                __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v3 = 1U;
            } else if (vlSelf->tb_insertionSort__DOT__i_start) {
                __Vdly__tb_insertionSort__DOT__dut__DOT__state = 3U;
            }
        } else if ((1U & (IData)(vlSelf->tb_insertionSort__DOT__dut__DOT__state))) {
            vlSelf->tb_insertionSort__DOT__dut__DOT__unnamedblk1__DOT__i = 8U;
            __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v4 
                = (0xffU & (IData)(vlSelf->tb_insertionSort__DOT__i_data));
            __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v4 = 1U;
            __Vdly__tb_insertionSort__DOT__dut__DOT__state = 2U;
            __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v5 
                = (0xffU & (IData)((vlSelf->tb_insertionSort__DOT__i_data 
                                    >> 8U)));
            __Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v5 = 1U;
            __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v6 
                = (0xffU & (IData)((vlSelf->tb_insertionSort__DOT__i_data 
                                    >> 0x10U)));
            __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v7 
                = (0xffU & (IData)((vlSelf->tb_insertionSort__DOT__i_data 
                                    >> 0x18U)));
            __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v8 
                = (0xffU & (IData)((vlSelf->tb_insertionSort__DOT__i_data 
                                    >> 0x20U)));
            __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v9 
                = (0xffU & (IData)((vlSelf->tb_insertionSort__DOT__i_data 
                                    >> 0x28U)));
            __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v10 
                = (0xffU & (IData)((vlSelf->tb_insertionSort__DOT__i_data 
                                    >> 0x30U)));
            __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v11 
                = (0xffU & (IData)((vlSelf->tb_insertionSort__DOT__i_data 
                                    >> 0x38U)));
        } else {
            vlSelf->tb_insertionSort__DOT__o_done = 0U;
            __Vdly__tb_insertionSort__DOT__dut__DOT__state = 1U;
        }
    } else {
        __Vdly__tb_insertionSort__DOT__dut__DOT__i_sign = 0U;
        __Vdly__tb_insertionSort__DOT__dut__DOT__state = 0U;
        vlSelf->tb_insertionSort__DOT__o_done = 0U;
    }
    vlSelf->tb_insertionSort__DOT__dut__DOT__state 
        = __Vdly__tb_insertionSort__DOT__dut__DOT__state;
    vlSelf->tb_insertionSort__DOT__dut__DOT__i_sign 
        = __Vdly__tb_insertionSort__DOT__dut__DOT__i_sign;
    if (__Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v0) {
        vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[__Vdlyvdim0__tb_insertionSort__DOT__dut__DOT__arr_temp__v0] 
            = __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v0;
    }
    if (__Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v1) {
        vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[__Vdlyvdim0__tb_insertionSort__DOT__dut__DOT__arr_temp__v1] 
            = __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v1;
    }
    if (__Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v2) {
        vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[0U] 
            = __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v2;
    }
    if (__Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v3) {
        vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[1U] 
            = __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v3;
    }
    if (__Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v4) {
        vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[0U] 
            = __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v4;
    }
    if (__Vdlyvset__tb_insertionSort__DOT__dut__DOT__arr_temp__v5) {
        vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[1U] 
            = __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v5;
        vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[2U] 
            = __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v6;
        vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[3U] 
            = __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v7;
        vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[4U] 
            = __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v8;
        vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[5U] 
            = __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v9;
        vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[6U] 
            = __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v10;
        vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[7U] 
            = __Vdlyvval__tb_insertionSort__DOT__dut__DOT__arr_temp__v11;
    }
    vlSelf->tb_insertionSort__DOT__dut__DOT__u_compare_block__DOT__w_compare_result 
        = (vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
           [0U] < vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
           [1U]);
    if (vlSelf->tb_insertionSort__DOT__dut__DOT__u_compare_block__DOT__w_compare_result) {
        vlSelf->tb_insertionSort__DOT__dut__DOT__w_less_data 
            = vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
            [0U];
        vlSelf->tb_insertionSort__DOT__dut__DOT__w_greater_data 
            = vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
            [1U];
    } else {
        vlSelf->tb_insertionSort__DOT__dut__DOT__w_less_data 
            = vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
            [1U];
        vlSelf->tb_insertionSort__DOT__dut__DOT__w_greater_data 
            = vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
            [0U];
    }
}

void Vtb_insertionSort___024root___eval_nba(Vtb_insertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_insertionSort___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtb_insertionSort___024root___timing_resume(Vtb_insertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root___timing_resume\n"); );
    // Body
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h4238c561__0.resume("@([changed] tb_insertionSort.o_done)");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_insertionSort___024root___timing_commit(Vtb_insertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root___timing_commit\n"); );
    // Body
    if ((! (4ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h4238c561__0.commit("@([changed] tb_insertionSort.o_done)");
    }
}

void Vtb_insertionSort___024root___eval_triggers__act(Vtb_insertionSort___024root* vlSelf);

bool Vtb_insertionSort___024root___eval_phase__act(Vtb_insertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_insertionSort___024root___eval_triggers__act(vlSelf);
    Vtb_insertionSort___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_insertionSort___024root___timing_resume(vlSelf);
        Vtb_insertionSort___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_insertionSort___024root___eval_phase__nba(Vtb_insertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_insertionSort___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_insertionSort___024root___dump_triggers__nba(Vtb_insertionSort___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_insertionSort___024root___dump_triggers__act(Vtb_insertionSort___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_insertionSort___024root___eval(Vtb_insertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_insertionSort___024root___dump_triggers__nba(vlSelf);
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
                Vtb_insertionSort___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb_insertionSort.sv", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_insertionSort___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_insertionSort___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_insertionSort___024root___eval_debug_assertions(Vtb_insertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
