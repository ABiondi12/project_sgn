%%% ANALISI BIAS

% LAUREA MAGISTRALE ING.ROBOTICA E DELL'AUTOMAZIONE
% CORSO: SISTEMI DI GUIDA E NAVIGAZIONE
% AUTORI: CRISTIAN TESCONI/LUCA CROSATO


%**************************************************************************
% Questo script analizza l'andamento del bias al variare della distanza tra
% due antenne. In particolare si cerca di verificare se esiste o meno un
% trend lineare del bias in funziona della distanza tra le due antenne.
% Occorre insierire manualmente i valori delle misure effettuate al metro
% laser e i corrispettivi valori del bias, che possono essere determinati
% come scarto tra il valor medio (ottenuto utilizzando lo script 
% 'acquisizione_distanze_due_antenne.m') e la misura al metro laser. 
% Le immagini vengono automaticamente salvate nella cartella './IMMAGINI_E1'.
%**************************************************************************
%% CLEAR
clear all
close all
clc

%% SALVATAGGIO IMMAGINI
global save
save = 'y';  %'y' se si vuole salvare, 'n' se non si vuole salvare le immagini

%% BIAS
range = [1554,2740,3870,4457,5571,6640,8430,9490,11042]; %misurazioni al metro laser [mm]
bias = [138,84,84,102,121,146,211,154,174]; 
% plot
figure('name', 'bias associati ai vari range medi ')
plot(range,bias,'*')
axis([0 12000 0 300])
grid on
title('Bias associati ai vari range medi')
% cambiare il name di salvataggio dell'immagine ogni qual volta si cambia
% file .txt
save_as('bias','IMMAGINI_E1')

%% INTERPOLAZIONE
bias(1) = [];
range(1) = [];
p = polyfit(range, bias, 1);
x = range;
for i=1:length(range)
    x(2,i) = 1;
end
x(1, length(range) + 1) = 0;
x(2, length(range) + 1) = 1;

% plot
figure('name', 'fit lineare ')
plot(range,bias,'*', x(1,:), p*x )
title('Fit lineare')
axis([0 12000 0 300])
grid on
save_as ('fit_lineare','IMMAGINI_E1')


