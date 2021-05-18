//++++++++++++++++++++++++++++
//.h Custom Includes
//++++++++++++++++++++++++++++
#include <math.h>

#include "stm32f4_custom_USART.h"
#include "timed_buffer.h"

// definizione del numero di agenti
#define number_agent 10
// definizione del tempo di arrivo del segnale PPS (in ms)
#define frame_PPS 1000
// definizione della suddivisione del frame_PPS
#define frequency_time_frame 5
#define time_slot_0 0
#define time_slot_1 1
#define time_slot_2 2
#define time_slot_3 3
#define time_slot_4 4
#define time_slot_5 5
#define time_slot_6 6
#define time_slot_7 7
#define time_slot_8 8
#define time_slot_9 9

static uint8_t time_frame_duration;
static uint8_t time_slot_duration;
static uint8_t limit_byte_sent;
static int previous_time_slot;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//mdlStart Wrapper Function Definition
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void wrap_synchronize_send_start_fcn()
{
   // definizione della durata di un time frame
   time_frame_duration=frame_PPS/frequency_time_frame;
   // definizione della durata di un time slot
   time_slot_duration=time_frame_duration/number_agent;
   // limite di caratteri inviabili in un time slot
   // il 6 indica i caratteri massimi inviabili in 1ms
   // il -10 è una costante cautelativa
   limit_byte_sent=time_slot_duration*6-10;
   previous_time_slot=-1;
   
   
   limit_byte_sent=limit_byte_sent*0.9;
   
}

void wrap_synchronize_send_output_fcn(double* input)
{   
	//input[0] è la variabile contatore che tiene memoria del tempo trascorso
	//input[0] si incrementa di 1 ogni 1ms
	//dalla varaibile input[0] si calcola il numero del time frame corrente
	int n_time_frame=input[0]/time_frame_duration;
	//dal numero del time frame corrente si calcola la costante offset_time_slot, 
	// necessaria per il calcolo del numero del time slot corrente.
	// il numero del time slot corrente deve essere indipendente dal numero del time frame.
	// offset_time_slot=0 per il n_time_frame0
	// offset_time_slot=numero agenti per il n_time_frame1
	// offset_time_slot=2*numero agenti per il n_time_frame2
	// ecc
	int offset_time_slot=n_time_frame*number_agent;
	// dalla variabile input[0] e dalla costante precedemente calcolata si può calcolare il time slot corrente.
	int n_time_slot=(input[0]/time_slot_duration)-offset_time_slot;
	uint8_t ch;
	uint8_t no_empty=0;
	int i=0;
	// faccio un controllo sul time slot corrente
	// in questo modo eseguo il for nello switch sottostante una sola volta per time slot
	// se cosi non fosse, eseguirei più volte il for nello stesso time slot 
	// (non garantendo cosi il rispetto del vincolo temporale)   
	if (previous_time_slot==n_time_slot)
		n_time_slot=-200;
	else
		previous_time_slot=n_time_slot;
	
	// in base al time slot corrente, eseguo UNA sola volta il for corrispondente
	// limit_byte_sent è settato nel wrap_synchronize_send_start_fcn in funzione della durata del time_slot
	switch (n_time_slot){
		case time_slot_0:
			for (i=0;i<limit_byte_sent;i++)
			{
				no_empty=timed_buffer_bs_read(&ch);
				if (no_empty)
				{
					USART2_Send((unsigned char)ch);
				}
				no_empty=0;
			}
		break;
		case time_slot_1:
			for (i=0;i<limit_byte_sent;i++)
			{
				no_empty=timed_buffer_virtual_car_1_read(&ch);
				if (no_empty)
				{
					USART2_Send((unsigned char)ch);
				}
				no_empty=0;
			}
		break;
		case time_slot_2:
			for (i=0;i<limit_byte_sent;i++)
			{
				no_empty=timed_buffer_virtual_car_2_read(&ch);
				if (no_empty)
				{
					USART2_Send((unsigned char)ch);
				}
				no_empty=0;
			}
		break;
		case time_slot_3:
			for (i=0;i<limit_byte_sent;i++)
			{
				no_empty=timed_buffer_virtual_car_3_read(&ch);
				if (no_empty)
				{
					USART2_Send((unsigned char)ch);
				}
				no_empty=0;
			}
		break;
		case time_slot_4:
			for (i=0;i<limit_byte_sent;i++)
			{
				no_empty=timed_buffer_virtual_car_4_read(&ch);
				if (no_empty)
				{
					USART2_Send((unsigned char)ch);
				}
				no_empty=0;
			}
		break;
		case time_slot_5:
			for (i=0;i<limit_byte_sent;i++)
			{
				no_empty=timed_buffer_virtual_car_5_read(&ch);
				if (no_empty)
				{
					USART2_Send((unsigned char)ch);
				}
				no_empty=0;
			}
		break;
		case time_slot_6:
			for (i=0;i<limit_byte_sent;i++)
			{
				no_empty=timed_buffer_virtual_car_6_read(&ch);
				if (no_empty)
				{
					USART2_Send((unsigned char)ch);
				}
				no_empty=0;
			}
		break;
		case time_slot_7:
			for (i=0;i<limit_byte_sent;i++)
			{
				no_empty=timed_buffer_virtual_car_7_read(&ch);
				if (no_empty)
				{
					USART2_Send((unsigned char)ch);
				}
				no_empty=0;
			}
		break;
		case time_slot_8:
			for (i=0;i<limit_byte_sent;i++)
			{
				no_empty=timed_buffer_virtual_car_8_read(&ch);
				if (no_empty)
				{
					USART2_Send((unsigned char)ch);
				}
				no_empty=0;
			}
		break;
		case time_slot_9:
			for (i=0;i<limit_byte_sent;i++)
			{
				no_empty=timed_buffer_virtual_car_9_read(&ch);
				if (no_empty)
				{
					USART2_Send((unsigned char)ch);
				}
				no_empty=0;
			}
		break;
		default:
		break;
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
