// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_test.h for the primary calling header

#include "Vtop_test__pch.h"
#include "Vtop_test__Syms.h"
#include "Vtop_test___024root.h"

VL_ATTR_COLD void Vtop_test___024root___eval_initial__TOP(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___eval_initial__TOP\n"); );
    // Init
    CData/*0:0*/ __Vfunc_check_sorted__3__Vfuncout;
    __Vfunc_check_sorted__3__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_check_sorted__3__data;
    __Vfunc_check_sorted__3__data = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x74657374U;
    __Vtemp_1[2U] = 0x746f705fU;
    __Vtemp_1[3U] = 0x74625fU;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(4, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    __Vfunc_check_sorted__3__data = vlSelf->top_test__DOT__w_odata;
    {
        if (((0xffU & (IData)((__Vfunc_check_sorted__3__data 
                               >> 8U))) < (0xffU & (IData)(__Vfunc_check_sorted__3__data)))) {
            __Vfunc_check_sorted__3__Vfuncout = 0U;
            goto __Vlabel1;
        }
        if (((0xffU & (IData)((__Vfunc_check_sorted__3__data 
                               >> 0x10U))) < (0xffU 
                                              & (IData)(
                                                        (__Vfunc_check_sorted__3__data 
                                                         >> 8U))))) {
            __Vfunc_check_sorted__3__Vfuncout = 0U;
            goto __Vlabel1;
        }
        if (((0xffU & (IData)((__Vfunc_check_sorted__3__data 
                               >> 0x18U))) < (0xffU 
                                              & (IData)(
                                                        (__Vfunc_check_sorted__3__data 
                                                         >> 0x10U))))) {
            __Vfunc_check_sorted__3__Vfuncout = 0U;
            goto __Vlabel1;
        }
        if (((0xffU & (IData)((__Vfunc_check_sorted__3__data 
                               >> 0x20U))) < (0xffU 
                                              & (IData)(
                                                        (__Vfunc_check_sorted__3__data 
                                                         >> 0x18U))))) {
            __Vfunc_check_sorted__3__Vfuncout = 0U;
            goto __Vlabel1;
        }
        if (((0xffU & (IData)((__Vfunc_check_sorted__3__data 
                               >> 0x28U))) < (0xffU 
                                              & (IData)(
                                                        (__Vfunc_check_sorted__3__data 
                                                         >> 0x20U))))) {
            __Vfunc_check_sorted__3__Vfuncout = 0U;
            goto __Vlabel1;
        }
        if (((0xffU & (IData)((__Vfunc_check_sorted__3__data 
                               >> 0x30U))) < (0xffU 
                                              & (IData)(
                                                        (__Vfunc_check_sorted__3__data 
                                                         >> 0x28U))))) {
            __Vfunc_check_sorted__3__Vfuncout = 0U;
            goto __Vlabel1;
        }
        if (((0xffU & (IData)((__Vfunc_check_sorted__3__data 
                               >> 0x38U))) < (0xffU 
                                              & (IData)(
                                                        (__Vfunc_check_sorted__3__data 
                                                         >> 0x30U))))) {
            __Vfunc_check_sorted__3__Vfuncout = 0U;
            goto __Vlabel1;
        }
        __Vfunc_check_sorted__3__Vfuncout = 1U;
        __Vlabel1: ;
    }
    vlSelf->top_test__DOT__unnamedblk1__DOT__sorted 
        = __Vfunc_check_sorted__3__Vfuncout;
    __Vtemp_2[0U] = 0x2e747874U;
    __Vtemp_2[1U] = 0x72746564U;
    __Vtemp_2[2U] = 0x756e736fU;
    __Vtemp_2[3U] = 0x2e2fU;
    VL_READMEM_N(true, 8, 8, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_2)
                 ,  &(vlSelf->top_test__DOT__driver_unit__DOT__mem)
                 , 0, ~0ULL);
    vlSelf->top_test__DOT__w_idata = ((0xffffffffff000000ULL 
                                       & vlSelf->top_test__DOT__w_idata) 
                                      | (IData)((IData)(
                                                        ((vlSelf->top_test__DOT__driver_unit__DOT__mem
                                                          [2U] 
                                                          << 0x10U) 
                                                         | ((vlSelf->top_test__DOT__driver_unit__DOT__mem
                                                             [1U] 
                                                             << 8U) 
                                                            | vlSelf->top_test__DOT__driver_unit__DOT__mem
                                                            [0U])))));
    vlSelf->top_test__DOT__w_idata = ((0xffff000000ffffffULL 
                                       & vlSelf->top_test__DOT__w_idata) 
                                      | ((QData)((IData)(
                                                         ((vlSelf->top_test__DOT__driver_unit__DOT__mem
                                                           [5U] 
                                                           << 0x10U) 
                                                          | ((vlSelf->top_test__DOT__driver_unit__DOT__mem
                                                              [4U] 
                                                              << 8U) 
                                                             | vlSelf->top_test__DOT__driver_unit__DOT__mem
                                                             [3U])))) 
                                         << 0x18U));
    vlSelf->top_test__DOT__w_idata = ((0xffffffffffffULL 
                                       & vlSelf->top_test__DOT__w_idata) 
                                      | ((QData)((IData)(
                                                         ((vlSelf->top_test__DOT__driver_unit__DOT__mem
                                                           [7U] 
                                                           << 8U) 
                                                          | vlSelf->top_test__DOT__driver_unit__DOT__mem
                                                          [6U]))) 
                                         << 0x30U));
    vlSelf->top_test__DOT__driver_unit__DOT__unnamedblk1__DOT__i = 8U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_test___024root___dump_triggers__stl(Vtop_test___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop_test___024root___eval_triggers__stl(Vtop_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop_test___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
