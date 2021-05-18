#include "packet_manager_c2k.h"
#include "circular_buffer.h"

// forward declaration of 'private' functions found in packet_manager.c
short _pm_send_byte(unsigned char id, char* sent);
short _pm_process_byte(unsigned char ch);

void pm_send_packet_c2k(unsigned char header)
{
	char sent;
	short ch;

	do {
        ch = _pm_send_byte(header, &sent);
        
		if (ch != -200) {        
			drv_scib_send((unsigned char)ch);
		}
    } while(sent == 0 && ch != -200);
}

void pm_read_packet_c2k()
{
	unsigned char tmp;
	char bytesread;

    do {
        bytesread = drv_scib_recv(&tmp);

        if (bytesread > 0) {
			_pm_process_byte(tmp);
        }
	} while (bytesread != 0);
}
