close all
clear all
% Velocità della luce
c = 3*10^8;
% Numero campioni
K = 60;

% Suppongo di avere un delay DT0 DT1 DT2 DT3 su ogni ancora e inoltre si
% considera anche quello del target DTt = 0.02, che si somma a tutti i range
% misurati.
DT = [(0.02+0.06) (0.02+0.08) (0.02+0.07) (0.02+0.055)];

DT_rd = [DT(1)*ones(1,3) DT(2)*ones(1,3) DT(3)*ones(1,3) DT(4)*ones(1,3)];

% rumore gaussiano ampiezza di 2 cm, (una diversa realizzazione per ogni acquisizione dei
% range relativi)
n = 0.02*randn(K,4);
n1 = 0.02*randn(K,4);
n2 = 0.02*randn(K,4);
n3 = 0.02*randn(K,4);

% Ridimensionamento della matrice coi campioni di rumore per costruire quella del data set.
for j = 1 : K
    for i = 1 : 4
        n_rd1=[n(j,1)*ones(1,3) n(j,2)*ones(1,3) n(j,3)*ones(1,3) n(j,4)*ones(1,3)];
        n_rd11=[n1(j,1)*ones(1,3) n1(j,2)*ones(1,3) n1(j,3)*ones(1,3) n1(j,4)*ones(1,3)];
        n_rd12=[n2(j,1)*ones(1,3) n2(j,2)*ones(1,3) n2(j,3)*ones(1,3) n2(j,4)*ones(1,3)];
        n_rd13=[n3(j,1)*ones(1,3) n3(j,2)*ones(1,3) n3(j,3)*ones(1,3) n3(j,4)*ones(1,3)];
    end
    n_rd2(j,1:12)=n_rd1(1:12);
    n_rd21(j,1:12)=n_rd11(1:12);
    n_rd22(j,1:12)=n_rd12(1:12);
    n_rd23(j,1:12)=n_rd13(1:12);
end

%% Set di posizioni testati

% Posizioni reali delle antenne nel setup
% a0_real = [0.0 0.0 0.0]';
% a1_real = [0.0 2.981 0.0]';
% a2_real = [4.722 1.721 0.0]';
% a3_real = [0.143 1.642 2.2240]';

% SET 1:
% a0_real = [0.0 0.0 0.0]';
% a1_real = [0.0 2.981 0.0]';
% a2_real = [4.722 -1.721 0.0]';
% a3_real = [0.143 -1.642 2.224]';

% SET 2:
% a0_real = [0.0 0.0 0.0]';
% a1_real = [0.0 2.981 0.0]';
% a2_real = [-4.722 -1.721 0.0]';
% a3_real = [0.143 -1.642 2.224]';

% SET 3
% a0_real = [0.0 0.0 0.0]';
% a1_real = [0.0 5.123 0.0]';
% a2_real = [4.722 -3.987 0.0]';
% a3_real = [0.7080 -1.642 2.224]';

% SET 4
% a0_real = [0.0 0.0 0.0]';
% a1_real = [0.0 5.123 0.0]';
% a2_real = [-4.722 -3.987 0.0]';
% a3_real = [0.0 0.0 2.224]';

% SET 5 
% a0_real = [0.0 0.0 0.0]';
% a1_real = [0.0 11.150 0.0]';
% a2_real = [-54.123 21 0.0]';
% a3_real = [5.0 0.0 2.224]';

% SET6
% a0_real = [0.0 0.0 0.0]';
% a1_real = [0.0 32.981 0.0]';
% a2_real = [-4.722 9.721 0.0]';
% a3_real = [3.143 0.642 2.224]';

% SET7
a0_real = [0.0 0.0 0.0]';
a1_real = [0.0 12.0 0.0]';
a2_real = [4.722 -9.721 0.0]';
a3_real = [3.143 -4.642 2.224]';

P = [a0_real, a1_real, a2_real, a3_real];

% Creo un vettore R 1x12 costituita di blocchi di 3 colonne, ogni blocco
% corrisponde ai RANGE VERI relativi alle altre antenne ordinate per ID
% crescente. 
l = 1;

for i = 1 : 4
    for j = 1 : 4
        if i ~= j
            D(1:3, l) = P(1:3, i)-P(1:3, j);
            l = l + 1;
        end
    end
end

for i = 1 : 12
    R(i) = norm(D(1:3, i));
end

% Creazione dell'insieme di range misurati
R_rd = ones(K,1)*R;
R_mis = R_rd + n_rd2 + ones(K,1)*DT_rd;

R_time = 1/c*R_mis;
DT_time = 1/c*DT;

R_m = mean(R_mis);

%% CALIBRAZIONE
% fase 1, ponendo il target vicino all'ancora 0. Determino DT_0t
% in quanto il valore misurato dall'ancora 0 è dato solo dai disturbi, quelli delle
% altre ancore sono dati dalle distanze relative a quell'ancora, perturbate
% dai disturbi agenti su di esse.
D1 = [DT(1)+n(:,1), R_mis(:,4), R_mis(:,7), R_mis(:,10)];

% Indicando DT_mt = DT_m + DT_t
DT_0t = mean(D1(:,1));

R_mis = R_rd + n_rd21 + ones(K,1)*DT_rd;

% fase 2, target vicino all'ancora 1. Trovo DT_1t
D2 = [R_mis(:,1), DT(2)+n1(:,2), R_mis(:,8), R_mis(:,11)];

DT_1t = mean(D2(:,2));

R_mis = R_rd + n_rd22 + ones(K,1)*DT_rd;
% fase 3, target vicino all'ancora 2.
D3 = [R_mis(:,2), R_mis(:,5), DT(3)+n2(:,3), R_mis(:,12)];
DT_2t = mean(D3(:,3));

R_mis = R_rd + n_rd23 + ones(K,1)*DT_rd;
% fase 4, target vicino all'ancora 3.
D4 = [R_mis(:,3), R_mis(:,6), R_mis(:,9), DT(4)+n3(:,4)];
DT_3t = mean(D4(:,4));

DT_est = [DT_0t, DT_1t, DT_2t, DT_3t];

R(1)
R_01 = mean(D1(:,2)) - DT_1t

R(2)
R_02 = mean(D1(:,3)) - DT_2t

R(3)
R_03 = mean(D1(:,4)) - DT_3t

R(5)
R_12 = mean(D3(:,2)) - DT_1t

R(6)
R_13 = mean(D4(:,2)) - DT_1t

R(9)
R_23 = mean(D4(:,3)) - DT_2t

R_new = [R_01 R_02 R_03 R_12 R_13 R_23];

%% Multidimensional Scaling
% Distanze euclidee richieste come ingresso dall'algoritmo di Classical
% Multidimensional Scaling.

E = [R_01, R_02, R_03, R_12, R_13, R_23];

% Richiamo dell'algoritmo di Classical Multidimensional Scaling nella 
% versione implementata. Le coordinate dei punti ricostruiti vengono
% salvate come vettori riga in test_CMD, ordinate per id crescente dell'ancora.
[test_CMD, U, U1, l, l1, B] = computeCMDS(E);

% (Per verifica provare i comandi Matlab che realizzano il Multidimensional
% Scaling. Se si vogliono utilizzare queste funzioni va cambiato il vettore
% trasl1 e il set di coordinate traslate per le coordinate ricostruite associata all'ancora 0, P_CMD)

p_CMD = cmdscale(E); %Classical Multidimensional Scaling
p_NMD = mdscale(E, 3); % Non-classical Multidimensional Scaling

% Traslazione del set di punti ricostruiti per portare le coordinate
% associate all'ancora 0 nell'origine del sistema di riferimento.
trasl1 = test_CMD(1,:);
Trasl1=[trasl1; trasl1; trasl1; trasl1];
%P_CMD = p_CMD - Trasl1;
P_CMD = test_CMD - Trasl1;

% Estrazione delle coordinate traslate associate alle ancore
A01 = P_CMD(1,:);
A1R1 = P_CMD(2,:);
A2R1 = P_CMD(3,:);
A3R1 = P_CMD(4,:);
% Applicazione della trasformazione che allinei questi punti al sistema di
% riferimento di interesse.
Pr_CMD = rotateSet(A01, A1R1, A2R1, A3R1);

%% Algebrico

[a0_alg1, a1_alg1, a2_alg1, a3_alg1] = rangesToPosALG(R_new);

dim = 0;
a0_alg = a0_alg1;
a1_alg = a1_alg1;
a2_alg = a2_alg1;
a3_alg = a3_alg1;


%% Compensazione Segni assumendo come input il segno delle coordinate X e Z della posizione dell'ancora2
if a2_real(1)*a2_alg(1)<0
    a2_alg(1)=(-1)*a2_alg(1);
    a3_alg(1)=(-1)*a3_alg(1);
end
if a2_real(1)*Pr_CMD(3,1) < 0
    Pr_CMD(3,1)=(-1)*Pr_CMD(3,1);
    Pr_CMD(4,1)=(-1)*Pr_CMD(4,1);
end

if a3_real(3)>0
   if a3_alg(3)< 0
       a3_alg(3)=(-1)*a3_alg(3);
   end
   if Pr_CMD(4,3) < 0
      Pr_CMD(4,3) = (-1)*Pr_CMD(4,3); 
   end
end

%% Calcolo indice di costo fitting e applicazione di fmincon per la minimizzazione vincolata dell'indice
syms x(k) R_m(m,r) S(m)

x(k) = x(k);
S(m) = S(m);
R_m(m,r) = R_m(m,r);

J1= 0;
for r = 1 : 4
    for m = 1 : 4
        if m ~= r
            J1 = J1 + 1/(2*(S(m))^2)*[(x(m) + sqrt((x(4 + 1 + 3*(m-1)) - x(4 + 1 + 3*(r-1)))^2 + (x(4 + 1 + 3*(m-1) + 1) - (x(4 + 1 + 3*(r-1) + 1)))^2 + (x(4 + 1 + 3*(m-1) + 2) - x(4 + 1 + 3*(r-1) + 2))^2) - R_m(m,r))^2];
        end
    end
end

clear x S R_m

S = std(R_mis');
R_mean = mean(R_mis);

R_m = [    0      R_mean(1)  R_mean(2)  R_mean(3);
       R_mean(4)      0      R_mean(5)  R_mean(6);
       R_mean(7)  R_mean(8)     0       R_mean(9);
       R_mean(10) R_mean(11) R_mean(12)     0    ];

   
myfun = @(x) (x(1) - R_m(1, 2) + ((x(5) - x(8))^2 + (x(6) - x(9))^2 + (x(7) - x(10))^2)^(1/2))^2/(2*S(1)^2) + (x(2) - R_m(2, 1) + ((x(5) - x(8))^2 + (x(6) - x(9))^2 + (x(7) - x(10))^2)^(1/2))^2/(2*S(2)^2) + (x(1) - R_m(1, 3) + ((x(5) - x(11))^2 + (x(6) - x(12))^2 + (x(7) - x(13))^2)^(1/2))^2/(2*S(1)^2) + (x(3) - R_m(3, 1) + ((x(5) - x(11))^2 + (x(6) - x(12))^2 + (x(7) - x(13))^2)^(1/2))^2/(2*S(3)^2) + (x(1) - R_m(1, 4) + ((x(5) - x(14))^2 + (x(6) - x(15))^2 + (x(7) - x(16))^2)^(1/2))^2/(2*S(1)^2) + (x(2) - R_m(2, 3) + ((x(8) - x(11))^2 + (x(9) - x(12))^2 + (x(10) - x(13))^2)^(1/2))^2/(2*S(2)^2) + (x(3) - R_m(3, 2) + ((x(8) - x(11))^2 + (x(9) - x(12))^2 + (x(10) - x(13))^2)^(1/2))^2/(2*S(3)^2) + (x(4) - R_m(4, 1) + ((x(5) - x(14))^2 + (x(6) - x(15))^2 + (x(7) - x(16))^2)^(1/2))^2/(2*S(4)^2) + (x(2) - R_m(2, 4) + ((x(8) - x(14))^2 + (x(9) - x(15))^2 + (x(10) - x(16))^2)^(1/2))^2/(2*S(2)^2) + (x(4) - R_m(4, 2) + ((x(8) - x(14))^2 + (x(9) - x(15))^2 + (x(10) - x(16))^2)^(1/2))^2/(2*S(4)^2) + (x(3) - R_m(3, 4) + ((x(11) - x(14))^2 + (x(12) - x(15))^2 + (x(13) - x(16))^2)^(1/2))^2/(2*S(3)^2) + (x(4) - R_m(4, 3) + ((x(11) - x(14))^2 + (x(12) - x(15))^2 + (x(13) - x(16))^2)^(1/2))^2/(2*S(4)^2);
   
A = [];

b = [];

Aeq = [1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;
       0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0;
       0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0;
       0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0;
       0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0;
       0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0;
       0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0];
   
beq = zeros(7,1);

x0 = [DT_est, 0, 0, 0, 0, R_new(1), 0, a2_real(1)/abs(a2_real(1))*R_new(2), R_new(2), 0, R_new(3), R_new(3), ...
    a3_real(3)/abs(a3_real(3))*R_new(3)];

x = fmincon(myfun, x0, A, b, Aeq, beq)

%% Confronto risultati

% Range veri
R 
% Range stimati
R_new

DT
DT_est

P_real = P'
P_est = [x(5:7); x(8:10); x(11:13); x(14:16)];
Pr_CMD
P_alg = [a0_alg(1:3), a1_alg(1:3), a2_alg(1:3), a3_alg(1:3)]'

%% Plot
A = 0:3;
figure;
subplot(3,1,1)
plot(A,abs(P_real(:,1)-P_est(:,1)), '-*');
hold on
grid on
plot(A,abs(P_real(:,1)-Pr_CMD(:,1)), '-r*');
plot(A,abs(P_real(:,1)-P_alg(:,1)), '-g*');
xlabel('ID ancora')
legend('ML', 'CMDS', 'Alg')
title('Errore di stima della coordinata x')

subplot(3,1,2)
plot(A,abs(P_real(:,2)-P_est(:,2)), '-*');
hold on
plot(A,abs(P_real(:,2)-Pr_CMD(:,2)), '-r*');
%hold on
plot(A,abs(P_real(:,2)-P_alg(:,2)), '-g*');
grid on
xlabel('ID ancora')
legend('ML', 'CMDS', 'Alg')
title('Errore di stima della coordinata y')

subplot(3,1,3)
plot(A,abs(P_real(:,3)-P_est(:,3)), '-*');
hold on
plot(A,abs(P_real(:,3)-Pr_CMD(:,3)), '-r*');
plot(A,abs(P_real(:,3)-P_alg(:,3)), '-g*');
grid on
xlabel('ID ancora')
legend('ML', 'CMDS', 'Alg')
title('Errore di stima della coordinata z')

figure;
subplot(3,1,1)
plot(A,abs(P_real(:,1)-Pr_CMD(:,1)), '-r*');
hold on
grid on
plot(A,abs(P_real(:,1)-P_alg(:,1)), '-g*');
xlabel('ID ancora')
legend('CMDS', 'Alg')
title('Errore di stima della coordinata x')

subplot(3,1,2)
plot(A,abs(P_real(:,2)-Pr_CMD(:,2)), '-r*');
hold on
plot(A,abs(P_real(:,2)-P_alg(:,2)), '-g*');
grid on
xlabel('ID ancora')
legend('CMDS', 'Alg')
title('Errore di stima della coordinata y')

subplot(3,1,3)
plot(A,abs(P_real(:,3)-Pr_CMD(:,3)), '-r*');
hold on
plot(A,abs(P_real(:,3)-P_alg(:,3)), '-g*');
grid on
xlabel('ID ancora')
legend('CMDS', 'Alg')
title('Errore di stima della coordinata z')
