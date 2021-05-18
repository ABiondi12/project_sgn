#include "stm32f4_custom_USART.h"
#include "rtwtypes.h"
//configure to use USART 2    
#define sonar_recv(PAR)  USART2_Receive(PAR)
#define sonar_send(PAR)  USART2_Send(PAR)

//#define i_uint16            uint16_t
//#define i_int32             int32_t


uint8_T ID = 0x00;
uint16_T Range;
uint16_T Data[2];
int offset;
int first_range_received;
int first_range_requested;
int counter;


void wrap_srf02_start_fcn()
{
	 // Invio la prima richiesta di range
	 first_range_received = 0;
	 first_range_requested = 1;
	 sonar_send((uint8_T)ID);
	 sonar_send((uint8_T)0x54);
	counter = 0;
	offset = 0;

}


void wrap_srf02_output_fcn(double* aroutput, double* newpacket)
{
	// Continuo ad inviare la prima richiesta di range ad ogni passo fino a quando non arrva la prima coppia di byte
	// Il flag first_range_requested = 1 indica che è stata inviata una richiesta di range a questo passo.La nuova richiesta è inviata solo
    //quando flag first_range_requested = 0 il quale viene posto a 0 ogni 10ms.
	if (first_range_received == 0) {
        if (first_range_requested == 0) {
					sonar_send((uint8_T)ID);
					sonar_send((uint8_T)0x54);
					first_range_requested = 1;
					counter = 0;
        } else {
            counter ++;
                    
            if (counter == 10)
            {
               first_range_requested = 0;
            }
        }        
    }
           
   // set newpacket output to 0 for now, parse() will set it to 1 if a valid packet was received
   newpacket[0] = 0;
    
    //Variabile di appoggio per il byte estrayyo
	unsigned char byte;

	//Variaible che mi tiene conto di quanti byte del payload sono arrivati
	//int offset = 0;
    
    while (sonar_recv(&byte))
    {

			if (offset<2){ 
				Data[offset] = byte;
				offset++;
			}
			
			if (offset==2){ 
				
				offset = 0;
				first_range_received = 1;
				
				// Dopo aver ricevuto entrambi i byte del range invio una nuova richiesta
			  sonar_send((uint8_T)ID);
	      sonar_send((uint8_T)0x54);
				
				// Il primo byte ricevuto è quello più significativo. Ricompongo il pacchetto e converto da cm in m
				Range = (0x00FF & Data[1])|(0xFF00 & (Data[0]<<8));
				newpacket[0] = 1;
				
        aroutput[0] = ((double)Range)/100.0;
				
				
			}
			
			break;
			
		                         
    }
}
