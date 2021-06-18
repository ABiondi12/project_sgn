function [tag_vicon_sync, delta_tag] = sync_vicon_tag(tag_vicon, tag)
%sync_vicon_tag calcola le posizioni sincronizzate per fare plot come il
%quiver tra le posizioni delle tag e quelle del sistema vicon

time_1	= tag_vicon(:, 1);		% copio i timestamp
time_2	= tag(:, 1);			% copio i timestamp
pos_1	= tag_vicon(:, 2:4);	% copio pos
pos_2	= tag(:, 2:4);			% copio pos

% mi creo un vettore tempo
% t_ris = max((time_1(end)-time_1(1))/length(time_1), (time_2(end)-time_2(1))/length(time_2) );
t_ris = max(max(diff(time_1)), max(diff(time_2)));
		% risoluzione temporale, prendo il max del timestep (e quindi min freq)
time_end = min(max(time_1), max(time_2)); % prendo il minimo dei tempi finali
time = 0:t_ris:time_end;	% vettore tempi

% init
tag_vicon_sync	= zeros(length(time),4);	% array vicon (1 timestap, 3 pos)
delta_tag		= zeros(length(time),4);	% array vicon (1 timestap, 3 pos)


% ciclo for
for i = 1:length(time)
	time_now = time(i);
	
	% trovo l'istante temporale piu` vicino al temp
	index_1 = floor(mean(find(abs(time_1 - time_now) < t_ris)));
	index_2 = floor(mean(find(abs(time_2 - time_now) < t_ris)));
	
	if isempty(index_1) || isempty(index_2) || isnan(index_1) || isnan(index_2)
		error('check')
	end
	
	pos1_now = pos_1(index_1,:);
	pos2_now = pos_2(index_2,:);
	
	% calcolo
	tag_vicon_sync(i,2:4)	= pos1_now;
	delta_tag(i,2:4)		= pos2_now - pos1_now;
	delta_tag(i,4)			= 0;
end

% assegno tempo
tag_vicon_sync(:,1)	= time;
delta_tag(:,1)		= time;


end

