Questo file descrive il contenuto della cartella.
In particolare è contenuto il materiale relativo alla modifica della frequenza di 
lavoro del sistema Pozyx.
Il file è stato utilizzato su un sistema Linux.
Sono presenti:

################################################################
#######             test_frequenza.py                  #########
################################################################
Script python che imposta i parametri UWB dei dispositivi connessi alla rete e comincia ad acquisire
i dati sulla frequenza e sul risultato del Positioning del tag.
I dati vengono salvati nella rispettiva cartella.


################################################################
#######             rangeToPos.py                      #########
################################################################
Script python per l'algoritmo algebrico di positioning. E' come rangesToPos.m ma per python.
Riadatta i risultati in un formato comodo per la libreria pypozyx.



################################################################
#######                  Canale5                       #########
################################################################
In essa sono contenute due cartelle:
 1)PROTOCOL_FAST
 2)PROTOCOL_PRECISION
Contiene 48 file .txt relativi alle prove con tutte le possibili combinazioni dei parametri UWB:
         - bitrate = [110,850,6810] kb/s
         - PRF = [16,64] MHz
         - Preamble lenght = [64,128,512,1024,1536,2048,4096]



################################################################
#######           frequenza_alg_PRECISION.m             ########
################################################################
Calcola indici statistici dei dt ed effettua i relativi grafici, al variare dei parametri UWB.
In particolare prevede che siano forniti 48 tipi di dati diversi, derivanti da 48 opportune simulazioni 
(combinazioni di tutti i possibili valori dei prametri UWB). Il protocollo utilizzato è PRECISION.



################################################################
#######           frequeza_alg_PRECISION_64.m          #########
################################################################
Calcola indici statistici dei dt ed effettua i relativi grafici, al variare dei parametri UWB.
In particolare prevede che siano forniti 24 tipi di dati diversi, derivanti da 24 opportune simulazioni 
(combinazioni di tutti i possibili valori dei prametri UWB, fissato PRF a 64Mhz). Il protocollo utilizzato è PRECISION.

################################################################
#######          frequeza_alg_FAST.m                   #########
################################################################
Calcola indici statistici dei dt ed effettua i relativi grafici, al variare dei parametri UWB.
In particolare prevede che siano forniti 48 tipi di dati diversi, derivanti da 48 opportune simulazioni 
(combinazioni di tutti i possibili valori dei prametri UWB). Il protocollo utilizzato è FAST.


################################################################
#######          frequeza_alg_FAST_64.m                #########
################################################################
Calcola indici statistici dei dt ed effettua i relativi grafici, al variare dei parametri UWB.
In particolare prevede che siano forniti 24 tipi di dati diversi, derivanti da 24 opportune simulazioni 
(combinazioni di tutti i possibili valori dei prametri UWB, fissato PRF a 64Mhz). Il protocollo utilizzato è FAST.


################################################################
#######                    IMMAGINI                    #########
################################################################
Cartella  contenente le immagini contenute negli script sopra citati.


