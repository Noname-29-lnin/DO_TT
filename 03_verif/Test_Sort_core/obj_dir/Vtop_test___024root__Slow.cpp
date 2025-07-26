// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_test.h for the primary calling header

#include "Vtop_test__pch.h"
#include "Vtop_test__Syms.h"
#include "Vtop_test___024root.h"

void Vtop_test___024root___ctor_var_reset(Vtop_test___024root* vlSelf);

Vtop_test___024root::Vtop_test___024root(Vtop_test__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_test___024root___ctor_var_reset(this);
}

void Vtop_test___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtop_test___024root::~Vtop_test___024root() {
}
