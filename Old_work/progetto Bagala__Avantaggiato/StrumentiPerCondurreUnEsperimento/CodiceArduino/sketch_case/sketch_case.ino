//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*                                                      PROGETTO DI GUIDA E NAVIGAZIONE
                                                     AVANTAGGIATO SABRINA E ALFREDO BAGALA'                                                 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Questo sketch serve per calcolare le coordinate di due tag attraverso l'utilizzo di Arduino. Nello specifico vengono impostati quattro casi 
   di configurazione, descritte di seguito nel loop, e testate per 250 campioni ciascuno. Questo rende possibile verificare il funzionamento 
   di tutte le combinazioni pensate in situazioni simili (presenza o meno di disturbo, distanza dalle ancore, eventuali ostacoli interposti).
   Innanzitutto bisogna impostare gli id delle ancore - NOTA: l'ordine con cui viene definito il network definirà il SDR del sistema Pozyx. 
   Una volta fatto ciò è possibile definire se il tag di cui si vuol avere informazioni è remoto o locale: in tale sketch solo il secondo di 
   questi casi è preso in considerazione. Qualora si volesse invece interrogare un dispositivo in remoto bisognerà sostituire doPositioning 
   con doRemotePositioning. La comunicazione seriale in questo sketch è affidata alla libreria SerialPort (Serial-->NewSerial).
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
////////////////// PARAMETRI ///////////////////
////////////////////////////////////////////////

//////////////////!!!!!!!!!!!//////////////////
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

int conta = 1;
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

  // se calibrazione = true vengono richieste le coordinate salvate nelle ancore durante l'ultima calibrazione e vengono inserite negli opportuni vettori.
  // controllo del buon esito dell'operazione altrimenti viene bloccata l'esecuzione
  // in caso contrario vengono prese le coordinate da inserire manualmente nei vettori anchors_x, anchors_y, height
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
  Pozyx.getTxPower(&gain2, 0x671A);                                         // ottengo l'informazione sul guadagno impostato nel secondo tag
  Pozyx.getUWBSettings(&set2, 0x671A);                                      // ottengo l'informazione sui parametri UWB impostati nel secondo tag
  
  POZYX_I2C_ADDRESS = 0x4A;                                                 // vengono ripetute le stesse operazioni per il secondo tag
  setAnchorsManual();                                                       // set manuale delle ancore
  Pozyx.setRangingProtocol(ranging_protocol);                               // set dell'algoritmo di ranging  
  Pozyx.setPositionAlgorithm(algorithm, dimension, remote_id);              // set dell'algoritmo di positioning 
  Pozyx.getTxPower(&gain1, 0x675E);                                         // ottengo l'informazione sul guadagno impostato nel primo tag
  Pozyx.getUWBSettings(&set1, 0x675E);                                      // ottengo l'informazione sui parametri UWB impostati nel secondo tag
  
  // set del clock di comunicazione I2C
  Wire.setClock(400000);
  delay(200);

  //printing della configurazione dei parametri UWB 
  printUWBparam(gain1,set1);
  printUWBparam(gain2,set2);
  NewSerial.println();
  
  // l'algoritmo di positioning ha un tempo di transitorio prima di andare a regime. In questo frangente i dati non sono plausibili.
  // Viene quindi fatto convergere l'algoritmo prima dell'invio dei dati su seriale
  while(time1-time < 500){
    POZYX_I2C_ADDRESS = 0x4B;
    status = Pozyx.doPositioning(&tag1.position, dimension, height, algorithm);

    POZYX_I2C_ADDRESS = 0x4A;
    status1 = Pozyx.doPositioning(&tag2.position, dimension, height, algorithm);
    time1 = millis();
  }
   
}

void loop(){
    time = micros();

/* Si effettua uno switch tra 4 casi, ma a parità di pacchetti inviati su seriale:
 *  1. richiesta di informazioni (positioning e ranging) solo al tag con indirizzo I2C 0x4A;
 *  2. richiesta di informazioni (positioning e ranging) solo al tag con indirizzo I2C 0x4B;
 *  3. richiesta di informazioni (positioning e ranging)ad entrambi con la successione 0x4A - 0x4B;
 *  4. richiesto di informazioni (positioning e ranging)ad entrambi con la successione 0x4B - 0x4A.
 *  Il caso 5 serve solo ad azzerare il contatore. 
 *  
 *  Da notare come in questo caso le ultime distanze calcolate vengano chieste anche nel momento in
 *  cui il positioning fallisce, in modo da non manipolare i dati
 */
    switch(conta/250%5){
          case 0:       \\ aggiorno solo 0x4A, il resto 0
              POZYX_I2C_ADDRESS = 0x4A;                                                         
              status1 = Pozyx.doPositioning(&tag2.position, dimension, height);
              if(status1){
                getDistance(&tag2, device_range_aux, remote_id);
              }else{
                getDistance(&tag2, device_range_aux, remote_id);
                zero(&tag2.position);
              }

              status = 0;
              zero(&tag1.position);
              zeroDist(&tag1);
          break;
   
          case 1:       \\ aggiorno solo 0x4B, il resto 0
              POZYX_I2C_ADDRESS = 0x4B;                                                         
              status = Pozyx.doPositioning(&tag1.position, dimension, height);
              if(status){
                getDistance(&tag1, device_range_aux, remote_id);
              }else{
                getDistance(&tag1, device_range_aux, remote_id);
                zero(&tag1.position);
              }

              status1 = 0;
              zero(&tag2.position);
              zeroDist(&tag2);
          break;
          
          case 2:       \\ aggiorno 0x4A e dopo 0x4B
              POZYX_I2C_ADDRESS = 0x4A;                                                         
              status1 = Pozyx.doPositioning(&tag2.position, dimension, height);   // viene lanciato l'algoritmo di positioning             
              if(status1){
                getDistance(&tag2, device_range_aux, remote_id);                  // vengono richieste le distanze dalle singole ancore
              }else{
                getDistance(&tag2, device_range_aux, remote_id);
                zero(&tag2.position);
              }

              POZYX_I2C_ADDRESS = 0x4B;
              status = Pozyx.doPositioning(&tag1.position, dimension, height);                  
              if(status){                                                                       
                getDistance(&tag1, device_range_aux, remote_id);                                
              }else{
                getDistance(&tag1, device_range_aux, remote_id);
                zero(&tag1.position);
              }               
          break;
          
          case 3:       \\ aggiorno 0x4B e dopo 0x4A
             POZYX_I2C_ADDRESS = 0x4B;
            status = Pozyx.doPositioning(&tag1.position, dimension, height);                  // viene lanciato l'algoritmo di positioning
            if(status){                                                                       
              getDistance(&tag1, device_range_aux, remote_id);                                // vengono richieste le distanze dalle singole ancore
            }else{
              getDistance(&tag1, device_range_aux, remote_id); 
              zero(&tag1.position);
            }
        
            POZYX_I2C_ADDRESS = 0x4A;                                                         // vengono ripetute le stesse operazioni per il secondo tag
            status1 = Pozyx.doPositioning(&tag2.position, dimension, height);
            if(status1){
              getDistance(&tag2, device_range_aux, remote_id);
            }else{
              getDistance(&tag2, device_range_aux, remote_id);
              zero(&tag2.position);
            }
          break;
          case 4:
              conta = 1;
          break;  
    }


    // printing dei dati
    printData(tag1);
    printData(tag2);

    // printing status. CODIFICA: 1 = successo solo del tag 1; 2 = successo solo del tag 2; 3 = successo di entrambi i tag;
    NewSerial.print(status+ 2*status1); 
    NewSerial.print(" ");
    // printing errore. CODIFICA: 1 = errore solo del tag 1; 2 = errore solo del tag 2; 3 = errore di entrambi i tag;
    NewSerial.print(error_pos(&tag1.position) + 2*error_pos(&tag2.position));  
    NewSerial.print(" ");         
    NewSerial.print(time);                                                       // printing del tempo per analisi in post-processing
    NewSerial.print(" ");
    NewSerial.println(conta/250%5);
    conta = conta + 1;
}


// ottiene le distanze salvate nei registri delle ancore l'ultima volta che sono state calcolate
void getDistance(dati *tag, device_range_t device_range, uint16_t remote_id){
      for(int i = 0; i < num_anchors; i++){
        Pozyx.getDeviceRangeInfo(anchors[i], &device_range, remote_id);
        tag->distance[i] = device_range.distance;
      }
      
}

//stampa il pacchetto di dati da inviare
void printData(dati tag){
    printCoordinates(tag.position);
    for(int i = 0; i < num_anchors; i++){
      NewSerial.print(tag.distance[i]);
      NewSerial.print(" ");
    }    
}

//stampa le coordinate
void printCoordinates(coordinates_t coor){
      NewSerial.print(coor.x);
      NewSerial.print(" ");
      NewSerial.print(coor.y);
      NewSerial.print(" ");
      NewSerial.print(coor.z);
      NewSerial.print(" ");
}

// viene ricercato un errore nel positioning: quando l'algoritmo fallisce le coordinate risultano tutte pari a zero
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

// richiede alle ancore le ultime coordinate salvate dalla calibrazione
int getAnchorsCoordinates(){
  int stato = 0;
  coordinates_t anchor_coor;
  for(int i = 0; i < num_anchors; i++){
    NewSerial.print("ANCHOR,");
    NewSerial.print("0x");
    NewSerial.print(anchors[i], HEX);
    NewSerial.print(",");
    stato = stato + Pozyx.getDeviceCoordinates(anchors[i], &anchor_coor, anchors[i]);
    anchors_x[i] = anchor_coor.x;
    anchors_y[i] = anchor_coor.y;
    heights[i] = anchor_coor.z;
    NewSerial.print(anchors_x[i]);
    NewSerial.print(",");
    NewSerial.print(anchors_y[i]);
    NewSerial.print(",");
    NewSerial.println(heights[i]);
  }
  return stato/4;
}

//pone a zero se il positioning fallisce
void zero(coordinates_t* coor){
  coor->x = 0;
  coor->y = 0;
  coor->z = 0;  
}

//pone a zero le distanze
void zeroDist(dati* tag){
  for (int i = 0; i < num_anchors; i++){
    tag->distance[i] = 0;
  }
}
