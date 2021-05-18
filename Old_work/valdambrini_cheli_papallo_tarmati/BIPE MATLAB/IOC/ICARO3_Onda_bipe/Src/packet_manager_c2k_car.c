#include "packet_manager_c2k_car.h"

// forward declaration of 'private' functions found in packet_manager.c
short _pm_send_byte(unsigned char id, unsigned char sender, unsigned char receiver, char* sent);
short _pm_process_byte(unsigned char ch);

//Funzione per la scrittura dei byte sulla seriale della macchinina
//la funzione è stata creata a partire dalla pm_send_packet_c2k
void pm_send_packet_car(unsigned char header,unsigned char sender, unsigned char receiver)
{
	char sent;
	short ch;

	do {
        ch = _pm_send_byte(header, sender, receiver, &sent);
        
		if (ch != -200) {
			USART2_Send((unsigned char)ch);
		}
    } while(sent == 0 && ch != -200);
}

//Funzione per la lettura della seriale della macchinina
//la funzione è stata creata a partire dalla pm_read_packet_c2k
void pm_read_packet_car()
{
	unsigned char tmp;
	char bytesread;

    do {
		bytesread=USART2_Receive(&tmp);
        if (bytesread > 0) {
			_pm_process_byte(tmp);
        }
	} while (bytesread != 0);
}