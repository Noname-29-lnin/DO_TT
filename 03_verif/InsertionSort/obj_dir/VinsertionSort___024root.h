// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VinsertionSort.h for the primary calling header

#ifndef VERILATED_VINSERTIONSORT___024ROOT_H_
#define VERILATED_VINSERTIONSORT___024ROOT_H_  // guard

#include "verilated.h"


class VinsertionSort__Syms;

class alignas(VL_CACHE_LINE_BYTES) VinsertionSort___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(i_clk,0,0);
    VL_IN8(i_rst_n,0,0);
    VL_IN8(i_start,0,0);
    VL_OUT8(o_done,0,0);
    CData/*2:0*/ insertionSort__DOT__state;
    CData/*2:0*/ insertionSort__DOT__n_state;
    CData/*7:0*/ insertionSort__DOT__key;
    CData/*3:0*/ insertionSort__DOT__i;
    CData/*3:0*/ insertionSort__DOT__j;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__i_clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__i_rst_n__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VL_IN8(i_data[8],7,0);
    VL_OUT8(o_data[8],7,0);
    VlUnpacked<CData/*7:0*/, 8> insertionSort__DOT__arr;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VinsertionSort__Syms* const vlSymsp;

    // CONSTRUCTORS
    VinsertionSort___024root(VinsertionSort__Syms* symsp, const char* v__name);
    ~VinsertionSort___024root();
    VL_UNCOPYABLE(VinsertionSort___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
