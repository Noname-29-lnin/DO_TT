// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_test.h for the primary calling header

#ifndef VERILATED_VTOP_TEST___024UNIT_H_
#define VERILATED_VTOP_TEST___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtop_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_test___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vtop_test__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_test___024unit(Vtop_test__Syms* symsp, const char* v__name);
    ~Vtop_test___024unit();
    VL_UNCOPYABLE(Vtop_test___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
