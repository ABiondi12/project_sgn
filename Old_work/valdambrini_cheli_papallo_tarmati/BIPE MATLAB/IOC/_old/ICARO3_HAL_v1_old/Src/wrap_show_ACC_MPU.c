#include "rtwtypes.h"
#include "stm32f4_custom_USART.h"
#include <cstdio>
#define I2C1_SENSORS_TEST

void wrap_show_ACC_MPU_start_fcn()
{
}

void wrap_show_ACC_MPU_output_fcn(real_T* input)
{
#ifdef I2C1_SENSORS_TEST
    char s[100];
    sprintf(s, "Acc MPU:%f,%f,%f;", input[0], input[1], input[2]);
    for (uint8_t i = 0; s[i] != '\0'; i++)
        {
            USART3_Send(s[i]);
        }
    USART3_Send(0x0D);
#endif
}
