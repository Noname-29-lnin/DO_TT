// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_test__Syms.h"


void Vtop_test___024root__trace_chg_0_sub_0(Vtop_test___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop_test___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root__trace_chg_0\n"); );
    // Init
    Vtop_test___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_test___024root*>(voidSelf);
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop_test___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop_test___024root__trace_chg_0_sub_0(Vtop_test___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgQData(oldp+0,(vlSelf->top_test__DOT__w_idata),64);
        bufp->chgCData(oldp+2,(vlSelf->top_test__DOT__driver_unit__DOT__mem[0]),8);
        bufp->chgCData(oldp+3,(vlSelf->top_test__DOT__driver_unit__DOT__mem[1]),8);
        bufp->chgCData(oldp+4,(vlSelf->top_test__DOT__driver_unit__DOT__mem[2]),8);
        bufp->chgCData(oldp+5,(vlSelf->top_test__DOT__driver_unit__DOT__mem[3]),8);
        bufp->chgCData(oldp+6,(vlSelf->top_test__DOT__driver_unit__DOT__mem[4]),8);
        bufp->chgCData(oldp+7,(vlSelf->top_test__DOT__driver_unit__DOT__mem[5]),8);
        bufp->chgCData(oldp+8,(vlSelf->top_test__DOT__driver_unit__DOT__mem[6]),8);
        bufp->chgCData(oldp+9,(vlSelf->top_test__DOT__driver_unit__DOT__mem[7]),8);
        bufp->chgIData(oldp+10,(vlSelf->top_test__DOT__driver_unit__DOT__unnamedblk1__DOT__i),32);
        bufp->chgBit(oldp+11,(vlSelf->top_test__DOT__unnamedblk1__DOT__sorted));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+12,(vlSelf->top_test__DOT__o_done));
        bufp->chgQData(oldp+13,(vlSelf->top_test__DOT__w_odata),64);
        bufp->chgQData(oldp+15,(vlSelf->top_test__DOT__DUT__DOT__stage
                                [0U]),64);
        bufp->chgQData(oldp+17,(vlSelf->top_test__DOT__DUT__DOT__stage
                                [1U]),64);
        bufp->chgQData(oldp+19,(vlSelf->top_test__DOT__DUT__DOT__stage
                                [2U]),64);
        bufp->chgQData(oldp+21,(vlSelf->top_test__DOT__DUT__DOT__stage
                                [3U]),64);
        bufp->chgQData(oldp+23,(vlSelf->top_test__DOT__DUT__DOT__stage
                                [4U]),64);
        bufp->chgQData(oldp+25,(vlSelf->top_test__DOT__DUT__DOT__stage
                                [5U]),64);
        bufp->chgQData(oldp+27,(vlSelf->top_test__DOT__DUT__DOT__stage
                                [6U]),64);
        bufp->chgQData(oldp+29,(vlSelf->top_test__DOT__DUT__DOT__stage
                                [7U]),64);
        bufp->chgQData(oldp+31,(vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__0__KET____DOT__temp),64);
        bufp->chgQData(oldp+33,(vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__1__KET____DOT__temp),64);
        bufp->chgQData(oldp+35,(vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__2__KET____DOT__temp),64);
        bufp->chgQData(oldp+37,(vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__3__KET____DOT__temp),64);
        bufp->chgQData(oldp+39,(vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__4__KET____DOT__temp),64);
        bufp->chgQData(oldp+41,(vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__5__KET____DOT__temp),64);
        bufp->chgQData(oldp+43,(vlSelf->top_test__DOT__DUT__DOT__stage_gen__BRA__6__KET____DOT__temp),64);
    }
    bufp->chgBit(oldp+45,(vlSelf->i_clk));
    bufp->chgBit(oldp+46,(vlSelf->i_rst_n));
    bufp->chgCData(oldp+47,(vlSelf->i_data_1),8);
    bufp->chgCData(oldp+48,(vlSelf->i_data_2),8);
    bufp->chgCData(oldp+49,(vlSelf->o_less_data),8);
    bufp->chgCData(oldp+50,(vlSelf->o_greater_data),8);
    bufp->chgBit(oldp+51,(vlSelf->compare_block_reg__DOT__w_compare_less));
    bufp->chgCData(oldp+52,(((IData)(vlSelf->compare_block_reg__DOT__w_compare_less)
                              ? (IData)(vlSelf->i_data_1)
                              : (IData)(vlSelf->i_data_2))),8);
    bufp->chgCData(oldp+53,(((IData)(vlSelf->compare_block_reg__DOT__w_compare_less)
                              ? (IData)(vlSelf->i_data_2)
                              : (IData)(vlSelf->i_data_1))),8);
    bufp->chgBit(oldp+54,(vlSelf->top_test__DOT__i_clk));
    bufp->chgBit(oldp+55,(vlSelf->top_test__DOT__i_rst_n));
}

void Vtop_test___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_test___024root__trace_cleanup\n"); );
    // Init
    Vtop_test___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_test___024root*>(voidSelf);
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
