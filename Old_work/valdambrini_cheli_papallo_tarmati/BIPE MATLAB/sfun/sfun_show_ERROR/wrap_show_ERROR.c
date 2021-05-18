#include "rtwtypes.h"
#include "stm32f4_custom_USART.h"
#include <cstdio>
//#define I2C1_SENSORS_TEST

void wrap_show_ERROR_start_fcn()
{
}

void wrap_show_ERROR_output_fcn(uint8_T* input1, uint8_T* input2, uint8_T* input3)
{
#ifdef I2C1_SENSORS_TEST

    USART3_Send(0x0D);
    char s1[10];
    // Sensor Enabled:
    sprintf(s1, "Sensors_Enabled:");
    for (uint8_t i = 0; s1[i] != '\0'; i++)
        {
            USART3_Send(s1[i]);
        }
    USART3_Send(input1[0]); USART3_Send('.');
    USART3_Send(input1[1]); USART3_Send('.');
    USART3_Send(input1[2]); USART3_Send('.');
    USART3_Send(input1[3]); USART3_Send(0x0D);

    char s2[10];
    // Error Counter:
    sprintf(s2, "Error_Counters:");
    for (uint8_t i = 0; s2[i] != '\0'; i++)
    {
        USART3_Send(s2[i]);
    }
    USART3_Send(input2[0]); USART3_Send('.');
    USART3_Send(input2[1]); USART3_Send('.');
    USART3_Send(input2[2]); USART3_Send('.');
    USART3_Send(input2[3]); USART3_Send(0x0D);

    char s3[10];
    // HAL Error Status:
    sprintf(s3, "HAL_Error_Status:");
    for (uint8_t i = 0; s3[i] != '\0'; i++)
    {
        USART3_Send(s3[i]);
    }
    USART3_Send(input3[0]); USART3_Send(0x0D);
#endif
}
