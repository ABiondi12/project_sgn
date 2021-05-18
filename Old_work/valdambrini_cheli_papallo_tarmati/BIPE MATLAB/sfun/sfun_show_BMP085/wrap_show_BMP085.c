#include "rtwtypes.h"
#include "stm32f4_custom_USART.h"
#include <cstdio>
//#define I2C1_SENSORS_TEST

void wrap_show_BMP085_start_fcn()
{
}

void wrap_show_BMP085_output_fcn(real_T* input)
{
#ifdef I2C1_SENSORS_TEST
    char s[20];
    sprintf(s, "Temp:%f", input[0]);
    for(uint8_t i = 0; s[i] != '\0'; i++)
        {
            USART3_Send(s[i]);
        }
    USART3_Send(0x0D);
    sprintf(s, "Alt:%f", input[1]);
    for(uint8_t i = 0; s[i] != '\0'; i++)
        {
            USART3_Send(s[i]);
        }
    USART3_Send(0x0D);
#endif
}
