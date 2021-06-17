% Questo script esegue l'analisi di cortile_6_15_num.bag

clear
% close all
clc

%% scegliere quale file analizzare:
filename = 'cortile_6_15_primo.mat';
% filename = 'cortile_6_15_secondo.mat';
% filename = 'cortile_6_15_terzo.mat';


%% Estrazione variabili
if exist(filename) == 2
	
	% estrazione dalla bag gia` avvenuta, carico il save
	load(filename)
	
else
	
	filename_bag = [filename(1:(end-3)), 'bag']; % cambio estensione del file
	
	% load
%	rosbag info 'cortile_6_15_primo.bag' % print info della bag
% 		/amcl_pose              330 msgs  : geometry_msgs/PoseWithCovarianceStamped
% 		/initialpose              4 msgs  : geometry_msgs/PoseWithCovarianceStamped
% 		/map                      1 msg   : nav_msgs/OccupancyGrid                 
% 		/orientation           9905 msgs  : geometry_msgs/Point                    
% 		/particlecloud          330 msgs  : geometry_msgs/PoseArray                
% 		/robot_pose           52995 msgs  : geometry_msgs/Point                    
% 		/scan                  4167 msgs  : sensor_msgs/LaserScan                  
% 		/tag_center           17299 msgs  : geometry_msgs/PoseStamped              
% 		/tf                  173181 msgs  : tf2_msgs/TFMessage                      (8 connections)
% 		/waypoint_publisher   34571 msgs  : geometry_msgs/Point

	bag = rosbag(filename_bag);

	% prima colonna tempo [s]
	% time
	time_end = bag.EndTime - bag.StartTime;
	
	
	% amcl_pose
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/amcl_pose');
	amcl_pose_pos	= [temp_bag.timeseries.Time - bag.StartTime, temp_bag.timeseries.Data(:, 4:6) ];
	amcl_pose_quat = [temp_bag.timeseries.Time - bag.StartTime, temp_bag.timeseries.Data(:, 7:end) ];
	
	% initialpose
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/initialpose');
	initialpose_pos		= [temp_bag.timeseries.Time - bag.StartTime, temp_bag.timeseries.Data(:, 4:6) ];
	initialpose_quat	= [temp_bag.timeseries.Time - bag.StartTime, temp_bag.timeseries.Data(:, 7:end) ];
	
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

	% rimuovo variabili temporanee
	clear temp_bag bag
	
	save(filename)
	
end

%% Calcoli
tag_center_heading = tag_center_quat(:,1:2); % cosi` mi copio il vettore tempo
tag_center_heading(:,2) = quat2yaw_array(tag_center_quat(:,2:end));

amcl_heading = amcl_pose_quat(:,1:2);  % cosi` mi copio il vettore tempo
amcl_heading(:,2) = quat2yaw_array(amcl_pose_quat(:,2:end));

initialpose_heading = initialpose_quat(:,1:2);  % cosi` mi copio il vettore tempo
initialpose_heading(:,2) = quat2yaw_array(initialpose_quat(:,2:end));

%% tracciato

axis_lim_full = [-10, 13, -12, 13];		% per vedere tutta la mappa
axis_lim_zoom = [-3, 6, -1, 4];			% per vedere solo il tracciato

% tracciato
figure(1)
clf
show(map)
hold on
% plot(robot_pos(:,2), robot_pos(:,3), 'b', 'DisplayName', 'stima')
plot(amcl_pose_pos(:,2),	amcl_pose_pos(:,3),		'r',	'DisplayName', 'amcl')
plot(tag_center_pos(:,2),	tag_center_pos(:,3),	'b--',	'DisplayName', 'tag center')
plot(initialpose_pos(:,2),	initialpose_pos(:,3),	'k*',	'DisplayName', 'initialpose')

hold off
grid on
% axis(axis_lim_full)
axis(axis_lim_zoom)
legend
title('Traiettoria')

%% x 

figure(10)
clf
plot(amcl_pose_pos(:,1),	amcl_pose_pos(:,2),		'r',	'DisplayName', 'amcl')
hold on
plot(robot_pos(:,1),		robot_pos(:,2),			'r --',	'DisplayName', 'robot pos')
plot(tag_center_pos(:,1),	tag_center_pos(:,2),	'b--',	'DisplayName', 'tag center')
plot(initialpose_pos(:,1),	initialpose_pos(:,2),	'k*',	'DisplayName', 'initialpose')
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
plot(amcl_pose_pos(:,1),	amcl_pose_pos(:,3),		'r',	'DisplayName', 'amcl')
hold on
plot(robot_pos(:,1),		robot_pos(:,3),			'r --',	'DisplayName', 'robot pos')
plot(tag_center_pos(:,1),	tag_center_pos(:,3),	'b--',	'DisplayName', 'tag center')
plot(initialpose_pos(:,1),	initialpose_pos(:,3),	'k*',	'DisplayName', 'initialpose')

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
plot(amcl_heading(:,1), unwrap(amcl_heading(:,2) -2*pi)* 180/pi, 'r', 'DisplayName', 'amcl')

hold off
axis tight
grid on
xlabel('Time [s]')
ylabel('heading [deg]')
legend('Location', 'Best')
title('Orientazione')

%% animation


