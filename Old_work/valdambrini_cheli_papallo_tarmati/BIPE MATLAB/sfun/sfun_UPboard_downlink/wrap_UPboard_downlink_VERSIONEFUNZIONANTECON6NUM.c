#include "rtwtypes.h"
#include "circular_buffer.h"

#define telemetry_send(PAR) USART3_Send(PAR) 
#define __byte(POINTER, DELTA) (((unsigned char*)POINTER)[DELTA])

void wrap_UPboard_downlink_start_fcn()
{
   //USART3_Init();
}

 //Original function
/*void wrap_UPboard_downlink_output_width_fcn(float* input, uint8_T width)
{
    char i = 0;
    telemetry_send((uint8_T)0x1A);
    telemetry_send((uint8_T)0x1B);
    telemetry_send((uint8_T)0x2C);  //aggiunta
	int32_t data;
	for (i = 0; i < width; i++)
	{
        
		data = input[i];
		int32_t *temp=(int32_t *)&(data);
       telemetry_send((uint8_T)__byte(temp,0));
       telemetry_send((uint8_T)__byte(temp,1));
       telemetry_send((uint8_T)__byte(temp,2));
       telemetry_send((uint8_T)__byte(temp,3));
	}

}

*/
//Modify function
void wrap_UPboard_downlink_output_width_fcn(float* input, uint8_T width)
{
    union DATA{
      char  s[4];
      float n;
    };
    union DATA d;
    
    char i = 0;
    telemetry_send((uint8_T)0x1A);
    telemetry_send((uint8_T)0x1B);
    telemetry_send((uint8_T)0x2C);  //aggiunta
	int32_t data;
	for (i = 0; i < width; i++)
	{
        
		d.n   = input[i];
	
       telemetry_send(d.s[0]);
       telemetry_send(d.s[1]);
       telemetry_send(d.s[2]);
       telemetry_send(d.s[3]);
	}

}

