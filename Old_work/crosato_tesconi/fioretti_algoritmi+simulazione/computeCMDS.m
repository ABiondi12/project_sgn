function [ X_, A_, U1_, l , l1, B] = computeCMDS( R )
% Questa funzione implementa la tecnica di Classical Multidimensional Scaling che ricava
% tramite decomposizione agli autovalori di B = X*X' la matrice delle
% coordinate dei punti X, a partire dalle distanze euclidee relative.

% Matrice delle distanze al quadrato
D = [0      R(1)^2 R(2)^2 R(3)^2
     R(1)^2   0    R(4)^2 R(5)^2
     R(2)^2 R(4)^2   0    R(6)^2
     R(3)^2 R(5)^2 R(6)^2  0   ];

J = eye(4) - 1/4*ones(4,4);
B = -1/2*J*D*J;

% Selezione degli autovalori a modulo maggiore, in numero
% pari alle dimensioni del problema. U1 è la matrice degli
% autovettori l1 quella degli autovalori di B.

[U1_, l1] = eig(B);

% Determinazione autovalore da escludere, e registrazione della sua posizione nella diagonale
min = abs(l1(1,1));
pos = 1;
for i = 1 : 4
   if abs(l1(i, i)) < min
       min = abs(l1(i,i));
       pos = i;
   end
end

K1 = [1 0 0];
K2 = [0 1 0];
K3 = [0 0 1];

K = [K1; K2; K3];

% l e A sono rispettivamente le matrici degli autovalori a modulo maggiore,
% in numero 3 in quanto lo spazio di arrivo è quello tridimensionale, e dei
% relativi autovettori.
dim = 0;
for j = 1 : 4
   if j~=pos && dim<3
       dim = dim + 1;
       l(dim,:) = K(dim,:)*l1(j,j);
       A_(:,dim) = U1_(:,j);
   end
end

% Set di coordinate ricostruite in un arbitrario sistema di riferimento, da
% traslare per portare l'origine in ANC0 e ruotare con la funzione rotateSet.m
% per ottenere quelle specifiche per il nostro caso.
X_ = A_*sqrt(l);

end


