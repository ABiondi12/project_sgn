#include "rtwtypes.h"
#include "stm32f4_custom_USART.h"
#include <cstdio>
#define DEBUG

void wrap_show_arduino_start_fcn()
{	
    //Here goes USARTx initialization IF USARTS aren't initialized in Simulink
}

void wrap_show_arduino_output_fcn(uint32_T* input_id, int32_T* input_x, int32_T* input_y, int8_t* input_dx, int8_t* input_dy, uint8_t* input_squal) {
    
    char s[300];
    uint32_t id = input_id[0];
    int32_t x = input_x[0];
    int32_t y = input_y[0];
    int8_t dx = input_dx[0];
    int8_t dy = input_dy[0];
    uint8_t squal = input_squal[0];
	
    if (id != 0) {
			sprintf(s, "Id: %d; X: %d; Y: %d; DX: %d; DY: %d; SQUAL: %d;\n", id, x, y, dx, dy, squal);

			for (uint8_t i = 0; s[i] != '\0'; i++)
					USART3_Send(s[i]);
			
		}
}
