--------------ALGORITMI+SIMULAZIONE----------------
In questa cartella si trovano le funzioni Matlab che sono necessarie per la determinazione delle posizioni 
delle ancore nel setup nel sistema di riferimento con origine nell'ancora0, direzione delle y crescenti passanti per ancora1 e direzione delle x crescenti definita dalla regione di piano cui appartiene ancora2.
L'asse z completa la terna levogira. Nelle slide Algoritmi-calibrazione.pdf sono spiegati gli algoritmi di calibrazione delle posizioni 
delle ancore.

rangesToPosALG: funzione che riceve in ingresso i range relativi tra le ancore, ordinati come: r01 r02 r03 r12 r13 r23, 
		dove rij sta ad indicare la distanza dall'ancora con id = i a quella con id = j.
		Consiste nel CALCOLO delle posizioni 3D delle ancore nel sistema di riferimento di interesse,
		restituite nell'ordine: [A0, A1, A2, A3] dove ciascuno è un vettore 1x3. Quando non è possibile
                individuare le posizioni nello spazio sulla base dei range (i triangoli su cui si basa l'algoritmo non si chiudono)
                vengono restituite coordinate tutte nulle.

computeCMDS: funzione che riceve in ingresso i range relativi delle ancore, ordinati r01 r02 r03 r12 r13 r23.
	     È un'implementazione dell'algoritmo di Classical Multidimensional Scaling, che ricostruisce 
             le posizioni 3d delle 4 ancore, espresse secondo un generico sistema di riferimento.

rotmatAA: funzione che richiede in ingresso il vettore che definisce l'asse e l'angolo di cui ruotare, espesso in rad,
	  restituisce la matrice di rotazione ASSE/ANGOLO, utile per ruotare i punti ricostruiti dall'algoritmo di 
	  Classical Multidimensional Scaling, richiamata in rotateSet.

rotateSet: funzione i cui ingressi sono i vettori 1x3 delle posizioni di ogni ancora, ordinate per id crescente,
	   risultato dell'algoritmo computeCMDS e effettua la rotazione rigida di questi punti
           per ottenere le coordinate associate alle ancore nel sistema di riferimento di interesse.
	   Consiglio di guardare il notebook Mathematica cmdScaling.nb o la sua versione pdf per una migliore comprensione del
           calcolo della matrice di rotazione. Lì sono state calcolate matrici di rotazione per diversi 
           set di punti, le equazioni e i risultati prodotti hanno portato alla definizione generale di questa funzione in Matlab.

SimulazioneCal: Script in cui si effettua la stima delle posizioni delle ancore in simulazione, con valori prefissati di delay per 			                ancore e tag in presenza di rumore. Nello script vengono testati gli algoritmi algebrico, classical multidimensional
                scaling da confrontare con i risultati della minimizzazione vincolata del funzionale di costo tramite fmincon.
