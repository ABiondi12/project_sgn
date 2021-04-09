Questo readme spiega come impostare le reti WIFI a cui si prova l'accesso all'avvio.



il file con le impostazioni si trova in /etc/network/ e si chiama interfaces. Per editarlo usare i seguenti comandi:

	cd /etc/network/
	sudo nano interfaces

Il file legge le configurazioni salvate in un file .conf di cui deve essere indicata la locazione. Aggiungere una riga per file conf e commentare le altre (con #).
Ad esempio se volessimo aggiungere una configurazione di rete con nome "NOME" e` consigliato inserire la seguente riga.

	wpa-conf /etc/wpa_supplicant/wpa_supplicant_NOME.conf



All'interno del file .conf ci deve essere questo:

	ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
	update_config=1
	country=IT

	network={
		ssid="nome-wifi"
		psk="password"
	}


E deve essere posizionato nel path specificato. Nel caso si usi quello di default (/etc/wpa_supplicant/), si riporta un comando utile

	cd /etc/wpa_supplicant/

e poi per creare il file:

	sudo nano wpa_supplicant_NOME.conf



