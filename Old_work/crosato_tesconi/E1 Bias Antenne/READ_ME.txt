In questa cartella � presento uno script python che permette di acquisire e salvare in un 
documento .txt la distanza tra due antenne. Occorre specificare gli ID delle due ancore all'interno 
del main (remote_id e destination_id).

Una volta acquisiti i dati il file viene salvato nella cartella "./data" e i risultati possono essere
analizzati mediante lo script "distanza_due_antenne.m".



####################################
####		Note		####
####################################

Nella funzione main dello script python � possibile settare il parametro remote_id. 
Questo se remote = False, si andr� a misurare la distanza tra il dispositivo Pozyx collegato
alla porta serial del PC e il dispositivo il cui id � specificato in 'destination_id'. 
Se invece si pone remote = True, si andr� a misurare la distanza tra i dispositivi Pozyx 
aventi gli identificativi 'remote_id' e 'destination_id'. 
