Questo epserimento prevede l'utilizzo di 7 dispositivi Pozyx.
Un dispositivo è collegato alla seriale, 4 dispositivi sono le ancore del sistema e gli 
ultimi due dispositivi vengono fissati ad un'asta mobile nella stanza.
Si acquisiscono i dati relativi alla posizione dei due dispositivi collegati all'asta e 
si guarda l'andamento del tempo della distanza tra essi relativa.


################################################################
#######             asta.py                      	########
################################################################
Acquisisce i dati dell'asta. Devono essere impostati gli id dei dispositivi connessi 
(tranne l'id del dispositivo collegato alla seriale).

################################################################
#######             rangeToPos.py                      #########
################################################################
Script python per l'algoritmo algebrico di positioning. E' come rangesToPos.m ma per python.
Riadatta i risultati in un formato comodo per la libreria pypozyx.