function [ x,y,Dx,Dy ] = calcolo_posizioni( a,b,c,Da,Db,Dc )

x = (a^2+b^2-c^2)/(2*b);
y = sqrt(a^2-x^2);
Dx = abs(a/b)*Da + abs(c/b)*Dc + abs(0.5 - a^2/(2*b^2)+c^2/(2*b^2))*Db; 
Dy = (  abs(2*a-2*x*a/b)*Da + abs(2*x*(0.5 - a^2/(2*b^2)+c^2/(2*b^2)))*Db + abs(2*x*c/b)*Dc)...
     / (2*sqrt(a^2-x^2));
end

