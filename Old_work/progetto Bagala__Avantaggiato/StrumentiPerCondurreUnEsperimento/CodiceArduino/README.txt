%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo                        %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%% SET PARAMETRI %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

----------------------pozyx_UWB_configurator:

Questo è il primo sketch da lanciare. Permette di settare i parametri UWB
(channel, bitrate, plen, prf) desiderati. Il set ottimale riscontrato è il
seguente:

- channel = 5;
- bitrate = 6810;
- plen = 64;
- prf = 64.

NOTA: tutti i device devono avere gli stessi parametri per poter comunicare.


----------------------pozyx_gain_configurator_2tag:

Questo sketch (!!!) DEVE (!!!) essere lanciato solo una volta ultimato il 
setting dei dati. In caso contrario il gain verrà nuovamente impostato al 
valore didefault e questa operazione andrà ripetuta per ottenere i risultati 
desiderati.

NOTA: la variabile "boolean save_gain" è impostata di default a true; 
impostarla a false farebbe si che il set del gain non sia salvato e, quindi, 
una volta chiuso lo sketch, il cambiamento non sarà effettivo. 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%% ESPERIEMENTO %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

----------------------sketch_completo:

Viene riportato il codice Arduino attraverso il quale sarà possibile ottenere,
se lo si desidera (bool calibrazione = true), le coordinate dalle ancore post
calibrazione (da effettuare con python); in alternativa, qualora si fosse a 
conoscenza delle coordinate, ma esse non fossero salvate nei device, è 
possibile inserirle manualmente nei vettori anchors_x, anchors_y, heigth.
Inoltre, sarà possibile inviare dati sia in formato binario che in formato
decimale.


----------------------sketch_case:

Viene riportato il codice Arduino attraverso il quale sarà possibile ottenere,
se lo si desidera (bool calibrazione = true), le coordinate dalle ancore post
calibrazione (da effettuare con python); in alternativa, qualora si fosse a 
conoscenza delle coordinate, ma esse non fossero salvate nei device, è 
possibile inserirle manualmente nei vettori anchors_x, anchors_y, heigth.
Questo sketch è strutturato per un esperimento in cui si effettui uno switch 
tra 4 casi in esame:

    1. richiesta di informazioni (positioning e ranging) solo al tag con 
       indirizzo I2C 0x4A;
    2. richiesta di informazioni (positioning e ranging) solo al tag con 
       indirizzo I2C 0x4B;
    3. richiesta di informazioni (positioning e ranging)ad entrambi con la 
       successione 0x4A - 0x4B;
    4. richiesto di informazioni (positioning e ranging)ad entrambi con la 
       successione 0x4B - 0x4A.
    5. Il caso 5 serve solo ad azzerare il contatore.

Questo permette di testare le varie situazioni, in una situazione ambientale simile.


----------------------sketch_ranging:

Questo sketch serve nel caso in cui si volesse effettuare un esperimento
esclusivamente sul ranging tra un'ancora e i due tag in parallelo.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%