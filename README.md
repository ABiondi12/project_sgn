# project_sgn
Questa repository contiene tutto il codice sviluppato e fornito per realizzare il progetto di Sistemi di Guida e Navigazione, corso seguito nel a.a. 2019/2020 e tenuto dal professore Lorenzo Pollini.

Lo scopo di questo lavoro è stato quello di migliorare il sistema di navigazione di un veicolo, chiamato Charlie, che sfrutta lidar, sistema UWB e l'algoritmo AMCL.

La repository e strutturata in diverse cartelle, in queste si trovano:
- Analisi_matlab, contiene script e funzioni per analizzare i dati raccolti attraverso delle rosbag. Queste si possono trovare in nel [Google Drive](https://drive.google.com/drive/folders/1rXppVs0qSfeEKQumRFrPhkpiYDCvTXOL?usp=sharing) associato a Charlie. 
- Info, racchiude molte informazioni utili su packages, linux's stuff e hardware utilizzato.
- Old_work, ci troviamo tutti i lavori precedenti che hanno a che fare con Charlie e il sistema Pozyx. 
	- python files, contiene alcuni file python utili per il debug del sistema Pozyx.
	- Relazione, i file sorgente di questa relazione.
	- Workspace, i vari workspace utilizzati:
		- charlie_autocalibration: file necessari all'autocalibrazione del sistema Pozyx
		- charlie_remote_ws: catkin workspace da caricare su pc, utile per rviz, vicon e per eseguire le rosbag.
		- charlie_ws: catkin workspace attualmente caricata su Charlie.

In caso di necessità è possibile ricostruire tutto l'ambiente Ros semplicemente seguendo le istruzioni riportate in Info\Pacchetti.ods e in  Info\readme_packages.txt.
