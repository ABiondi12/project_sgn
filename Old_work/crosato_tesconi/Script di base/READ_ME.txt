In questa cartella sono presenti gli script utilizzati per effettuare un'autocalibrazione
delle ancore e il positioning del tag.


################################################################
######			autocalibration_ransac.py			############
################################################################
Pacchetti da installare:
	matplotlib
	python3-tk
	numpy
	scipy
	
Eseguire lo script:
Da Windows: aprire un ambiente di sviluppo tipo Pyzo e lanciare lo script.
Da Linux aprire un terminale ed eseguire come amministratore:
	$ sudo python3 autocalibration.py

Questo script effettua un'autocalibrazione delle ancore. Per farlo funzionare occorre 
per prima cosa avere quattro ancore correttamente alimentate ed un dispositivo Pozyx connesso
alla porta USB del PC il quale servirà da comunicazione seriale tra la rete Pozyx e l'utente.
L'autocalibrazione prevede un'acquisizione delle distanze tra le coppie di ancore e l'utilizzo 
dell'algoritmo ransac per ottenere i valori delle distanze stesse.
L'algoritmo ransac pulisce le misure da eventuali outliers e i suoi parametri sono settati nello 
script. E' comunque possibile andare a cambiare i parametri dell'algoritmo dalla shell. In questo 
modo non e' necessario riaquisire nuovamente le misure se l'algoritmo non converge ma possono essere
reimpostati run time i parametri dell'algoritmo per effettuare nuove prove dell'algoritmo ransac.
I dati 'raw' vengono plottati nell'immagine raw_distances.png mentre i dati fittati con l'algoritmo 
ransac, qualora questo abbia avuto successo, sono salvati in autocalibration_results.png.
E' infine possibile lanciare anche una versione meno recente dello script di autocalibrazione che
non ripulisce i dati da outliers (no algoritmo ransac). Tuttavia sconsigliamo tale metodo in quanto
la procedura con l'algoritmo ransac è più affidabile e lo script è più aggiornato.

Il dispositivo seriale può, a discrezione dell'utente, essere un'ancora o un tag. 

N.B.: 	per la comunicazione seriale può eventualmente essere utilizzata una delle ancore per le 
		quali si vuole effettuare l'autocalibrazione, utilizzando quindi un totale di 4 (non 5!)
		dispositivi Pozyx per effettuare l'autocalibrazione.
		  
In fondo allo script (dopo if __name__ == "__m ain__":) è possibile andare a settare i vari 
parametri della rete:
	- auto_cal =	mettere a True se si vuole fare autocalibrazione, False se si vuole effettuare 
					una calibrazione manuale.
	- serial_id = 	id del dispositivo connesso alla porta seriale. Esso è stampato sulla schedina
					elettronica del dispositivo stesso ed è un numero esadecimale (es. 0x6e7a)
	- anchor_ids =	id delle ancore che vogliono essere utilizzate. Da inserire in una lista ordi-
					nata.
					
	- Vari Parametri dell'Ultra Wide Band, meglio indicati nello script stesso.
	- Vari Parametri dell'algoritmo RANSAC
	
Una volta terminata la calibrazione, sia questa stata manuale o automatica, ciascuna ancora avrà 
salvata nella propria lista dei dispositivi, le proprie coordinate. Questi dati sono quindi salvati
permanentemente nella memoria flash  dei dispositivi.

Sempre nella funzione main è possibile settare i parametri UWB.

La procedura di autocalibrazione è così articolata:
1)	viene fornita sul terminale il risultato della comunicazione UWB dei dispositivi, se i disposivi
	hanno tutti gli stessi parametri, si può procedere con la calibrazione, altrimenti questa dovrà
	essere interrotta.
2)	se i parametri UWB dei dispositivi sono differenti e non si conoscesse i parametri UWB dei 
	dispositivi stessi, si consiglia di riavviare i dispositivi. Se i parametri UWB non tornano a 
	quelli di default, significa che i precedenti utilizzatori hanno permanentemente modificato 
	i parametri dei dispositivi. Contattare le persone in questione oppure reinstallare il firmware
	dei dispositivi oppure tentare di modificare i parametri finché il tag non comunica con questi 
	dispositivi (si tratta comunque di 96 prove, quindi è consigliabile reinstallare il firmware se 
	possibile).
3)	se i parametri uwb sono stati settati e la variabile saveUWBSettings è impostata a True, i 
	parametri UWB vengono impostati permantemente a quelli impostati. Se saveUWBSettings è impostata 
	a False, non saranno salvati permanentemente i parametri UWB.
4)	se la variabile autoCal è settata a False, inserire manualmente all'interno dello script la 
	distanza tra le ancore, misurata ad esempio con un metro laser, altrimenti ha inizio la 
	procedura di autocalibrazione.
5)	vengono effettuate un numero di acquisizioni preimpostate nello script delle distanze tra le 
	possibili coppie di antenne. 
6)	i dati relativi a questa acquisizione vengono inseriti in un grafico nell'immagine 
	raw_distances.png
7)	ha inizio una procedura di algoritmo ransac per la rimozione degli outliers, se questa ha 
	successo verrà mostrata un'immagine autocalibration_results.png che riassumerà i risultati 
	dell'algoritmo.
8)	viene chiesto se si desidera ripetere l'algoritmo ransac e se si vogliono modificare i parametri
	di tale algoritmo.
9)	le distanze calcolate con l'algoritmo ransac vengono fornite in input all'algoritmo algebrico 
	per la determinazione delle coordinate delle ancore.
10)	i risultati dell'autocalibrazione delle ancore vengono mostrati sulla shell e si chiede se si 
	desidera salvare le coordinate delle ancore nella loro lista interna dei dispositivi. In questo 
	modo è possibile realizzare futuri script di positioning che non richiedano di inserire 
	manualmente le coordinate delle ancore. Basterà far sì che in una prima fase di setup il tag 
	interroghi le ancore chiedendo loro le coordinate e salvare i risultati di questa procedura 
	nella lista interna dei dispositivi del tag. E' comunque necessario inserire manualmente gli id
	delle ancore nell'ordine della convenzione.
	
###########################################################
####	CONVENZIONE SULLA DISPOSIZIONE DELLE ANCORE    ####
###########################################################

La lista delle ancore da inserire nello script autocalibration,py e in tutti gli script da noi 
prodotti è una lista ORDINATA che segue la seguente convenzione:

anchor_ids = [id ancora 0, id ancora 1, id ancora 2, id ancora 3]

L'ancora 0 è posta nell'origine del sistema di riferimento che verrà generato dalla
calibrazione automatica.
L'ancora 1 definisce il verso positivo e la direzione dell'asse y
L'ancora 2 definisce il verso positivo dell'asse x.
Le prime tre ancore giacciono su un piano parallelo al piano orizzontale e sono colpanari.
L'ancora 3 definisce il verso positivo dell'asse z e deve essere posta ad una quota superiore alle 
altre 3 ancore, in modo da avere una z positiva verso l'alto.

Le ancore sono state poste per i vari esperimenti circa ai vertici di un tetraedro.

Vista in pianta:

	O Ancora 1


									
						
							O Ancora 2
			O Ancora 3 z>0
        ^ y
        |
        |
        |
	O----------> x
		Ancora 0

L'algoritmo utilizzato per l'autocalibrazione è puramente algebrico ed è descritto nella relazione.

########################################################
######			doPositioning.py			############
########################################################
Lo scopo di questo script è quello di effettuare il positioning di un dispositivo connesso alla
seriale del PC. 
Questo script potrebbe essere "imitato" su uno sketch di Arduino ed essere utilizzato per ricevere
in tempo reale i dati sulla posizione del tag ad esso collegato.

N.B.: 	occorre prima aver lanciato autocalibration.py almeno una volta, altrimenti il tag non
		saprà quali sono le coordinate delle ancore della rete e non potrà fare l'algoritmo di 
		Positioning.

L'algoritmo di positioning utilizzato è quello fornito dalla Pozyx.

Occorre specificare l'id delle ancore utilizzate per la triangolazione, sempre secondo la 
convenzione precedentemente specificata.



########################################################
######			rangesToPos.py				############
########################################################
Contiene la funzione ausiliaria utilizzata per determinare le coordinate delle ancore
a partire dalle distanze relative tra di esse. E' necessario fornire come argomenti 6 valori di 
distanze positivi: [r01,r02,r03,r12,r13,r23].

E' un file che viene importato in autocalibration.py e in doPositioning.py



############################################################
####			Parametri_UWB.txt					    ####
############################################################
Una volta che autocalibration.py è stato eseguito correttamente viene generato un file di testo 
contenente i parametri UWB settati in autocalibration, in modo tale da non dover stare a 
specificarli in doPositioning.py
Ricordiamo infatti che, qualora si avessero diversi parametri UWB settati sui vari dispositivi,
questi non potrebbero dialogare tra loro.


########################################################
######			raw_distances.png			############
########################################################
Immagine che mostra i dati acquisiti sulle distanze tra le varie coppie di antenne. Può essere utile
per guidare la scelta dei parametri dell'algoritmo ransac.


########################################################
######			autocalibration_results.png	############
########################################################
Immagine che mostra i risultati dell'algoritmo ransac.





