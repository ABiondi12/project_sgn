#include "rtwtypes.h"
#include "stm32f4_custom_USART.h"
#include <cstdio>

void wrap_show_GPS_start_fcn()
{
}

void wrap_show_GPS_output_fcn(real_T* input)
{
    char s[100];
    sprintf(s, "lat:%f lon:%f alt:%f ", input[0], input[1], input[8]);
    for(uint8_t i = 0; s[i] != '\0'; i++)
        USART3_Send(s[i]);
}
