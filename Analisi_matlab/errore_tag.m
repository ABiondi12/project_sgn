function [err_array, err_norm] = errore_tag(vett1, vett2)
%ERRORE_TAG Calcola l'errore (2 - 1) e la norma dell'errore tra i due vettori
%inseriti. I vettori input devono essere nsamples x 4 (1 timestamp, 3 pos)

time_1	= vett1(:, 1);		% copio i timestamp
time_2	= vett2(:, 1);		% copio i timestamp
pos_1	= vett1(:, 2:4);	% copio pos
pos_2	= vett2(:, 2:4);	% copio pos

% mi creo un vettore tempo
% t_ris = max((time_1(end)-time_1(1))/length(time_1), (time_2(end)-time_2(1))/length(time_2) );
t_ris = max(max(diff(time_1)), max(diff(time_2)));
		% risoluzione temporale, prendo il max del timestep (e quindi min freq)
time_end = min(max(time_1), max(time_2)); % prendo il minimo dei tempi finali
time = 0:t_ris:time_end;	% vettore tempi

% init
err_array	= zeros(length(time),4);	% array errore (1 timestap, 3 pos)
err_norm	= zeros(length(time),2);	% array norm errore (1 timestap, 1 norm)	


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
	err_now			= pos2_now - pos1_now;
	err_norm_now	= norm(err_now,2);
	
	% assegno
	err_array(i,1)		= time_now;
	err_array(i,2:4)	= err_now;
	
	err_norm(i,1)		= time_now;
	err_norm(i,2)		= err_norm_now;
	
	
end


end

