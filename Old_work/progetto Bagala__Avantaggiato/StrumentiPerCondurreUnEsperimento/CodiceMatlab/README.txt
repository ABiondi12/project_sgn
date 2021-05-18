%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo                        %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
CodiceMatlab
Viene riportato il codice matlab per l'analisi statistica dei dati relativi 
ad un esperimento.

Per la sua fruizione è necessario seguire il seguente formato:

 -------------tag1------------||-------------tag2------------||--status-||-errore-||tempo||---caso--||
 x y z dist0 dist1 dist2 dist3||x y z dist0 dist1 dist2 dist3||{0,1,2,3}||{0,1,2,3}||[ms]||{0,1,2,3}||
 -----------------------------||-----------------------------||---------||---------||----||---------|| 

Qualora, alcuni dei dati qui riportati non venissero utilizzati e/o salvati 
durante l'esperimento, sarà necessario porre a zero la variabile 
(utilizzata come un booleano) corrispondente nel codice matlab.
Il file principale, nonchè quello da lanciare per tutta l'analisi, è 
"AnalizzaEsperimento.m", dove si trovano anche le variabili appena citate 
ed alcuni altri parametri modificabili.  