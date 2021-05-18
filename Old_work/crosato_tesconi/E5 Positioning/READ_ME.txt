Come utilizzare questi file:
1) lanciare lo script acquisizioni_distanze_antenne.py
2) lanciare lo script Calibrazione_automatica.m, inserendo il nome del file da cui leggere 
  i dati. Le coordinate delle ancore sono salvate nelle variabili 'A0', 'A1', 'A2', 'A3'.
3) effettuare la misurazione manuale della distanza tra le antenne e tra le antenne e il tag
4) utilizzare lo script Calibrazione_manuale.m, inserendo le distanze tra le coppie di 
  ancore, ottenute dalla misurazione manuale precedente (punto 3).
  Le coordinate delle ancore sono salvate nelle variabili 'A0', 'A1', 'A2', 'A3', quelle del tag
  in 'AT_'.
5) lanciare lo script PosTag.py, inserendo prima le coordinate delle ancore ottenute da 
  Calibrazione_manuale.m poi da Calibrazione_automatica.m, ossia dai punti 2 e 4
6) utilizzare lo script PosTag_manuale.m, rinominando opportunamente il file da cui si vanno
	a leggere i dati.Il file fornirà inizialmente degli istogrammi contenenti i 
	dati originali. Ripulire tali dati da eventuali outlier selezionando gli intervalli di 
	interesse.
7) utilizzare lo script PosTag_automatico.m, rinominando opportunamente il file da cui si 
	vanno a  leggere i dati. Il file fornirà inizialmente degli istogrammi contenenti i 
	dati originali. Ripulire tali dati da eventuali outlier selezionando gli intervalli di 
	interesse.
8) Utilizzare Plot3D.m o Plot2D.m


####################################################
####	acquisizione_distanze_antenne.py	####
####################################################
Questo script python prevede un setup di 4 antenne ed un dispositivo collegato alla porta
USB del PC. Una volta lanciato vengono effettuate una serie di acquisizioni delle distanze
relative tra le 4 antenne del setup. Queste distanze vengono salvate nella cartella './dati'
in un formato del tipo 'distanza_coppie_antenne_0.txt'.
Tali dati vengono poi utilizzati per 



####################################################
####		PosTag.py			####
####################################################
Effettua il positioning del Tag (possibilità di fare sia tag remoto che tag seriale) 
e salva i risultati ottenuti nel file './dati/PosTag_i.txt'. Questi file devono essere impostati manualmente nello script
python. Vengono anche salvate le distanze tra il tag e le varie ancore ad ogni passo 
di iterazione dell'algoritmo di Positioning, in modo tale da garantire l'eventuale 
possibilità di confrontare l'algoritmo di Positioning di Pozyx con altri algoritmi.
Le coordinate delle ancore devono essere inserite manualmente. E' necessario quindi
effettuare prima un'acquisizione delle distanze tra le coppie di antenne mediante i 
file python presenti in ESPERIMENTO 4 ed inserire le coordinate così ottenute all'interno
di questo script.

####################################################
####		PlotPos3D.m			####
####################################################
Plot 3D delle posizioni delle ancore e del tag. Vengono prima mostrate le immagini delle 
ancore, poi le immagini del tag e infine del sistema complessivo.

####################################################
####		PlotPos2D.m			####
####################################################
Immagini in pianta. Come Plot 3D.

####################################################
####		Calibrazione_manuale.m		####
####################################################
Questo script permette di effettuare una calibrazione delle ancore con
range di ingresso all'algoritmo misurati manualmente col metro laser. 
EFfettua inoltre il calcolo della propagazione dell'errore e salva i dati
in un file .mat.

####################################################
####		Calibrazione_automatica.m	####
####################################################
Questo script permette di effettuare una calibrazione delle ancore con
range di ingresso all'algoritmo ottenuti dall'autoranging effettuato con 
lo script python acquisizioni_distanze_antenne.py. 
Effettua il calcolo degli indici statistici e salva i dati in un file .mat.



####################################################
####		Cartella './dati'		####
####################################################
Quando viene lanciato lo script python 'PosTag.py', viene generato in questa cartella il 
file 'PosTag_i.txt'.
I file 'PosTag_automatico.txt' e 'PosTag_manuale.txt' sono dei file inizialmente salvati 
come 'PosTag_i.txt' e poi da noi rinominati per l'analisi dei dati della relazione.
Sono poi presenti alcuni file .mat che servono per realizzare i grafici 2D e 3D.
Infine il file 'distanza_coppie_antenne_0.txt' contiene una lista di acquisizioni delle 
distanze relative tra le coppie di antenne ottenuta tramite lo script 
'acquisizioni_distanze_antenne.py', viene utilizzato dallo script 'Calibrazione_automatica.m'.


