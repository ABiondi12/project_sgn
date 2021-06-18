% Questo script esegue l'analisi di Confronto_stanzavolo_Vicon.bag

clear
close all
clc

%% scegliere quale file analizzare:
filename = 'Confronto_stanzavolo_Vicon.mat';

%% Estrazione variabili
if exist(filename) == 2
	
	% estrazione dalla bag gia` avvenuta, carico il save
	load(filename)
	
else
	
	filename_bag = [filename(1:(end-3)), 'bag']; % cambio estensione del file
	
	% load
%	rosbag info 'Confronto_stanzavolo_Vicon.bag' % print info della bag

%     /amcl_pose                   159     geometry_msgs/PoseWithCovarianceStamped                   
%     /charlie_vicon_map         11539     geometry_msgs/PoseStamped                                                                                                                                                 
%     /map                           1     nav_msgs/OccupancyGrid                     
%     /orientation                1015     geometry_msgs/Point                                                                                                                                                                                                                                                                                                                                                          }
%     /particlecloud               159     geometry_msgs/PoseArray                                                                                                                                                     
%     /robot_pose                24082     geometry_msgs/Point                                                                                                                                                                                                                                                                                                                                                                           }
%     /rosout               3.7926e+05     rosgraph_msgs/Log                                                                                                                                                                                                    
%     /rosout_agg           3.7958e+05     rosgraph_msgs/Log                                                                                                                                                                                                 
%     /scan                       2795     sensor_msgs/LaserScan                                                                                                                                                                     
%     /tag_center                11424     geometry_msgs/PoseStamped 
%     /tf                   1.3656e+05     tf2_msgs/TFMessage  

	bag = rosbag(filename_bag);

	% prima colonna tempo [s]
	% time
	time_end = bag.EndTime - bag.StartTime;
	
	
	% amcl_pose
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/amcl_pose');
	amcl_pose_pos	= [temp_bag.timeseries.Time - bag.StartTime, temp_bag.timeseries.Data(:, 4:6) ];
	amcl_pose_quat = [temp_bag.timeseries.Time - bag.StartTime, temp_bag.timeseries.Data(:, 7:end) ];
	
	% map
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/map');
	map = readBinaryOccupancyGrid(temp_bag.readMessages{1}); % per mostrarla show(map)
	
	% stm_or
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/orientation');
	stm_or = [temp_bag.timeseries.Time - bag.StartTime, temp_bag.timeseries.Data(:,3)];

	% robot_pose
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/robot_pose');
	
	robot_pos	= [temp_bag.timeseries.Time - bag.StartTime, temp_bag.timeseries.Data(:,1:2) ];
	robot_or	= [temp_bag.timeseries.Time - bag.StartTime, temp_bag.timeseries.Data(:,3) ];
	
	% tag_center
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/tag_center');
	tag_center_pos	= [temp_bag.timeseries.Time - bag.StartTime, temp_bag.timeseries.Data(:, 4:6) ];
	tag_center_quat = [temp_bag.timeseries.Time - bag.StartTime, temp_bag.timeseries.Data(:, 7:end) ];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	% charlie_vicon_pos
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/charlie_vicon_map');
	charlie_vicon_pos = [temp_bag.timeseries.Time, temp_bag.timeseries.Data(:,4:6)];
	charlie_vicon_pos(:,1) = charlie_vicon_pos(:,1) - bag.StartTime; 

	% charlie_vicon_or (quaternione)
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/charlie_vicon_map');
	charlie_vicon_or = [temp_bag.timeseries.Time, temp_bag.timeseries.Data(:,7:10)];
	charlie_vicon_or(:,1) = charlie_vicon_or(:,1) - bag.StartTime; 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	
	% rimuovo variabili temporanee
	
	clear temp_bag bag	
	save(filename)
	
end

%% Calcoli

tag_center_heading = tag_center_quat(:,1:2); % cosi` mi copio il vettore tempo
tag_center_heading(:,2) = quat2yaw_array(tag_center_quat(:,2:end));

amcl_heading = amcl_pose_quat(:,1:2);  % cosi` mi copio il vettore tempo
amcl_heading(:,2) = quat2yaw_array(amcl_pose_quat(:,2:end));

%%%% Vicon analysis

% vicon_yaw
vicon_yaw		= zeros(size(charlie_vicon_or,1), 2);
vicon_yaw(:,1)	= charlie_vicon_or(:,1);					% copio i timestamp
vicon_yaw(:,2)	= quat2yaw_array(charlie_vicon_or(:,2:5));	% calcolo lo yaw

% presa per buona l'orientazione vicon, costruisco posizione delle tag
[tag0_vicon, tag1_vicon] = tag_vicon(charlie_vicon_pos, charlie_vicon_or);

% calcolo errore: MODIFICA COL CENTRO
[err_array, err_norm] = errore_tag(tag_center_pos, charlie_vicon_pos);
err_arr_normato = err_array; % cosi` da copiare il tempo
err_arr_normato(:,2:4) = err_array(:,2:4)./err_norm(:,2);
[pos_quiver_sync, delta_quiver_sync] = sync_vicon_tag(charlie_vicon_pos, tag_center_pos);

%% tracciato

axis_lim_zoom = [-2, 3, -2, 3];		% per vedere solo il tracciato
axis_lim_full = [-4, 6, -3, 3];		% per vedere tutta la mappa
	
% tracciato
figure(10)
clf
show(map)
hold on
% plot(robot_pos(:,2), robot_pos(:,3), 'b', 'DisplayName', 'stima')
plot(amcl_pose_pos(:,2),	amcl_pose_pos(:,3),		'r', 	'DisplayName', 'amcl')
plot(tag_center_pos(:,2),	tag_center_pos(:,3),	'b--', 	'DisplayName', 'tag center')
plot(charlie_vicon_pos(:,2),	charlie_vicon_pos(:,3),	'k',	'DisplayName', 'vicon')

hold off
grid on
% axis(axis_lim_full)
axis(axis_lim_zoom)
legend
title('Traiettoria')

%% x 

figure(11)
clf
plot(amcl_pose_pos(:,1),	amcl_pose_pos(:,2),		'r', 'Linewidth', 1,	'DisplayName', 'amcl')
hold on
plot(robot_pos(:,1),		robot_pos(:,2),			'r --', 'Linewidth', 1,	'DisplayName', 'robot pos')
plot(tag_center_pos(:,1),	tag_center_pos(:,2),	'b--', 'Linewidth', 1,	'DisplayName', 'tag center')
plot(charlie_vicon_pos(:,1),	charlie_vicon_pos(:,2),	'k--', 'Linewidth', 1,	'DisplayName', 'Vicon')
hold off
axis tight
grid on
xlabel('Time [s]')
ylabel('x axis [m]')
legend('Location', 'Best')

title('Andamento su asse x')

%% y
figure(20)
clf
plot(amcl_pose_pos(:,1),	amcl_pose_pos(:,3),		'r', 'Linewidth', 1,	'DisplayName', 'amcl')
hold on
plot(robot_pos(:,1),		robot_pos(:,3),			'r --', 'Linewidth', 1,	'DisplayName', 'robot pos')
plot(tag_center_pos(:,1),	tag_center_pos(:,3),	'b--', 'Linewidth', 1,	'DisplayName', 'tag center')
plot(charlie_vicon_pos(:,1),	charlie_vicon_pos(:,3),	'k--', 'Linewidth', 1,	'DisplayName', 'Vicon')

hold off
axis tight
grid on
xlabel('Time [s]')
ylabel('y axis [m]')
legend('Location', 'Best')

title('Andamento su asse y')

%% orientation - Heading
figure(30)
clf
plot(stm_or(:,1),	-stm_or(:,2) * 180/pi,		'c',	'DisplayName', 'stm')
hold on
plot(tag_center_heading(:,1),	unwrap(tag_center_heading(:,2))* 180/pi,	'b',	'DisplayName', 'tag center')
plot(amcl_heading(:,1), unwrap(amcl_heading(:,2))* 180/pi, 'r', 'DisplayName', 'amcl')

hold off
axis tight
grid on
xlabel('Time [s]')
ylabel('heading [deg]')
legend('Location', 'Best')
title('Orientazione')

%% plot di tag_center_pos
figure(1)
clf
plot(tag_center_pos(:,1), tag_center_pos(:,2))
hold on
plot(tag_center_pos(:,1), tag_center_pos(:,3))
plot(tag_center_pos(:,1), tag_center_pos(:,4))
axis tight
hold off
grid on
xlabel('Time [s]')
ylabel('Posizione centro delle tag [m]')
title('Dati raw di tag centre')

%% confronto tag_center_pos e charlie_vicon_pos (su x e y)
figure(2)
clf
plot(tag_center_pos(:,1),		tag_center_pos(:,2), 'DisplayName', 'x raw', 'Linewidth', 0.2)
hold on
plot(tag_center_pos(:,1),		tag_center_pos(:,3), 'DisplayName', 'y raw', 'Linewidth', 0.2)

plot(charlie_vicon_pos(:,1),	charlie_vicon_pos(:,2), 'DisplayName', 'x vicon', 'Linewidth', 1.2)
plot(charlie_vicon_pos(:,1),	charlie_vicon_pos(:,3), 'DisplayName', 'y vicon', 'Linewidth', 1.2)
axis tight
hold off
grid on
xlabel('Time [s]')
ylabel('Posizioni [m]')
legend
title('Confronto tag centre')

%% errore su tag centre
figure(3)
clf
plot(err_array(:,1),		err_array(:,2), 'DisplayName', 'x', 'Linewidth', 0.5)
hold on
plot(err_array(:,1),		err_array(:,3), 'DisplayName', 'y', 'Linewidth', 0.5)
plot(err_norm(:,1),		err_norm(:,2), 'k--','DisplayName', 'norm', 'Linewidth', 1)
axis tight
hold off
grid on
xlabel('Time [s]')
ylabel('Errore vicon - uwb [m]')
legend
title('Errori su tag centre')

%% confronto orientazione vicon e stm
figure(4)
clf
plot(stm_or(:,1),	(unwrap(-stm_or(:,2))) * 180/pi, 'Linewidth', 1, 'DisplayName', 'stm')
hold on
plot(vicon_yaw(:,1), (unwrap(vicon_yaw(:,2))) * 180/pi, 'Linewidth', 1, 'DisplayName', 'vicon')
plot(tag_center_heading(:,1), (unwrap(tag_center_heading(:,2))) * 180/pi, 'Linewidth', 1, 'DisplayName', 'atan2 tag')
axis tight
hold off
grid on
xlabel('Time [s]')
ylabel('Yaw [deg]')
legend
title('Confronto heading') 

%% Plot errore map tag centre
% circonferenza di rif con centro nella media dell'errore e avente raggio
% pari a 3 sigma (3*deviazione standard) della norma dell'errore
figure(300)
clf
plot(err_array(:,2), err_array(:,3), 'r*','DisplayName', 'tag0')
hold on
circ_temp = circle([mean(err_array(:,2)),mean(err_array(:,3))], 3*std(err_norm(:,2)), 500  );
plot(circ_temp(1,:), circ_temp(2,:), 'k--', 'DisplayName', '3 \sigma')
axis equal
hold off
grid on
xlabel('x [m]')
ylabel('y [m]')
legend
title('Errore su tag centre')

%% tag centre normato
figure(301)
clf
plot((err_arr_normato(:,2)) , err_arr_normato(:,3), 'r*','DisplayName', 'tag0')
hold on
circ_temp = circle([0,0], 1, 500  );
plot(circ_temp(1,:), circ_temp(2,:), 'k--', 'DisplayName', 'Circ. Unitaria')
axis equal
hold off
grid on
xlabel('x [m]')
ylabel('y [m]')
legend
title('Errore normato su tag centre')

% plot(err1_array(:,2), err1_array(:,3), 'b*','DisplayName', 'tag1')

%% plot errore quiver
% tag0
figure(400)
clf
quiver(	pos_quiver_sync(:,2),		pos_quiver_sync(:,3), ...
		delta_quiver_sync(:,2),	delta_quiver_sync(:,3) , 'b', 'Linewidth', 1, 'DisplayName', 'tag centre error')
axis equal
hold off
grid on
legend
xlabel('x [m]')
ylabel('y [m]')
title('Quiver su tag centre')

%% animation
% animate_charlie_stanzavolo_Vicon
 

