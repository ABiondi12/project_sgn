% Questo script esegue l'analisi di uwbvicon_confronto.bag

clear
close all
clc

% load
rosbag info 'uwbvicon_confronto.bag'    % print info della bag
bag = rosbag('uwbvicon_confronto.bag');


%% Estrazione variabili

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
stm_or = temp_bag.timeseries.Data(:,3);
stm_or(:,1) = stm_or(:,1) + temp_bag.timeseries.Data(:,2)/1e9 - bag.StartTime; 

% rimuovo variabile temporanea
clear temp_bag

%% Qualche plot a caso

% plot di tag0
figure(1)
clf
plot(tag0_pos(:,1), tag0_pos(:,2))
hold on
plot(tag0_pos(:,1), tag0_pos(:,3))
plot(tag0_pos(:,1), tag0_pos(:,4))
axis tight
hold off
grid on
xlabel('Time [s]')
ylabel('Posizione tag0 [m]')

% confronto tag0 con tag0_f (su x e y)
figure(2)
clf
plot(tag0_pos(:,1), tag0_pos(:,2), 'DisplayName', 'x tag0')
hold on
plot(tag0_pos(:,1), tag0_pos(:,3), 'DisplayName', 'y tag0')
plot(tag0_f_pos(:,1), tag0_f_pos(:,2), 'DisplayName', 'x tag0_f', 'Linewidth', 1.2)
plot(tag0_f_pos(:,1), tag0_f_pos(:,3), 'DisplayName', 'y tag0_f', 'Linewidth', 1.2)
axis tight
hold off
grid on
xlabel('Time [s]')
ylabel('Posizioni [m]')
legend


% confronto tag0 con tag0_f (su x e y) e charlie_vicon
figure(3)
clf
plot(tag0_pos(:,1), tag0_pos(:,2), 'DisplayName', 'x tag0')
hold on
plot(tag0_pos(:,1), tag0_pos(:,3), 'DisplayName', 'y tag0')

plot(tag0_f_pos(:,1), tag0_f_pos(:,2), 'DisplayName', 'x tag0_f', 'Linewidth', 1.2)
plot(tag0_f_pos(:,1), tag0_f_pos(:,3), 'DisplayName', 'y tag0_f', 'Linewidth', 1.2)

plot(charlie_vicon_pos(:,1), charlie_vicon_pos(:,2), 'DisplayName', 'x Vicon', 'Linewidth', 1)
plot(charlie_vicon_pos(:,1), charlie_vicon_pos(:,3), 'DisplayName', 'y Vicon', 'Linewidth', 1)
axis tight
hold off
grid on
xlabel('Time [s]')
ylabel('Posizioni [m]')
legend









