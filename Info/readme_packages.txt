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
	sudo apt-get install python3-pandas 		(non serve per autocalibrazione, ma per altri file di pozyx)

	pip3 install pypozyx

Una volta installati questi pacchetti, connettere una o entrambe le tag per poter comunicare con le ancore e infine eseguire il file di autocalibrazione attraverso:
	cd ~/charlie_autocalibration
	python3 autocalibration_ransac.py


###################################################
###		navigation package 		###
###################################################
Prima di compilare con catkin serve aver installato:
	sudo apt-get install libsdl-image1.2-dev


###################################################
###	Installazione di Scan_tools 		###
###################################################
Questo readme spiega come far costruire a catkin il pacchetto Scan tools.

Prima di compilare servono i seguenti pacchetti:
	geometry2
		https://wiki.ros.org/geometry2?distro=melodic
	perception-pcl
		https://wiki.ros.org/pcl_ros?distro=melodic
	pcl_msgs
		https://wiki.ros.org/pcl_msgs?distro=melodic
	csm
		Per come installare CSM leggere sotto.



###########################################
###	Installazione di CSM 		###
###########################################

Come installare CSM, modulo necessario a laser_scan_matcher dato che l'installazione di default non funziona (problemi di compatibilita` nel CMAKE)

clone the csm-Repo in your catkin_ws: 
	git clone https://github.com/AndreaCensi/csm
solve dependencies: 
	rosdep install --from-paths src --ignore-src -r -y
    move into csm:
	cd csm
Use the install instructions from their manual:
	cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr/local .
	make
	sudo make install

Good to use catkin_make
	cd ..
    	catkin_make

Questa soluzione e` stata trovata in: https://github.com/ccny-ros-pkg/scan_tools/issues/63






