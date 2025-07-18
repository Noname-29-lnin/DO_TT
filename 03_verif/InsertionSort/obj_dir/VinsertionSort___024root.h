// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VinsertionSort.h for the primary calling header

#ifndef VERILATED_VINSERTIONSORT___024ROOT_H_
#define VERILATED_VINSERTIONSORT___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class VinsertionSort__Syms;

class alignas(VL_CACHE_LINE_BYTES) VinsertionSort___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_insertionSort__DOT__i_clk;
    CData/*0:0*/ tb_insertionSort__DOT__i_rst_n;
    CData/*0:0*/ tb_insertionSort__DOT__i_start;
    CData/*0:0*/ tb_insertionSort__DOT__o_done;
    CData/*1:0*/ tb_insertionSort__DOT__DUT__DOT__state;
    CData/*1:0*/ tb_insertionSort__DOT__DUT__DOT__n_state;
    CData/*7:0*/ tb_insertionSort__DOT__DUT__DOT__key;
    CData/*3:0*/ tb_insertionSort__DOT__DUT__DOT__i;
    CData/*3:0*/ tb_insertionSort__DOT__DUT__DOT__j;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_insertionSort__DOT__i_clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_insertionSort__DOT__i_rst_n__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_insertionSort__DOT__o_done__0;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 8> tb_insertionSort__DOT__i_data;
    VlUnpacked<CData/*7:0*/, 8> tb_insertionSort__DOT__o_data;
    VlUnpacked<CData/*7:0*/, 8> tb_insertionSort__DOT__DUT__DOT__arr;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h4238c561__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

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
