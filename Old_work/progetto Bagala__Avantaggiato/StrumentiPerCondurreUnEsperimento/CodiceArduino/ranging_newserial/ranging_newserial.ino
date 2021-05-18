//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*                                                      PROGETTO DI GUIDA E NAVIGAZIONE
                                                     AVANTAGGIATO SABRINA E ALFREDO BAGALA'                                                 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Questo sketch serve per calcolare le distanze di due tag da un'ancora attraverso l'utilizzo di Arduino. Bisogna impostare l' id dell'ancora 
   rispetto alla quale effettuare il ranging.
   La comunicazione seriale in questo sketch è affidata alla libreria SerialPort (Serial-->NewSerial)*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Pozyx.h>
#include <Pozyx_definitions.h>
#include <Wire.h>
#include <SerialPort.h>

/* usa NewNewSerial per la porta 0: questo va inserito solo nel caso si utilizzi la libreria <NewSerialPort.h>. La libreria permette di configurare 
   fino a quattro porte NewSeriali virtuali - NOTA: nella libreria queste hanno una dimensione definita del buffer NewSeriale, qualora 
   il pacchetto di dati superasse i 60 bytes, sarebbe opportuno modificarne la dimensione a meno di rallentamenti nella comunicazione*/
USE_NEW_SERIAL;

////////////////////////////////////////////////
////////////////// PARAMETERS //////////////////
////////////////////////////////////////////////

const uint8_t num_anchors = 4;          // numero di ancore

// viene definita una struttura per raggruppare tutti i dati di interesse relativi ad un tag
struct dati
{
   coordinates_t position;              // coordinate del tag (contiente [position.x;position.y;position.z])
   uint16_t id;                         // identificativo unico del tag
   uint32_t distance[num_anchors];      // vettore contente le distanze relative tra lo specifico tag e le ancore
};

// vengono create due strutture dati in quanto lo sketch è pensato per l'utilizzo di due tag in parallelo
dati tag1;
dati tag2;

// codice per eventuale identificazione dell'errore
int8_t POS_ERROR = 0x01;
int8_t POS_SUCCESS = 0x00;

// vettore ausiliario per il salvataggio delle distanze
device_range_t device_range_aux;                                      // contiene un "timestamp", una "distance" e un "RSS" (potenza del segnale correlato alla misura) 

uint16_t remote_id = NULL;                                            // setta l'id dell'eventuale tag remoto
bool remote = false;                                                  // true se esiste un tag remoto

uint16_t anchors[num_anchors] = {0x6939, 0x6E7A, 0x6E44, 0x6E6C};     // network ID delle ancore: inserire le ancore secondo la convenzione POZYX
int32_t anchors_x[num_anchors] = {0, 0, 1758, 886};                   // coordinata x delle ancore in mm
int32_t anchors_y[num_anchors] = {0, 2829, 1745, 1579};               // coordinata y delle ancore in mm
int32_t heights[num_anchors] = {0, 0, 0, 1076};                       // coordinata z delle ancore in mm

uint8_t ranging_protocol = POZYX_RANGE_PROTOCOL_FAST;   // protocollo del ranging Pozyx; l'alternativa è l'algoritmo PRECISION settato di default
uint8_t algorithm = POZYX_POS_ALG_UWB_ONLY;             // algoritmo di positioning, è possibile settare anche POZYX_POS_ALG_TRACKING per oggetti che si muovono velocemente

uint8_t dimension = POZYX_3D;                           // dimensione del positioning. Alternative: POZYX_2D, POZYX_2.5D, POZYX_3D. La seconda possibilità fornisce il risultato di 
                                                        // una triangolazione planare su un piano ad un'altezza differente (da inserire nella variabile height) rispetto a quello
                                                        // su cui si trovano le prime tre ancore
int32_t height =  80; 
                                 
// variabili in cui verranno salvati gli esiti degli algoritmi
int status;
int status1;

// variabili per successiva analisi dell'update-rate
unsigned long time;
unsigned long time1;

////////////////////////////////////////////////

void setup(){
  NewSerial.begin(115200);                                                  // baundrate massimo ammissibile su Arduino Uno Rev3
  POZYX_I2C_ADDRESS = 0x4B;                                                 // indirizzo del tag, va inserito prima del begin date le modifiche apportate alla libreria. 
                                                                            // Risulta indifferente inserire l'id di un o dell'altro tag
  float gain1;
  float gain2;
  UWB_settings_t set1;
  UWB_settings_t set2;
                                                                          
  // inizializzazione del sistema e controllo del buon esito dell'operazione
  if(Pozyx.begin() == POZYX_FAILURE){
    NewSerial.println(F("ERROR: Unable to connect to POZYX shield"));
    NewSerial.println(F("Reset required"));
    delay(100);
    abort();
  }
 
  Pozyx.setRangingProtocol(ranging_protocol);                               // set dell'algoritmo di ranging  
  Pozyx.getTxPower(&gain2, 0x671A);                                         // ottengo l'informazione sul guadagno impostato nel secondo tag
  Pozyx.getUWBSettings(&set2, 0x671A);                                      // ottengo l'informazione sui parametri UWB impostati nel secondo tag
  
  POZYX_I2C_ADDRESS = 0x4A;                                                 // vengono ripetute le stesse operazioni per il secondo tag
  Pozyx.setRangingProtocol(ranging_protocol);                               // set dell'algoritmo di ranging  
  Pozyx.getTxPower(&gain1, 0x675E);                                         // ottengo l'informazione sul guadagno impostato nel primo tag
  Pozyx.getUWBSettings(&set1, 0x675E);                                      // ottengo l'informazione sui parametri UWB impostati nel secondo tag
  
  // set del clock di comunicazione I2C
  Wire.setClock(400000);
  delay(200);

  //printing della configurazione dei parametri UWB 
  printUWBparam(gain1,set1);
  printUWBparam(gain2,set2);
  NewSerial.println();

}

void loop(){
    time = micros();
    
    POZYX_I2C_ADDRESS = 0x4B;
    status = Pozyx.doRanging(anchors[0], &device_range_aux);
    if(status == POZYX_SUCCESS){ 
      NewSerial.print(device_range_aux.distance);
    }else{
      NewSerial.print(0);
    }
    NewSerial.print(" "); 
    
    POZYX_I2C_ADDRESS = 0x4A;                                                         // vengono ripetute le stesse operazioni per il secondo tag
    status = Pozyx.doRanging(anchors[0], &device_range_aux);
    if(status == POZYX_SUCCESS){ 
      NewSerial.print(device_range_aux.distance);
    }else{
      NewSerial.print(0);
    }
    NewSerial.print(" "); 
            
    NewSerial.println(time);                                                           // printing del tempo per analisi in post-processing
}


//stampa il guadagno e i parametri UWB settati nei tag
void printUWBparam(float gain, UWB_settings_t set){
    NewSerial.print("gain: ");
    NewSerial.print(gain);
    NewSerial.print(" ");
    NewSerial.print("channel: ");
    NewSerial.print(set.channel);
    NewSerial.print(" ");
    NewSerial.print("bitrate: ");
    NewSerial.print(set.bitrate);
    NewSerial.print(" ");
    NewSerial.print("plen: ");
    NewSerial.print(set.plen);
    NewSerial.print(" ");
    NewSerial.print("prf: ");
    NewSerial.print(set.prf);
    NewSerial.print(" ");
}
