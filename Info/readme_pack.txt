###################################################
###	Installazione di pozyx_ros 		###
###################################################
Questo readme spiega come far costruire a catkin il pacchetto pozyx_ros.

Prima di compilare servono i seguenti pacchetti:
	pypozyx
		pip install pypozyx
	pyserial package
		pip install pyserial

###################################################
###	Autocalibrazione sisema pozyx 		###
###################################################

Per i file di autocalibrazione (che utilizza python3) sono necessari alcuni pacchetti. Per il raspberry non e` consigliabile installare attraverso pip3 (dato che c'e` bisogno di ricompilare i file attraverso il processore ARM del raspberry). Quindi si va ad utilizzare:
	sudo apt update
	sudo apt python3-numpy
	sudo apt python3-scipy
	sudo apt python3-matplotlib

	pip3 install pypozyx

Una volta installati questi pacchetti, connettere una o entrambe le tag per poter comunicare con le ancore e infine eseguire il file di autocalibrazione attraverso:
	cd ~/charlie_autocalibration
	python3 autocalibration_ransac.py

###########################################################
###	Installazione di pacchetti aggiuntivi python	###
###########################################################

pandas:
	sudo apt-get install python3-pandas


###################################################
###		navigation package 		###
###################################################
sudo apt-get install libsdl-image1.2-dev






