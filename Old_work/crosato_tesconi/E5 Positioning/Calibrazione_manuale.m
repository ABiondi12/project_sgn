%%% CALIBRAZIONE MANUALE

% LAUREA MAGISTRALE : ING. ROBOTICA E DELL'AUTOMAZIONE
% CORSO: SISTEMI DI GUIDA E NAVIGAZIONE
% AUTORI: CRISTIAN TESCONI/LUCA CROSATO

%**************************************************************************
% Questo script permette di effettuare una calibrazione delle ancore con
% range di ingresso all'algoritmo misurati manualmente col metro laser. 
% EFfettua inoltre il calcolo della propagazione dell'errore e salva i dati
% in un file .mat.
%**************************************************************************
clear all, close all, clc

% Range fra le varie coppie di ancore
R01 = 5126; 
R02 = 5731;
R03 = 3522;
R12 = 4155; 
R13 = 3008;
R23 = 2663;
R_mis = [R01, R02, R03, R12, R13, R23];

% incertezze fra le varie coppie di ancore
D01 = 10;
D02 = 10;
D03 = 15; 
D12 = 10;
D13 = 10;
D23 = 10;

% range tag-ancore
R0T = 2374;
R1T = 2859;
R2T = 4132;
R3T = 1645;
Rt = [R01, R02, R0T, R12, R1T, R2T];
% incertezze tag-ancore
D0T = 10;
D1T = 10;
D2T = 10;
D3T = 20;

%% PROPAGAZIONE ERRORE (ANCORE)
[ Dx2, Dy2, Dx3, Dy3, Dz3] = prop_err( R01, R02, R03, R12, R13, R23, D01, ...
                                                D02, D03, D12, D13, D23 )
Dx1 = 0;
Dy1 = D01;
Dz1 = 0;
Dz2 = 0;
inc = [Dx1,Dy1,Dz1,Dx2,Dy2,Dz2,Dx3,Dy3,Dz3];                                           
%% ALGORITMO DI CALIBRAZIONE ALGEBRICO (ANCORE)
[A0, A1,A2,A3] = rangesToPos(R_mis)



%% PROPAGAZIONE ERRORE (TAG)
% 3 rappresenta il tag remoto

[ Dx2, Dy2, DxT, DyT, DzT] = prop_err( R01, R02, R0T, R12, R13, R2T, D01, ...
                                        D02, D0T, D12, D1T, D2T )
%% ALGORITMO DI CALIBRAZIONE ALGEBRICO (TAG)
% A3 rappresenta le coordinate del tag remoto.
[A0_, A1_,A2_,AT_] = rangesToPos(Rt)

%% SALVATAGGIO DATI
save('Calibrazione_manuale.mat','A0','A1','A2','A3','inc')
movefile('Calibrazione_manuale.mat', './dati/')
