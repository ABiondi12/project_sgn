In questa cartella sono presenti vari script per il setup di una rete Pozyx e per effettuare le 
misurazioni del Positioning.

﻿Come utilizzare questi file:
0) utilizzare lo script set_UWB_parameters.py per impostare i parametri UWB desiderati alle varie ancore. Per farlo basta lancirare lo script avendo collegato alla seriale il dispositivo di cui
si desidera impostare i parametri UWB. 
1) lanciare lo script autocalibration_ransac.py, che effettuerà un'autocalibrazione del sistema.
5) lanciare lo script acquisizione_dati.py. Occorre aprire il codice dello script e cambiare i seguenti parametri:
	- dist: rappresenta la distanza a cui viene effettuato il positioning (quella riferita
		alla rotella metrica), che modificherà l'intestazione del file .txt generato contenente i 			i dati dell'aquisizione.
	- N: numero di acquisizioni da effettuare.

I dati vengono salvati nella cartella Dati, il file si chiama PosTag_i.txt. Il numero intero che
identifica il file è automaticamente generato.

Gli script ransac.py e rangesToPos.py sono moduli importati in autocalibration_ransac.py e acquisizione_dati.py. Devono quindi trovarsi nella stessa cartella di quest'ultimi due script.

File matlab:
1) Distanza_massima.m realizza gli istogrammi e calcola le varianze dei dati acquisiti,
	ripulendo eventuali dati esageratamente fuori scala.
2) Distanza_massima_original.m realizza gli istrogrammi dei dati ottenuti, senza ripulire.
3) save_as.m è una function utilizzata negli altri script
4) grafici.m fa i grafici.


