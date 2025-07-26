// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_test.h for the primary calling header

#include "Vtop_test__pch.h"
#include "Vtop_test___024root.h"

VL_ATTR_COLD void Vtop_test___024root___eval_static(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop_test___024root___eval_final(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_test___024root___dump_triggers__stl(Vtop_test___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop_test___024root___eval_phase__stl(Vtop_test___024root* vlSelf);

VL_ATTR_COLD void Vtop_test___024root___eval_settle(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___eval_settle\n"); );
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
            Vtop_test___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../../02_rtl/compare_block_reg.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop_test___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_test___024root___dump_triggers__stl(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop_test___024root___stl_sequent__TOP__0(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___stl_sequent__TOP__0\n"); );
    // Body
    if (VL_UNLIKELY(((IData)(vlSelf->top_test__DOT__scoreboard_unit__DOT__i_done) 
                     & (IData)(vlSelf->top_test__DOT__check_sorted)))) {
        VL_WRITEF("-> PASS");
    }
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
    vlSelf->compare_block_reg__DOT__w_compare_less 
        = ((IData)(vlSelf->i_data_1) < (IData)(vlSelf->i_data_2));
}

VL_ATTR_COLD void Vtop_test___024root___eval_stl(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtop_test___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vtop_test___024root___eval_triggers__stl(Vtop_test___024root* vlSelf);

VL_ATTR_COLD bool Vtop_test___024root___eval_phase__stl(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop_test___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop_test___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_test___024root___dump_triggers__ico(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_test___024root___dump_triggers__act(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge i_clk or negedge i_rst_n)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge top_test.i_clk or negedge top_test.i_rst_n)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_test___024root___dump_triggers__nba(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge i_clk or negedge i_rst_n)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge top_test.i_clk or negedge top_test.i_rst_n)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop_test___024root___ctor_var_reset(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->i_clk = VL_RAND_RESET_I(1);
    vlSelf->i_rst_n = VL_RAND_RESET_I(1);
    vlSelf->i_data_1 = VL_RAND_RESET_I(8);
    vlSelf->i_data_2 = VL_RAND_RESET_I(8);
    vlSelf->o_less_data = VL_RAND_RESET_I(8);
    vlSelf->o_greater_data = VL_RAND_RESET_I(8);
    vlSelf->compare_block_reg__DOT__w_compare_less = VL_RAND_RESET_I(1);
    vlSelf->top_test__DOT__i_clk = VL_RAND_RESET_I(1);
    vlSelf->top_test__DOT__i_rst_n = VL_RAND_RESET_I(1);
    vlSelf->top_test__DOT__o_done = VL_RAND_RESET_I(1);
    vlSelf->top_test__DOT__w_idata = VL_RAND_RESET_Q(64);
    vlSelf->top_test__DOT__w_odata = VL_RAND_RESET_Q(64);
    vlSelf->top_test__DOT__check_sorted = VL_RAND_RESET_I(1);
    vlSelf->top_test__DOT__unnamedblk1__DOT__sorted = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->top_test__DOT__driver_unit__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top_test__DOT__driver_unit__DOT__unnamedblk1__DOT__i = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->top_test__DOT__DUT__DOT__stage[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__0__KET____DOT__temp = VL_RAND_RESET_Q(64);
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__1__KET____DOT__temp = VL_RAND_RESET_Q(64);
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__2__KET____DOT__temp = VL_RAND_RESET_Q(64);
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__3__KET____DOT__temp = VL_RAND_RESET_Q(64);
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__4__KET____DOT__temp = VL_RAND_RESET_Q(64);
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__5__KET____DOT__temp = VL_RAND_RESET_Q(64);
    vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__6__KET____DOT__temp = VL_RAND_RESET_Q(64);
    vlSelf->top_test__DOT__scoreboard_unit__DOT__i_done = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__i_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__i_rst_n__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__top_test__DOT__i_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__top_test__DOT__i_rst_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
