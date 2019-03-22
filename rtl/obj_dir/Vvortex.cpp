// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VVortex.h for the primary calling header

#include "VVortex.h"
#include "VVortex__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VVortex) {
    VVortex__Syms* __restrict vlSymsp = __VlSymsp = new VVortex__Syms(this, name());
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VVortex::__Vconfigure(VVortex__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VVortex::~VVortex() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VVortex::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VVortex::eval\n"); );
    VVortex__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void VVortex::_eval_initial_loop(VVortex__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VVortex::_sequent__TOP__1(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_sequent__TOP__1\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at VX_fetch.v:128
    vlTOPp->Vortex__DOT__vx_fetch__DOT__stall_reg = 
	((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__stall));
    // ALWAYS at VX_fetch.v:128
    vlTOPp->Vortex__DOT__vx_fetch__DOT__old = ((IData)(vlTOPp->reset)
					        ? 0U
					        : vlTOPp->Vortex__DOT__vx_fetch__DOT__temp_PC);
    // ALWAYS at VX_fetch.v:128
    vlTOPp->Vortex__DOT__vx_fetch__DOT__BR_reg = ((IData)(vlTOPp->reset)
						   ? 0U
						   : 
						  ((IData)(4U) 
						   + vlTOPp->Vortex__DOT__memory_branch_dest));
    // ALWAYS at VX_fetch.v:128
    vlTOPp->Vortex__DOT__vx_fetch__DOT__delay_reg = 0U;
    // ALWAYS at VX_fetch.v:128
    vlTOPp->Vortex__DOT__vx_fetch__DOT__real_PC = ((IData)(vlTOPp->reset)
						    ? 0U
						    : 
						   ((IData)(4U) 
						    + vlTOPp->Vortex__DOT__vx_fetch__DOT__PC_to_use));
    // ALWAYS at VX_fetch.v:128
    vlTOPp->Vortex__DOT__vx_fetch__DOT__state = ((IData)(vlTOPp->reset)
						  ? 0U
						  : 
						 ((IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__prev_debug)
						   ? 4U
						   : 
						  ((IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal)
						    ? 1U
						    : 
						   ((IData)(vlTOPp->Vortex__DOT__memory_branch_dir)
						     ? 2U
						     : 0U))));
    // ALWAYS at VX_fetch.v:128
    vlTOPp->Vortex__DOT__vx_fetch__DOT__JAL_reg = ((IData)(vlTOPp->reset)
						    ? 0U
						    : 
						   ((IData)(4U) 
						    + vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal_dest));
    // ALWAYS at VX_fetch.v:128
    vlTOPp->Vortex__DOT__vx_fetch__DOT__prev_debug = 0U;
    // ALWAYS at VX_fetch.v:71
    vlTOPp->Vortex__DOT__vx_fetch__DOT__PC_to_use = 
	((IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__delay_reg)
	  ? vlTOPp->Vortex__DOT__vx_fetch__DOT__old
	  : ((IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__stall_reg)
	      ? vlTOPp->Vortex__DOT__vx_fetch__DOT__old
	      : ((0x10U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
		  ? 0U : ((8U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
			   ? 0U : ((4U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
				    ? ((2U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
				        ? 0U : ((1U 
						 & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
						 ? 0U
						 : vlTOPp->Vortex__DOT__vx_fetch__DOT__old))
				    : ((2U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
				        ? ((1U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
					    ? vlTOPp->Vortex__DOT__vx_fetch__DOT__real_PC
					    : vlTOPp->Vortex__DOT__vx_fetch__DOT__BR_reg)
				        : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
					    ? vlTOPp->Vortex__DOT__vx_fetch__DOT__JAL_reg
					    : vlTOPp->Vortex__DOT__vx_fetch__DOT__real_PC)))))));
}

VL_INLINE_OPT void VVortex::_sequent__TOP__2(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_sequent__TOP__2\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdlyvdim0__Vortex__DOT__vx_decode__DOT__vx_register_file__DOT__registers__v0,4,0);
    VL_SIG8(__Vdlyvset__Vortex__DOT__vx_decode__DOT__vx_register_file__DOT__registers__v0,0,0);
    VL_SIG8(__Vdlyvset__Vortex__DOT__vx_csr_handler__DOT__csr__v0,0,0);
    VL_SIG16(__Vdlyvdim0__Vortex__DOT__vx_csr_handler__DOT__csr__v0,11,0);
    VL_SIG16(__Vdlyvval__Vortex__DOT__vx_csr_handler__DOT__csr__v0,11,0);
    VL_SIG(__Vdlyvval__Vortex__DOT__vx_decode__DOT__vx_register_file__DOT__registers__v0,31,0);
    // Body
    __Vdlyvset__Vortex__DOT__vx_csr_handler__DOT__csr__v0 = 0U;
    __Vdlyvset__Vortex__DOT__vx_decode__DOT__vx_register_file__DOT__registers__v0 = 0U;
    // ALWAYS at VX_csr_handler.v:34
    vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address 
	= vlTOPp->Vortex__DOT__decode_csr_address;
    // ALWAYS at VX_csr_handler.v:34
    vlTOPp->Vortex__DOT__vx_csr_handler__DOT__cycle 
	= (VL_ULL(1) + vlTOPp->Vortex__DOT__vx_csr_handler__DOT__cycle);
    // ALWAYS at VX_e_m_reg.v:117
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__branch_type;
    // ALWAYS at VX_e_m_reg.v:117
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__curr_PC = vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__curr_PC;
    // ALWAYS at VX_e_m_reg.v:117
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_offset 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__itype_immed;
    // ALWAYS at VX_d_e_reg.v:130
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__upper_immed 
	= (0xfffffU & ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
		        ? 0U : ((0x37U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
				 ? (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				    >> 0xcU) : ((0x17U 
						 == 
						 (0x7fU 
						  & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
						 ? 
						(vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						 >> 0xcU)
						 : 0U))));
    // ALWAYS at VX_d_e_reg.v:130
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rs2_src = 
	(1U & ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	        ? 0U : (1U & (((IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__is_itype) 
			       | (0x23U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)))
			       ? 1U : 0U))));
    // ALWAYS at VX_csr_handler.v:34
    if (vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__valid) {
	vlTOPp->Vortex__DOT__vx_csr_handler__DOT__instret 
	    = (VL_ULL(1) + vlTOPp->Vortex__DOT__vx_csr_handler__DOT__instret);
    }
    // ALWAYS at VX_e_m_reg.v:117
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__mem_write 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__mem_write;
    // ALWAYS at VX_e_m_reg.v:117
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__mem_read 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__mem_read;
    // ALWAYS at VX_e_m_reg.v:117
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal = vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__jal;
    // ALWAYS at VX_e_m_reg.v:117
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal_dest 
	= (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 
	   + vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__jal_offset);
    // ALWAYS at VX_csr_handler.v:43
    if (vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__is_csr) {
	__Vdlyvval__Vortex__DOT__vx_csr_handler__DOT__csr__v0 
	    = (0xfffU & vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__csr_result);
	__Vdlyvset__Vortex__DOT__vx_csr_handler__DOT__csr__v0 = 1U;
	__Vdlyvdim0__Vortex__DOT__vx_csr_handler__DOT__csr__v0 
	    = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__csr_address;
    }
    // ALWAYS at VX_register_file.v:30
    if (((0U != (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb)) 
	 & (0U != (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__rd)))) {
	__Vdlyvval__Vortex__DOT__vx_decode__DOT__vx_register_file__DOT__registers__v0 
	    = ((3U == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
	        ? vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__PC_next
	        : ((1U == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
		    ? vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__alu_result
		    : vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__mem_result));
	__Vdlyvset__Vortex__DOT__vx_decode__DOT__vx_register_file__DOT__registers__v0 = 1U;
	__Vdlyvdim0__Vortex__DOT__vx_decode__DOT__vx_register_file__DOT__registers__v0 
	    = vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__rd;
    }
    // ALWAYS at VX_e_m_reg.v:117
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__rd2 = vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd2;
    // ALWAYSPOST at VX_csr_handler.v:45
    if (__Vdlyvset__Vortex__DOT__vx_csr_handler__DOT__csr__v0) {
	vlTOPp->Vortex__DOT__vx_csr_handler__DOT__csr[__Vdlyvdim0__Vortex__DOT__vx_csr_handler__DOT__csr__v0] 
	    = __Vdlyvval__Vortex__DOT__vx_csr_handler__DOT__csr__v0;
    }
    // ALWAYS at VX_d_e_reg.v:130
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__branch_type 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	    ? 0U : (IData)(vlTOPp->Vortex__DOT__decode_branch_type));
    // ALWAYS at VX_d_e_reg.v:130
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__curr_PC = 
	((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	  ? 0U : vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__curr_PC);
    vlTOPp->Vortex__DOT__memory_branch_dest = (vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__curr_PC 
					       + (vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_offset 
						  << 1U));
    // ALWAYS at VX_d_e_reg.v:130
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__itype_immed 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	    ? 0xdeadbeefU : vlTOPp->Vortex__DOT__decode_itype_immed);
    // ALWAYS at VX_m_w_reg.v:60
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__valid = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__valid;
    vlTOPp->out_cache_driver_in_mem_write = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__mem_write;
    // ALWAYS at VX_d_e_reg.v:130
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__mem_write 
	= (7U & ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
		  ? 7U : ((0x23U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
			   ? (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			      >> 0xcU) : 7U)));
    vlTOPp->out_cache_driver_in_mem_read = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__mem_read;
    // ALWAYS at VX_d_e_reg.v:130
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__mem_read 
	= (7U & ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
		  ? 7U : ((3U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
			   ? (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			      >> 0xcU) : 7U)));
    // ALWAYS at VX_d_e_reg.v:130
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__jal = ((~ (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)) 
						 & ((0x6fU 
						     == 
						     (0x7fU 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						    | ((0x67U 
							== 
							(0x7fU 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						       | ((0x73U 
							   == 
							   (0x7fU 
							    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
							  & ((0U 
							      == 
							      (7U 
							       & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								  >> 0xcU))) 
							     & (2U 
								> 
								(0xfffU 
								 & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								    >> 0x14U))))))));
    // ALWAYS at VX_d_e_reg.v:130
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 = ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
						  ? 0U
						  : vlTOPp->Vortex__DOT__decode_rd1);
    // ALWAYS at VX_d_e_reg.v:130
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__jal_offset 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	    ? 0U : ((0x6fU == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
		     ? ((0xffe00000U & (VL_NEGATE_I((IData)(
							    (1U 
							     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								>> 0x1fU)))) 
					<< 0x15U)) 
			| ((0x100000U & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
					 >> 0xbU)) 
			   | ((0xff000U & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction) 
			      | ((0x800U & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
					    >> 9U)) 
				 | (0x7feU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
					      >> 0x14U))))))
		     : ((0x67U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
			 ? ((0xfffff000U & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								    >> 0x1fU)))) 
					    << 0xcU)) 
			    | (0xfffU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
					 >> 0x14U)))
			 : ((0x73U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
			     ? (((0U == (7U & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
					       >> 0xcU))) 
				 & (2U > (0xfffU & 
					  (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
					   >> 0x14U))))
				 ? 0xb0000000U : 0xdeadbeefU)
			     : 0xdeadbeefU))));
    // ALWAYS at VX_e_m_reg.v:117
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__csr_address 
	= vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__csr_address;
    // ALWAYS at VX_e_m_reg.v:117
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__is_csr = vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__is_csr;
    // ALWAYS at VX_e_m_reg.v:117
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__csr_result 
	= ((8U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
	    ? ((4U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
	        ? ((2U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		    ? ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		        ? (vlTOPp->Vortex__DOT__csr_decode_csr_data 
			   & ((IData)(0xffffffffU) 
			      - vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__csr_mask))
		        : (vlTOPp->Vortex__DOT__csr_decode_csr_data 
			   | vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__csr_mask))
		    : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
		        ? vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__csr_mask
		        : 0xdeadbeefU)) : 0xdeadbeefU)
	    : 0xdeadbeefU);
    // ALWAYS at VX_m_w_reg.v:60
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__rd = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__rd;
    vlTOPp->out_cache_driver_in_data = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__rd2;
    // ALWAYS at VX_d_e_reg.v:130
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd2 = ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
						  ? 0U
						  : 
						 ((((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd) 
						    | (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd)) 
						   | (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_wb_fwd))
						   ? 
						  ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd)
						    ? 
						   ((3U 
						     == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb))
						     ? vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__PC_next_out
						     : vlTOPp->Vortex__DOT__execute_alu_result)
						    : 
						   ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd)
						     ? 
						    ((3U 
						      == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
						      ? vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__PC_next
						      : 
						     ((2U 
						       == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
						       ? vlTOPp->in_cache_driver_out_data
						       : vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result))
						     : 
						    ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_wb_fwd)
						      ? 
						     ((3U 
						       == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						       ? vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__PC_next
						       : 
						      ((2U 
							== (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						        ? vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__mem_result
						        : vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__alu_result))
						      : 0xdeadbeefU)))
						   : 
						  vlTOPp->Vortex__DOT__vx_decode__DOT__vx_register_file__DOT__registers
						  [
						  (0x1fU 
						   & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						      >> 0x14U))]));
    vlTOPp->Vortex__DOT__csr_decode_csr_data = ((0xc00U 
						 == (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address))
						 ? (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__cycle)
						 : 
						((0xc80U 
						  == (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address))
						  ? (IData)(
							    (vlTOPp->Vortex__DOT__vx_csr_handler__DOT__cycle 
							     >> 0x20U))
						  : 
						 ((0xc02U 
						   == (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address))
						   ? (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__instret)
						   : 
						  ((0xc82U 
						    == (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address))
						    ? (IData)(
							      (vlTOPp->Vortex__DOT__vx_csr_handler__DOT__instret 
							       >> 0x20U))
						    : 
						   vlTOPp->Vortex__DOT__vx_csr_handler__DOT__csr
						   [vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address]))));
    // ALWAYSPOST at VX_register_file.v:32
    if (__Vdlyvset__Vortex__DOT__vx_decode__DOT__vx_register_file__DOT__registers__v0) {
	vlTOPp->Vortex__DOT__vx_decode__DOT__vx_register_file__DOT__registers[__Vdlyvdim0__Vortex__DOT__vx_decode__DOT__vx_register_file__DOT__registers__v0] 
	    = __Vdlyvval__Vortex__DOT__vx_decode__DOT__vx_register_file__DOT__registers__v0;
    }
    // ALWAYS at VX_e_m_reg.v:117
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__valid = vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__valid;
    vlTOPp->Vortex__DOT__execute_branch_stall = ((0U 
						  != (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__branch_type)) 
						 | (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__jal));
    // ALWAYS at VX_d_e_reg.v:130
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__csr_address 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	    ? 0U : (IData)(vlTOPp->Vortex__DOT__decode_csr_address));
    // ALWAYS at VX_d_e_reg.v:130
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__is_csr = 
	((~ (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)) 
	 & (IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__is_csr));
    // ALWAYS at VX_d_e_reg.v:130
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__csr_mask 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	    ? 0U : (((IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__is_csr) 
		     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			>> 0xeU)) ? (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
					      >> 0xfU))
		     : vlTOPp->Vortex__DOT__decode_rd1));
    // ALWAYS at VX_d_e_reg.v:130
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op = 
	((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	  ? 0xfU : ((0x63U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
		     ? ((5U > (IData)(vlTOPp->Vortex__DOT__decode_branch_type))
			 ? 1U : 0xaU) : ((0x37U == 
					  (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
					  ? 0xbU : 
					 ((0x17U == 
					   (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
					   ? 0xcU : 
					  ((IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__is_csr)
					    ? ((1U 
						== 
						(3U 
						 & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						    >> 0xcU)))
					        ? 0xdU
					        : (
						   (2U 
						    == 
						    (3U 
						     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							>> 0xcU)))
						    ? 0xeU
						    : 0xfU))
					    : (((0x23U 
						 == 
						 (0x7fU 
						  & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						| (3U 
						   == 
						   (0x7fU 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)))
					        ? 0U
					        : (
						   (0x4000U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 
						   ((0x2000U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 
						    ((0x1000U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 9U
						      : 8U)
						     : 
						    ((0x1000U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 
						     ((0U 
						       == 
						       (0x7fU 
							& (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							   >> 0x19U)))
						       ? 6U
						       : 7U)
						      : 5U))
						    : 
						   ((0x2000U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 
						    ((0x1000U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 4U
						      : 3U)
						     : 
						    ((0x1000U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 2U
						      : 
						     ((0x13U 
						       == 
						       (0x7fU 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
						       ? 0U
						       : 
						      ((0U 
							== 
							(0x7fU 
							 & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							    >> 0x19U)))
						        ? 0U
						        : 1U)))))))))));
    // ALWAYS at VX_e_m_reg.v:117
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__rd = vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd;
    // ALWAYS at VX_m_w_reg.v:60
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__mem_result 
	= vlTOPp->in_cache_driver_out_data;
    vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2 = 
	((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rs2_src)
	  ? vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__itype_immed
	  : vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd2);
    // ALWAYS at VX_m_w_reg.v:60
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__alu_result 
	= vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result;
    // ALWAYS at VX_m_w_reg.v:60
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__PC_next = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__PC_next;
    // ALWAYS at VX_m_w_reg.v:60
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb;
    // ALWAYS at VX_d_e_reg.v:130
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__valid = (
						   (~ (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)) 
						   & (IData)(vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__valid));
    // ALWAYS at VX_d_e_reg.v:130
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd = (0x1fU 
						& ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
						    ? 0U
						    : 
						   (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						    >> 7U)));
    // ALWAYS at VX_e_m_reg.v:117
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result 
	= vlTOPp->Vortex__DOT__execute_alu_result;
    // ALWAYS at VX_e_m_reg.v:117
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__PC_next = vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__PC_next_out;
    // ALWAYS at VX_e_m_reg.v:117
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb = vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb;
    // ALWAYS at VX_execute.v:69
    vlTOPp->Vortex__DOT__execute_alu_result = ((8U 
						& (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
					        ? (
						   (4U 
						    & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						    ? 
						   ((2U 
						     & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						     ? vlTOPp->Vortex__DOT__csr_decode_csr_data
						     : 
						    ((1U 
						      & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						      ? vlTOPp->Vortex__DOT__csr_decode_csr_data
						      : 
						     (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__curr_PC 
						      + 
						      (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__upper_immed 
						       << 0xcU))))
						    : 
						   ((2U 
						     & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						      ? 
						     (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__upper_immed 
						      << 0xcU)
						      : 
						     ((vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 
						       >= vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						       ? 0U
						       : 0xffffffffU))
						     : 
						    ((1U 
						      & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						      ? 
						     (vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2 
						      & vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1)
						      : 
						     (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 
						      | vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2))))
					        : (
						   (4U 
						    & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						    ? 
						   ((2U 
						     & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						      ? 
						     ((0x1fU 
						       >= vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						       ? 
						      (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 
						       >> vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						       : 0U)
						      : 
						     ((0x1fU 
						       >= vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						       ? 
						      (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 
						       >> vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						       : 0U))
						     : 
						    ((1U 
						      & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						      ? 
						     (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 
						      ^ vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						      : 
						     ((vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 
						       < vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						       ? 1U
						       : 0U)))
						    : 
						   ((2U 
						     & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						      ? 
						     (VL_LTS_III(1,32,32, vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1, vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						       ? 1U
						       : 0U)
						      : 
						     ((0x1fU 
						       >= vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						       ? 
						      (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 
						       << vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						       : 0U))
						     : 
						    ((1U 
						      & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						      ? 
						     (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 
						      - vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						      : 
						     (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 
						      + vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)))));
    vlTOPp->out_cache_driver_in_address = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result;
    // ALWAYS at VX_memory.v:60
    vlTOPp->Vortex__DOT__memory_branch_dir = (1U & 
					      ((4U 
						& (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
					        ? (
						   (2U 
						    & (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
						    ? 
						   ((~ (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type)) 
						    & (~ 
						       (vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result 
							>> 0x1fU)))
						    : 
						   ((1U 
						     & (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
						     ? 
						    (vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result 
						     >> 0x1fU)
						     : 
						    (~ 
						     (vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result 
						      >> 0x1fU))))
					        : (
						   (2U 
						    & (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
						     ? 
						    (vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result 
						     >> 0x1fU)
						     : 
						    (0U 
						     != vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result))
						    : 
						   ((IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type) 
						    & (0U 
						       == vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result)))));
    // ALWAYS at VX_d_e_reg.v:130
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__PC_next_out 
	= ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
	    ? 0U : ((IData)(4U) + vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__curr_PC));
    // ALWAYS at VX_d_e_reg.v:130
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb = ((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling)
						 ? 0U
						 : 
						((((0x6fU 
						    == 
						    (0x7fU 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						   | (0x67U 
						      == 
						      (0x7fU 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))) 
						  | ((0x73U 
						      == 
						      (0x7fU 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						     & (0U 
							== 
							(7U 
							 & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							    >> 0xcU)))))
						  ? 3U
						  : 
						 ((3U 
						   == 
						   (0x7fU 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
						   ? 2U
						   : 
						  ((((((IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__is_itype) 
						       | (0x33U 
							  == 
							  (0x7fU 
							   & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))) 
						      | (0x37U 
							 == 
							 (0x7fU 
							  & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))) 
						     | (0x17U 
							== 
							(0x7fU 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))) 
						    | (IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__is_csr))
						    ? 1U
						    : 0U))));
}

void VVortex::_initial__TOP__3(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_initial__TOP__3\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at VX_csr_handler.v:27
    vlTOPp->Vortex__DOT__vx_csr_handler__DOT__cycle = VL_ULL(0);
    vlTOPp->Vortex__DOT__vx_csr_handler__DOT__instret = VL_ULL(0);
    vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address = 0U;
    // INITIAL at VX_fetch.v:44
    vlTOPp->Vortex__DOT__vx_fetch__DOT__stall_reg = 0U;
    vlTOPp->Vortex__DOT__vx_fetch__DOT__delay_reg = 0U;
    vlTOPp->Vortex__DOT__vx_fetch__DOT__old = 0U;
    vlTOPp->Vortex__DOT__vx_fetch__DOT__state = 0U;
    vlTOPp->Vortex__DOT__vx_fetch__DOT__real_PC = 0U;
    vlTOPp->Vortex__DOT__vx_fetch__DOT__JAL_reg = 0U;
    vlTOPp->Vortex__DOT__vx_fetch__DOT__BR_reg = 0U;
    vlTOPp->Vortex__DOT__vx_fetch__DOT__prev_debug = 0U;
    // INITIAL at VX_m_w_reg.v:39
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__alu_result = 0U;
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__mem_result = 0U;
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__rd = 0U;
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb = 0U;
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__PC_next = 0U;
    vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__valid = 0U;
    // INITIAL at VX_e_m_reg.v:72
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__rd = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__rd2 = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__PC_next = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__mem_read = 7U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__mem_write = 7U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__csr_address = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__is_csr = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__csr_result = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__curr_PC = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_offset = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal_dest = 0U;
    vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__valid = 0U;
    // INITIAL at VX_d_e_reg.v:79
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd2 = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__PC_next_out = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rs2_src = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__itype_immed = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__mem_read = 7U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__mem_write = 7U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__branch_type = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__upper_immed = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__csr_address = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__is_csr = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__csr_mask = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__curr_PC = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__jal = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__jal_offset = 0U;
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__valid = 0U;
}

void VVortex::_settle__TOP__4(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_settle__TOP__4\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Vortex__DOT__vx_decode__DOT__is_itype = 
	((0x13U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
	 | (3U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)));
    vlTOPp->Vortex__DOT__vx_decode__DOT__is_csr = (
						   (0x73U 
						    == 
						    (0x7fU 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						   & (0U 
						      != 
						      (7U 
						       & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							  >> 0xcU))));
    vlTOPp->Vortex__DOT__decode_csr_address = (0xfffU 
					       & (((0U 
						    != 
						    (7U 
						     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							>> 0xcU))) 
						   & (2U 
						      <= 
						      (0xfffU 
						       & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							  >> 0x14U))))
						   ? 
						  (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						   >> 0x14U)
						   : 0x55U));
    // ALWAYS at VX_decode.v:249
    vlTOPp->Vortex__DOT__decode_branch_type = ((0x63U 
						== 
						(0x7fU 
						 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
					        ? (
						   (0x4000U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 
						   ((0x2000U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 
						    ((0x1000U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 6U
						      : 5U)
						     : 
						    ((0x1000U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 4U
						      : 3U))
						    : 
						   ((0x2000U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 0U
						     : 
						    ((0x1000U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 2U
						      : 1U)))
					        : 0U);
    vlTOPp->Vortex__DOT__vx_decode__DOT__alu_tempp 
	= (0xfffU & (((1U == (7U & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				    >> 0xcU))) | (5U 
						  == 
						  (7U 
						   & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						      >> 0xcU))))
		      ? (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				  >> 0x14U)) : (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						>> 0x14U)));
    vlTOPp->Vortex__DOT__csr_decode_csr_data = ((0xc00U 
						 == (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address))
						 ? (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__cycle)
						 : 
						((0xc80U 
						  == (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address))
						  ? (IData)(
							    (vlTOPp->Vortex__DOT__vx_csr_handler__DOT__cycle 
							     >> 0x20U))
						  : 
						 ((0xc02U 
						   == (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address))
						   ? (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__instret)
						   : 
						  ((0xc82U 
						    == (IData)(vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address))
						    ? (IData)(
							      (vlTOPp->Vortex__DOT__vx_csr_handler__DOT__instret 
							       >> 0x20U))
						    : 
						   vlTOPp->Vortex__DOT__vx_csr_handler__DOT__csr
						   [vlTOPp->Vortex__DOT__vx_csr_handler__DOT__decode_csr_address]))));
    // ALWAYS at VX_fetch.v:71
    vlTOPp->Vortex__DOT__vx_fetch__DOT__PC_to_use = 
	((IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__delay_reg)
	  ? vlTOPp->Vortex__DOT__vx_fetch__DOT__old
	  : ((IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__stall_reg)
	      ? vlTOPp->Vortex__DOT__vx_fetch__DOT__old
	      : ((0x10U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
		  ? 0U : ((8U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
			   ? 0U : ((4U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
				    ? ((2U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
				        ? 0U : ((1U 
						 & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
						 ? 0U
						 : vlTOPp->Vortex__DOT__vx_fetch__DOT__old))
				    : ((2U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
				        ? ((1U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
					    ? vlTOPp->Vortex__DOT__vx_fetch__DOT__real_PC
					    : vlTOPp->Vortex__DOT__vx_fetch__DOT__BR_reg)
				        : ((1U & (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__state))
					    ? vlTOPp->Vortex__DOT__vx_fetch__DOT__JAL_reg
					    : vlTOPp->Vortex__DOT__vx_fetch__DOT__real_PC)))))));
    vlTOPp->out_cache_driver_in_data = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__rd2;
    vlTOPp->out_cache_driver_in_mem_read = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__mem_read;
    vlTOPp->out_cache_driver_in_mem_write = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__mem_write;
    vlTOPp->Vortex__DOT__memory_branch_dest = (vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__curr_PC 
					       + (vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_offset 
						  << 1U));
    vlTOPp->out_cache_driver_in_address = vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result;
    // ALWAYS at VX_memory.v:60
    vlTOPp->Vortex__DOT__memory_branch_dir = (1U & 
					      ((4U 
						& (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
					        ? (
						   (2U 
						    & (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
						    ? 
						   ((~ (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type)) 
						    & (~ 
						       (vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result 
							>> 0x1fU)))
						    : 
						   ((1U 
						     & (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
						     ? 
						    (vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result 
						     >> 0x1fU)
						     : 
						    (~ 
						     (vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result 
						      >> 0x1fU))))
					        : (
						   (2U 
						    & (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type))
						     ? 
						    (vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result 
						     >> 0x1fU)
						     : 
						    (0U 
						     != vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result))
						    : 
						   ((IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__branch_type) 
						    & (0U 
						       == vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result)))));
    vlTOPp->Vortex__DOT__execute_branch_stall = ((0U 
						  != (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__branch_type)) 
						 | (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__jal));
    vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2 = 
	((IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rs2_src)
	  ? vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__itype_immed
	  : vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd2);
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd 
	= ((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
		       >> 0x14U)) == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd)) 
	    & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			       >> 0x14U)))) & (0U != (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb)));
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd 
	= ((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
		       >> 0xfU)) == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd)) 
	    & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			       >> 0xfU)))) & (0U != (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb)));
    // ALWAYS at VX_decode.v:238
    vlTOPp->Vortex__DOT__decode_itype_immed = ((0x40U 
						& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
					        ? (
						   (0x20U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 
						   ((0x10U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 0xdeadbeefU
						     : 
						    ((8U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 0xdeadbeefU
						      : 
						     ((4U 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						       ? 0xdeadbeefU
						       : 
						      ((2U 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						        ? 
						       ((1U 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
							 ? 
							((0xfffff000U 
							  & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
										>> 0x1fU)))) 
							     << 0xcU)) 
							 | ((0x800U 
							     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								>> 0x14U)) 
							    | ((0x400U 
								& (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								   << 3U)) 
							       | ((0x3f0U 
								   & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								      >> 0x15U)) 
								  | (0xfU 
								     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
									>> 8U))))))
							 : 0xdeadbeefU)
						        : 0xdeadbeefU))))
						    : 0xdeadbeefU)
					        : (
						   (0x20U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 
						   ((0x10U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 0xdeadbeefU
						     : 
						    ((8U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 0xdeadbeefU
						      : 
						     ((4U 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						       ? 0xdeadbeefU
						       : 
						      ((2U 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						        ? 
						       ((1U 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
							 ? 
							((0xfffff000U 
							  & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
										>> 0x1fU)))) 
							     << 0xcU)) 
							 | ((0xfe0U 
							     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								>> 0x14U)) 
							    | (0x1fU 
							       & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								  >> 7U))))
							 : 0xdeadbeefU)
						        : 0xdeadbeefU))))
						    : 
						   ((0x10U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 
						    ((8U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 0xdeadbeefU
						      : 
						     ((4U 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						       ? 0xdeadbeefU
						       : 
						      ((2U 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						        ? 
						       ((1U 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
							 ? 
							((0xfffff000U 
							  & (VL_NEGATE_I((IData)(
										(1U 
										& ((IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__alu_tempp) 
										>> 0xbU)))) 
							     << 0xcU)) 
							 | (IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__alu_tempp))
							 : 0xdeadbeefU)
						        : 0xdeadbeefU)))
						     : 
						    ((8U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 0xdeadbeefU
						      : 
						     ((4U 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						       ? 0xdeadbeefU
						       : 
						      ((2U 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						        ? 
						       ((1U 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
							 ? 
							((0xfffff000U 
							  & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
										>> 0x1fU)))) 
							     << 0xcU)) 
							 | (0xfffU 
							    & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							       >> 0x14U)))
							 : 0xdeadbeefU)
						        : 0xdeadbeefU))))));
    // ALWAYS at VX_fetch.v:94
    vlTOPp->Vortex__DOT__vx_fetch__DOT__temp_PC = (
						   ((IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal) 
						    & (~ (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__delay_reg)))
						    ? vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal_dest
						    : 
						   (((IData)(vlTOPp->Vortex__DOT__memory_branch_dir) 
						     & (~ (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__delay_reg)))
						     ? vlTOPp->Vortex__DOT__memory_branch_dest
						     : vlTOPp->Vortex__DOT__vx_fetch__DOT__PC_to_use));
    // ALWAYS at VX_execute.v:69
    vlTOPp->Vortex__DOT__execute_alu_result = ((8U 
						& (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
					        ? (
						   (4U 
						    & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						    ? 
						   ((2U 
						     & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						     ? vlTOPp->Vortex__DOT__csr_decode_csr_data
						     : 
						    ((1U 
						      & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						      ? vlTOPp->Vortex__DOT__csr_decode_csr_data
						      : 
						     (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__curr_PC 
						      + 
						      (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__upper_immed 
						       << 0xcU))))
						    : 
						   ((2U 
						     & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						      ? 
						     (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__upper_immed 
						      << 0xcU)
						      : 
						     ((vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 
						       >= vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						       ? 0U
						       : 0xffffffffU))
						     : 
						    ((1U 
						      & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						      ? 
						     (vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2 
						      & vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1)
						      : 
						     (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 
						      | vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2))))
					        : (
						   (4U 
						    & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						    ? 
						   ((2U 
						     & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						      ? 
						     ((0x1fU 
						       >= vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						       ? 
						      (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 
						       >> vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						       : 0U)
						      : 
						     ((0x1fU 
						       >= vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						       ? 
						      (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 
						       >> vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						       : 0U))
						     : 
						    ((1U 
						      & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						      ? 
						     (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 
						      ^ vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						      : 
						     ((vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 
						       < vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						       ? 1U
						       : 0U)))
						    : 
						   ((2U 
						     & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						      ? 
						     (VL_LTS_III(1,32,32, vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1, vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						       ? 1U
						       : 0U)
						      : 
						     ((0x1fU 
						       >= vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						       ? 
						      (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 
						       << vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						       : 0U))
						     : 
						    ((1U 
						      & (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__alu_op))
						      ? 
						     (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 
						      - vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)
						      : 
						     (vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd1 
						      + vlTOPp->Vortex__DOT__vx_execute__DOT__ALU_in2)))));
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd 
	= (((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			>> 0x14U)) == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__rd)) 
	     & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				>> 0x14U)))) & (0U 
						!= (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))) 
	   & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd)));
    vlTOPp->Vortex__DOT__forwarding_fwd_stall = (((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd) 
						  | (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd)) 
						 & (2U 
						    == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb)));
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd 
	= (((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			>> 0xfU)) == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__rd)) 
	     & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				>> 0xfU)))) & (0U != (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))) 
	   & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd)));
    vlTOPp->curr_PC = vlTOPp->Vortex__DOT__vx_fetch__DOT__temp_PC;
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_wb_fwd 
	= ((((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			 >> 0x14U)) == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__rd)) 
	      & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				 >> 0x14U)))) & (0U 
						 != (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))) 
	    & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd))) 
	   & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd)));
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling 
	= ((IData)(vlTOPp->Vortex__DOT__forwarding_fwd_stall) 
	   | (IData)(vlTOPp->Vortex__DOT__execute_branch_stall));
    vlTOPp->Vortex__DOT__vx_fetch__DOT__stall = (((
						   (0x63U 
						    == 
						    (0x7fU 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						   | ((0x6fU 
						       == 
						       (0x7fU 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						      | (0x67U 
							 == 
							 (0x7fU 
							  & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)))) 
						  | (IData)(vlTOPp->Vortex__DOT__forwarding_fwd_stall)) 
						 | (IData)(vlTOPp->Vortex__DOT__execute_branch_stall));
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_wb_fwd 
	= ((((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			 >> 0xfU)) == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__rd)) 
	      & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				 >> 0xfU)))) & (0U 
						!= (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))) 
	    & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd))) 
	   & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd)));
    vlTOPp->Vortex__DOT__decode_rd1 = ((0x6fU == (0x7fU 
						  & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
				        ? vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__curr_PC
				        : ((((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd) 
					     | (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd)) 
					    | (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_wb_fwd))
					    ? ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd)
					        ? (
						   (3U 
						    == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb))
						    ? vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__PC_next_out
						    : vlTOPp->Vortex__DOT__execute_alu_result)
					        : ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd)
						    ? 
						   ((3U 
						     == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
						     ? vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__PC_next
						     : 
						    ((2U 
						      == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
						      ? vlTOPp->in_cache_driver_out_data
						      : vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result))
						    : 
						   ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_wb_fwd)
						     ? 
						    ((3U 
						      == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						      ? vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__PC_next
						      : 
						     ((2U 
						       == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						       ? vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__mem_result
						       : vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__alu_result))
						     : 0xdeadbeefU)))
					    : vlTOPp->Vortex__DOT__vx_decode__DOT__vx_register_file__DOT__registers
					   [(0x1fU 
					     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						>> 0xfU))]));
}

VL_INLINE_OPT void VVortex::_sequent__TOP__5(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_sequent__TOP__5\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at VX_f_d_reg.v:26
    vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__valid = (1U 
						   & ((~ 
						       ((IData)(vlTOPp->reset) 
							| (IData)(vlTOPp->Vortex__DOT__forwarding_fwd_stall))) 
						      & (~ (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__stall))));
    // ALWAYS at VX_f_d_reg.v:26
    vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__curr_PC = 
	(((IData)(vlTOPp->reset) | (IData)(vlTOPp->Vortex__DOT__forwarding_fwd_stall))
	  ? 0U : vlTOPp->Vortex__DOT__vx_fetch__DOT__temp_PC);
    // ALWAYS at VX_f_d_reg.v:26
    vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
	= (((IData)(vlTOPp->reset) | (IData)(vlTOPp->Vortex__DOT__forwarding_fwd_stall))
	    ? 0U : ((IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__stall)
		     ? 0U : vlTOPp->fe_instruction));
    // ALWAYS at VX_fetch.v:94
    vlTOPp->Vortex__DOT__vx_fetch__DOT__temp_PC = (
						   ((IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal) 
						    & (~ (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__delay_reg)))
						    ? vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__jal_dest
						    : 
						   (((IData)(vlTOPp->Vortex__DOT__memory_branch_dir) 
						     & (~ (IData)(vlTOPp->Vortex__DOT__vx_fetch__DOT__delay_reg)))
						     ? vlTOPp->Vortex__DOT__memory_branch_dest
						     : vlTOPp->Vortex__DOT__vx_fetch__DOT__PC_to_use));
    vlTOPp->curr_PC = vlTOPp->Vortex__DOT__vx_fetch__DOT__temp_PC;
    vlTOPp->Vortex__DOT__vx_decode__DOT__is_itype = 
	((0x13U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
	 | (3U == (0x7fU & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)));
    vlTOPp->Vortex__DOT__vx_decode__DOT__is_csr = (
						   (0x73U 
						    == 
						    (0x7fU 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						   & (0U 
						      != 
						      (7U 
						       & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							  >> 0xcU))));
    vlTOPp->Vortex__DOT__decode_csr_address = (0xfffU 
					       & (((0U 
						    != 
						    (7U 
						     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							>> 0xcU))) 
						   & (2U 
						      <= 
						      (0xfffU 
						       & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							  >> 0x14U))))
						   ? 
						  (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						   >> 0x14U)
						   : 0x55U));
    // ALWAYS at VX_decode.v:249
    vlTOPp->Vortex__DOT__decode_branch_type = ((0x63U 
						== 
						(0x7fU 
						 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
					        ? (
						   (0x4000U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 
						   ((0x2000U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 
						    ((0x1000U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 6U
						      : 5U)
						     : 
						    ((0x1000U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 4U
						      : 3U))
						    : 
						   ((0x2000U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 0U
						     : 
						    ((0x1000U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 2U
						      : 1U)))
					        : 0U);
    vlTOPp->Vortex__DOT__vx_decode__DOT__alu_tempp 
	= (0xfffU & (((1U == (7U & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				    >> 0xcU))) | (5U 
						  == 
						  (7U 
						   & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						      >> 0xcU))))
		      ? (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				  >> 0x14U)) : (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						>> 0x14U)));
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd 
	= ((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
		       >> 0x14U)) == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd)) 
	    & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			       >> 0x14U)))) & (0U != (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb)));
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd 
	= ((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
		       >> 0xfU)) == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__rd)) 
	    & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			       >> 0xfU)))) & (0U != (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb)));
    // ALWAYS at VX_decode.v:238
    vlTOPp->Vortex__DOT__decode_itype_immed = ((0x40U 
						& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
					        ? (
						   (0x20U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 
						   ((0x10U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 0xdeadbeefU
						     : 
						    ((8U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 0xdeadbeefU
						      : 
						     ((4U 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						       ? 0xdeadbeefU
						       : 
						      ((2U 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						        ? 
						       ((1U 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
							 ? 
							((0xfffff000U 
							  & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
										>> 0x1fU)))) 
							     << 0xcU)) 
							 | ((0x800U 
							     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								>> 0x14U)) 
							    | ((0x400U 
								& (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								   << 3U)) 
							       | ((0x3f0U 
								   & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								      >> 0x15U)) 
								  | (0xfU 
								     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
									>> 8U))))))
							 : 0xdeadbeefU)
						        : 0xdeadbeefU))))
						    : 0xdeadbeefU)
					        : (
						   (0x20U 
						    & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						    ? 
						   ((0x10U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 0xdeadbeefU
						     : 
						    ((8U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 0xdeadbeefU
						      : 
						     ((4U 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						       ? 0xdeadbeefU
						       : 
						      ((2U 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						        ? 
						       ((1U 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
							 ? 
							((0xfffff000U 
							  & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
										>> 0x1fU)))) 
							     << 0xcU)) 
							 | ((0xfe0U 
							     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								>> 0x14U)) 
							    | (0x1fU 
							       & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
								  >> 7U))))
							 : 0xdeadbeefU)
						        : 0xdeadbeefU))))
						    : 
						   ((0x10U 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						     ? 
						    ((8U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 0xdeadbeefU
						      : 
						     ((4U 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						       ? 0xdeadbeefU
						       : 
						      ((2U 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						        ? 
						       ((1U 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
							 ? 
							((0xfffff000U 
							  & (VL_NEGATE_I((IData)(
										(1U 
										& ((IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__alu_tempp) 
										>> 0xbU)))) 
							     << 0xcU)) 
							 | (IData)(vlTOPp->Vortex__DOT__vx_decode__DOT__alu_tempp))
							 : 0xdeadbeefU)
						        : 0xdeadbeefU)))
						     : 
						    ((8U 
						      & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						      ? 0xdeadbeefU
						      : 
						     ((4U 
						       & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						       ? 0xdeadbeefU
						       : 
						      ((2U 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
						        ? 
						       ((1U 
							 & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)
							 ? 
							((0xfffff000U 
							  & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
										>> 0x1fU)))) 
							     << 0xcU)) 
							 | (0xfffU 
							    & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
							       >> 0x14U)))
							 : 0xdeadbeefU)
						        : 0xdeadbeefU))))));
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd 
	= (((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			>> 0x14U)) == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__rd)) 
	     & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				>> 0x14U)))) & (0U 
						!= (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))) 
	   & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd)));
    vlTOPp->Vortex__DOT__forwarding_fwd_stall = (((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd) 
						  | (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd)) 
						 & (2U 
						    == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb)));
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd 
	= (((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			>> 0xfU)) == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__rd)) 
	     & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				>> 0xfU)))) & (0U != (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))) 
	   & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd)));
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_wb_fwd 
	= ((((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			 >> 0x14U)) == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__rd)) 
	      & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				 >> 0x14U)))) & (0U 
						 != (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))) 
	    & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd))) 
	   & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd)));
    vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__stalling 
	= ((IData)(vlTOPp->Vortex__DOT__forwarding_fwd_stall) 
	   | (IData)(vlTOPp->Vortex__DOT__execute_branch_stall));
    vlTOPp->Vortex__DOT__vx_fetch__DOT__stall = (((
						   (0x63U 
						    == 
						    (0x7fU 
						     & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						   | ((0x6fU 
						       == 
						       (0x7fU 
							& vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)) 
						      | (0x67U 
							 == 
							 (0x7fU 
							  & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction)))) 
						  | (IData)(vlTOPp->Vortex__DOT__forwarding_fwd_stall)) 
						 | (IData)(vlTOPp->Vortex__DOT__execute_branch_stall));
    vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_wb_fwd 
	= ((((((0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
			 >> 0xfU)) == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__rd)) 
	      & (0U != (0x1fU & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
				 >> 0xfU)))) & (0U 
						!= (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))) 
	    & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd))) 
	   & (~ (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd)));
}

VL_INLINE_OPT void VVortex::_combo__TOP__6(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_combo__TOP__6\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Vortex__DOT__decode_rd1 = ((0x6fU == (0x7fU 
						  & vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction))
				        ? vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__curr_PC
				        : ((((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd) 
					     | (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd)) 
					    | (IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_wb_fwd))
					    ? ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd)
					        ? (
						   (3U 
						    == (IData)(vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__wb))
						    ? vlTOPp->Vortex__DOT__vx_d_e_reg__DOT__PC_next_out
						    : vlTOPp->Vortex__DOT__execute_alu_result)
					        : ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd)
						    ? 
						   ((3U 
						     == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
						     ? vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__PC_next
						     : 
						    ((2U 
						      == (IData)(vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__wb))
						      ? vlTOPp->in_cache_driver_out_data
						      : vlTOPp->Vortex__DOT__vx_e_m_reg__DOT__alu_result))
						    : 
						   ((IData)(vlTOPp->Vortex__DOT__vx_forwarding__DOT__src1_wb_fwd)
						     ? 
						    ((3U 
						      == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						      ? vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__PC_next
						      : 
						     ((2U 
						       == (IData)(vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__wb))
						       ? vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__mem_result
						       : vlTOPp->Vortex__DOT__vx_m_w_reg__DOT__alu_result))
						     : 0xdeadbeefU)))
					    : vlTOPp->Vortex__DOT__vx_decode__DOT__vx_register_file__DOT__registers
					   [(0x1fU 
					     & (vlTOPp->Vortex__DOT__vx_f_d_reg__DOT__instruction 
						>> 0xfU))]));
}

void VVortex::_eval(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_eval\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
	vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    vlTOPp->_combo__TOP__6(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void VVortex::_eval_initial(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_eval_initial\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
    vlTOPp->_initial__TOP__3(vlSymsp);
}

void VVortex::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::final\n"); );
    // Variables
    VVortex__Syms* __restrict vlSymsp = this->__VlSymsp;
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VVortex::_eval_settle(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_eval_settle\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
}

VL_INLINE_OPT QData VVortex::_change_request(VVortex__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_change_request\n"); );
    VVortex* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VVortex::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
	Verilated::overWidthError("reset");}
}
#endif // VL_DEBUG

void VVortex::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VVortex::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    fe_instruction = VL_RAND_RESET_I(32);
    in_cache_driver_out_data = VL_RAND_RESET_I(32);
    curr_PC = VL_RAND_RESET_I(32);
    out_cache_driver_in_address = VL_RAND_RESET_I(32);
    out_cache_driver_in_mem_read = VL_RAND_RESET_I(3);
    out_cache_driver_in_mem_write = VL_RAND_RESET_I(3);
    out_cache_driver_in_data = VL_RAND_RESET_I(32);
    Vortex__DOT__decode_csr_address = VL_RAND_RESET_I(12);
    Vortex__DOT__decode_rd1 = VL_RAND_RESET_I(32);
    Vortex__DOT__decode_itype_immed = VL_RAND_RESET_I(32);
    Vortex__DOT__decode_branch_type = VL_RAND_RESET_I(3);
    Vortex__DOT__execute_branch_stall = VL_RAND_RESET_I(1);
    Vortex__DOT__execute_alu_result = VL_RAND_RESET_I(32);
    Vortex__DOT__memory_branch_dir = VL_RAND_RESET_I(1);
    Vortex__DOT__memory_branch_dest = VL_RAND_RESET_I(32);
    Vortex__DOT__csr_decode_csr_data = VL_RAND_RESET_I(32);
    Vortex__DOT__forwarding_fwd_stall = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_fetch__DOT__stall_reg = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_fetch__DOT__delay_reg = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_fetch__DOT__old = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_fetch__DOT__state = VL_RAND_RESET_I(5);
    Vortex__DOT__vx_fetch__DOT__real_PC = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_fetch__DOT__JAL_reg = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_fetch__DOT__BR_reg = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_fetch__DOT__prev_debug = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_fetch__DOT__PC_to_use = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_fetch__DOT__stall = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_fetch__DOT__temp_PC = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_f_d_reg__DOT__instruction = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_f_d_reg__DOT__curr_PC = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_f_d_reg__DOT__valid = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_decode__DOT__is_itype = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_decode__DOT__is_csr = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_decode__DOT__alu_tempp = VL_RAND_RESET_I(12);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    Vortex__DOT__vx_decode__DOT__vx_register_file__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Vortex__DOT__vx_d_e_reg__DOT__rd = VL_RAND_RESET_I(5);
    Vortex__DOT__vx_d_e_reg__DOT__rd1 = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_d_e_reg__DOT__rd2 = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_d_e_reg__DOT__alu_op = VL_RAND_RESET_I(4);
    Vortex__DOT__vx_d_e_reg__DOT__wb = VL_RAND_RESET_I(2);
    Vortex__DOT__vx_d_e_reg__DOT__PC_next_out = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_d_e_reg__DOT__rs2_src = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_d_e_reg__DOT__itype_immed = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_d_e_reg__DOT__mem_read = VL_RAND_RESET_I(3);
    Vortex__DOT__vx_d_e_reg__DOT__mem_write = VL_RAND_RESET_I(3);
    Vortex__DOT__vx_d_e_reg__DOT__branch_type = VL_RAND_RESET_I(3);
    Vortex__DOT__vx_d_e_reg__DOT__upper_immed = VL_RAND_RESET_I(20);
    Vortex__DOT__vx_d_e_reg__DOT__csr_address = VL_RAND_RESET_I(12);
    Vortex__DOT__vx_d_e_reg__DOT__is_csr = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_d_e_reg__DOT__csr_mask = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_d_e_reg__DOT__curr_PC = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_d_e_reg__DOT__jal = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_d_e_reg__DOT__jal_offset = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_d_e_reg__DOT__valid = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_d_e_reg__DOT__stalling = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_execute__DOT__ALU_in2 = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_e_m_reg__DOT__alu_result = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_e_m_reg__DOT__rd = VL_RAND_RESET_I(5);
    Vortex__DOT__vx_e_m_reg__DOT__rd2 = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_e_m_reg__DOT__wb = VL_RAND_RESET_I(2);
    Vortex__DOT__vx_e_m_reg__DOT__PC_next = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_e_m_reg__DOT__mem_read = VL_RAND_RESET_I(3);
    Vortex__DOT__vx_e_m_reg__DOT__mem_write = VL_RAND_RESET_I(3);
    Vortex__DOT__vx_e_m_reg__DOT__csr_address = VL_RAND_RESET_I(12);
    Vortex__DOT__vx_e_m_reg__DOT__is_csr = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_e_m_reg__DOT__csr_result = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_e_m_reg__DOT__curr_PC = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_e_m_reg__DOT__branch_offset = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_e_m_reg__DOT__branch_type = VL_RAND_RESET_I(3);
    Vortex__DOT__vx_e_m_reg__DOT__jal = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_e_m_reg__DOT__jal_dest = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_e_m_reg__DOT__valid = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_m_w_reg__DOT__alu_result = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_m_w_reg__DOT__mem_result = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_m_w_reg__DOT__rd = VL_RAND_RESET_I(5);
    Vortex__DOT__vx_m_w_reg__DOT__wb = VL_RAND_RESET_I(2);
    Vortex__DOT__vx_m_w_reg__DOT__PC_next = VL_RAND_RESET_I(32);
    Vortex__DOT__vx_m_w_reg__DOT__valid = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_forwarding__DOT__src1_exe_fwd = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_forwarding__DOT__src1_mem_fwd = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_forwarding__DOT__src1_wb_fwd = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_forwarding__DOT__src2_exe_fwd = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_forwarding__DOT__src2_mem_fwd = VL_RAND_RESET_I(1);
    Vortex__DOT__vx_forwarding__DOT__src2_wb_fwd = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<4096; ++__Vi0) {
	    Vortex__DOT__vx_csr_handler__DOT__csr[__Vi0] = VL_RAND_RESET_I(12);
    }}
    Vortex__DOT__vx_csr_handler__DOT__cycle = VL_RAND_RESET_Q(64);
    Vortex__DOT__vx_csr_handler__DOT__instret = VL_RAND_RESET_Q(64);
    Vortex__DOT__vx_csr_handler__DOT__decode_csr_address = VL_RAND_RESET_I(12);
}