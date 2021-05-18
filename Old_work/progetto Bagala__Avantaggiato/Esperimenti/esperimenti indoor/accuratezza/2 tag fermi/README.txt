%%%%%%%%%%%%%%%PROGETTO DI SISTEMI DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%%%%%%%%
		Bagalà Alfredo & Avantaggiato Sabrina

%%%%%% ACCURATEZZA %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Questo esperimento valuta l'accuratezza e la precisione del positioning e del ranging 
di due tag lasciati fermi nella stessa posizione.
I parametri UWB impostati sono:
- channel = 5;
- bitrate = 6810 kbit/sec;
- plen = 64 symbols;
- prf = 64 MHz.
I dati sono riportati in questa forma:
	-----------1 tag--------------------------------|| ----------------2 tag---------------------------
	coord_x coord_y coord_z dist0 dist1 dist2 dist3 ||coord_x coord_y coord_z dist0 dist1 dist2 dist3  
	------------------------------------------------||-------------------------------------------------

Sono stati effettuati tre esperimenti. 
è stata verificata la precisione confrontando i ranging  con le distanze reali ottenute 
mediante un metro laser.
Per riprodurre questo esperimento è necessario caricare lo sketch di base (serial o newserial)
 e commentare l'istruzione  finalizzata alla stampa del tempo e dell'errore.
