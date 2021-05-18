function [ Dx2, Dy2, Dx3, Dy3, Dz3] = prop_err( R01, R02, R03, R12, R13, R23, D01, ...
                                                D02, D03, D12, D13, D23 )
% function [ Dx2, Dy2, Dx3, Dy3, Dz3] = prop_err( R01, R02, R03, R12, R13, R23, D01, ...
%                                                 D02, D03, D12, D13, D23 )
% Questa funzione effettua una propagazione degli errori e sulla base 
% delle incertezze nelle misurazioni al metro laser, fornisce 
% l'incertezza delle coordinate delle singole ancore.
% Dy = sum(abs(dy/dx)*Dx). Dove dy/dx è la derivata di y rispetto alla 
% variabile x, Dx è l'incertezza su x, e sum indica la sommatoria su tutte
% le variabili indipendenti di cui y è funzione.



R = [R01, R02, R03, R12, R13, R23];
D = [D01, D02, D03, D12, D13, D23];

for i = 1:6
   if ((R(i)<0)||(D(i)<0))
       error('Le distanze e le incertezze devono essere positive.')
   end
end


syms r01 r02 r03 r12 r13 r23             
y2 = (r01^2 - r12^2 + r02^2)/ (2*r01);
x2 = sqrt(r02^2 - y2^2);
y3 = (r03^2 - r13^2 + r01^2)/(2*r01);
x3 = (x2^2 - 2*y3*y2 + y2^2 - r23^2 + r03^2)/(2*x2);
z3 = sqrt(r03^2 - x3^2 - y3^2);

Dy2_sym = simplify(jacobian(y2,[r01,r02,r03,r12,r13,r23]));
Dy2 = abs(subs(Dy2_sym, [r01,r02,r03,r12,r13,r23], R))*D';

Dx2_sym = simplify(jacobian(x2,[r01,r02,r03,r12,r13,r23]));
Dx2 = abs(subs(Dx2_sym, [r01,r02,r03,r12,r13,r23], R))*D';

Dx3_sym = simplify(jacobian(x3,[r01,r02,r03,r12,r13,r23]));
Dx3 = abs(subs(Dx3_sym, [r01,r02,r03,r12,r13,r23], R))*D';

Dy3_sym = simplify(jacobian(y3,[r01,r02,r03,r12,r13,r23]));
Dy3 = abs(subs(Dy3_sym, [r01,r02,r03,r12,r13,r23], R))*D';

Dz3_sym = simplify(jacobian(z3,[r01,r02,r03,r12,r13,r23]));
Dz3 = abs(subs(Dz3_sym, [r01,r02,r03,r12,r13,r23], R))*D';

Dx3 = double(Dx3);
Dy3 = double(Dy3);
Dz3 = double(Dz3);
Dx2 = double(Dx2);
Dy2 = double(Dy2);


end

