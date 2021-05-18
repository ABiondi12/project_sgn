%%%%%%%%%%PROGETTO DI SISTEMI DI GUIDA E NAVIGAZONE %%%%%%%%%%%%%%%%%
	     Bagalà Alfredo & Avantaggiato Sabrina

%%%%%%%%%%%%%%%%%CONFRONTO PORTE SERIALI %%%%%%%%%%%%%%%%%%%%

In questa sezione sono state confrontate le frequenze di lavoro ottenute utilizzando 
la libreria standard di Arduino e la libreria SerialPort.h
Nelle cartelle 'provanewSerial' sono riportati i dati ottenuti includendo la SerialPort
utilizzando sia un tag che due tag. Ogni cartella si riferisce al singolo esperimento.
In ogni cartella sono presenti i seguenti file:


- NewSerial2tag.txt : riporta i dati relativi a entrambi i tag.
  I dati sono stati ricavati nella seguente forma :
-----------1 tag--------------------------------|| ----------------2 tag---------------------------|| tempo ||
coord_x coord_y coord_z dist0 dist1 dist2 dist3 ||coord_x coord_y coord_z dist0 dist1 dist2 dist3  || [ms]  ||
------------------------------------------------||-------------------------------------------------||-------||


- NewSerial.txt : riporta i dati relativi a un solo tag.
  I dati sono stati ricavati nella seguente forma :
-----------1 tag--------------------------------|| tempo ||
coord_x coord_y coord_z dist0 dist1 dist2 dist3 || [ms]  ||
------------------------------------------------||-------||

Lo script EsperimentiNewSerial.m analizza i dati ottenuti.
Appena aperto lo script, bisogna definire cd inserendo la cartella relativa all'esperimento che si vuole analizzare
in termini di frequenza media e deviazione dei valori della frequenza.
Per riprodurre l'esperimento bisogna aprire lo sketch di base serial o new serial a seconda se si vuole
utilizzare rispettivamente la seriale standard o la serialPort.










