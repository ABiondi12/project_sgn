Descrizione generale dei file contenuti dentro il pacchetto charlie_launch.
Aggiornato al 16 Aprile 2021


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
		descrizione: init frames di hector mapping e tf
		
		esegue: 
			node hector_mapping
			node tf (static transform base_stabilized_to_laser_broadcaster)

	new_map.launch
		descrizione:

		esegue:
			node rplidarNode (parametri di default, da sostituire con rplidar_ros/launch/rplidar_a3.launch)
			node hector_mapping (con alcuni parametri, magari creare un file stile mapping_default)
			node rviz (config new_map_cfg)
			hector_geotiff_traj_server.launch
			node tf (static IMU2laser_tf)

folder rviz_cfg
	Contiene tutte le configurazioni necessarie a rviz
