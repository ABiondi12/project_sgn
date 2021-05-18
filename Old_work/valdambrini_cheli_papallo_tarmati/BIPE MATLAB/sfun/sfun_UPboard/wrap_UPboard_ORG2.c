
#include "stm32f4_custom_USART.h"
//configure to use USART 5    
#define upboard_recv(PAR)  USART3_Receive(PAR)
#define i_uint16            uint16_t
#define i_int32             int32_t

//#define ALL_ELEMENT 228
#define ALL_ELEMENT 24
#define ELEMENT_Work 231 //228+3
//#define NUMBER_OF_ANGLES 57
#define NUMBER_OF_ANGLES 6

//unsigned char *parseptr;

//Variabili temporanee contenenti la posizione in coordinate ArUco 
double ArUco_PX ;
double ArUco_PY ;
double ArUco_PZ ;

//Variabili temporanee contenenti la velocita' in coordinate ArUco
double ArUco_SX ;
double ArUco_SY ;
double ArUco_SZ ;

double gradi[NUMBER_OF_ANGLES];

//double aruco_fix;
//double flag;


//Variabile di lavoro usata nella macchina a stati finiti
long int Work[ELEMENT_Work];
unsigned char receivedCharFromSerial[ELEMENT_Work]; //aggiunta

//Definizione degli stati della macchina a stati usata per il parsing del messaggio
// da ArUco
typedef enum{
	
		wait_SYNC1, 
		wait_SYNC2,
		wait_ID,
		wait_PAYLOAD
	
} wating_state;



void wrap_UPboard_start_fcn()
{
    int i;

	for(i=0;i<ELEMENT_Work;i++) Work[i]=0;
}

//parseFcn parses the UPboard message
// Type Periodic/Polled



//                    Header      ID   Length (Bytes) Payload  
// Message Structure 0x1A 0x1B   0x2C    27          see below 
// byte offset - number format - name - unit - description
// 0 - I4 - ArUco X pos
// 4 - I4 - ArUco Y pos
// 8 - I4 - ArUco Z pos
// 12 - I4 - ArUco ROLL
// 16 - I4 - ArUco PITCH
// 20 - I4 - ArUco YAW

/*Original Parser function
//NOTE: ADD 3 to byte_offeste to get position of first byte into Work vector
// example: byte 0 of ArUco X is in position 0+3 = 3 of Work
int parseFcn(long int* Work){
	
    long int PX, PY, PZ, SX, SY, SZ;
    
	//In Work si trova il payload letto, che va sistemato trmite opportuni shift all'interno delle variabili temporanee di posizione
	// e velocita'.
	PX = (0x000000FF & Work[3])|(0x0000FF00 & (Work[4]<<8))|(0x00FF0000 & (Work[5]<<16))|(0xFF000000 & (Work[6]<<24));
	PY = (0x000000FF & Work[7])|(0x0000FF00 & (Work[8]<<8))|(0x00FF0000 & (Work[9]<<16))|(0xFF000000 & (Work[10]<<24));
	PZ = (0x000000FF & Work[11])|(0x0000FF00 & (Work[12]<<8))|(0x00FF0000 & (Work[13]<<16))|(0xFF000000 & (Work[14]<<24));
	SX = (0x000000FF & Work[15])|(0x0000FF00 & (Work[16]<<8))|(0x00FF0000 & (Work[17]<<16))|(0xFF000000 & (Work[18]<<24));
	SY = (0x000000FF & Work[19])|(0x0000FF00 & (Work[20]<<8))|(0x00FF0000 & (Work[21]<<16))|(0xFF000000 & (Work[22]<<24));
	SZ = (0x000000FF & Work[23])|(0x0000FF00 & (Work[24]<<8))|(0x00FF0000 & (Work[25]<<16))|(0xFF000000 & (Work[26]<<24));
	
//     aruco_fix = ((double)(0x000000FF & Work[13]));       // prelevo il aruco_fix byte
//     flags = ((double)(0x00000001 & Work[14]));         // prelevo solo il flag di GPSFixOK

	ArUco_PX = ((double)PX)/1000.0;
	ArUco_PY = ((double)PY)/1000.0;
	ArUco_PZ = ((double)PZ)/1000.0;

	ArUco_SX = ((double)SX)/1000.0;
	ArUco_SY = ((double)SY)/1000.0;
	ArUco_SZ = ((double)SZ)/1000.0;


	//return 0 if packet decoded but aruco_fix is not ok
//     if(flags == 0)
//         return 0;
//     else
        return 1;
}

*/

//int parseFcn(long int* Work,unsigned char*receivedCharFromSerial){
int parseFcn(unsigned char* receivedCharFromSerial){

  union DATA{
      char  s[4];
      float n;
    } d;
   //union DATA d;
    int j;
    for(int i=0; i<NUMBER_OF_ANGLES;i++){
         j = i*4;
        d.s[0]=receivedCharFromSerial[j];d.s[1]=receivedCharFromSerial[j+1];d.s[2]=receivedCharFromSerial[j+2];d.s[3]=receivedCharFromSerial[j+3];
       gradi[i]=(double)d.n;
   
    }
        return 1;
}






void wrap_UPboard_output_fcn(double* aroutput, double* newpacket)

{
    char i;
    
    // set newpacket output to 0 for now, parse() will set it to 1 if a valid packet was received
    newpacket[0] = 0;
    
    //Variabile di appoggio per il byte estrayyo
	unsigned char byte;
	
	//Stato corrente della macchina a stati finiti
	wating_state wait = Work[0];
	
	//Variabile che mi tiene conto di quanti byte del payload sono arrivati
	int offset = Work[2];
    
    while (upboard_recv(&byte))
    {
        switch (wait){
			
		case wait_SYNC1:
			if (byte == 0x1A){
				
				wait = wait_SYNC2;
				Work[0] = wait;
				offset = 0;
				Work[2] = offset;
				
			}
			break;
			
			
		case wait_SYNC2:
			if (byte == 0x1B){	
				wait = wait_ID;	
				offset = 0;
			}	
			else{
				wait = wait_SYNC1;
				offset = 0;
			}
			Work[0] = wait;
			Work[2] = offset;
			break;
			
			
		case wait_ID:
			if (byte == 0x2C){
				wait = wait_PAYLOAD;
				offset = 0;	
			}
			else{
				wait = wait_SYNC1;
				offset = 0;
			}
			Work[2] = offset;
			Work[0] = wait;
			break;
				
		case wait_PAYLOAD:
			//Salvo in Work (dalla postazione 3 alla 26) il payload.
			//Solo quando tutti i dati sono stati ricevuti richiamo parseFcn
			// e aggiorno le varibiali globali (in modo da evitare inconsistenze)
			if (offset<ALL_ELEMENT){ 
				//Work[3+offset] = byte;
                receivedCharFromSerial[offset] = byte;
				offset++;
				wait = wait_PAYLOAD;
			}
			//else{ Bug Fixed: utilizzando l'else si perdeva tutto un pacchetto a seguito di uno correttamente acquisito.
			if (offset==ALL_ELEMENT){ 
				
				offset = 0;
				//newpacket[0] = parseFcn(Work);
               // newpacket[0] = parseFcn(Work,receivedCharFromSerial);
                newpacket[0] = parseFcn(receivedCharFromSerial);                
				
				//Aggiorno i "link" in uscita da aruco
//                 aroutput[] = 
                
                for(int i=0;i<NUMBER_OF_ANGLES;i++){
				aroutput[i] = gradi[i] ;
				
		
				
				wait = wait_SYNC1;
				
			}
			Work[0] = wait;
			Work[2] = offset;
			break;
			
			
	}                         
    }
}
}