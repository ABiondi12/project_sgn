%%%%%%%%%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		   Bagalà Alfredo & Avantaggiato Sabrina
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ESPERIMENTI OUTDOOR

POSITIONING E RANGING
Sono stati svolti alcuni esperimenti per testare il funzionamento delle antenne outdoor.
Nella cartella 'Dati' sono riportate le misure ottenute.
In particolare in:
- outdoor2 : sono presenti i dati relativi al positioning e al ranging dei due tag, 
	distanziati di 40 cm e ad un altezza di due metri dal terreno.
	L'ancora 0 si trova a 20 m sia dall'ancora 1 che alla 2.
	I dati sono così riportati:
	-----------1 tag--------------------------------|| ----------------2 tag---------------------------|| errore  || tempo ||
	coord_x coord_y coord_z dist0 dist1 dist2 dist3 ||coord_x coord_y coord_z dist0 dist1 dist2 dist3  ||{0,1,2,3}|| [ms]  ||
	------------------------------------------------||-------------------------------------------------||---------||-------||

errore = 0 -> quando il doPositioning da esito positivo.
errore = 1 -> quando il doPositioning del 1 tag fallisce.
errore = 2 -> quando il doPositioning del 2 tag fallisce.
errore = 3 -> quando il doPositioning di entrambi i tag fallisce.

- outdoor3 :  sono presenti i dati relativi al positioning e ranging dei due tag, 
	distanziati di 40 cme ad un altezza di due metri dal terreno.
	L'ancora 0 si trova a 30 m sia dall'ancora 1 che alla 2.
I dati sono così riportati:
	-----------1 tag--------------------------------|| ----------------2 tag---------------------------|| errore  || tempo ||
	coord_x coord_y coord_z dist0 dist1 dist2 dist3 ||coord_x coord_y coord_z dist0 dist1 dist2 dist3  ||{0,1,2,3}|| [ms]  ||
	------------------------------------------------||-------------------------------------------------||---------||-------||

errore = 0 -> quando il doPositioning da esito positivo.
errore = 1 -> quando il doPositioning del 1 tag fallisce.
errore = 2 -> quando il doPositioning del 2 tag fallisce.
errore = 3 -> quando il doPositioning di entrambi i tag fallisce.

Vengono analizzati positioning e ranging relativi ai due tag attraverso lo script 
Esperimentioutdoor2.m
Lo sketch di Arduino usato per effettuare questo esperimento è presente nella cartella sketch_base o in sketch final 
aprendo sketch new_serial (o sketch_serial se si vuole usare la seriale standand di Arduino)



RANGING
Sono stati svolti alcuni esperimenti per testare la distanza massima di comunicazione
tra i due tag e un antenna in ambiente outdoor.
Lasciando l'ancora 0 fissa, ci muovevamo lungo una linea fermandoci a prelevare misure di
ranging ogni 5 metri.
Nella cartella 'Dati' sono riportate le misure ottenute sia con il gain massimo(33) che 
con gain impostato da default(11.5) e al variare del bitrate.
I dati sono riportati nel seguente modo:

	|| errore  ||-----------1 tag------|| errore  ||---------2 tag--------|| tempo ||
	||{0,1}    ||          dist0       ||{0,1}    ||         dist0        || [ms]  ||
	||---------||----------------------||---------||----------------------||-------||

errore = 1 -> quando il doRanging da esito positivo.
errore = 0 -> quando il doRanging fallisce.

Vengono analizzati i ranging relativi ai due tag attraverso lo script 
esperimentioutdoor.m.
Lo sketch di Arduino usato per effettuare questo esperimento è presente nella cartella sketch_final 
aprendo il file ranging_newserial (o ranging_serial se si usa la libreria seriale standard di Arduino)
