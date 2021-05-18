%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 	   Bagalà Alfredo & Avantaggiato Sabrina
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ESPERIMENTO VARIAZIONE_CLOCK 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Questo esperimento carcola la frequenza di lavoro  e l'update rate al variare della 
frequenza del clock del bus I2C.
l'influenza delLa variazione della frequenza del clock è stata valutata sia per l'istruzione di
Ranging che per l'istruzione di Positioning.
Infatti nelle cartelle, sono riportati i dati relativi sia al Ranging che al Positioning.

Ogni cartella contiene due file .txt che si riferiscono a due distinte prove:
- Wireclock = 100 kHz
- Wireclock = 400 kHz

Ogni file txt contiene due colonne di dati:
	|| tempo || durata istruzione considerata ||
	|| [ms]  ||            [ms]               ||
	||-------||-------------------------------||
	
- 1 colonna --> tempo al loop i-esimo. La differenza tra due tempi successivi 
		restituisce la durata del loop; è utilizzato per calcolare 
		l'update rate.

- 2 colonna --> durata della singola istruzione considerata ( doPositioning o
 		doRanging)	
	
Gli script EsperimentiRanging.m e EsperimentiPositioning.m analizzano la frequenza e 
l'update Rate.
Per rprodurre l'esperimento bisogna caricare uno degli sketch presenti nella cartella sketch di base.
Per ottenere però la durata della singola istruzione, è necessario inserire un ulteriore contatatore che 
viene incrementato subito dopo l'istruzione di interesse.
Per settare il clock l'istruzione da usare prima del setup è Wire.setclock(400).
Di default, è settato a 100kHz.

