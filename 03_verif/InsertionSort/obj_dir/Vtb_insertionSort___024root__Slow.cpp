// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_insertionSort.h for the primary calling header

#include "Vtb_insertionSort__pch.h"
#include "Vtb_insertionSort__Syms.h"
#include "Vtb_insertionSort___024root.h"

void Vtb_insertionSort___024root___ctor_var_reset(Vtb_insertionSort___024root* vlSelf);

Vtb_insertionSort___024root::Vtb_insertionSort___024root(Vtb_insertionSort__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_insertionSort___024root___ctor_var_reset(this);
}

void Vtb_insertionSort___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtb_insertionSort___024root::~Vtb_insertionSort___024root() {
}
