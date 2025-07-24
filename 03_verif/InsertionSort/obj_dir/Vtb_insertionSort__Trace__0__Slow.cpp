// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_insertionSort__Syms.h"


VL_ATTR_COLD void Vtb_insertionSort___024root__trace_init_sub__TOP__0(Vtb_insertionSort___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("tb_insertionSort", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+27,0,"SIZE_DATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"NUM_VALS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+22,0,"i_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"i_rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"i_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+25,0,"i_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+1,0,"o_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+2,0,"o_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+27,0,"NUM_VALS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"SIZE_DATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+22,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"i_rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"i_start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+25,0,"i_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+1,0,"o_done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+2,0,"o_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+4,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->pushPrefix("arr_temp", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+5+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+13,0,"key",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+14,0,"i_sign",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+15,0,"w_less_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+16,0,"w_greater_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("u_compare_block", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+27,0,"SIZE_DATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"i_data_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+18,0,"i_data_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+15,0,"o_less_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+16,0,"o_greater_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+19,0,"w_compare_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+20,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+21,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_insertionSort___024root__trace_init_top(Vtb_insertionSort___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root__trace_init_top\n"); );
    // Body
    Vtb_insertionSort___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_insertionSort___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_insertionSort___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_insertionSort___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_insertionSort___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_insertionSort___024root__trace_register(Vtb_insertionSort___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vtb_insertionSort___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtb_insertionSort___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtb_insertionSort___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtb_insertionSort___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_insertionSort___024root__trace_const_0_sub_0(Vtb_insertionSort___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_insertionSort___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root__trace_const_0\n"); );
    // Init
    Vtb_insertionSort___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_insertionSort___024root*>(voidSelf);
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_insertionSort___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_insertionSort___024root__trace_const_0_sub_0(Vtb_insertionSort___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+27,(8U),32);
}

VL_ATTR_COLD void Vtb_insertionSort___024root__trace_full_0_sub_0(Vtb_insertionSort___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_insertionSort___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root__trace_full_0\n"); );
    // Init
    Vtb_insertionSort___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_insertionSort___024root*>(voidSelf);
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_insertionSort___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_insertionSort___024root__trace_full_0_sub_0(Vtb_insertionSort___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_insertionSort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_insertionSort___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->tb_insertionSort__DOT__o_done));
    bufp->fullQData(oldp+2,(vlSelf->tb_insertionSort__DOT__o_data),64);
    bufp->fullCData(oldp+4,(vlSelf->tb_insertionSort__DOT__dut__DOT__state),3);
    bufp->fullCData(oldp+5,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[0]),8);
    bufp->fullCData(oldp+6,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[1]),8);
    bufp->fullCData(oldp+7,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[2]),8);
    bufp->fullCData(oldp+8,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[3]),8);
    bufp->fullCData(oldp+9,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[4]),8);
    bufp->fullCData(oldp+10,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[5]),8);
    bufp->fullCData(oldp+11,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[6]),8);
    bufp->fullCData(oldp+12,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp[7]),8);
    bufp->fullCData(oldp+13,(vlSelf->tb_insertionSort__DOT__dut__DOT__key),8);
    bufp->fullIData(oldp+14,(vlSelf->tb_insertionSort__DOT__dut__DOT__i_sign),32);
    bufp->fullCData(oldp+15,(((IData)(vlSelf->tb_insertionSort__DOT__dut__DOT__u_compare_block__DOT__w_compare_result)
                               ? vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                              [0U] : vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                              [1U])),8);
    bufp->fullCData(oldp+16,(((IData)(vlSelf->tb_insertionSort__DOT__dut__DOT__u_compare_block__DOT__w_compare_result)
                               ? vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                              [1U] : vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                              [0U])),8);
    bufp->fullCData(oldp+17,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                             [0U]),8);
    bufp->fullCData(oldp+18,(vlSelf->tb_insertionSort__DOT__dut__DOT__arr_temp
                             [1U]),8);
    bufp->fullBit(oldp+19,(vlSelf->tb_insertionSort__DOT__dut__DOT__u_compare_block__DOT__w_compare_result));
    bufp->fullIData(oldp+20,(vlSelf->tb_insertionSort__DOT__dut__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+21,(vlSelf->tb_insertionSort__DOT__dut__DOT__unnamedblk2__DOT__i),32);
    bufp->fullBit(oldp+22,(vlSelf->tb_insertionSort__DOT__i_clk));
    bufp->fullBit(oldp+23,(vlSelf->tb_insertionSort__DOT__i_rst_n));
    bufp->fullBit(oldp+24,(vlSelf->tb_insertionSort__DOT__i_start));
    bufp->fullQData(oldp+25,(vlSelf->tb_insertionSort__DOT__i_data),64);
}
