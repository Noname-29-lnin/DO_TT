// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtop_test__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtop_test::Vtop_test(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtop_test__Syms(contextp(), _vcname__, this)}
    , i_clk{vlSymsp->TOP.i_clk}
    , i_rst_n{vlSymsp->TOP.i_rst_n}
    , i_data_1{vlSymsp->TOP.i_data_1}
    , i_data_2{vlSymsp->TOP.i_data_2}
    , o_less_data{vlSymsp->TOP.o_less_data}
    , o_greater_data{vlSymsp->TOP.o_greater_data}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtop_test::Vtop_test(const char* _vcname__)
    : Vtop_test(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtop_test::~Vtop_test() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtop_test___024root___eval_debug_assertions(Vtop_test___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop_test___024root___eval_static(Vtop_test___024root* vlSelf);
void Vtop_test___024root___eval_initial(Vtop_test___024root* vlSelf);
void Vtop_test___024root___eval_settle(Vtop_test___024root* vlSelf);
void Vtop_test___024root___eval(Vtop_test___024root* vlSelf);

void Vtop_test::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop_test::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtop_test___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtop_test___024root___eval_static(&(vlSymsp->TOP));
        Vtop_test___024root___eval_initial(&(vlSymsp->TOP));
        Vtop_test___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtop_test___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vtop_test::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vtop_test::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vtop_test::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtop_test::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtop_test::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtop_test___024root___eval_final(Vtop_test___024root* vlSelf);

VL_ATTR_COLD void Vtop_test::final() {
    Vtop_test___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtop_test::hierName() const { return vlSymsp->name(); }
const char* Vtop_test::modelName() const { return "Vtop_test"; }
unsigned Vtop_test::threads() const { return 1; }
void Vtop_test::prepareClone() const { contextp()->prepareClone(); }
void Vtop_test::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vtop_test::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vtop_test___024root__trace_decl_types(VerilatedVcd* tracep);

void Vtop_test___024root__trace_init_top(Vtop_test___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop_test___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_test___024root*>(voidSelf);
    Vtop_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop_test___024root__trace_decl_types(tracep);
    Vtop_test___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop_test___024root__trace_register(Vtop_test___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtop_test::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtop_test::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vtop_test___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
