//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*                                                      PROGETTO DI GUIDA E NAVIGAZIONE
                                                     AVANTAGGIATO SABRINA E ALFREDO BAGALA'                                                 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Questo sketch serve per calcolare le coordinate di due tag attraverso l'utilizzo di Arduino. Innanzitutto bisogna impostare gli id delle 
   ancore - NOTA: l'ordine con cui viene definito il network definirà il SDR del sistema Pozyx. Una volta fatto ciò è possibile definire 
   se il tag di cui si vuol avere informazioni è remoto o locale: in tale sketch solo il secondo di questi casi è preso in considerazione.
   Qualora si volesse invece interrogare un dispositivo in remoto bisognerà sostituire doPositioning con doRemotePositioning.
   Le coordinate delle antenne devono essere inserite manualmente nei vettori che di seguito verranno messi in evidenza. La calibrazione viene 
   effettuata esternamente dal codice in "Script di base" (codice python).
   Qui la comunicazione seriale può trasmettere dati sia in formato binario(bool binario = true) abilitato per la lettura da parte dell'autopilota, 
   sia in formato decimale, con la possibilità di salvataggio dei dati tramite lo sketch "salva_simula". 
   Vedere file simulink "ICARO_III_debug_telemetry_online_receiver_POXYZ_v1slx.slx per la simulazione dell'autopilota"
   C'è inoltre la possibilità di scegliere se inserire manualmente le coordinate delle ancore nel SdR Pozyx sia manualmente che facendole 
   richiedere automaticamente alle ancore. Ovviamente, la seconda di queste opzioni è possibile solo a posteriori della calibrazione implementata
   dal codice python. La gestione dipende dalla variabile booleana "calibrazione"*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//include delle librerie utilizzate: assicurarsi che si trovino nella cartella "libraries" di Arduino
#include <Pozyx.h>
#include <Pozyx_definitions.h>
#include <Wire.h>
#include <SerialPort.h>

/* usa NewSerial per la porta 0: questo va inserito solo nel caso si utilizzi la libreria <SerialPort.h>. La libreria permette di configurare 
   fino a quattro porte seriali virtuali - NOTA: nella libreria queste hanno una dimensione definita del buffer seriale, qualora 
   il pacchetto di dati superasse i 60 bytes, sarebbe opportuno modificarne la dimensione a meno di rallentamenti nella comunicazione*/
USE_NEW_SERIAL;

////////////////////////////////////////////////
////////////////// PARAMETERS //////////////////
////////////////////////////////////////////////

//////////////////!!!!!!!!!!!//////////////////
bool binario = false; // gestione del printing binario o decimale (true = Binario; false = Decimale)
bool calibrazione = false; // true = vengono richiesti i valore di coordinate salvate nella memoria flash delle singole ancore
                           // false = le coordinate delle ancore sono quelle in anchors_x, anchors_y e heights (da inserire manualmente)
//////////////////!!!!!!!!!!!//////////////////

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
int32_t anchors_x[num_anchors] = {0, 0, 1758, 886} ;                                       // coordinata x delle ancore in mm
int32_t anchors_y[num_anchors] = {0, 2829, 1745, 1579};                                       // coordinata y delle ancore in mm
int32_t heights[num_anchors] = {0, 0, 0, 1076};                                         // coordinata z delle ancore in mm

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
NewSerial.begin(115200);                                                    // baundrate massimo ammissibile su Arduino Uno Rev3
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

  // vengono richieste le coordinate salvate nelle ancore durante l'ultima calibrazione e vengono inserite negli opportuni vettori.
  // controllo del buon esito dell'operazione altrimenti viene bloccata l'esecuzione
  if(calibrazione){
    if(getAnchorsCoordinates == POZYX_FAILURE){
         NewSerial.println(F("ERROR: Coordinates not setted"));
         NewSerial.println(F("Reset required"));
         delay(100);
         abort();
    }
  }
  
  setAnchorsManual();                                                       // set manuale delle ancore
  Pozyx.setRangingProtocol(ranging_protocol);                               // set dell'algoritmo di ranging  
  Pozyx.setPositionAlgorithm(algorithm, dimension, remote_id);              // set dell'algoritmo di positioning 
  if(!binario){
    Pozyx.getTxPower(&gain2, 0x671A);                                         // ottengo l'informazione sul guadagno impostato nel secondo tag
  }
  Pozyx.getUWBSettings(&set2, 0x671A);                                      // ottengo l'informazione sui parametri UWB impostati nel secondo tag
  
//  POZYX_I2C_ADDRESS = 0x4A;                                                 // vengono ripetute le stesse operazioni per il secondo tag
//  setAnchorsManual();                                                       // set manuale delle ancore
//  Pozyx.setRangingProtocol(ranging_protocol);                               // set dell'algoritmo di ranging  
//  Pozyx.setPositionAlgorithm(algorithm, dimension, remote_id);              // set dell'algoritmo di positioning 
  if(!binario){
    Pozyx.getTxPower(&gain1, 0x675E);                                         // ottengo l'informazione sul guadagno impostato nel primo tag
  }
  Pozyx.getUWBSettings(&set1, 0x675E);                                      // ottengo l'informazione sui parametri UWB impostati nel secondo tag
  
  // set del clock di comunicazione I2C: questa è la modifica più importante per un miglioramento della frequenza di lavoro
  Wire.setClock(400000);
  delay(200);

  if(!binario){
  //printing della configurazione dei parametri UWB 
  printUWBparam(gain1,set1);
  printUWBparam(gain2,set2);
  NewSerial.println();
  }
  
  // l'algoritmo di positioning ha un tempo di transitorio prima di andare a regime. In questo frangente i dati non sono plausibili.
  // Viene quindi fatto andare il protocollo a regime prima dell'invio dei dati su seriale
  while(time1-time < 500){
    POZYX_I2C_ADDRESS = 0x4B;
    status = Pozyx.doPositioning(&tag1.position, dimension, height, algorithm);

    POZYX_I2C_ADDRESS = 0x4A;
    status1 = Pozyx.doPositioning(&tag2.position, dimension, height, algorithm);
    time1 = millis();
  }
   
}

void loop(){

    POZYX_I2C_ADDRESS = 0x4B;
    status = Pozyx.doPositioning(&tag1.position, dimension, height);                  // viene lanciato l'algoritmo di positioning
    if(status==1){                                                                       
      getDistance(&tag1);                                // vengono richieste le distanze dalle singole ancore
    }else{
      getDistance(&tag1); 
      zero(&tag1.position);
    }

//    POZYX_I2C_ADDRESS = 0x4A;                                                         // vengono ripetute le stesse operazioni per il secondo tag
//    status1 = Pozyx.doPositioning(&tag2.position, dimension, height);
//    if(status1==1){
//      getDistance(&tag2);
//    }else{
//      getDistance(&tag2);
//      zero(&tag2.position);
//    }

    if(binario){
    // printing del carattere di inizio stringa secondo codifica per la lettura da parte dell'autopilota
    NewSerial.write("BB");                                                  
    }
    
    // printing dei dati
    printData(tag1);
    //printData(tag2);

    if(binario){
      // printing errore. CODIFICA: 1 = errore solo del tag 1; 2 = errore solo del tag 2; 3 = errore di entrambi i tag;
      NewSerial.write(error_pos(&tag1.position) + 2*error_pos(&tag2.position));     
    }else{
      //NewSerial.println(error_pos(&tag1.position) + 2*error_pos(&tag2.position)); 
      NewSerial.print(status); 
      NewSerial.print(" ");
      NewSerial.println(error_pos(&tag1.position));
    }

}



//Stampa il pacchetto di dati da inviare
void printData(dati tag){
    printCoordinates(tag.position);
    for(int i = 0; i < num_anchors; i++){
      if(binario){
        print4_u(&tag.distance[i]);
      }else{
        NewSerial.print(tag.distance[i]);
        NewSerial.print(" ");
      }
    }    
}

// ottiene le distanze salvate nei registri delle ancore l'ultima volta che sono state calcolate
void getDistance(dati *tag){
      for(int i = 0; i < num_anchors; i++){
        Pozyx.getDeviceRangeInfo(anchors[i], &device_range_aux, remote_id);
        tag->distance[i] = device_range_aux.distance;
      }   
}

//stampa le coordinate
void printCoordinates(coordinates_t coor){
      if(binario){
        print4(coor.x);
        print4(coor.y);
        print4(coor.z);
      }else{
        NewSerial.print(coor.x);
        NewSerial.print(" ");
        NewSerial.print(coor.y);
        NewSerial.print(" ");
        NewSerial.print(coor.z);
        NewSerial.print(" ");
      }
}

//stampa di un intero di 4 bytes
void print4(int32_t var){
  unsigned char* tempP;
  tempP = (unsigned char*)&var;
  for(int i = 0; i< 4 ; i++){
    NewSerial.write(tempP[i]);
  }  
}

//stampa di un intero senza segno di 4 bytes
void print4_u(uint32_t var){
  unsigned char* tempP; 
  tempP = (unsigned char*)&var;
  for(int i = 0; i< 4 ; i++){
    NewSerial.write(tempP[i]);
  }  
}

//viene ricercato un errore nel positioning: quando l'algoritmo fallisce le coordinate risultano tutte pari a zero
int error_pos(coordinates_t* c){
  if((c->x == 0) & (c->y == 0) & (c->z == 0))
    return POS_ERROR;
  return POS_SUCCESS;
}
  
// funzione che setta manualmente le coordinate delle ancore
void setAnchorsManual(){
  for(int i = 0; i < num_anchors; i++){
    device_coordinates_t anchor;
    anchor.network_id = anchors[i];
    anchor.flag = 0x1;
    anchor.pos.x = anchors_x[i];
    anchor.pos.y = anchors_y[i];
    anchor.pos.z = heights[i];
    Pozyx.addDevice(anchor, remote_id);
  }
  if (num_anchors > 4){
    Pozyx.setSelectionOfAnchors(POZYX_ANCHOR_SEL_AUTO, num_anchors, remote_id);
  }
}

// richiede alle ancore le ultime coordinate salvate dalla calibrazione
int getAnchorsCoordinates(){
  int stato = 0;
  coordinates_t anchor_coor;
  for(int i = 0; i < num_anchors; i++){
    stato = stato + Pozyx.getDeviceCoordinates(anchors[i], &anchor_coor, anchors[i]);
    anchors_x[i] = anchor_coor.x;
    anchors_y[i] = anchor_coor.y;
    heights[i] = anchor_coor.z;
  }
  return stato/4;
}

//pone a zero se il positioning fallisce
void zero(coordinates_t* coor){
  coor->x = 0;
  coor->y = 0;
  coor->z = 0;  
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
