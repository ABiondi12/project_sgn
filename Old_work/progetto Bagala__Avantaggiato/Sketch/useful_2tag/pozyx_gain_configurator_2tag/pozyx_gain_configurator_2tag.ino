/** ///////////////// PROGETTO di SISTEMI DI GUIDA E NAVIGAZIONE /////////////////////////
 *                        Bagalà Alfredo & Avantaggiato Sabrina

 * Questo sketch setta e salva se desiderato il gain UWB  di tutti i dispositivi appartenenti al network cioè ancore e tag. 
 * NOTA 1 : Per permettere il salvataggio nella memoria interna di ogni device è necessario settare la variabile booleana save_gain a true. 
 * NOTA 2 : Questo sketch deve essere usato dopo aver impostato gli altri parametri UWB (bitrate, channel, prf, plen)tramite lo sketch interattivo: pozyx_UWB_configurator, 
 *          sempre presente nella cartella useful.
 * NOTA 3:  Questo sketch è stato scaricato dal sito pozyx e poi è stato adattato per essere usato con la libreria seriale: SerialPort.h.
 *          Se si volesse usare la libreria seriale standard di Arduino, è necessario:
 *          -commentare -> #include <SerialPort.h> 
*           -commentare la macro -> USE_NEW_SERIAL
 *          -sostituire NewSerial con Serial in tutte le istruzioni
 * NOTA 4 : Questo sketch è stato scaricato dal sito pozyx e poi è stato adattato per essere usato con due tag simultaneamente. Quindi è necessario
 *          all'interno del codice inizializzare gli indirizzi I2C dei tag
 */

#include <Pozyx.h>
#include <Pozyx_definitions.h>
#include <Wire.h>
#include <SerialPort.h>

// uso della NewSerial
USE_NEW_SERIAL; 

/////////////////////////////////////////////////////////////////////////////////////
////////////////// PARAMETERS ///////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

float desired_gain = 33.0f;     // inserire qui il valore di gain che si desidera settare
boolean save_gain = true;       // variabile booleana che permette il salvataggio. true -> salva il valore di gain desiderato nei corrispettivi registri

const int num_devices = 5;      // numero di device (escludendo il tag locale), a cui si desidera settare il gain

 // nel caso che abbiamo considerato, il tag locale è quello con indirizzo 0x4B e ID 0x675E
 //LISTA n°1:
uint16_t devices[num_devices] = {0x671A, 0x6939, 0x6E7A, 0x6E44, 0x6E6C}; // ID dei device( escludendo quello del locale.
uint16_t device_local = 0x675E;

// Nel caso in cui si volesse inizializzare nel setup prima l'indirizzo OX4A, bisogna decommentare le seguenti due righe e commentare le corrispettive precedenti:
//LISTA n°2:
//uint16_t devices[num_devices] = {0x675E, 0x6939, 0x6E7A, 0x6E44, 0x6E6C}; // ID dei device( escludendo quello del locale.
//uint16_t device_local = 0x671A;

///////////////////////////////////////////////////////////////////////////////////////////////

void setup(){
  NewSerial.begin(115200);
  POZYX_I2C_ADDRESS = 0x4B;    // inizializza l'indirizzo del tag locale (in questo caso quello non saldato) 
  
  if(Pozyx.begin() == POZYX_FAILURE){
    NewSerial.println(F("ERROR: Unable to connect to POZYX shield"));
    NewSerial.println(F("Reset required"));
    delay(100);
    abort();
  }
  
 //viene impostato il valore desired_gain a tutti i devices
  for (int i = 0; i < num_devices; i++){
    int status = Pozyx.setTxPower(desired_gain, devices[i]);
    uint8_t registers[1] = {POZYX_UWB_GAIN};
    if (save_gain){
      status &= Pozyx.saveRegisters(registers, 1, devices[i]);
    }
    if (status == POZYX_SUCCESS){
      printSuccess(devices[i]);
    }else{
      printFailure(devices[i]);
    }
  }
  
 // viene impostato il valore di desidered_gain dell'altro  tag
  POZYX_I2C_ADDRESS = 0x4A;     //Se qui si imposta 0x4B bisogna commentare la lista numero 1 e decommentare la LISTA n°2
    int status = Pozyx.setTxPower(desired_gain, device_local);
    uint8_t registers[1] = {POZYX_UWB_GAIN};
    if (save_gain){
      status &= Pozyx.saveRegisters(registers, 1, device_local);
    }
    if (status == POZYX_SUCCESS){
      printSuccess(device_local);
    }else{
      printFailure(device_local);
    }
}

// stampa che il salvataggio è avvenuto con successo
void printSuccess(uint16_t device_id){
  NewSerial.print("Configuration of device 0x");
  NewSerial.print(device_id, 16);
  NewSerial.print(" was successful!\n");
}

//stampa che il salvataggio non è avvenuto
void printFailure(uint16_t device_id){
  NewSerial.print("Configuration of device 0x");
  NewSerial.print(device_id, 16);
  NewSerial.print(" failed!\n");
}

void loop(){
  delay(10000);
}
