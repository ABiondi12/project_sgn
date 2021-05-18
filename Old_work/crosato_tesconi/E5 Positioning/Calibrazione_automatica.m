%%% DISTANZA FRA TUTTE LE COPPIE DI ANCORE
%
% LAUREA MAGISTRALE ING.ROBOTICA E DELL'AUTOMAZIONE
% CORSO: SISTEMI DI GUIDA E NAVIGAZIONE
% AUTORI: CRISTIAN TESCONI/LUCA CROSATO

%**************************************************************************
% Questo script permette di effettuare una calibrazione delle ancore con
% range di ingresso all'algoritmo ottenuti dall'autoranging effettuato con 
% effettuato con lo script python acquisizioni_distanze_antenne.py. 
% Effettua il calcolo degli indici statistici e salva i dati in un file
% .mat.
%**************************************************************************

%% CLEAR 
clear all;
close all;
clc;

%% CARICAMENTO E SALVATAGGIO DATI

filename = './dati/distanza_coppie_antenne_1.txt';
file = fopen(filename);
A = textscan(file,'%s %s %s %s %s %s %s %s %s %s %s %s');
fclose(file);


N = length(A{1});
M = length(A);
C = zeros(N,M);
h=1; %indice di riga
k=1;
for i=1:M %seleziono la cella
    h = 1;
    for j=2:N %scorro gli elementi della cella
        if (strcmp(A{i}{j},'Err'))
            C(h,k) = -1;
        else 
            C(h,k)=str2num(A{i}{j});
        end
        h = h+1;
    end
    k=k+1;
end

C = C(1:(N-1),:);

i = size(C);
i = i(1);


for j = 1:M
    i = size(C);
    i = i(1);
    while (i>0)
        if (C(i,j)<0)
           C(i,:)=[]; 
        end
        i = i - 1;
    end
end

r01 = C(:,1);
r02 = C(:,2);
r03 = C(:,3);
r12 = C(:,5);
r13 = C(:,6);
r23 = C(:,9);

% valori medi delle distanze euclidee misurate col sistema pozyx (rij) fra le ancore
r01_medio = mean(r01);
r02_medio = mean(r02);
r03_medio = mean(r03);
r12_medio = mean(r12);
r13_medio = mean(r13);
r23_medio = mean(r23);


R = [r01_medio,r02_medio,r03_medio,r12_medio,r13_medio,r23_medio]

% risultato dell'algoritmo sui valor medi delle misurazioni
[A0,A1,A2,A3] = rangesToPos (R)

% valor medio dei risultati dell'algoritmo su ciascuna misurazione
P = zeros(length(r01), M);
for i=1:length(r12)
    Q = [r01(i),r02(i),r03(i),r12(i),r13(i),r23(i)];
    [P(i,1:3), P(i,4:6),P(i,7:9),P(i,10:12)] = rangesToPos (Q);
end

ancore = zeros(1,12);
for j = 1:M
    ancore(j) = real(mean(P(:,j))); %valor medio
    sigma(j) = sqrt(var(P(:,j)));   %deviazione standard
end

%% SALVATAGGIO DATI
save('Calibrazione_automatica.mat','A0','A1','A2','A3','sigma')
movefile('Calibrazione_automatica.mat', './dati/')
