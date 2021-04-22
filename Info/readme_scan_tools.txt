###################################################
###			Installazione di Scan_tools 		###
###################################################
Questo readme spiega come far costruire a catkin il pacchetto Scan tools.

Prima di compilare servono i seguenti pacchetti:
	geometry2
		https://wiki.ros.org/geometry2?distro=melodic
		eliminare tf2_bullet, non serve
	perception-pcl
		https://wiki.ros.org/pcl_ros?distro=melodic
	pcl_msgs
		https://wiki.ros.org/pcl_msgs?distro=melodic
	csm
		Per come installare CSM leggere sotto.



###########################################
###			Installazione di CSM 		###
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
