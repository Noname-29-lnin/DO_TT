// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_insertionSort__Syms.h"


void Vtb_insertionSort___024root__trace_chg_0_sub_0(Vtb_insertionSort___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_insertionSort___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root__trace_chg_0\n"); );
    // Init
    Vtb_insertionSort___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_insertionSort___024root*>(voidSelf);
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_insertionSort___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_insertionSort___024root__trace_chg_0_sub_0(Vtb_insertionSort___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->tb_insertionSort__DOT__o_done));
        bufp->chgQData(oldp+1,(vlSelf->tb_insertionSort__DOT__o_data),64);
        bufp->chgCData(oldp+3,(vlSelf->tb_insertionSort__DOT__dut__DOT__state),3);
        bufp->chgCData(oldp+4,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[0]),8);
        bufp->chgCData(oldp+5,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[1]),8);
        bufp->chgCData(oldp+6,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[2]),8);
        bufp->chgCData(oldp+7,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[3]),8);
        bufp->chgCData(oldp+8,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[4]),8);
        bufp->chgCData(oldp+9,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[5]),8);
        bufp->chgCData(oldp+10,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[6]),8);
        bufp->chgCData(oldp+11,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[7]),8);
        bufp->chgCData(oldp+12,(vlSelf->tb_insertionSort__DOT__dut__DOT__key),8);
        bufp->chgIData(oldp+13,(vlSelf->tb_insertionSort__DOT__dut__DOT__i_sign),32);
        bufp->chgCData(oldp+14,(((IData)(vlSelf->tb_insertionSort__DOT__dut__DOT__u_compare_block__DOT__w_compare_result)
                                  ? vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                                 [0U] : vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                                 [1U])),8);
        bufp->chgCData(oldp+15,(((IData)(vlSelf->tb_insertionSort__DOT__dut__DOT__u_compare_block__DOT__w_compare_result)
                                  ? vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                                 [1U] : vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                                 [0U])),8);
        bufp->chgCData(oldp+16,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                                [0U]),8);
        bufp->chgCData(oldp+17,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                                [1U]),8);
        bufp->chgBit(oldp+18,(vlSelf->tb_insertionSort__DOT__dut__DOT__u_compare_block__DOT__w_compare_result));
        bufp->chgIData(oldp+19,(vlSelf->tb_insertionSort__DOT__dut__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+20,(vlSelf->tb_insertionSort__DOT__dut__DOT__unnamedblk2__DOT__i),32);
    }
    bufp->chgBit(oldp+21,(vlSelf->tb_insertionSort__DOT__i_clk));
    bufp->chgBit(oldp+22,(vlSelf->tb_insertionSort__DOT__i_rst_n));
    bufp->chgBit(oldp+23,(vlSelf->tb_insertionSort__DOT__i_start));
    bufp->chgQData(oldp+24,(vlSelf->tb_insertionSort__DOT__i_data),64);
}

void Vtb_insertionSort___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root__trace_cleanup\n"); );
    // Init
    Vtb_insertionSort___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_insertionSort___024root*>(voidSelf);
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
