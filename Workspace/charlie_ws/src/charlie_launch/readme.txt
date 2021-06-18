Descrizione generale dei file contenuti dentro il pacchetto charlie_launch.
Aggiornato al 16 Aprile 2021

!!DA FINIRE!!

folder launch:
	hector_geotiff_traj_server.launch
		descrizione:	
			inizializza server geotiff
		esegue:
			node hector_trajectory_server
			node hector_geotiff

	laser_Scan_matcher.launch
		descrizione:
			inizializza l'acquisizione da lidar_a3 e il necessario per lidar_scan_matcher
		esegue:
			rplidar_ros/launch/rplidar_a3.launch
			node static_transform_publisher (per definire la trasformazione base tra frame
			node laser_scan_matcher
			
	lidar_hector.launch
		descrizione:
			inizializza l'acquisizione da lidar_a3 e la slam utilizzando hector_slam
		esegue:
			rplidar_ros/launch/rplidar_a3.launch
			node rviz (config lidar_hector_cfg)
			mapping_default.launch
			hector_geotiff/launch/geotiff_mapper.launch

	mapping_default.launch
		descrizione:
		
		esegue:

	new_map.launch

folder rviz_cfg
	Contiene tutte le configurazioni necessarie a rviz