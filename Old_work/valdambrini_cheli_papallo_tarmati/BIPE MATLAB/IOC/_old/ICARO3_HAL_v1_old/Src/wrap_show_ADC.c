#include "rtwtypes.h"
#include "stm32f4_custom_USART.h"
#include <cstdio>

void wrap_show_ADC_start_fcn()
{
}

void wrap_show_ADC_output_fcn(uint32_T* input)
{
    char s[20];
    
    sprintf(s, "Ch1:%lu\0", input[0]);
    for(uint8_t i = 0; s[i] != '\0'; i++)
        USART3_Send(s[i]);
    USART3_Send(0x0D);

    sprintf(s, "Ch2:%lu\0", input[1]);
    for(uint8_t i = 0; s[i] != '\0'; i++)
        USART3_Send(s[i]);
    USART3_Send(0x0D);

     sprintf(s, "Ch3:%lu\0", input[2]);
    for(uint8_t i = 0; s[i] != '\0'; i++)
        USART3_Send(s[i]);
    USART3_Send(0x0D);

    sprintf(s, "Ch4:%lu\0", input[3]);
    for(uint8_t i = 0; s[i] != '\0'; i++)
        USART3_Send(s[i]);
    USART3_Send(0x0D);
}
