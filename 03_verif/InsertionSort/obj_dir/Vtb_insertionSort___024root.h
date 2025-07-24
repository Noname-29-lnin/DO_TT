// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_insertionSort.h for the primary calling header

#ifndef VERILATED_VTB_INSERTIONSORT___024ROOT_H_
#define VERILATED_VTB_INSERTIONSORT___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_insertionSort__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_insertionSort___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_insertionSort__DOT__i_clk;
    CData/*0:0*/ tb_insertionSort__DOT__i_rst_n;
    CData/*0:0*/ tb_insertionSort__DOT__i_start;
    CData/*0:0*/ tb_insertionSort__DOT__o_done;
    CData/*2:0*/ tb_insertionSort__DOT__dut__DOT__state;
    CData/*7:0*/ tb_insertionSort__DOT__dut__DOT__key;
    CData/*7:0*/ tb_insertionSort__DOT__dut__DOT__w_less_data;
    CData/*7:0*/ tb_insertionSort__DOT__dut__DOT__w_greater_data;
    CData/*0:0*/ tb_insertionSort__DOT__dut__DOT__u_compare_block__DOT__w_compare_result;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_insertionSort__DOT__i_clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_insertionSort__DOT__i_rst_n__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_insertionSort__DOT__o_done__0;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ tb_insertionSort__DOT__dut__DOT__i_sign;
    IData/*31:0*/ tb_insertionSort__DOT__dut__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ tb_insertionSort__DOT__dut__DOT__unnamedblk2__DOT__i;
    IData/*31:0*/ __VactIterCount;
    QData/*63:0*/ tb_insertionSort__DOT__i_data;
    QData/*63:0*/ tb_insertionSort__DOT__o_data;
    VlUnpacked<CData/*7:0*/, 8> tb_insertionSort__DOT__dut__DOT__arr_temp;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h4238c561__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_insertionSort__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_insertionSort___024root(Vtb_insertionSort__Syms* symsp, const char* v__name);
    ~Vtb_insertionSort___024root();
    VL_UNCOPYABLE(Vtb_insertionSort___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
