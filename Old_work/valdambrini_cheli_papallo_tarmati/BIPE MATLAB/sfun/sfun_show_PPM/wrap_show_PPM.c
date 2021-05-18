#include "rtwtypes.h"
#include "stm32f4_custom_USART.h"
#include <cstdio>
#define DEBUG

void wrap_show_PPM_start_fcn()
{	
    //Here goes USARTx initialization IF USARTS aren't initialized in Simulink
}

void wrap_show_PPM_output_fcn(uint32_T* input, uint8_T* input2) {
    if (input2[0] == 1) // input2[0] is the New Message Flag
    {
#ifdef DEBUG
        char s[200];
        sprintf(s, "%lu\n%lu\n%lu\n%lu\n%lu\n%lu\n%lu\n%lu\n%lu",
               (unsigned long) input[0], (unsigned long) input[1], (unsigned long) input[2],
               (unsigned long) input[3], (unsigned long) input[4], (unsigned long) input[5],
               (unsigned long) input[6], (unsigned long) input[7], (unsigned long) input[8]);

        for (uint8_t i = 0; s[i] != '\0'; i++)
            USART3_Send(s[i]);
        USART3_Send(0x0D); //Break the line.
#endif
    }
    else
    {}
}
