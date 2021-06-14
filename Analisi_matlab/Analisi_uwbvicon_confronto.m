% Questo script esegue l'analisi di uwbvicon_confronto.bag

clear
% close all
clc

%% Estrazione variabili

if exist('uwbvicon_confronto.mat') == 2
	
	% estrazione dalla bag gia` avvenuta, carico il save
	load('uwbvicon_confronto.mat')
	
else
	% load
	rosbag info 'uwbvicon_confronto.bag'    % print info della bag
	bag = rosbag('uwbvicon_confronto.bag');

	% prima colonna tempo [s]
	% tag0
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/tag0_pose');
	tag0_pos = temp_bag.timeseries.Data(:,[1,4:6]);
	% Aggiungo i nanosecondi e sottraggo lo starttime
	tag0_pos(:,1) = tag0_pos(:,1) + temp_bag.timeseries.Data(:,2)/1e9 - bag.StartTime; 


	% tag0_f
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/tag0_pose_f');
	tag0_f_pos = temp_bag.timeseries.Data(:,[1,4:6]);
	tag0_f_pos(:,1) = tag0_f_pos(:,1) + temp_bag.timeseries.Data(:,2)/1e9 - bag.StartTime; 


	% tag1
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/tag1_pose');
	tag1_pos = temp_bag.timeseries.Data(:,[1,4:6]);
	tag1_pos(:,1) = tag1_pos(:,1) + temp_bag.timeseries.Data(:,2)/1e9 - bag.StartTime; 


	% tag1_f
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/tag1_pose_f');
	tag1_f_pos = temp_bag.timeseries.Data(:,[1,4:6]);
	tag1_f_pos(:,1) = tag1_f_pos(:,1) + temp_bag.timeseries.Data(:,2)/1e9 - bag.StartTime; 


	% charlie_vicon_pos
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/charlie_vicon_uwb');
	charlie_vicon_pos = temp_bag.timeseries.Data(:,[1,4:6]);
	charlie_vicon_pos(:,1) = charlie_vicon_pos(:,1) + temp_bag.timeseries.Data(:,2)/1e9 - bag.StartTime; 


	% charlie_vicon_or (quaternione)
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/charlie_vicon_uwb');
	charlie_vicon_or = temp_bag.timeseries.Data(:,[1,7:10]);
	charlie_vicon_or(:,1) = charlie_vicon_or(:,1) + temp_bag.timeseries.Data(:,2)/1e9 - bag.StartTime; 


	% stm_or
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/orientation');
	stm_or = [temp_bag.timeseries.Time, temp_bag.timeseries.Data(:,3)];
	stm_or(:,1) = stm_or(:,1) + temp_bag.timeseries.Data(:,2)/1e9 - bag.StartTime; 
	
	% time
	time_end = bag.EndTime - bag.StartTime;
	
	% rimuovo variabili temporanee
	clear temp_bag bag
	
	save('uwbvicon_confronto.mat')
	
end

%% calcoli

% vicon_yaw
vicon_yaw		= zeros(size(charlie_vicon_or,1), 2);
vicon_yaw(:,1)	= charlie_vicon_or(:,1);  % copio i timestamp
vicon_yaw(:,2)	= quat2yaw_array(charlie_vicon_or(:,2:5)); % calcolo lo yaw

% tag_yaw
tag_yaw		= tagspos2yaw(tag0_pos, tag1_pos);
tag_f_yaw	= tagspos2yaw(tag0_f_pos, tag1_f_pos); % Non mi torna questo - !!

% presa per buona l'orientazione vicon, costruisco posizione delle tag
[tag0_vicon, tag1_vicon] = tag_vicon(charlie_vicon_pos, charlie_vicon_or);

% calcolo errore
[err0_array, err0_norm] = errore_tag(tag0_pos, tag0_vicon);
[err1_array, err1_norm] = errore_tag(tag1_pos, tag1_vicon);

%% plot check del sistema vicon
% figure(200)
% clf
% plot(tag0_vicon(:,1),		tag0_vicon(:,2), 'DisplayName', 'x tag0', 'Linewidth', 0.5)
% hold on
% % plot(tag0_vicon(:,1),		tag0_vicon(:,3), 'DisplayName', 'y tag0', 'Linewidth', 0.5)
% 
% plot(tag1_vicon(:,1),		tag1_vicon(:,2), 'DisplayName', 'x tag1', 'Linewidth', 0.5)
% % plot(tag1_vicon(:,1),		tag1_vicon(:,3), 'DisplayName', 'y tag1', 'Linewidth', 0.5)
% 
% plot(charlie_vicon_pos(:,1),		charlie_vicon_pos(:,2), 'DisplayName', 'x charlie', 'Linewidth', 1)
% % plot(charlie_vicon_pos(:,1),		charlie_vicon_pos(:,3), 'DisplayName', 'y charlie', 'Linewidth', 1)
% 
% axis tight
% hold off
% grid on
% xlabel('Time [s]')
% ylabel('Posizioni [m]')
% legend
% title('Confronto tag0')


% figure(201)
% clf
% plot(tag0_vicon(:,2),		tag0_vicon(:,3), 'DisplayName', 'tag0', 'Linewidth', 0.5)
% hold on
% plot(tag1_vicon(:,2),		tag1_vicon(:,3), 'DisplayName', 'tag1', 'Linewidth', 0.5)
% 
% plot(charlie_vicon_pos(:,2),		charlie_vicon_pos(:,3), 'DisplayName', 'charlie', 'Linewidth', 1)
% axis tight
% hold off
% grid on
% xlabel('x [m]')
% ylabel('y [m]')
% legend
% title('Map tutto vicon')


%% Qualche plot
% 
% % plot di tag0
% figure(1)
% clf
% plot(tag0_pos(:,1), tag0_pos(:,2))
% hold on
% plot(tag0_pos(:,1), tag0_pos(:,3))
% plot(tag0_pos(:,1), tag0_pos(:,4))
% axis tight
% hold off
% grid on
% xlabel('Time [s]')
% ylabel('Posizione tag0 [m]')
% title('Dati raw di tag0')

% confronto tag0, tag0_f  e tag0vicon (su x e y)
figure(1)
clf
plot(tag0_pos(:,1),		tag0_pos(:,2), 'DisplayName', 'x raw', 'Linewidth', 0.2)
hold on
plot(tag0_pos(:,1),		tag0_pos(:,3), 'DisplayName', 'y raw', 'Linewidth', 0.2)

plot(tag0_f_pos(:,1),	tag0_f_pos(:,2), 'DisplayName', 'x media', 'Linewidth', 1)
plot(tag0_f_pos(:,1),	tag0_f_pos(:,3), 'DisplayName', 'y media', 'Linewidth', 1)

plot(tag0_vicon(:,1),	tag0_vicon(:,2), 'DisplayName', 'x vicon', 'Linewidth', 1.2)
plot(tag0_vicon(:,1),	tag0_vicon(:,3), 'DisplayName', 'y vicon', 'Linewidth', 1.2)
axis tight
hold off
grid on
xlabel('Time [s]')
ylabel('Posizioni [m]')
legend
title('Confronto tag0')

% errore su tag0
figure(2)
clf
plot(err0_array(:,1),		err0_array(:,2), 'DisplayName', 'x', 'Linewidth', 0.5)
hold on
plot(err0_array(:,1),		err0_array(:,3), 'DisplayName', 'y', 'Linewidth', 0.5)
plot(err0_norm(:,1),		err0_norm(:,2), 'k--','DisplayName', 'norm', 'Linewidth', 1)
axis tight
hold off
grid on
xlabel('Time [s]')
ylabel('Errore vicon - uwb [m]')
legend
title('Errori su tag0')

% confronto tag1, tag1_f  e tag1vicon (su x e y)
figure(3)
clf
plot(tag1_pos(:,1),		tag1_pos(:,2), 'DisplayName', 'x raw', 'Linewidth', 0.2)
hold on
plot(tag1_pos(:,1),		tag1_pos(:,3), 'DisplayName', 'y raw', 'Linewidth', 0.2)

plot(tag1_f_pos(:,1),	tag1_f_pos(:,2), 'DisplayName', 'x media', 'Linewidth', 1)
plot(tag1_f_pos(:,1),	tag1_f_pos(:,3), 'DisplayName', 'y media', 'Linewidth', 1)

plot(tag1_vicon(:,1),	tag1_vicon(:,2), 'DisplayName', 'x vicon', 'Linewidth', 1.2)
plot(tag1_vicon(:,1),	tag1_vicon(:,3), 'DisplayName', 'y vicon', 'Linewidth', 1.2)
axis tight
hold off
grid on
xlabel('Time [s]')
ylabel('Posizioni [m]')
legend
title('Confronto tag1')

% errore su tag1
figure(4)
clf
plot(err1_array(:,1),		err1_array(:,2), 'DisplayName', 'x', 'Linewidth', 0.5)
hold on
plot(err1_array(:,1),		err1_array(:,3), 'DisplayName', 'y', 'Linewidth', 0.5)
plot(err1_norm(:,1),		err1_norm(:,2), 'k--','DisplayName', 'norm', 'Linewidth', 1)
axis tight
hold off
grid on
xlabel('Time [s]')
ylabel('Errore vicon - uwb [m]')
legend
title('Errori su tag1')



% confronto orientazione vicon e stm
figure(5)
clf
plot(stm_or(:,1),	unwrap(-stm_or(:,2))+2*pi, 'DisplayName', 'stm_{yaw}')
hold on
plot(vicon_yaw(:,1), unwrap(vicon_yaw(:,2))+2*pi, 'DisplayName', 'vicon_{yaw}')
plot(tag_f_yaw(:,1), unwrap(tag_f_yaw(:,2))+2*pi, 'DisplayName', 'tag_{yaw}')
axis tight
hold off
grid on
xlabel('Time [s]')
ylabel('Yaw [rad]')
legend
title('Confronto yaw')


%% Plot map
% 
% % plot3D
% figure(4)
% clf
% plot3(tag0_f_pos(:,2), tag0_f_pos(:,3), tag0_f_pos(:,4),  'DisplayName', 'tag0_f', 'Linewidth', 0.8)
% hold on
% plot3(tag1_f_pos(:,2), tag1_f_pos(:,3), tag1_f_pos(:,4),  'DisplayName', 'tag1_f', 'Linewidth', 0.8)
% plot3(charlie_vicon_pos(:,2), charlie_vicon_pos(:,3), charlie_vicon_pos(:,4),  ...
%     'DisplayName', 'tag0_f', 'Linewidth', 0.8)
% axis tight
% hold off
% grid on
% xlabel('x [m]')
% ylabel('y [m]')
% zlabel('z [m]')

% plot3D e asse z = 0
time_init = 1; % non ha senso dato che vado di sample e non di tempo!!!
time_stop = 500;
figure(100)
clf
plot(tag0_f_pos(time_init:time_stop,2), tag0_f_pos(time_init:time_stop,3), 'DisplayName', 'tag0_f', 'Linewidth', 0.8)
hold on
plot(tag1_f_pos(time_init:time_stop,2), tag1_f_pos(time_init:time_stop,3), 'DisplayName', 'tag1_f', 'Linewidth', 0.8)
plot(charlie_vicon_pos(time_init:time_stop,2), charlie_vicon_pos(time_init:time_stop,3),  ...
    'DisplayName', 'vicon', 'Linewidth', 0.8)
% axis tight
axis equal
hold off
grid on
xlabel('x [m]')
ylabel('y [m]')
zlabel('z [m]')
legend
title('Map')


%% Animazione



