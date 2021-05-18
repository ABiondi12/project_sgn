%%%%%%%%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		   Bagalà Alfredo & Avantaggiato Sabrina
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ESPERIMENTO UPDATE RATE DELLE ISTRUZIONI DI INTERESSE
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
In questo esperimento viene analizzato l'update rate delle istruzioni utilizzate nel loop
di Arduino.
Ogni cartella 'prova' contiente 2 altre cartelle relative agli esperimenti eseguiti 
rispettivamente con un tag e con 2 tag. Ognuna di queste sottocartelle contiene 
4 file txt che si riferiscono ai seguenti esperimenti:

1) doPositioning --> viene stampata a video una stringa contenente le coordinate
		     calcolate attraverso la funzione doPositioning e il tempo accumulato
		     ad ogni loop (la differenza tra due tempi successivi corrisponde
		     alla durata del loop stesso).
	I dati sono riportati nella seguente forma per i due tag:
	-----------1 tag--------|| ----------2 tag--------|| tempo ||
	coord_x coord_y coord_z ||coord_x coord_y coord_z || [ms]  ||
	------------------------||------------------------||-------||

	I dati sono riportati nella seguente forma per un tag:
	-----------1 tag--------|| tempo ||
	coord_x coord_y coord_z || [ms]  ||
	------------------------||-------||

2) doPositioningconGet -->  viene stampata a video una stringa contenente le coordinate
		            calcolate attraverso la funzione doPositioning, le distanze dalle 
			    ancore restituite dalla funzione GetDeviceRangeInfo e il tempo 
			    accumulato ad ogni loop (la differenza tra due tempi successivi 
			    corrisponde alla durata del loop stesso).
	
	I dati sono riportati nella seguente forma per i due tag:
	-----------1 tag--------------------------------|| ----------------2 tag---------------------------|| tempo ||
	coord_x coord_y coord_z dist0 dist1 dist2 dist3 ||coord_x coord_y coord_z dist0 dist1 dist2 dist3  || [ms]  ||
	------------------------------------------------||-------------------------------------------------||-------||
	
	I dati sono riportati nella seguente forma per un tag:
	-----------1 tag--------------------------------|| tempo ||
	coord_x coord_y coord_z dist0 dist1 dist2 dist3 || [ms]  ||
	------------------------------------------------||-------||

3) doRanging -->  viene stampata a video una stringa contenente le distanze dalle singole 
		  ancore calcolate attraverso la funzione doRanging e il tempo accumulato
		  ad ogni loop (la differenza tra due tempi successivi corrisponde
		  alla durata del loop stesso).

	I dati sono riportati nella seguente forma per i due tag:
	------------------------|| ---------------------------|| tempo ||
	 dist0 dist1 dist2 dist3|| dist0 dist1 dist2 dist3    || [ms]  ||
	------------------------||----------------------------||-------||
	
	I dati sono riportati nella seguente forma per un tag:
	----------------------- || tempo ||
	 dist0 dist1 dist2 dist3|| [ms]  ||
	----------------------- ||-------||

4) Get -->  viene stampata a video una stringa contenente le distanze dalle ancore
	    restituite dalla funzione GetDeviceRangeInfo e il tempo accumulato
	    ad ogni loop (la differenza tra due tempi successivi corrisponde
            alla durata del loop stesso).

I dati sono riportati nella seguente forma per i due tag:
	------------------------|| ---------------------------|| tempo ||
	 dist0 dist1 dist2 dist3|| dist0 dist1 dist2 dist3    || [ms]  ||
	------------------------||----------------------------||-------||
	
	I dati sono riportati nella seguente forma per un tag:
	----------------------- || tempo ||
	 dist0 dist1 dist2 dist3|| [ms]  ||
	----------------------- ||-------||

Lo script Esperimenti_istruzioni.m analizza i dati.
Per riprodurre l'esperimento bisogna caricare lo sketch di base (serial o newserial) e 
usare l'istruzione desiderata presente nella getDistance.



