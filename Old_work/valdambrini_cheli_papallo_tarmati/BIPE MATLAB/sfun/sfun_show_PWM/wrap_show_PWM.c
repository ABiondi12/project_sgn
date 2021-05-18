#include "rtwtypes.h"
#include "stm32f4_custom_USART.h"
#include <cstdio>
#define DEBUG

void wrap_show_PWM_start_fcn()
{	
    //Here goes USARTx initialization IF USARTS aren't initialized in Simulink
}

void wrap_show_PWM_output_fcn(uint16_T* input_duty, uint16_T* input_ton, uint16_T* input_freq) {
    
        char s[200];
		double duty = input_duty[0]/100.0;
        double TOn = input_ton[0]/1000.0;
		double freq = input_freq[0]/100.0;
	
        sprintf(s, "Duty: %lf;T-On: %lf;Freq: %lf;\n", duty, TOn, freq);

        for (uint8_t i = 0; s[i] != '\0'; i++)
            USART3_Send(s[i]);
        USART3_Send(0x0D); //Break the line.
}
