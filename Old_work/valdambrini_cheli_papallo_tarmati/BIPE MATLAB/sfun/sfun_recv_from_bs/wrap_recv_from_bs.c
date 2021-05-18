// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Regole per aggiungere un pacchetto che si vuole riceve:
//     1) aggiungere #include "packet_nomepacchetto.h"
//     2) aggiungere la struttura dati del pacchetto "extern struct Nomepacchetto nomepacchetto_data;"
//     3) aggiungere nella funzione new_packet di questo file il caso di header== ID_Pacchetto
//     4) utilizzare "pm_read_packet_c2k()" per ricevere il pacchetto dalla USART2        
//
//     5) ricordarsi che l'ID_Pacchetto deve si deve trovare in "packet_ids.h"
//     6) ricordarsi che il pacchetto deve essere correttamente registrato nel packet_manager (file: wrap_pm_init)
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//++++++++++++++++++++++++++++
//.h Custom Includes
//++++++++++++++++++++++++++++
#include <math.h>
#include "packet_manager.h"
#include "packet_manager_c2k_car.h"
#include "packet_pc_to_car.h"
#include "packet_ids.h"
#include "packet_startstop_seeker.h"
#include "packet_startstop_seeker_init.h"
#include "packet_car_telemetry.h"

//#include "DSP2833x_Device.h"
//++++++++++++++++++++++++++++

#define BROADCAST 255

extern struct Pc_to_car pc_to_car_data;
extern struct Startstop_seeker startstop_seeker_data;
extern struct Car_telemetry car_telemetry_data;
extern struct Startstop_seeker_init startstop_seeker_init_data;

double* ecef_ref_wires = 0; 
double* position_target = 0; 
double* velocity_target = 0; 
char* waypoint_wires = 0;
unsigned char* cmd_wires = 0;
unsigned char* mode_wires = 0;
double* gain_pid_wires = 0;
unsigned char* new_packet_wires = 0;
// id della macchina corrente
static unsigned char id=0;
// variale di start/stop ingaggio
// il seeker inizia a seguire il target passato dal PC solo se startstop_seeker==1
static unsigned char startstop_seeker=0;

static i_float Kp_motore;
static i_float Ki_motore;
static i_float Kp_sterzo;
static i_float Ki_sterzo;
static i_float bs_ecef_px;
static i_float bs_ecef_py;
static i_float bs_ecef_pz;


void new_packet(unsigned char header, unsigned char sender, unsigned char receiver)
{
	//se il pacchetto arrivato è il PCK_BS_TO_CAR e l'ID è della macchina corrente eseguo, altrimento non faccio niente
	if (header == PCK_PC_TO_CAR && (receiver==id || receiver==BROADCAST))
	{
		// set wires with the correspondent data
		mode_wires[0] = pc_to_car_data.mode;
		
		ecef_ref_wires[0] = pc_to_car_data.ecef_ref_x;
		ecef_ref_wires[1] = pc_to_car_data.ecef_ref_y;
		ecef_ref_wires[2] = pc_to_car_data.ecef_ref_z;
		
		waypoint_wires[0] = pc_to_car_data.waypoint_px_ned;
		waypoint_wires[1] = pc_to_car_data.waypoint_py_ned;
		
		cmd_wires[0] = pc_to_car_data.cmd1;
		cmd_wires[1] = pc_to_car_data.cmd2;
		cmd_wires[2] = pc_to_car_data.cmd3;
		cmd_wires[3] = pc_to_car_data.cmd4;
		
		gain_pid_wires[0] = pc_to_car_data.Kp_motore;
		gain_pid_wires[1] = pc_to_car_data.Ki_motore;
		gain_pid_wires[2] = pc_to_car_data.Kp_sterzo;
		gain_pid_wires[3] = pc_to_car_data.Ki_sterzo;
							   
		//set cmd data_valid bit to 1 (valid)
		new_packet_wires[0] = 1;
	   
	}
	else if (header == PCK_STARTSTOP_SEEKER_INIT && receiver==id){
		Kp_motore = startstop_seeker_init_data.Kp_motore;
		Ki_motore = startstop_seeker_init_data.Ki_motore;
		Kp_sterzo = startstop_seeker_init_data.Kp_sterzo;
		Ki_sterzo = startstop_seeker_init_data.Ki_sterzo;
		bs_ecef_px = startstop_seeker_init_data.bs_ecef_px;
		bs_ecef_py = startstop_seeker_init_data.bs_ecef_py;
		bs_ecef_pz = startstop_seeker_init_data.bs_ecef_pz;
		gain_pid_wires[0] = Kp_motore;
		gain_pid_wires[1] = Ki_motore;
		gain_pid_wires[2] = Kp_sterzo;
		gain_pid_wires[3] = Ki_sterzo;
		ecef_ref_wires[0] = bs_ecef_px;
		ecef_ref_wires[1] = bs_ecef_py;
		ecef_ref_wires[2] = bs_ecef_pz;
	}
	else if (header == PCK_STARTSTOP_SEEKER && receiver==id){
		mode_wires[0]=6;
		//start stop ingaggio
		startstop_seeker = startstop_seeker_data.mode;
		position_target[0] = startstop_seeker_data.target_ecef_px;
		position_target[1] = startstop_seeker_data.target_ecef_py;
		position_target[2] = startstop_seeker_data.target_ecef_pz;
		velocity_target[0]=startstop_seeker_data.target_ecef_vx;
		velocity_target[1]=startstop_seeker_data.target_ecef_vy;
		velocity_target[2]=startstop_seeker_data.target_ecef_vz;
		gain_pid_wires[0] = Kp_motore;
		gain_pid_wires[1] = Ki_motore;
		gain_pid_wires[2] = Kp_sterzo;
		gain_pid_wires[3] = Ki_sterzo;
		ecef_ref_wires[0] = bs_ecef_px;
		ecef_ref_wires[1] = bs_ecef_py;
		ecef_ref_wires[2] = bs_ecef_pz;
		
		if (startstop_seeker==0)
		{
			//procedura di STOP!!!!
			mode_wires[0]=0;
		}
		
		new_packet_wires[0] = 1;
	}
	else{
		new_packet_wires[0] = 0;
	}
}

void err_d(unsigned char header, unsigned char errno)
{
	if (header == 1 && errno == 0)
	{
		
	}
}

void err_s(unsigned char header, unsigned char errno)
{
	if (header == 1 && errno == 0)
	{
		
	}
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//mdlStart Wrapper Function Definition
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void wrap_recv_from_bs_start_fcn(unsigned char* mode_ptr, double* ecef_ref_ptr, char* waypoint_ptr, unsigned char* cmd_ptr, double* gain_pid_ptr, unsigned char* new_packet_ptr, double* position_target_ptr, double* velocity_target_ptr)
{
    // Init outputs
    mode_wires = mode_ptr;
    mode_wires[0] = 0;
    
    ecef_ref_wires = ecef_ref_ptr;
    ecef_ref_wires[0] = 0;
    ecef_ref_wires[1] = 0;
    ecef_ref_wires[2] = 0;
    
    waypoint_wires = waypoint_ptr;
    waypoint_wires[0] = 0;
    waypoint_wires[0] = 0;
    
    cmd_wires = cmd_ptr;
    cmd_wires[0] = 0;
    cmd_wires[1] = 0;
    cmd_wires[2] = 0;
    cmd_wires[3] = 0;
    
    gain_pid_wires = gain_pid_ptr;
    gain_pid_wires[0] = 0;
    gain_pid_wires[1] = 0;
    gain_pid_wires[2] = 0;
    gain_pid_wires[3] = 0;
    
	position_target=position_target_ptr;
	position_target[0]=0;
	position_target[1]=0;
	position_target[2]=0;
	
	velocity_target=velocity_target_ptr;
	velocity_target[0]=0;
	velocity_target[1]=0;
	velocity_target[2]=0;
	
    new_packet_wires = new_packet_ptr;
    new_packet_wires[0] = 0;  
}

void wrap_recv_from_bs_output_fcn(unsigned char* mode_ptr, double* ecef_ref_ptr, char* waypoint_ptr, unsigned char* cmd_ptr, double* gain_pid_ptr, unsigned char* new_packet_ptr, double* id_car)
{

    //set data_valid bits to 0 (not valid)
    new_packet_wires[0] = 0;  
	//setto l'id della macchina corrente, in base al blocco costante id_car di simulink
    id=id_car[0];
    pm_read_packet_car();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
