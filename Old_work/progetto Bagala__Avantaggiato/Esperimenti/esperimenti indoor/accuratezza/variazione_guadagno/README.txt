%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%
       Avantaggiato Sabrina & Bagalà Alfredo 

%%%%%%%%%%%%%%%%%%%%%%%%%%%% VARIAZIONE DEL GAIN %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
In questi esperimenti viene valutata l'accuratezza del positioning e del ranging al variare 
del gain.
Sono stati riportati i dati di due esperimenti lasciando i due tag fermi nella stessa 
posizione.

Nelle cartelle "1 esperimento" e "2 esperimento" sono contenuti i dati raccolti durante
l'esperimento, variando il gain.
In ogni riga dei dati raccolti sono presenti le seguenti misure:

-----------1 tag--------------------------------|| ----------------2 tag---------------------------|| errore  || tempo ||
coord_x coord_y coord_z dist0 dist1 dist2 dist3 ||coord_x coord_y coord_z dist0 dist1 dist2 dist3  ||{0,1,2,3}|| [ms]  ||
------------------------------------------------||-------------------------------------------------||---------||-------||
errore = 0 -> quando il doPositioning da esito positivo.
errore = 1 -> quando il doPositioning del 1 tag fallisce.
errore = 2 -> quando il doPositioning del 2 tag fallisce.
errore = 3 -> quando il doPositioning di entrambi i  tag fallisce.

Se si volesse riprodurre l'analisi dell'esperimento, è necessario avviare lo script di Matlab "variazione_gain".
Esso valuta i dati di ogni signolo file txt e crea una tabella 't' che riassume l'analisi.
lo script "variazione_gain" richiama altre funzioni:

analizza -> calcola media, deviazione standard e numeri di fallimenti della matrice dei dati in ingresso

elimina_overflow -> elimina per ogni colonna gli overflow, ovvero quei valori che superano una certa soglia da
noi definita nella funzione.

calcola_freq_UWB -> prelevando il vettore relativo al tempo, calcola frequenza media e deviazione della frequenza.

Lo sketch Arduino correlato a questo esperimento è sketch_serial o sketch_newserial presenti nella cartella sketch di base .
NOTA : per variare il gain è però necessario utilizzare lo sketch presente in useful : pozyx_gain_configurator
inizializzando la variabile gain con il valore desiderato.
