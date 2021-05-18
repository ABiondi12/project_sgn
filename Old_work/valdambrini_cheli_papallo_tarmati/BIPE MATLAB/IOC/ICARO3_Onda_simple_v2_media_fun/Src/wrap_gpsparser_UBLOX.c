#ifdef TEXAS_INSTRUMENT_DSP2833x
    #include "drv_scibtx.h"
    #include "drv_scicrx.h"
    #include "c2000_type.h"
#else   // STM32F4 Discovery
    #include "stm32f4_custom_USART.h"
    #define drv_scic_recv(PAR)  USART5_Receive(PAR)
    #define i_uint16            uint16_t
    #define i_int32             int32_t
#endif

#define GPS_BUFFSIZE 256 // plenty big
#define ELEMENT_IWORK 55

unsigned char buffer_UBLOX[GPS_BUFFSIZE];
unsigned char *parseptr;

//Variabili temporanee contenenti la posizione in coordinate ECEF (usate dal GPS) 
double ECEF_PX ;
double ECEF_PY ;
double ECEF_PZ ;

//Variabili temporanee contenenti la velocita' in coordinate ECEF (usate dal GPS)
double ECEF_SX ;
double ECEF_SY ;
double ECEF_SZ ;

double gps_fix;
double flags;


//Variabile di lavoro usata nella macchina a stati finiti
long int IWork[ELEMENT_IWORK];

//Definizione degli stati della macchina a stati usata per il parsing del messaggio
// da GPS
typedef enum{
	
		wait_SYNC1, 
		wait_SYNC2,
		wait_CLASS,
		wait_ID,
		wait_LENGTH1,
		wait_LENGTH2,
		wait_PAYLOAD
	
} wating_state;



void wrap_gpsparser_UBLOX_start_fcn()
{
    int i;

	for(i=0;i<ELEMENT_IWORK;i++) IWork[i]=0;
}

//parseSentence parses the NAV-SOL binary protocol UBLOX message
// Message NAV-SOL
// Description Navigation Solution Information
// Firmware Supported on u-blox 6 from firmware version 6.00 up to version 7.03.
// Type Periodic/Polled
// Comment This message combines Position, velocity and time solution in ECEF, including accuracy
// figures
//                    Header      ID   Length (Bytes) Payload    Checksum
// Message Structure 0xB5 0x62 0x01 0x06 52          see below   CK_A CK_B
// byte offset - number format - name - unit - description
// 0 - U4 - iTOW ms GPS Millisecond Time of Week
// 4 - I4 - fTOW ns Fractional Nanoseconds remainder of rounded ms above, range -500000 .. 500000
// 8 - I2 - week - GPS week (GPS time)
// 10 - U1 - gpsFix - GPSfix Type, range 0..5
//     0x00 = No Fix
//     0x01 = Dead Reckoning only
//     0x02 = 2D-Fix
//     0x03 = 3D-Fix
//     0x04 = GPS + dead reckoning combined
//     0x05 = Time only fix
//     0x06..0xff: reserved
// 11 - X1 - flags - Fix Status Flags (see graphic below)
//    bit0: GPSfixok, bit1: diffsoln, bit2: WKNSET, bit3: TOWSET
// 12 - I4 - ecefX cm ECEF X coordinate
// 16 - I4 - ecefY cm ECEF Y coordinate
// 20 - I4 - ecefZ cm ECEF Z coordinate
// 24 - U4 - pAcc cm 3D Position Accuracy Estimate
// 28 - I4 - ecefVX cm/s ECEF X velocity
// 32 - I4 - ecefVY cm/s ECEF Y velocity
// 36 - I4 - ecefVZ cm/s ECEF Z velocity
// 40 - U4 - sAcc cm/s Speed Accuracy Estimate
// 44 - U2 0.01 pDOP - Position DOP
// 46 - U1 - reserved1 - Reserved
// 47 - U1 - numSV - Number of SVs used in Nav Solution
// 48 - U4 - reserved2 - Reserved
//
//NOTE: ADD 3 to byte_offeste to get position of first byte into IWORK vector
// example: byte 0 of ecefX is in position 12+3 = 15 of IWork
int parseSentence(long int* IWork){
	
    long int PX, PY, PZ, SX, SY, SZ;
    
	//In IWork si trova il payload letto, che va sistemato trmite opportuni shift all'interno delle variabili temporanee di posizione
	// e velocita'.
	PX = (0x000000FF & IWork[15])|(0x0000FF00 & (IWork[16]<<8))|(0x00FF0000 & (IWork[17]<<16))|(0xFF000000 & (IWork[18]<<24));
	PY = (0x000000FF & IWork[19])|(0x0000FF00 & (IWork[20]<<8))|(0x00FF0000 & (IWork[21]<<16))|(0xFF000000 & (IWork[22]<<24));
	PZ = (0x000000FF & IWork[23])|(0x0000FF00 & (IWork[24]<<8))|(0x00FF0000 & (IWork[25]<<16))|(0xFF000000 & (IWork[26]<<24));
	SX = (0x000000FF & IWork[31])|(0x0000FF00 & (IWork[32]<<8))|(0x00FF0000 & (IWork[33]<<16))|(0xFF000000 & (IWork[34]<<24));
	SY = (0x000000FF & IWork[35])|(0x0000FF00 & (IWork[36]<<8))|(0x00FF0000 & (IWork[37]<<16))|(0xFF000000 & (IWork[38]<<24));
	SZ = (0x000000FF & IWork[39])|(0x0000FF00 & (IWork[40]<<8))|(0x00FF0000 & (IWork[41]<<16))|(0xFF000000 & (IWork[42]<<24));
	
    gps_fix = ((double)(0x000000FF & IWork[13]));       // prelevo il gps_fix byte
    flags = ((double)(0x00000001 & IWork[14]));         // prelevo solo il flag di GPSFixOK

	ECEF_PX = ((double)PX)/100.0;
	ECEF_PY = ((double)PY)/100.0;
	ECEF_PZ = ((double)PZ)/100.0;

	ECEF_SX = ((double)SX)/100.0;
	ECEF_SY = ((double)SY)/100.0;
	ECEF_SZ = ((double)SZ)/100.0;


	//return 0 if packet decoded but gps_fix is not ok
    if(flags == 0)
        return 0;
    else
        return 1;
}

void wrap_gpsparser_UBLOX_output_fcn(double* gpsoutput, double* newpacket)
{
    char i;
    
    // parser working variables
	static unsigned char state = 0;
	static unsigned char payload_length = 0;
	static unsigned char payload_read = 0;
	static unsigned char checksum = 0;
	unsigned char calculated_checksum = 0;
    
    // gps data variables
    i_int32 latitude = 0;
    i_int32 longitude = 0;
    i_int32 altitude_msl = 0;
    i_uint16 fix_mode = 0;
    i_uint16 hdop = 0;
    
    // set newpacket output to 0 for now, parse() will set it to 1 if a valid packet was received
    newpacket[0] = 0;
    
    //Variabile di appoggio per il byte estrayyo
	unsigned char byte;
	
	//Stato corrente della macchina a stati finiti
	wating_state wait = IWork[0];
	
	//Variaible che mi tiene conto di quanti byte del payload sono arrivati
	int offset = IWork[2];
    
    while (drv_scic_recv(&byte))
    {
        switch (wait){
			
		case wait_SYNC1:
			if (byte == 0xB5){
				
				wait = wait_SYNC2;
				IWork[0] = wait;
				offset = 0;
				IWork[2] = offset;
				
			}
			break;
			
			
		case wait_SYNC2:
			// waiting for ID Position byte
			if (byte == 0x62){	
				wait = wait_CLASS;	
				offset = 0;
			}	
			else{
				wait = wait_SYNC1;
				offset = 0;
			}
			IWork[0] = wait;
			IWork[2] = offset;
			break;
			
			
		case wait_CLASS:
			if (byte == 0x01){
				wait = wait_ID;
				offset = 0;
			}
			else{
				wait = wait_SYNC1;
				offset = 0;
			}
			IWork[2] = offset;
			IWork[0] = wait;
			break;
			
			
		case wait_ID:
			if (byte == 0x06){
				wait = wait_LENGTH1;
				offset = 0;	
			}
			else{
				wait = wait_SYNC1;
				offset = 0;
			}
			IWork[2] = offset;
			IWork[0] = wait;
			break;
			
			
		case wait_LENGTH1:	
			if (byte == 0x34){
				wait = wait_LENGTH2; 
				offset = 0;
			}
			else{
				wait = wait_SYNC1;  
				offset = 0;
			}
			IWork[2] = offset;
			IWork[0] = wait;
			break;
			
			
		case wait_LENGTH2:
			if (byte == 0x00){
				wait = wait_PAYLOAD;                    
				offset = 0;
			}
			else{
				wait = wait_SYNC1;
				offset = 0;
			}
			IWork[2] = offset;
			IWork[0] = wait;
			break;
			
			
		case wait_PAYLOAD:
			//Salvo in IWork (dalla postazione 4 alla 54) il payload.
			//Solo quando tutti i dati sono stati ricevuti richiamo parseSentence
			// e aggiorno le varibiali globali (in modo da evitare inconsistenze)
			if (offset<52){ 
				IWork[3+offset] = byte;
				offset++;
				wait = wait_PAYLOAD;
			}
			if (offset==52){    //Bug Fixed: si aveva la perdita di un messaggio al termine di un messaggio correttamente ricevuto.
                                //
				
				offset = 0;
				newpacket[0] = parseSentence(IWork);
				
				//Aggiorno i "link" in uscita dal gps
//                 gpsoutput[] = 
				gpsoutput[0] = ECEF_PX;
				gpsoutput[1] = ECEF_PY;
				gpsoutput[2] = ECEF_PZ;
				gpsoutput[3] = ECEF_SX;
				gpsoutput[4] = ECEF_SY;
				gpsoutput[5] = ECEF_SZ;
		
				gpsoutput[6] = gps_fix;
				
				wait = wait_SYNC1;
				
			}
			IWork[0] = wait;
			IWork[2] = offset;
			break;
			
			
	}                         
    }
}
