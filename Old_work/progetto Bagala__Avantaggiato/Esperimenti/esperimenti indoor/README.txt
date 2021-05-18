%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%%%%%
        Bagalà Alfredo & Avantaggiato Sabrina

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ESPERIMENTI INDOOR
L'obiettivo ultimo degli esperimenti indoor è stato quello di caratterizzare 
il funzionamento del sistema Pozyx da due punti di vista:
- determinare l'accuratezza e la precisione delle misure ricavate
- determinare la velocità alla quale, posizioni e coordinate dei tag, vengono aggiornate.
 
La cartella 'accuratezza' contiene il materiale utilizzato per effettuare l'esperimento.
Sono presenti i dati, le figure e gli script matlab utili all'analisi.
Gli esperimenti relativi a questa sezione :
- 2 tag fermi : 		analizza precisione e accuratezza dei dati ottenuti lasciando i due tag fermi
				nello stesso punto 
- variazione gain :		analizza la correlazione tra precisione e valore di gain impostato.

La cartella 'update rate' contiene a sua volta le seguenti cartelle corrispondenti ai singoli esperimenti:
- confronto porte seriali :     sono stati ricavati, in fase preliminare, gli update rate di posizioni e distanze
				utilizzando le due diverse librerie di porta seriale ( seriale standard di Arduino 
				e la libreria SerialPort).

- istruzioni di interesse : 	contiene il materiale per l'esperimento finalizzato a ricavare gli
				update rate delle istruzioni impiegate nel loop di Arduino, 
				necessarie per la localizzazione del tag

- parametri UWB 	  : 	L'esperimento ha condotto diverse prove sperimentali finalizzate a ricavare 
				la configurazione UWB ottimale da settare a tutti i device per ottenere 
				il massimo update_rate

- variazione_clock 	  : 	Questo esperimento ha confrontato gli update rate di Positioning e di Ranging 
				variando la velocità di comunicazione del bus I2C. Ha esaltato dunque 
				l'importanza di settare la massimo velocità di comunicazione.

- variazione_guadagno 	  : 	é stato variato il guadagno per analizzare un'eventuale correlazione tra 
				gain e variazione di frequenza