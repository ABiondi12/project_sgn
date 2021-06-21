% Questo script esegue l'analisi di uwbvicon_confronto.bag

clear
close all
clc

addpath('functions')
addpath('files_bag_mat')

%% scegliere quale file analizzare:

% filename = 'uwbvicon_confronto0611.mat';
filename = 'uwbvicon_confronto0615.mat';

%% Estrazione variabili

if exist(filename) == 2
	
	% estrazione dalla bag gia` avvenuta, carico il save
	load(filename)
	
else
	% load
	
	filename_bag = [filename(1:(end-3)), 'bag']; % cambio estensione del file
	bag = rosbag(filename_bag);
	
	% decommenta quella che vuoi vedere
	%	rosbag info uwbvicon_confronto0611    % print info della bag
	% 	rosbag info uwbvicon_confronto0615    % print info della bag
	
	% prima colonna tempo [s]
	% time
	time_end = bag.EndTime - bag.StartTime;
	
	% tag0
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/tag0_pose');
	tag0_pos = [temp_bag.timeseries.Time, temp_bag.timeseries.Data(:,4:6)];
	tag0_pos(:,1) = tag0_pos(:,1) - bag.StartTime; 

	% tag0_f
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/tag0_pose_f');
	tag0_f_pos = [temp_bag.timeseries.Time, temp_bag.timeseries.Data(:,4:6)];
	tag0_f_pos(:,1) = tag0_f_pos(:,1) - bag.StartTime; 

	% tag1
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/tag1_pose');
	tag1_pos = [temp_bag.timeseries.Time, temp_bag.timeseries.Data(:,4:6)];
	tag1_pos(:,1) = tag1_pos(:,1) - bag.StartTime; 

	% tag1_f
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/tag1_pose_f');
	tag1_f_pos = [temp_bag.timeseries.Time, temp_bag.timeseries.Data(:,4:6)];
	tag1_f_pos(:,1) = tag1_f_pos(:,1) - bag.StartTime; 

	% charlie_vicon_pos
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/charlie_vicon_uwb');
	charlie_vicon_pos = [temp_bag.timeseries.Time, temp_bag.timeseries.Data(:,4:6)];
	charlie_vicon_pos(:,1) = charlie_vicon_pos(:,1) - bag.StartTime; 

	% charlie_vicon_or (quaternione)
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/charlie_vicon_uwb');
	charlie_vicon_or = [temp_bag.timeseries.Time, temp_bag.timeseries.Data(:,7:10)];
	charlie_vicon_or(:,1) = charlie_vicon_or(:,1) - bag.StartTime; 

	% stm_or
	temp_bag = select(bag,'Time',...
		[bag.StartTime bag.EndTime],'Topic','/orientation');
	stm_or = [temp_bag.timeseries.Time, temp_bag.timeseries.Data(:,3)];
	stm_or(:,1) = stm_or(:,1) - bag.StartTime; 
	
	% time
	time_end = bag.EndTime - bag.StartTime;
	
	% rimuovo variabili temporanee
	clear temp_bag bag
	
	save(filename)
	
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
err0_arr_normato = err0_array; % cosi` da copiare il tempo
err0_arr_normato(:,2:4) = err0_array(:,2:4)./err0_norm(:,2);
[pos_quiver_sync0, delta_quiver_sync0] = sync_vicon_tag(tag0_vicon, tag0_pos);

[err1_array, err1_norm] = errore_tag(tag1_pos, tag1_vicon);
err1_arr_normato = err1_array; % cosi` da copiare il tempo
err1_arr_normato(:,2:4) = err1_array(:,2:4)./err1_norm(:,2);
[pos_quiver_sync1, delta_quiver_sync1] = sync_vicon_tag(tag1_vicon, tag1_pos);

%% stats errore:
clc
% tag0
fprintf(['tag0 x media:', num2str(mean(err0_array(:,2))), ... 
	' stdcov ', num2str(std(err0_array(:,2))) , '\n']  )

fprintf(['tag0 y media:', num2str(mean(err0_array(:,3))), ... 
	' stdcov ', num2str(std(err0_array(:,3))) , '\n']  )

fprintf(['tag0 norm:   ', num2str(mean(err0_norm(:,2))), ... 
	'  stdcov ', num2str(std(err0_norm(:,2))) , '\n']  )

% tag1
fprintf(['tag1 x media:', num2str(mean(err1_array(:,2))), ... 
	' stdcov ', num2str(std(err1_array(:,2))) , '\n']  )

fprintf(['tag1 y media:', num2str(mean(err1_array(:,3))), ... 
	' stdcov ', num2str(std(err1_array(:,3))) , '\n']  )

fprintf(['tag1 norm:   ', num2str(mean(err1_norm(:,2))), ... 
	'  stdcov ', num2str(std(err1_norm(:,2))) , '\n']  )

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

% confronto tag0, tag0_f  e tag0vicon (su x)
figure(1)
clf
plot(tag0_pos(:,1),		tag0_pos(:,2), 'DisplayName', 'x raw', 'Linewidth', 0.2)
hold on
% plot(tag0_pos(:,1),		tag0_pos(:,3), 'DisplayName', 'y raw', 'Linewidth', 0.2)

plot(tag0_f_pos(:,1),	tag0_f_pos(:,2), 'DisplayName', 'x media', 'Linewidth', 1)
% plot(tag0_f_pos(:,1),	tag0_f_pos(:,3), 'DisplayName', 'y media', 'Linewidth', 1)

plot(tag0_vicon(:,1),	tag0_vicon(:,2), 'DisplayName', 'x vicon', 'Linewidth', 2)
% plot(tag0_vicon(:,1),	tag0_vicon(:,3), 'DisplayName', 'y vicon', 'Linewidth', 1.2)
axis tight
hold off
grid on
xlabel('Time [s]')
ylabel('Posizioni [m]')
legend
title('Confronto tag0 x')

% confronto tag0, tag0_f  e tag0vicon (su y)
figure(2)
clf
% plot(tag0_pos(:,1),		tag0_pos(:,2), 'DisplayName', 'x raw', 'Linewidth', 0.2)
plot(tag0_pos(:,1),		tag0_pos(:,3), 'DisplayName', 'y raw', 'Linewidth', 0.2)
hold on
% plot(tag0_f_pos(:,1),	tag0_f_pos(:,2), 'DisplayName', 'x media', 'Linewidth', 1)
plot(tag0_f_pos(:,1),	tag0_f_pos(:,3), 'DisplayName', 'y media', 'Linewidth', 1)

% plot(tag0_vicon(:,1),	tag0_vicon(:,2), 'DisplayName', 'x vicon', 'Linewidth', 1.2)
plot(tag0_vicon(:,1),	tag0_vicon(:,3), 'DisplayName', 'y vicon', 'Linewidth', 2)
axis tight
hold off
grid on
xlabel('Time [s]')
ylabel('Posizioni [m]')
legend
title('Confronto tag0 y')



% errore su tag0 
figure(3)
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



% confronto tag1, tag1_f  e tag1vicon (su x)
figure(4)
clf
plot(tag1_pos(:,1),		tag1_pos(:,2), 'DisplayName', 'x raw', 'Linewidth', 0.2)
hold on
% plot(tag1_pos(:,1),		tag1_pos(:,3), 'DisplayName', 'y raw', 'Linewidth', 0.2)

plot(tag1_f_pos(:,1),	tag1_f_pos(:,2), 'DisplayName', 'x media', 'Linewidth', 1)
% plot(tag1_f_pos(:,1),	tag1_f_pos(:,3), 'DisplayName', 'y media', 'Linewidth', 1)

plot(tag1_vicon(:,1),	tag1_vicon(:,2), 'DisplayName', 'x vicon', 'Linewidth', 2)
% plot(tag1_vicon(:,1),	tag1_vicon(:,3), 'DisplayName', 'y vicon', 'Linewidth', 1.2)
axis tight
hold off
grid on
xlabel('Time [s]')
ylabel('Posizioni [m]')
legend
title('Confronto tag1 x')

% confronto tag1, tag1_f  e tag1vicon (su y)
figure(5)
clf
% plot(tag1_pos(:,1),		tag1_pos(:,2), 'DisplayName', 'x raw', 'Linewidth', 0.2)
plot(tag1_pos(:,1),		tag1_pos(:,3), 'DisplayName', 'y raw', 'Linewidth', 0.2)
hold on

% plot(tag1_f_pos(:,1),	tag1_f_pos(:,2), 'DisplayName', 'x media', 'Linewidth', 1)
plot(tag1_f_pos(:,1),	tag1_f_pos(:,3), 'DisplayName', 'y media', 'Linewidth', 1)

% plot(tag1_vicon(:,1),	tag1_vicon(:,2), 'DisplayName', 'x vicon', 'Linewidth', 1.2)
plot(tag1_vicon(:,1),	tag1_vicon(:,3), 'DisplayName', 'y vicon', 'Linewidth', 2)
axis tight
hold off
grid on
xlabel('Time [s]')
ylabel('Posizioni [m]')
legend
title('Confronto tag1 y')

% errore su tag1
figure(6)
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
figure(7)
clf
plot(stm_or(:,1),	(unwrap(-stm_or(:,2))+2*pi) * 180/pi, 'Linewidth', 1, 'DisplayName', 'stm')
hold on
plot(vicon_yaw(:,1), (unwrap(vicon_yaw(:,2))+2*pi) * 180/pi, 'Linewidth', 1, 'DisplayName', 'vicon')
plot(tag_f_yaw(:,1), (unwrap(tag_f_yaw(:,2))+2*pi) * 180/pi, 'Linewidth', 1, 'DisplayName', 'atan2 tag')
axis tight
hold off
grid on
xlabel('Time [s]')
ylabel('Yaw [deg]')
legend
title('Confronto heading')


%% Plot errore map
% circonferenza di rif con centro nella media dell'errore e avente raggio
% pari a 3 sigma (3*deviazione standard) della norma dell'errore

% tag0
figure(300)
clf
plot(err0_array(:,2), err0_array(:,3), 'r*','DisplayName', 'tag0')
hold on
circ_temp = circle([mean(err0_array(:,2)),mean(err0_array(:,3))], 3*std(err0_norm(:,2)), 500  );
plot(circ_temp(1,:), circ_temp(2,:), 'k--', 'DisplayName', '3 \sigma')
axis equal
hold off
grid on
xlabel('x [m]')
ylabel('y [m]')
legend
title('Errore su tag0')

% tag0 normato
figure(301)
clf
plot((err0_arr_normato(:,2)) , err0_arr_normato(:,3), 'r*','DisplayName', 'tag0')
hold on
circ_temp = circle([0,0], 1, 500  );
plot(circ_temp(1,:), circ_temp(2,:), 'k--', 'DisplayName', 'Circ. Unitaria')
axis equal
hold off
grid on
xlabel('x [m]')
ylabel('y [m]')
legend
title('Errore normato su tag0')

% tag1
figure(302)
clf
plot(err1_array(:,2), err1_array(:,3), 'b*','DisplayName', 'tag1')
hold on
circ_temp = circle([mean(err1_array(:,2)),mean(err1_array(:,3))], 3*std(err1_norm(:,2)), 500  );
plot(circ_temp(1,:), circ_temp(2,:), 'k--', 'DisplayName', '3 \sigma')
axis equal
hold off
grid on
xlabel('x [m]')
ylabel('y [m]')
legend
title('Errore su tag1')

% tag1 normato
figure(303)
clf
plot((err0_arr_normato(:,2)) , err0_arr_normato(:,3), 'b*','DisplayName', 'tag1')
hold on
circ_temp = circle([0,0], 1, 500  );
plot(circ_temp(1,:), circ_temp(2,:), 'k--', 'DisplayName', 'Circ. Unitaria')
axis equal
hold off
grid on
xlabel('x [m]')
ylabel('y [m]')
legend
title('Errore normato su tag1')

% plot(err1_array(:,2), err1_array(:,3), 'b*','DisplayName', 'tag1')


%% plot errore quiver
% tag0
figure(400)
clf
quiver(	pos_quiver_sync0(:,2),		pos_quiver_sync0(:,3), ...
		delta_quiver_sync0(:,2),	delta_quiver_sync0(:,3) , 'b', 'Linewidth', 1, 'DisplayName', 'err tag0 orient')
axis equal
hold off
grid on
legend
xlabel('x [m]')
ylabel('y [m]')
title('Quiver su tag0')

% tag1
figure(401)
clf
quiver(	pos_quiver_sync1(:,2),		pos_quiver_sync1(:,3), ...
		delta_quiver_sync1(:,2),	delta_quiver_sync1(:,3) , 'r', 'Linewidth', 1, 'DisplayName', 'err tag1 orient')
axis equal
hold off
grid on
legend
xlabel('x [m]')
ylabel('y [m]')
title('Quiver su tag1')

% tag0 e tag1
figure(402)
clf
quiver(	pos_quiver_sync0(:,2),		pos_quiver_sync0(:,3), ...
		delta_quiver_sync0(:,2),	delta_quiver_sync0(:,3) , 'b', 'Linewidth', 1, 'DisplayName', 'err tag0 orient')
hold on
quiver(	pos_quiver_sync1(:,2),		pos_quiver_sync1(:,3), ...
		delta_quiver_sync1(:,2),	delta_quiver_sync1(:,3) , 'r', 'Linewidth', 1, 'DisplayName', 'err tag1 orient')
axis equal
axis([1.6,3.2,1.7,3])
hold off
grid on
legend
xlabel('x [m]')
ylabel('y [m]')
title('Quiver sui tag')


%% Animazione
% tutto l'animazione si trova in animate_charlie, scommentare per eseguire:
% animate_charlie_uwbvicon_confronto

