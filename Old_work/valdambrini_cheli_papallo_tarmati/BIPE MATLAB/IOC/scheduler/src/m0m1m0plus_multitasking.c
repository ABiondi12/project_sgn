
#include "mw_force_no_optimization.h"
#include "arm_cortex_m_multitasking.h"
/* Re-entrant function for multi-tasking: arm_cortex_m_call_thread_with_context_switch*/

__attribute__ ((naked)) void arm_cortex_m_call_thread_with_context_switch(void (* isr_routine_ptr)(void)) {
     __asm volatile ("     push {r0, r1}");
     __asm volatile ("     SUB SP, SP, #0x20");
     __asm volatile ("     ADR R0,Call_isr_routine_in_thread_mode");
     __asm volatile ("     NOP");
     __asm volatile ("     STR R0,[SP, #24]");
     __asm volatile ("     MOV R0,#0x01");
     __asm volatile ("     LSL R0,#24");
     __asm volatile ("     STR R0,[SP, #28]");
     __asm volatile ("     MOV R0,#0x6");
     __asm volatile ("     mvn r0, r0");
     __asm volatile ("     MOV LR, R0");
     __asm volatile ("     BX LR");
     __asm volatile ("Call_isr_routine_in_thread_mode:");
     __asm volatile ("     pop {r0, r1}");
     __asm volatile ("     BLX R0");
     __asm volatile ("     ISB");
     __asm volatile ("     SVC #0");
     __asm volatile ("Unknown_Execution:");
     __asm volatile ("     B Unknown_Execution");
}
/* SVC Interrupt service routine to restore the context: SVC_Handler*/

__attribute__ ((naked)) void SVC_Handler(void) {
     __asm volatile ("     MOVS r0, #0x4");
     __asm volatile ("     MOV r1, LR");
     __asm volatile ("     TST r0, r1");
     __asm volatile ("     BEQ stack_used_msp");
     __asm volatile ("     MRS R0, PSP");
     __asm volatile ("     B get_service_request");
     __asm volatile ("stack_used_msp:");
     __asm volatile ("     MRS R0, MSP");
     __asm volatile ("get_service_request:");
     __asm volatile ("     LDR R1, [R0, #24]");
     __asm volatile ("     SUB R1, R1, #0x2");
     __asm volatile ("     LDRB R0, [R1]");
     __asm volatile ("     CMP R0, #0");
     __asm volatile ("     BEQ svc_service_0");
     __asm volatile ("     B Unknown_SVC_Request");
     __asm volatile ("svc_service_0:");
     __asm volatile ("     ADD SP, SP, #32");
     __asm volatile ("     POP {R0, R1}");
     __asm volatile ("     MSR APSR_nzcvq, R0");
     __asm volatile ("     BX R1");
     __asm volatile ("Unknown_SVC_Request:");
     __asm volatile ("     B Unknown_SVC_Request");
}
