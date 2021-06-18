function [tag0_vicon, tag1_vicon] = tag_vicon(charlie_vicon_pos, charlie_vicon_or)
%TAG_VICON Estrapola e restituisce la posizione dei due tag come se fossero
%misurati dal sistema vicon


l = 0.495;  % [m] distanza tra le due tag
d = 0.12;   % [m] distanza da centro al lato
time		= charlie_vicon_or(:, 1);	% copio i timestamp
vicon_yaw	= quat2yaw_array(charlie_vicon_or(:, 2:5)); % calcolo lo yaw [rad]

% vettori in frame body
tag0_vett = [l/2;	d; 0];
tag1_vett = [-l/2;	d; 0];

% vettori in frame uwb
tag0_vicon = zeros(length(time),4);	% init tag frontale		nsamples x 4 (1 timestampp, 3 pos)
tag1_vicon = zeros(length(time),4);	% init tag posteriore	nsamples x 4 (1 timestampp, 3 pos)

for i = 1:length(time)
	yaw_now = vicon_yaw(i);
	
	%tag0
	tag0_ruotato = rotz(yaw_now) * tag0_vett;	% ruoto
	tag0_vicon(i,1)		= time(i);				% assegno tempo
	tag0_vicon(i,2:4)	= tag0_ruotato' + charlie_vicon_pos(i, 2:4); % traslo 
	
	%tag1
	tag1_ruotato = rotz(yaw_now) * tag1_vett;	% ruoto
	tag1_vicon(i,1)		= time(i);				% assegno tempo
	tag1_vicon(i,2:4)	= tag1_ruotato' + charlie_vicon_pos(i, 2:4); % traslo 
	
end



end

function mat = rotz(angle)
	mat = [	cos(angle)	-sin(angle) 0;
			sin(angle)	cos(angle)	0;
			0			0			1];

end