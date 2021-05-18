#include "rtwtypes.h"
#include "stm32f4_custom_USART.h"

void wrap_USART4_Sendbyte_start_fcn()
{
}

void wrap_USART4_Sendbyte_output_fcn(uint8_t* byte_to_send)
{
    USART4_Send((unsigned char)byte_to_send[0]);
}

