function [ x,y,Dx,Dy ] = calcolo_pos_3D( a,b,c,z,Da,Db,Dc,Dz )
%**************************************************************************
% Serve per stimare l'errore effettuato al metro laser delle coordinate x e
% y di una data ancora. Si pone l'ancora 1 in [0,0,0], l'ancora 2 in [x2, 0
% 0]. Per calcolare l'errore sulle coordinate x e y dell'ancora 3 (ancora 
% pensata coplanare alle prime due), si ponga z = 0 e Dz = 0. Se invece si è
% interessati all'ancora 4 (ancora fuori dal piano), si avrà z != 0 e Dz
% !=0. 
% a = distanza tra l'ancora xxxx
% b = ----
% c = ----
%**************************************************************************

x = (a^2+b^2-c^2)/(2*b);
y = sqrt(a^2-x^2);
Dx = abs(a/b)*Da + abs(c/b)*Dc + abs(0.5)*Db; 
Dy = (  abs(2*a-2*x*a/b)*Da + abs(x)*Db + abs(2*x*c/b)*Dc+abs(2*z)*Dz)...
     / (2*sqrt(a^2-x^2));
end


