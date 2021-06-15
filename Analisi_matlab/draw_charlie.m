function [box_handle, dot_handle, tags_handle] = draw_charlie(pos, yaw, col)
%DRAW_CHARLIE Printa nella figura corrente un rettangolo inclinato
%rappresentante charlie

l = 0.6;	% [m] distanza longitudinale
d = 0.12;   % [m] distanza da centro al lato

% vertici
alto_sin	=	[l/2;	d;		0];
alto_des	=	[l/2;	-d;		0];
basso_sin	=	[-l/2;	d;		0];
basso_des	=	[-l/2;	-d;		0];
% feltro che indica il davanti
pallino		=	[0.25;	0.05;	0];
%tag
tag0		=	[0.495/2;	d;		0];
tag1		=	[-0.495/2;	d;		0];

% ruoto e traslo
alto_sin_new	=	pos' + rotz(yaw)	* alto_sin;
alto_des_new	=	pos' + rotz(yaw)	* alto_des;
basso_sin_new	=	pos' + rotz(yaw)	* basso_sin;
basso_des_new	=	pos' + rotz(yaw)	* basso_des;
pallino_new		=	pos' + rotz(yaw)	* pallino;
tag0_new		=	pos' + rotz(yaw)	* tag0;
tag1_new		=	pos' + rotz(yaw)	* tag1;

v = [	basso_sin_new(1)	basso_sin_new(2);	...
		basso_des_new(1)	basso_des_new(2);	...
		alto_des_new(1)		alto_des_new(2);	...
		alto_sin_new(1)		alto_sin_new(2);];
f = [1 2 3 4];

box_handle = patch('Faces',f,'Vertices',v,'FaceColor','white', 'EdgeColor', col);
hold on
dot_handle = plot(pallino_new(1), pallino_new(2), 'o', 'MarkerEdgeColor', col, 'MarkerSize', 3);
tags_handle = plot([tag0_new(1), tag1_new(1)], [tag0_new(2), tag1_new(2)], 'd', 'MarkerEdgeColor', col, 'MarkerSize', 3);
hold off


end


function mat = rotz(angle)
	mat = [	cos(angle)	-sin(angle) 0;
			sin(angle)	cos(angle)	0;
			0			0			1];

end