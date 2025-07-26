// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_test.h for the primary calling header

#include "Vtop_test__pch.h"
#include "Vtop_test__Syms.h"
#include "Vtop_test___024unit.h"

void Vtop_test___024unit___ctor_var_reset(Vtop_test___024unit* vlSelf);

Vtop_test___024unit::Vtop_test___024unit(Vtop_test__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_test___024unit___ctor_var_reset(this);
}

void Vtop_test___024unit::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtop_test___024unit::~Vtop_test___024unit() {
}
