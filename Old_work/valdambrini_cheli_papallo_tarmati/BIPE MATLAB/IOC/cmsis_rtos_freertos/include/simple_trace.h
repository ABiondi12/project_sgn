extern void trace_send_via_USART(char byte_to_send);
extern void start_TIM2();

#define traceSTART() start_TIM2();
#define traceTASK_SWITCHED_IN() trace_send_via_USART(pxCurrentTCB->pcTaskName[0]);
//#define traceTASK_SWITCHED_OUT() trace_send_via_USART((char)((pxCurrentTCB->pcTaskName[0])+32));
#define trace_BLOCKING_ON_QUEUE_RECEIVE();
