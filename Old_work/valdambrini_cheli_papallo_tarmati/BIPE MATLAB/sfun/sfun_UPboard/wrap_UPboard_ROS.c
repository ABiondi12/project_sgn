
#include "stm32f4_custom_USART.h"
//configure to use USART 5  
//#include <string>
#include <stdio.h>
#include <cstdlib>
#include "stm32f4_LED_debug.h"


#define upboard_recv(PAR)  USART3_Receive(PAR) //cambiato usart da 5 a 3
#define i_uint16            uint16_t
#define i_int32             int32_t

#define HEADER_A     (unsigned char) 0x1A
#define HEADER_B     (unsigned char) 0x1B
#define PAYLOAD_POSE (unsigned char) 0x2C


#define  DIM_ARRAY              28 
#define  DIM_MSG                27 
#define  NUM_CHARS_SIX_NUMBERS  24 

#define ELEMENT_Work 27


typedef enum{
	START,
    HEADER_1_ARRIVED,
    HEADER_2_ARRIVED,
    ID_ARRIVED,
    WAIT_PAYLOAD,
    PAYLOAD_ARRIVED,
} STATES;

STATES state=START;
int    offset=0;
 
//std::string string_position_orientation;
//std::string string_to_decode;

unsigned char string_position_orientation[28];
unsigned char string_to_decode[28];


void parser_msg_and_change_state(unsigned char);
float decode_payload(unsigned char* );

void wrap_UPboard_start_fcn()
{
  LED_OnOff(LED_ArancionePin, 1);   
 memset(&string_position_orientation[0], 0, sizeof(string_position_orientation));
 memset(&string_to_decode[0], 0, sizeof(string_to_decode));
	
}



void parser_msg_and_change_state(unsigned char c ){
	
    switch(state){
		
	  case START:
		    offset=0;
		      LED_OnOff( LED_RossoPin, 1);//DEBUG
            memset(&string_position_orientation[0], 0, sizeof(string_position_orientation));
            if(c == HEADER_A)
            {
                state=HEADER_1_ARRIVED;
            }else
            {
	        
                state=START;
            }
            break;		
				
        case HEADER_1_ARRIVED:
            if(c == HEADER_B)
            {
                state=HEADER_2_ARRIVED;
            }else
            {
		
                state=START;
            }
            break;

        case HEADER_2_ARRIVED:
            if(c == PAYLOAD_POSE)
            {
                state=ID_ARRIVED;
     
            }
            else
            {
	
                state=START;
            }
            break;

        case ID_ARRIVED:
            //string_position_orientation.clear();
            memset(&string_position_orientation[0], 0, sizeof(string_position_orientation));
            //string_position_orientation+=c;
            string_position_orientation[offset]=c;
            offset=1;
            state=WAIT_PAYLOAD;
           
            break;

        case WAIT_PAYLOAD:
            if(offset<NUM_CHARS_SIX_NUMBERS)
                {
                    //string_position_orientation+=c;
                string_position_orientation[offset]=c;
                
                    state=WAIT_PAYLOAD;
                    offset++;
               		   
                }
            else if(offset==NUM_CHARS_SIX_NUMBERS)
                {
                    offset=0;
                    state=PAYLOAD_ARRIVED;
               		
                }
            else{
				
			}    
                
            break;
    }	
		
}	



//main
void wrap_UPboard_output_fcn(double* aroutput, double* newpacket)
{
    //Variabile di appoggio per il byte estrayyo
	unsigned char byte;
	

	//Variabile che mi tiene conto di quanti byte del payload sono arrivati
	//int offset = Work[2];
    upboard_recv(&byte);
    parser_msg_and_change_state(byte);
    if(state==PAYLOAD_ARRIVED){
                 LED_OnOff( LED_RossoPin, 0);//DEBUG//DEBUG
                aroutput[0] =(double)decode_payload(&string_position_orientation[0]);
                aroutput[1] =(double)decode_payload(&string_position_orientation[4]);
                aroutput[2] =(double)decode_payload(&string_position_orientation[8]);
                aroutput[3] =(double)decode_payload(&string_position_orientation[12]);
                aroutput[4] =(double)decode_payload(&string_position_orientation[16]);
                aroutput[5] =(double)decode_payload(&string_position_orientation[20]);
               
                state=START;
    }                
}

//float  decode_payload(std::string sn)
float  decode_payload(unsigned char* sn)
{
    union D{
		 char   s[4];
		 float  a;
	} d;
   	
     d.s[0]='\0';d.s[1]='\0';d.s[2]='\0';d.s[3]='\0';      
     d.s[0]=sn[0];d.s[1]=sn[1];d.s[2]=sn[2];d.s[3]=sn[3];
    
    return d.a;
}



