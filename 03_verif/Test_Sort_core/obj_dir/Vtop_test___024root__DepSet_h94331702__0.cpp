// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_test.h for the primary calling header

#include "Vtop_test__pch.h"
#include "Vtop_test___024root.h"

VL_ATTR_COLD void Vtop_test___024root___eval_initial__TOP(Vtop_test___024root* vlSelf);
VlCoroutine Vtop_test___024root___eval_initial__TOP__Vtiming__0(Vtop_test___024root* vlSelf);
VlCoroutine Vtop_test___024root___eval_initial__TOP__Vtiming__1(Vtop_test___024root* vlSelf);

void Vtop_test___024root___eval_initial(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___eval_initial\n"); );
    // Body
    Vtop_test___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vtop_test___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtop_test___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__i_clk__0 = vlSelf->i_clk;
    vlSelf->__Vtrigprevexpr___TOP__i_rst_n__0 = vlSelf->i_rst_n;
    vlSelf->__Vtrigprevexpr___TOP__top_test__DOT__i_clk__0 
        = vlSelf->top_test__DOT__i_clk;
    vlSelf->__Vtrigprevexpr___TOP__top_test__DOT__i_rst_n__0 
        = vlSelf->top_test__DOT__i_rst_n;
}

VL_INLINE_OPT VlCoroutine Vtop_test___024root___eval_initial__TOP__Vtiming__0(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    IData/*31:0*/ __Vtask_tsk_clock_gen__0__PERIOD;
    __Vtask_tsk_clock_gen__0__PERIOD = 0;
    // Body
    __Vtask_tsk_clock_gen__0__PERIOD = 0xaU;
    vlSelf->top_test__DOT__i_clk = 1U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(__Vtask_tsk_clock_gen__0__PERIOD, 
                                           nullptr, 
                                           "tlib.svh", 
                                           7);
        vlSelf->top_test__DOT__i_clk = (1U & (~ (IData)(vlSelf->top_test__DOT__i_clk)));
    }
}

VL_INLINE_OPT VlCoroutine Vtop_test___024root___eval_initial__TOP__Vtiming__1(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Init
    IData/*31:0*/ __Vtask_tsk_reset__1__RESETPERIOD;
    __Vtask_tsk_reset__1__RESETPERIOD = 0;
    // Body
    __Vtask_tsk_reset__1__RESETPERIOD = 0xaU;
    vlSelf->top_test__DOT__i_rst_n = 0U;
    co_await vlSelf->__VdlySched.delay(__Vtask_tsk_reset__1__RESETPERIOD, 
                                       nullptr, "tlib.svh", 
                                       14);
    vlSelf->top_test__DOT__i_rst_n = 1U;
}

VL_INLINE_OPT void Vtop_test___024root___ico_sequent__TOP__0(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->compare_block_reg__DOT__w_compare_less 
        = ((IData)(vlSelf->i_data_1) < (IData)(vlSelf->i_data_2));
}

void Vtop_test___024root___eval_ico(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vtop_test___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtop_test___024root___eval_triggers__ico(Vtop_test___024root* vlSelf);

bool Vtop_test___024root___eval_phase__ico(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop_test___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop_test___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop_test___024root___eval_act(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop_test___024root___nba_sequent__TOP__0(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___nba_sequent__TOP__0\n"); );
    // Init
    QData/*63:0*/ __Vdlyvval__top_test__DOT__DUT__DOT__stage__v0;
    __Vdlyvval__top_test__DOT__DUT__DOT__stage__v0 = 0;
    QData/*63:0*/ __Vdlyvval__top_test__DOT__DUT__DOT__stage__v1;
    __Vdlyvval__top_test__DOT__DUT__DOT__stage__v1 = 0;
    QData/*63:0*/ __Vdlyvval__top_test__DOT__DUT__DOT__stage__v2;
    __Vdlyvval__top_test__DOT__DUT__DOT__stage__v2 = 0;
    QData/*63:0*/ __Vdlyvval__top_test__DOT__DUT__DOT__stage__v3;
    __Vdlyvval__top_test__DOT__DUT__DOT__stage__v3 = 0;
    QData/*63:0*/ __Vdlyvval__top_test__DOT__DUT__DOT__stage__v4;
    __Vdlyvval__top_test__DOT__DUT__DOT__stage__v4 = 0;
    QData/*63:0*/ __Vdlyvval__top_test__DOT__DUT__DOT__stage__v5;
    __Vdlyvval__top_test__DOT__DUT__DOT__stage__v5 = 0;
    QData/*63:0*/ __Vdlyvval__top_test__DOT__DUT__DOT__stage__v6;
    __Vdlyvval__top_test__DOT__DUT__DOT__stage__v6 = 0;
    QData/*63:0*/ __Vdlyvval__top_test__DOT__DUT__DOT__stage__v7;
    __Vdlyvval__top_test__DOT__DUT__DOT__stage__v7 = 0;
    // Body
    if (vlSelf->top_test__DOT__i_rst_n) {
        __Vdlyvval__top_test__DOT__DUT__DOT__stage__v0 
            = vlSelf->top_test__DOT__w_idata;
        __Vdlyvval__top_test__DOT__DUT__DOT__stage__v1 
            = vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__0__KET____DOT__temp;
        __Vdlyvval__top_test__DOT__DUT__DOT__stage__v2 
            = vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__1__KET____DOT__temp;
        __Vdlyvval__top_test__DOT__DUT__DOT__stage__v3 
            = vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__2__KET____DOT__temp;
        __Vdlyvval__top_test__DOT__DUT__DOT__stage__v4 
            = vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__3__KET____DOT__temp;
        __Vdlyvval__top_test__DOT__DUT__DOT__stage__v5 
            = vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__4__KET____DOT__temp;
        __Vdlyvval__top_test__DOT__DUT__DOT__stage__v6 
            = vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__5__KET____DOT__temp;
        __Vdlyvval__top_test__DOT__DUT__DOT__stage__v7 
            = vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__6__KET____DOT__temp;
        vlSelf->top_test__DOT__w_odata = vlSelf->top_test__DOT__DUT__DOT__stage
            [7U];
        vlSelf->top_test__DOT__o_done = 1U;
    } else {
        __Vdlyvval__top_test__DOT__DUT__DOT__stage__v0 = 0ULL;
        __Vdlyvval__top_test__DOT__DUT__DOT__stage__v1 = 0ULL;
        __Vdlyvval__top_test__DOT__DUT__DOT__stage__v2 = 0ULL;
        __Vdlyvval__top_test__DOT__DUT__DOT__stage__v3 = 0ULL;
        __Vdlyvval__top_test__DOT__DUT__DOT__stage__v4 = 0ULL;
        __Vdlyvval__top_test__DOT__DUT__DOT__stage__v5 = 0ULL;
        __Vdlyvval__top_test__DOT__DUT__DOT__stage__v6 = 0ULL;
        __Vdlyvval__top_test__DOT__DUT__DOT__stage__v7 = 0ULL;
        vlSelf->top_test__DOT__w_odata = 0ULL;
        vlSelf->top_test__DOT__o_done = 0U;
    }
    vlSelf->top_test__DOT__DUT__DOT__stage[0U] = __Vdlyvval__top_test__DOT__DUT__DOT__stage__v0;
    vlSelf->top_test__DOT__DUT__DOT__stage[1U] = __Vdlyvval__top_test__DOT__DUT__DOT__stage__v1;
    vlSelf->top_test__DOT__DUT__DOT__stage[2U] = __Vdlyvval__top_test__DOT__DUT__DOT__stage__v2;
    vlSelf->top_test__DOT__DUT__DOT__stage[3U] = __Vdlyvval__top_test__DOT__DUT__DOT__stage__v3;
    vlSelf->top_test__DOT__DUT__DOT__stage[4U] = __Vdlyvval__top_test__DOT__DUT__DOT__stage__v4;
    vlSelf->top_test__DOT__DUT__DOT__stage[5U] = __Vdlyvval__top_test__DOT__DUT__DOT__stage__v5;
    vlSelf->top_test__DOT__DUT__DOT__stage[6U] = __Vdlyvval__top_test__DOT__DUT__DOT__stage__v6;
    vlSelf->top_test__DOT__DUT__DOT__stage[7U] = __Vdlyvval__top_test__DOT__DUT__DOT__stage__v7;
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__0__KET____DOT__temp 
        = vlSelf->top_test__DOT__DUT__DOT__stage[0U];
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__0__KET____DOT__temp 
        = ((0xffffffffffff0000ULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__0__KET____DOT__temp) 
           | (IData)((IData)((0xffffU & (((0xffU & (IData)(
                                                           vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [0U])) 
                                          > (0xffU 
                                             & (IData)(
                                                       (vlSelf->top_test__DOT__DUT__DOT__stage
                                                        [0U] 
                                                        >> 8U))))
                                          ? ((0xff00U 
                                              & ((IData)(
                                                         vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [0U]) 
                                                 << 8U)) 
                                             | (0xffU 
                                                & (IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [0U] 
                                                           >> 8U))))
                                          : (IData)(
                                                    vlSelf->top_test__DOT__DUT__DOT__stage
                                                    [0U]))))));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__0__KET____DOT__temp 
        = ((0xffffffffff0000ffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__0__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [0U] 
                                                             >> 8U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [0U] 
                                                         >> 0x10U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [0U] 
                                                           >> 8U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [0U] 
                                                            >> 0x10U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [0U] 
                                                      >> 8U)))))) 
              << 8U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__0__KET____DOT__temp 
        = ((0xffffffff0000ffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__0__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [0U] 
                                                             >> 0x10U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [0U] 
                                                         >> 0x18U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [0U] 
                                                           >> 0x10U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [0U] 
                                                            >> 0x18U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [0U] 
                                                      >> 0x10U)))))) 
              << 0x10U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__0__KET____DOT__temp 
        = ((0xffffff0000ffffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__0__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [0U] 
                                                             >> 0x18U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [0U] 
                                                         >> 0x20U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [0U] 
                                                           >> 0x18U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [0U] 
                                                            >> 0x20U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [0U] 
                                                      >> 0x18U)))))) 
              << 0x18U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__0__KET____DOT__temp 
        = ((0xffff0000ffffffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__0__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [0U] 
                                                             >> 0x20U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [0U] 
                                                         >> 0x28U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [0U] 
                                                           >> 0x20U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [0U] 
                                                            >> 0x28U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [0U] 
                                                      >> 0x20U)))))) 
              << 0x20U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__0__KET____DOT__temp 
        = ((0xff0000ffffffffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__0__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [0U] 
                                                             >> 0x28U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [0U] 
                                                         >> 0x30U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [0U] 
                                                           >> 0x28U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [0U] 
                                                            >> 0x30U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [0U] 
                                                      >> 0x28U)))))) 
              << 0x28U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__0__KET____DOT__temp 
        = ((0xffffffffffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__0__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [0U] 
                                                             >> 0x30U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [0U] 
                                                         >> 0x38U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [0U] 
                                                           >> 0x30U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [0U] 
                                                            >> 0x38U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [0U] 
                                                      >> 0x30U)))))) 
              << 0x30U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__1__KET____DOT__temp 
        = vlSelf->top_test__DOT__DUT__DOT__stage[1U];
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__1__KET____DOT__temp 
        = ((0xffffffffffff0000ULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__1__KET____DOT__temp) 
           | (IData)((IData)((0xffffU & (((0xffU & (IData)(
                                                           vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [1U])) 
                                          > (0xffU 
                                             & (IData)(
                                                       (vlSelf->top_test__DOT__DUT__DOT__stage
                                                        [1U] 
                                                        >> 8U))))
                                          ? ((0xff00U 
                                              & ((IData)(
                                                         vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [1U]) 
                                                 << 8U)) 
                                             | (0xffU 
                                                & (IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [1U] 
                                                           >> 8U))))
                                          : (IData)(
                                                    vlSelf->top_test__DOT__DUT__DOT__stage
                                                    [1U]))))));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__1__KET____DOT__temp 
        = ((0xffffffffff0000ffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__1__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [1U] 
                                                             >> 8U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [1U] 
                                                         >> 0x10U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [1U] 
                                                           >> 8U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [1U] 
                                                            >> 0x10U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [1U] 
                                                      >> 8U)))))) 
              << 8U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__1__KET____DOT__temp 
        = ((0xffffffff0000ffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__1__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [1U] 
                                                             >> 0x10U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [1U] 
                                                         >> 0x18U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [1U] 
                                                           >> 0x10U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [1U] 
                                                            >> 0x18U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [1U] 
                                                      >> 0x10U)))))) 
              << 0x10U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__1__KET____DOT__temp 
        = ((0xffffff0000ffffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__1__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [1U] 
                                                             >> 0x18U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [1U] 
                                                         >> 0x20U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [1U] 
                                                           >> 0x18U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [1U] 
                                                            >> 0x20U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [1U] 
                                                      >> 0x18U)))))) 
              << 0x18U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__1__KET____DOT__temp 
        = ((0xffff0000ffffffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__1__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [1U] 
                                                             >> 0x20U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [1U] 
                                                         >> 0x28U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [1U] 
                                                           >> 0x20U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [1U] 
                                                            >> 0x28U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [1U] 
                                                      >> 0x20U)))))) 
              << 0x20U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__1__KET____DOT__temp 
        = ((0xff0000ffffffffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__1__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [1U] 
                                                             >> 0x28U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [1U] 
                                                         >> 0x30U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [1U] 
                                                           >> 0x28U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [1U] 
                                                            >> 0x30U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [1U] 
                                                      >> 0x28U)))))) 
              << 0x28U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__1__KET____DOT__temp 
        = ((0xffffffffffffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__1__KET____DOT__temp) 
           | ((QData)((IData)((0xffU & (IData)((vlSelf->top_test__DOT__DUT__DOT__stage
                                                [1U] 
                                                >> 0x38U))))) 
              << 0x38U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__2__KET____DOT__temp 
        = vlSelf->top_test__DOT__DUT__DOT__stage[2U];
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__2__KET____DOT__temp 
        = ((0xffffffffffff0000ULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__2__KET____DOT__temp) 
           | (IData)((IData)((0xffffU & (((0xffU & (IData)(
                                                           vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [2U])) 
                                          > (0xffU 
                                             & (IData)(
                                                       (vlSelf->top_test__DOT__DUT__DOT__stage
                                                        [2U] 
                                                        >> 8U))))
                                          ? ((0xff00U 
                                              & ((IData)(
                                                         vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [2U]) 
                                                 << 8U)) 
                                             | (0xffU 
                                                & (IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [2U] 
                                                           >> 8U))))
                                          : (IData)(
                                                    vlSelf->top_test__DOT__DUT__DOT__stage
                                                    [2U]))))));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__2__KET____DOT__temp 
        = ((0xffffffffff0000ffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__2__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [2U] 
                                                             >> 8U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [2U] 
                                                         >> 0x10U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [2U] 
                                                           >> 8U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [2U] 
                                                            >> 0x10U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [2U] 
                                                      >> 8U)))))) 
              << 8U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__2__KET____DOT__temp 
        = ((0xffffffff0000ffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__2__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [2U] 
                                                             >> 0x10U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [2U] 
                                                         >> 0x18U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [2U] 
                                                           >> 0x10U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [2U] 
                                                            >> 0x18U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [2U] 
                                                      >> 0x10U)))))) 
              << 0x10U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__2__KET____DOT__temp 
        = ((0xffffff0000ffffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__2__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [2U] 
                                                             >> 0x18U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [2U] 
                                                         >> 0x20U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [2U] 
                                                           >> 0x18U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [2U] 
                                                            >> 0x20U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [2U] 
                                                      >> 0x18U)))))) 
              << 0x18U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__2__KET____DOT__temp 
        = ((0xffff0000ffffffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__2__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [2U] 
                                                             >> 0x20U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [2U] 
                                                         >> 0x28U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [2U] 
                                                           >> 0x20U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [2U] 
                                                            >> 0x28U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [2U] 
                                                      >> 0x20U)))))) 
              << 0x20U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__2__KET____DOT__temp 
        = ((0xffffffffffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__2__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (IData)((vlSelf->top_test__DOT__DUT__DOT__stage
                                                  [2U] 
                                                  >> 0x30U))))) 
              << 0x30U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__3__KET____DOT__temp 
        = vlSelf->top_test__DOT__DUT__DOT__stage[3U];
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__3__KET____DOT__temp 
        = ((0xffffffffffff0000ULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__3__KET____DOT__temp) 
           | (IData)((IData)((0xffffU & (((0xffU & (IData)(
                                                           vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [3U])) 
                                          > (0xffU 
                                             & (IData)(
                                                       (vlSelf->top_test__DOT__DUT__DOT__stage
                                                        [3U] 
                                                        >> 8U))))
                                          ? ((0xff00U 
                                              & ((IData)(
                                                         vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [3U]) 
                                                 << 8U)) 
                                             | (0xffU 
                                                & (IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [3U] 
                                                           >> 8U))))
                                          : (IData)(
                                                    vlSelf->top_test__DOT__DUT__DOT__stage
                                                    [3U]))))));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__3__KET____DOT__temp 
        = ((0xffffffffff0000ffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__3__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [3U] 
                                                             >> 8U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [3U] 
                                                         >> 0x10U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [3U] 
                                                           >> 8U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [3U] 
                                                            >> 0x10U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [3U] 
                                                      >> 8U)))))) 
              << 8U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__3__KET____DOT__temp 
        = ((0xffffffff0000ffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__3__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [3U] 
                                                             >> 0x10U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [3U] 
                                                         >> 0x18U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [3U] 
                                                           >> 0x10U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [3U] 
                                                            >> 0x18U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [3U] 
                                                      >> 0x10U)))))) 
              << 0x10U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__3__KET____DOT__temp 
        = ((0xffffff0000ffffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__3__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [3U] 
                                                             >> 0x18U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [3U] 
                                                         >> 0x20U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [3U] 
                                                           >> 0x18U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [3U] 
                                                            >> 0x20U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [3U] 
                                                      >> 0x18U)))))) 
              << 0x18U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__3__KET____DOT__temp 
        = ((0xffffffffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__3__KET____DOT__temp) 
           | ((QData)((IData)((0xffffffU & (IData)(
                                                   (vlSelf->top_test__DOT__DUT__DOT__stage
                                                    [3U] 
                                                    >> 0x28U))))) 
              << 0x28U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__4__KET____DOT__temp 
        = vlSelf->top_test__DOT__DUT__DOT__stage[4U];
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__4__KET____DOT__temp 
        = ((0xffffffffffff0000ULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__4__KET____DOT__temp) 
           | (IData)((IData)((0xffffU & (((0xffU & (IData)(
                                                           vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [4U])) 
                                          > (0xffU 
                                             & (IData)(
                                                       (vlSelf->top_test__DOT__DUT__DOT__stage
                                                        [4U] 
                                                        >> 8U))))
                                          ? ((0xff00U 
                                              & ((IData)(
                                                         vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [4U]) 
                                                 << 8U)) 
                                             | (0xffU 
                                                & (IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [4U] 
                                                           >> 8U))))
                                          : (IData)(
                                                    vlSelf->top_test__DOT__DUT__DOT__stage
                                                    [4U]))))));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__4__KET____DOT__temp 
        = ((0xffffffffff0000ffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__4__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [4U] 
                                                             >> 8U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [4U] 
                                                         >> 0x10U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [4U] 
                                                           >> 8U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [4U] 
                                                            >> 0x10U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [4U] 
                                                      >> 8U)))))) 
              << 8U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__4__KET____DOT__temp 
        = ((0xffffffff0000ffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__4__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [4U] 
                                                             >> 0x10U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [4U] 
                                                         >> 0x18U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [4U] 
                                                           >> 0x10U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [4U] 
                                                            >> 0x18U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [4U] 
                                                      >> 0x10U)))))) 
              << 0x10U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__4__KET____DOT__temp 
        = ((0xffffffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__4__KET____DOT__temp) 
           | ((QData)((IData)((IData)((vlSelf->top_test__DOT__DUT__DOT__stage
                                       [4U] >> 0x20U)))) 
              << 0x20U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__5__KET____DOT__temp 
        = vlSelf->top_test__DOT__DUT__DOT__stage[5U];
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__5__KET____DOT__temp 
        = ((0xffffffffffff0000ULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__5__KET____DOT__temp) 
           | (IData)((IData)((0xffffU & (((0xffU & (IData)(
                                                           vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [5U])) 
                                          > (0xffU 
                                             & (IData)(
                                                       (vlSelf->top_test__DOT__DUT__DOT__stage
                                                        [5U] 
                                                        >> 8U))))
                                          ? ((0xff00U 
                                              & ((IData)(
                                                         vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [5U]) 
                                                 << 8U)) 
                                             | (0xffU 
                                                & (IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [5U] 
                                                           >> 8U))))
                                          : (IData)(
                                                    vlSelf->top_test__DOT__DUT__DOT__stage
                                                    [5U]))))));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__5__KET____DOT__temp 
        = ((0xffffffffff0000ffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__5__KET____DOT__temp) 
           | ((QData)((IData)((0xffffU & (((0xffU & (IData)(
                                                            (vlSelf->top_test__DOT__DUT__DOT__stage
                                                             [5U] 
                                                             >> 8U))) 
                                           > (0xffU 
                                              & (IData)(
                                                        (vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [5U] 
                                                         >> 0x10U))))
                                           ? ((0xff00U 
                                               & ((IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [5U] 
                                                           >> 8U)) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (IData)(
                                                           (vlSelf->top_test__DOT__DUT__DOT__stage
                                                            [5U] 
                                                            >> 0x10U))))
                                           : (IData)(
                                                     (vlSelf->top_test__DOT__DUT__DOT__stage
                                                      [5U] 
                                                      >> 8U)))))) 
              << 8U));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__5__KET____DOT__temp 
        = ((0xffffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__5__KET____DOT__temp) 
           | (0xffffffffff000000ULL & vlSelf->top_test__DOT__DUT__DOT__stage
              [5U]));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__6__KET____DOT__temp 
        = vlSelf->top_test__DOT__DUT__DOT__stage[6U];
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__6__KET____DOT__temp 
        = ((0xffffffffffff0000ULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__6__KET____DOT__temp) 
           | (IData)((IData)((0xffffU & (((0xffU & (IData)(
                                                           vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [6U])) 
                                          > (0xffU 
                                             & (IData)(
                                                       (vlSelf->top_test__DOT__DUT__DOT__stage
                                                        [6U] 
                                                        >> 8U))))
                                          ? ((0xff00U 
                                              & ((IData)(
                                                         vlSelf->top_test__DOT__DUT__DOT__stage
                                                         [6U]) 
                                                 << 8U)) 
                                             | (0xffU 
                                                & (IData)(
                                                          (vlSelf->top_test__DOT__DUT__DOT__stage
                                                           [6U] 
                                                           >> 8U))))
                                          : (IData)(
                                                    vlSelf->top_test__DOT__DUT__DOT__stage
                                                    [6U]))))));
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__6__KET____DOT__temp 
        = ((0xffffULL & vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__6__KET____DOT__temp) 
           | (0xffffffffffff0000ULL & vlSelf->top_test__DOT__DUT__DOT__stage
              [6U]));
}

VL_INLINE_OPT void Vtop_test___024root___nba_sequent__TOP__1(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (vlSelf->i_rst_n) {
        if (vlSelf->compare_block_reg__DOT__w_compare_less) {
            vlSelf->o_greater_data = vlSelf->i_data_2;
            vlSelf->o_less_data = vlSelf->i_data_1;
        } else {
            vlSelf->o_greater_data = vlSelf->i_data_1;
            vlSelf->o_less_data = vlSelf->i_data_2;
        }
    } else {
        vlSelf->o_greater_data = 0U;
        vlSelf->o_less_data = 0U;
    }
}

void Vtop_test___024root___eval_nba(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop_test___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop_test___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vtop_test___024root___timing_resume(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___timing_resume\n"); );
    // Body
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtop_test___024root___eval_triggers__act(Vtop_test___024root* vlSelf);

bool Vtop_test___024root___eval_phase__act(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop_test___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtop_test___024root___timing_resume(vlSelf);
        Vtop_test___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop_test___024root___eval_phase__nba(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop_test___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_test___024root___dump_triggers__ico(Vtop_test___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_test___024root___dump_triggers__nba(Vtop_test___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_test___024root___dump_triggers__act(Vtop_test___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop_test___024root___eval(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___eval\n"); );
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
            Vtop_test___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../../02_rtl/compare_block_reg.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop_test___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop_test___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../../02_rtl/compare_block_reg.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop_test___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../../02_rtl/compare_block_reg.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtop_test___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtop_test___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop_test___024root___eval_debug_assertions(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->i_clk & 0xfeU))) {
        Verilated::overWidthError("i_clk");}
    if (VL_UNLIKELY((vlSelf->i_rst_n & 0xfeU))) {
        Verilated::overWidthError("i_rst_n");}
}
#endif  // VL_DEBUG
