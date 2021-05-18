Questa cartella contiene tutti gli sketch prodotti o customizzati
in questo progetto.
Nella cartella useful sono presenti gli sketch prodotti dalla Pozyx e da noi 
adattati per un utilizzo di due tag contemporanei e della libreria SerialPort.
In particolare:

- pozyx_gain_configurator_2tag --> permette di settare il parametro UWB gain di 
				   tutti i dispositivi Pozyx ;

- pozyx _UWB_configurator --> permette di settare i restanti parametri UWB (bitrate,
			      channel, prf, plen) di tutti i dispositivi Pozyx.
			      N.B. il gain viene settato di default a
		              seconda del valore degli altri parametri.

	NOTA : I commenti presenti nei singoli sketch, illustrano le modifiche 
	da apportare qualora si volesse utilizzare la Seriale standard di Arduino.

Le restanti cartelle si riferiscono a due versioni differenti degli stessi sketch. 

In "sketch_base" ci sono:

- sketch_base_newserial --> esegue le operazioni di Positioning e Ranging, stampando
			    i risultati sul monitor Seriale, tramite utilizzo della
			    libreria SerialPort (in allegato nella cartella 'Librerie');

- sketch_base_newserial_binario --> esegue le operazioni di Positioning e Ranging, 
				    stampando i risultati in formato binario, tramite 
				    utilizzo della libreria SerialPort (in allegato 
				    nella cartella 'Librerie');

- sketch_base_Serial --> esegue le operazioni di Positioning e Ranging, stampando
			 i risultati sul monitor Seriale, tramite utilizzo della
			 libreria seriale standard di Arduino.

In "sketch_final" ci sono le versioni finali degli stessi di sopra con l'unica differenza 
che non è necessario inserire le coordinate dopo la calibrazione, ma possono essere
automaticamente richieste alle ancore (e stampate). Questa possibilità è gestita dalla
variabile booleana "calibrazione". Inoltre sketch_newserial_binario permette ora di 
stampare sia in binario che in decimale, settando opportunamente la variabile booleana
"binario". Infine, sono presenti anche i seguenti sketch:

- ranging_newserial --> esegue il Ranging tra tag ed un'ancora di cui va specificato l'id, 
		    	stampando i risultati sul monitor Seriale, tramite utilizzo della
			libreria SerialPort (in allegato nella cartella 'Librerie');

- ranging_serial --> esegue il Ranging tra tag ed un'ancora di cui va specificato l'id, 
		    stampando i risultati sul monitor Seriale, tramite utilizzo della
		    libreria seriale standard di Arduino.
