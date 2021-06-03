Nei vari rosbags disponibili questi sono i topic di ingresso e di uscita

Segnali di ingresso (topics):
	- scan				- output del Lidar
	- tag_center			- centro delle tag in coordinate map, yaw da stm
	- orientation			- orientazione letta da stm (solo il campo yaw ha valori)
	- map				- mappa

Segnali di uscita (topics):
	- robot_pose			- posa del robot stimata da AMCL (o pari a tag_center se il Lidar è oscurato) in coordinate mappa
	- tf				- le varie TF presenti



Per riprodurre i rosbags, usare il seguente comando:  "rosbag play --topics /scan /tag_center /orientation /map"
Per simulare il comportamento del sistema con in ingresso questi dati copiare il launch file "localization_for_bagfile.launch" in charlie_ws/src/charlie_pkg/launch
e quindi eseguire il seguente comando: "roslaunch charlie_pkg localization_for_bagfile.launch"
