function out = draw_charlie(pos, yaw)
%DRAW_CHARLIE Printa nella figura corrente un rettangolo inclinato
%rappresentante charlie

l = 0.6;  % [m] distanza tra le due tag
d = 0.12;   % [m] distanza da centro al lato

% vertici
alto_sin	=	[l/2;	d;	0];
alto_des	=	[l/2;	-d; 0];
basso_sin	=	[-l/2;	d;	0];
basso_des	=	[-l/2;	-d; 0];

% ruoto e traslo
alto_sin_new	=	pos' + rotz(yaw)	* alto_sin;
alto_des_new	=	pos' + rotz(yaw)	* alto_des;
basso_sin_new	=	pos' + rotz(yaw)	* basso_sin;
basso_des_new	=	pos' + rotz(yaw)	* basso_des;

v = [	basso_sin_new(1)	basso_sin_new(2);	...
		basso_des_new(1)	basso_des_new(2);	...
		alto_des_new(1)		alto_des_new(2);	...
		alto_sin_new(1)		alto_sin_new(2);];
f = [1 2 3 4];

out = patch('Faces',f,'Vertices',v,'FaceColor','white');


end


function mat = rotz(angle)
	mat = [	cos(angle)	-sin(angle) 0;
			sin(angle)	cos(angle)	0;
			0			0			1];

end