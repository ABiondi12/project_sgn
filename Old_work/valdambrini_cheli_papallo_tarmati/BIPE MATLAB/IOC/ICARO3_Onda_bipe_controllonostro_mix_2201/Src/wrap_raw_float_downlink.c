#include "rtwtypes.h"
//#include "drv_sciatx.h"

#include "circular_buffer.h"

#define telemetry_send(PAR) USART3_Send(PAR)
#define __byte(POINTER, DELTA) (((unsigned char*)POINTER)[DELTA])

void wrap_raw_float_downlink_start_fcn()
{
   //USART3_Init();
}

void wrap_raw_float_downlink_output_width_fcn(float* input, uint8_T width)
{
    char i = 0;
    static unsigned int temp_prova_prescaler = 100;
    
    telemetry_send((unsigned char)'B');
    telemetry_send((unsigned char)'B');
  
    for (i = 0; i < width; i++)
    {
        int *temp=(int *)&(input[i]);
       telemetry_send((uint8_T)__byte(temp,0));
       telemetry_send((uint8_T)__byte(temp,1));
       telemetry_send((uint8_T)__byte(temp,2));
       telemetry_send((uint8_T)__byte(temp,3));
    }
    
    
//     drv_scia_send((unsigned char)'B');
//     drv_scia_send((unsigned char)'B');
//     
//     
//     /*temp_prova_prescaler--;
//     if (temp_prova_prescaler==0) {
//         temp_prova_prescaler= 100;
//         drv_scia_send((unsigned char)'*');
//         
//         
//     }*/
//     
//     for (i = 0; i < width; i++)
//     {
//         int *temp=(int *)&(input[i]);
//         drv_scia_send((uint8_T)__byte(temp,0));
//         drv_scia_send((uint8_T)__byte(temp,1));
//         drv_scia_send((uint8_T)__byte(temp,2));
//         drv_scia_send((uint8_T)__byte(temp,3));
//     }
}
