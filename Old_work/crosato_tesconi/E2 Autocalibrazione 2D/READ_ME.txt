Per i sistema Pozyx si parla di calibrazione 2D quando le ancore del sistema 
vengono posizionate sullo stesso piano e il tag si muove coplanare alle ancore.
Si parla ivnece di calibrazione 2.5D quando le ancore sono coplanari e il tag 
si muove parallelamente ad esse.

####################################################
####	Convenzione sulle ancore		####
####################################################
In questo esperimento abbiamo leggermente modificato la convenzione sulle 
ancore (per motivi cronologici è stato prima adottato questo metodo e poi 
ci siamo adeguati alla convenzione utilizzata da Fioretti).
In questo setup si numerano le ancore da 1 a 4. L'ancora 1 è nell'origine,
l'ancora 2 è posta lungo l'asse x, l'ancora 3 ha una y positiva e infine 
l'ancora 4 ha sia x che y positive. Tutte le ancore sono coplanari, coerentemente
con il fatto che si utilizza un'autocalibrazione 2D.

####################################################
####	auto_calibrazione_2D.py			####
####################################################
Lo script auto_calibrazione_2D.py lancia un certo numero di acquisizioni di 
autocalibrazioni 2D (possibilità anche di effettuare autocalibrazione 2.5D).
I dati vengono salvati nel file 'auto_calibrazione_2D_geometria_i.txt'.


####################################################
####	auto_calibrazione_2D.m			####
####################################################
Lo script matlab auto_calibrazione.m effettua un caricamento dei dati ottenuti
e divide le soluzioni in vari gruppi. Questo script è stato pensato per gli 
specifici dati ottenuti, in quanto il raggruppamento viene fatto manualmente
sulla base della configurazione ottenuta e della specifica serie storica dei 
dati. In linea di principio però può essere preso come spunto per script simili.


############################################
####	calcolo_posizioni.m		####
############################################
Una volta acquisite le distanze tra le varie antenne si può utilizzare lo 
script 'calcolo_posizioni.m' per ottenere le incertezze sulle coordinate (x,y)
di ciascuna antenna sulla base dell'incertezza sulla distanze relative Rij tra
le varie coppie di antenne. Lo script non è altro che l'applicazione diretta 
del metodo di propagazione degli errori la cui descrizione teorica è riportata
nella relazione.
