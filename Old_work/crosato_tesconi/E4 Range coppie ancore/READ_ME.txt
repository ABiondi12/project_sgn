####################################################
####	acquisizioni_distanze_antenne.py	####
####################################################
Con questo script python è possibile acquisire le distanze tra le coppie di antenne
del setup. Vengono effettuate una serie di tali misurazioni e salvate nel file di testo
"./dati/distanza_coppie_antenne_i.txt". Automaticamente viene generato il file di testo 
con il numero corretto, in modo da non sovrascrivere i precedenti.


####################################################
####	calibrazione_automatica.m		####
####################################################
Prende in ingresso i dati presenti nel file .txt precedentemente generato e resituisce le
coordinate delle ancore e i rispettivi scarti quadratici medi, utilizzando l'algoritmo 
algebrico.


####################################################
####	calibrazione_metro_laser.m		####
####################################################
Prende in ingresso le misurazioni al metro laser delle distanze tra le antenne e le relative
incertezze ed applica l'algoritmo algebrico. Per determinare l'incertezza sulle coordinate 
delle ancore utilizza il metodo della propagazione degli errori.


####################################################
####	prop_err.m				####
####################################################
Propagazione degli errori per il problema in questione.

####################################################
####	rangesToPosALG.m e rangesToPos_new.m	####
####################################################
Funzioni matlab che implementano il metodo algebrico per determinare la posizione 
delle ancore. Il primo è l'algoritmo originale, il secondo è una versione modificata
che consente di non chiamare più volte il comando "solve" di Matlab, consentendo di 
risparmiare tempo nel caso in cui ci siano molti dati da analizzare.
