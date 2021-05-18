%%% ACQUISIZIONI DISTANZA FRA DUE ANTENNE

% LAUREA MAGISTRALE ING.ROBOTICA E DELL'AUTOMAZIONE
% CORSO: SISTEMI DI GUIDA E NAVIGAZIONE
% AUTORI: CRISTIAN TESCONI/LUCA CROSATO


%**************************************************************************
% Questo script importa il file.txt della distanza fra due ancore, ne 
% realizza l'istogramma delle misure acquisite e ne calcola gli indici
% statistici.
%**************************************************************************

%% CARICAMENTO DATI 
file = 'distanza_due_antenne_9';
filename = strcat(strcat('./data/',file,'.txt');
delimiterIn = ' ';
headerlinesIn = 0; %scarta la prima riga
dati = importdata(filename,delimiterIn,headerlinesIn);

%% SALVATAGGIO IMMAGINI
global save
save = 'y'; %'y' se si vuole salvare, 'n' se non si vuole salvare le immagini

%% PLOT
figure('Name', 'Istogramma acquisizioni distanza due antenne:')
hist(dati,15)
save_as (file,'IMMAGINI_E1')

%% INDICI STATISTICI
N = length(dati);
val_medio = sum(dati)/N;
sigma = sqrt(var(dati));






