%%%%%%%%%%%%%%%  PROGETTO DI SISTEMI DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%
		    Bagalà Alfredo & Avantaggiato Sabrina

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ESPERIMENTO PER TESTARE L'AFFIDABILITA' DEL SISTEMA POZYX

L'esperimento che è stato condotto ha avuto l'obiettivo di analizzare i ranging ottenuti dai due tag
fermi e in movimento. Ci siamo focalizzati ad interpretare eventuali errori 
dichiarati dall'algoritmo osservando le misure ottenute, cercando di correlarli a qualche possibile 
errore nella comunicazione I2C con i due tag.
In particolare è stato realizzato uno sketch ad hoc, che shifta tra gli indrizzi dei tag in 
comunicazione I2C con Arduino.
Questo sketch restituisce i dati nel seguente modo:

-----------1 tag--------------------------------|| ----------------2 tag---------------------------|| status  ||errore   || tempo ||
coord_x coord_y coord_z dist0 dist1 dist2 dist3 ||coord_x coord_y coord_z dist0 dist1 dist2 dist3  ||{0,1,2,3}||{0,1,2,3}|| [ms]  ||
------------------------------------------------||-------------------------------------------------||---------||---------||-------||

errore = 0 -> quando il doPositioning  restituisce coordinate diverse da zero.
errore = 1 -> quando il doPositioning del 1 tag restituisce valori nulli di coordinate.
errore = 2 -> quando il doPositioning del 2 tag restituisce valori nulli di coordinate.
errore = 3 -> quando il doPositioning di entrambi i tag restituisce valori nulli di coordinate.

status = 0 -> quando l'algoritmo del doPositioning  fallisce.
status = 1 -> quando l'algoritmo del doPositioning del primo tag da esito positivo.
status = 2 -> quando l'algoritmo del doPositioning del secondo tag da esito positivo.
status = 3 -> quando il doPositioning di entrambi i tag da esito positivo.

I dati ottenuti da questo esperimento sono all'interno della cartella "Dati".
Per riprodurre lo stesso test bisogna lanciare lo sketch_case presente nella cartella 'ComeCondurreUnEsperimento'