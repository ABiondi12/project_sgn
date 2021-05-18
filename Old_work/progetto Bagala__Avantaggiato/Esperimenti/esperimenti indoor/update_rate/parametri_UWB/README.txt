%%%%%%PARAMETRI UWB %%%%
In questa sezione è stato calcolato l'update rate del positioning e ranging al variare 
dei parametri UWB. In particolare sono stati condotti esperimenti al variare del bitrate,
plen e canale.

- esperimento al variare del bitrate:
  Per ogni dispositivo è settato il seguente set dei parametri :
	gain    : 11.5
	plen    : 64 symbols
	prf     : 64 MHz
	channel : 5 
  uwb_funbitrate.m è uno script che analizza i dati in funzione del valore di bitrate, ovvero quando bitrate 
  assume il valore di 110kbit/s, 850kbit/s, 6810kbit/s.

  In 'dati' sono riportati 3 file .txt relativi a questo esperimento. I file sono questi:
	- channel5bitrate6810PRF64plen64 : bitrate pari a 6810kbit/s;
	- channel5bitrate850PRF64plen64  : bitrate pari a 850kbit/s;
	- channel5bitrate110PRF64plen64  : bitrate pari a 110kbit/s;
  I dati sono riportati nella seguente forma:
	-----------1 tag--------------------------------|| ----------------2 tag---------------------------|| errore  || tempo ||
	coord_x coord_y coord_z dist0 dist1 dist2 dist3 ||coord_x coord_y coord_z dist0 dist1 dist2 dist3  ||{0,1,2,3}|| [ms]  ||
	------------------------------------------------||-------------------------------------------------||---------||-------||
 
 
- esperimento al variare del plen:
  Per ogni dispositivo è settato il seguente set dei parametri :
	gain    : 11.5
	bitrate : 6810 kbit/s
	prf     : 64 MHz
	channel : 5 
  uwb_funplen.m è uno script che analizza i dati in funzione del valore di plen, ovvero quando il plen
  assume il valore di 64,128,256,512,1024,1536,2048.

  In 'dati' sono riportati i file .txt relativi a questo esperimento. I file sono questi:
	- channel5bitrate6810PRF64plen64    : plen pari a 64
	- channel5bitrate6810PRF64plen128   : plen pari a 128
	- channel5bitrate6810PRF64plen256   : plen pari a 256
	- channel5bitrate6810PRF64plen512   : plen pari a 512
	- channel5bitrate6810PRF64plen1024  : plen pari a 1024
	- channel5bitrate6810PRF64plen1536  : plen pari a 1536
	- channel5bitrate6810PRF64plen2048  : plen pari a 2048
  I dati sono riportati nella seguente forma:
	-----------1 tag--------------------------------|| ----------------2 tag---------------------------|| errore  || tempo ||
	coord_x coord_y coord_z dist0 dist1 dist2 dist3 ||coord_x coord_y coord_z dist0 dist1 dist2 dist3  ||{0,1,2,3}|| [ms]  ||
	------------------------------------------------||-------------------------------------------------||---------||-------||


- esperimento al variare del canale:
  Per ogni dispositivo è settato il seguente set dei parametri :
	gain    : 11.5
	bitrate : 6810 kbit/s
	plen    : 64 symbols
	prf     : 64 MHz
  uwb_funcanali.m è uno script che analizza i dati in funzione del valore di canale, ovvero quando il canale
  assume il valore di {1,2,3,4,5,7}

  In 'dati' sono riportati i file .txt relativi a questo esperimento. I file sono questi:
	- channel1bitrate6810PRF64plen64   : channel 1
	- channel2bitrate6810PRF64plen64   : channel 2
	- channel3bitrate6810PRF64plen64   : channel 3
	- channel4bitrate6810PRF64plen64   : channel 4
	- channel5bitrate6810PRF64plen64   : channel 5
	- channel7bitrate6810PRF64plen64   : channel 7

  I dati sono riportati nella seguente forma:
	-----------1 tag--------------------------------|| ----------------2 tag---------------------------|| errore  || tempo ||
	coord_x coord_y coord_z dist0 dist1 dist2 dist3 ||coord_x coord_y coord_z dist0 dist1 dist2 dist3  ||{0,1,2,3}|| [ms]  ||
	------------------------------------------------||-------------------------------------------------||---------||-------||

Per riprodurre l'esperimento è necessario caricare in fase preliminare lo sketch pozyx_configurator_2tag
settando i parametri UWB. Dop, bisogna utilizzare uno dei tag presenti in sketch di base( serial o newSerial).


 