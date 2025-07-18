// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VinsertionSort__pch.h"

//============================================================
// Constructors

VinsertionSort::VinsertionSort(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VinsertionSort__Syms(contextp(), _vcname__, this)}
    , i_clk{vlSymsp->TOP.i_clk}
    , i_rst_n{vlSymsp->TOP.i_rst_n}
    , i_start{vlSymsp->TOP.i_start}
    , o_done{vlSymsp->TOP.o_done}
    , i_data{vlSymsp->TOP.i_data}
    , o_data{vlSymsp->TOP.o_data}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VinsertionSort::VinsertionSort(const char* _vcname__)
    : VinsertionSort(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VinsertionSort::~VinsertionSort() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VinsertionSort___024root___eval_debug_assertions(VinsertionSort___024root* vlSelf);
#endif  // VL_DEBUG
void VinsertionSort___024root___eval_static(VinsertionSort___024root* vlSelf);
void VinsertionSort___024root___eval_initial(VinsertionSort___024root* vlSelf);
void VinsertionSort___024root___eval_settle(VinsertionSort___024root* vlSelf);
void VinsertionSort___024root___eval(VinsertionSort___024root* vlSelf);

void VinsertionSort::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VinsertionSort::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VinsertionSort___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VinsertionSort___024root___eval_static(&(vlSymsp->TOP));
        VinsertionSort___024root___eval_initial(&(vlSymsp->TOP));
        VinsertionSort___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VinsertionSort___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VinsertionSort::eventsPending() { return false; }

uint64_t VinsertionSort::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VinsertionSort::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VinsertionSort___024root___eval_final(VinsertionSort___024root* vlSelf);

VL_ATTR_COLD void VinsertionSort::final() {
    VinsertionSort___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VinsertionSort::hierName() const { return vlSymsp->name(); }
const char* VinsertionSort::modelName() const { return "VinsertionSort"; }
unsigned VinsertionSort::threads() const { return 1; }
void VinsertionSort::prepareClone() const { contextp()->prepareClone(); }
void VinsertionSort::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void VinsertionSort::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'VinsertionSort::trace()' called on model that was Verilated without --trace option");
}
