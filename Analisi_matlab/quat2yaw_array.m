function array_yaw = quat2yaw_array(array_quat, index_eul)
%QUAT2YAW_ARRAY Questa funzione estrae da ogni riga di un vettore
%(contenente un quaternione) l'angolo yaw
%	vettore in entrata deve essere nsample x 4 (quaternione)

if nargin < 2
	index_eul = 3;
end

l = size(array_quat,1);
if size(array_quat,2) ~= 4
	error('Dimensioni sbagliate')
end

array_yaw = zeros(size(array_quat,1), 1);

for i = 1:l
    eul = quat2eul(array_quat(i,:),'ZYX');
    array_yaw(i,:) = eul(index_eul); % why?
end



end

