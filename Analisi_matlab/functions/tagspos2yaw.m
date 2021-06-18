function tag_yaw = tagspos2yaw(tag0_pos, tag1_pos)
%TAGSPOS2YAW questa funzione calcola l'angolo yaw tramite la posizione
%delle tag

%	vettore in entrata deve essere nsample x 4(1 timestamp, 3 posizione)


l = min( size(tag0_pos,1), size(tag1_pos,1) );


if abs(size(tag0_pos,1)- size(tag1_pos,1)) > 100
    warning(' I due tag hanno un numero di sample troppo diverso')
end

tag_yaw = zeros(l, 2);  %init
if size(tag0_pos,1) < size(tag1_pos,1)
    tag_yaw(:,1) = tag0_pos(:,1);	% assegno timestamp
else
	tag_yaw(:,1) = tag1_pos(:,1);	% assegno timestamp
end

for i = 1:l
    tag_yaw(i,2) = atan2(   (tag0_pos(i,3)- tag1_pos(i,3)), ... % y
                            (tag0_pos(i,2)- tag1_pos(i,2)));    % x
end


end

