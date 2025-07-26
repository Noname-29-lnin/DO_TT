// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_test.h for the primary calling header

#ifndef VERILATED_VTOP_TEST___024ROOT_H_
#define VERILATED_VTOP_TEST___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtop_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_test___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(i_clk,0,0);
    VL_IN8(i_rst_n,0,0);
    CData/*0:0*/ top_test__DOT__i_clk;
    CData/*0:0*/ top_test__DOT__i_rst_n;
    VL_IN8(i_data_1,7,0);
    VL_IN8(i_data_2,7,0);
    VL_OUT8(o_less_data,7,0);
    VL_OUT8(o_greater_data,7,0);
    CData/*0:0*/ compare_block_reg__DOT__w_compare_less;
    CData/*0:0*/ top_test__DOT__o_done;
    QData/*63:0*/ top_test__DOT__w_idata;
    QData/*63:0*/ top_test__DOT__w_odata;
    CData/*0:0*/ top_test__DOT__check_sorted;
    CData/*0:0*/ top_test__DOT__unnamedblk1__DOT__sorted;
    QData/*63:0*/ top_test__DOT__DUT__DOT__stage_gen__BRA__0__KET____DOT__temp;
    QData/*63:0*/ top_test__DOT__DUT__DOT__stage_gen__BRA__1__KET____DOT__temp;
    QData/*63:0*/ top_test__DOT__DUT__DOT__stage_gen__BRA__2__KET____DOT__temp;
    QData/*63:0*/ top_test__DOT__DUT__DOT__stage_gen__BRA__3__KET____DOT__temp;
    QData/*63:0*/ top_test__DOT__DUT__DOT__stage_gen__BRA__4__KET____DOT__temp;
    QData/*63:0*/ top_test__DOT__DUT__DOT__stage_gen__BRA__5__KET____DOT__temp;
    QData/*63:0*/ top_test__DOT__DUT__DOT__stage_gen__BRA__6__KET____DOT__temp;
    CData/*0:0*/ top_test__DOT__scoreboard_unit__DOT__i_done;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__i_clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__i_rst_n__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__top_test__DOT__i_clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__top_test__DOT__i_rst_n__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ top_test__DOT__driver_unit__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 8> top_test__DOT__driver_unit__DOT__mem;
    VlUnpacked<QData/*63:0*/, 8> top_test__DOT__DUT__DOT__stage;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop_test__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_test___024root(Vtop_test__Syms* symsp, const char* v__name);
    ~Vtop_test___024root();
    VL_UNCOPYABLE(Vtop_test___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
