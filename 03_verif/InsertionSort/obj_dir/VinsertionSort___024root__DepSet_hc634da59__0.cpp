// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VinsertionSort.h for the primary calling header

#include "VinsertionSort__pch.h"
#include "VinsertionSort__Syms.h"
#include "VinsertionSort___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VinsertionSort___024root___dump_triggers__act(VinsertionSort___024root* vlSelf);
#endif  // VL_DEBUG

void VinsertionSort___024root___eval_triggers__act(VinsertionSort___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VinsertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinsertionSort___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->tb_insertionSort__DOT__i_clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_insertionSort__DOT__i_clk__0))) 
                                     | ((~ (IData)(vlSelf->tb_insertionSort__DOT__i_rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_insertionSort__DOT__i_rst_n__0))));
    vlSelf->__VactTriggered.set(1U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__VactTriggered.set(2U, ((IData)(vlSelf->tb_insertionSort__DOT__o_done) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_insertionSort__DOT__o_done__0)));
    vlSelf->__Vtrigprevexpr___TOP__tb_insertionSort__DOT__i_clk__0 
        = vlSelf->tb_insertionSort__DOT__i_clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_insertionSort__DOT__i_rst_n__0 
        = vlSelf->tb_insertionSort__DOT__i_rst_n;
    vlSelf->__Vtrigprevexpr___TOP__tb_insertionSort__DOT__o_done__0 
        = vlSelf->tb_insertionSort__DOT__o_done;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.set(2U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VinsertionSort___024root___dump_triggers__act(vlSelf);
    }
#endif
}
