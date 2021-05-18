%%% DISTANZA MASSIMA DI LAVORO

% LAUREA MAGISTRALE ING.ROBOTICA E DELL'AUTOMAZIONE
% CORSO: SISTEMI DI GUIDA E NAVIGAZIONE
% AUTORI: CRISTIAN TESCONI/LUCA CROSATO


%**************************************************************************
% Questo script importa il file.txt della distanza fra due ancore, ne 
% realizza l'istogramma delle misure acquisite e ne calcola gli indici
% statistici.
%**************************************************************************

%% CLEAR 
clear all
close all
clc


%% SALVATAGGIO IMMAGINI
global save
save = 'y';


%% 
path = strcat('./','Dati/');
d = dir(strcat(path,'*.txt'));
num_el = numel(d); % numero di file .txt relativi all'algoritmo FAST
name = 'PosTag_';

for t = 4:19
    number = num2str(t);
    filename = strcat(path,name,number,'.txt'); 
    file = fopen(filename,'r');
    A = textscan(file,'%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s');
    fclose(file);
    
    % Ripulitura dati da 'Err' 
    C = zeros(length(A{1})-3,length(A));
    h=1; %indice di riga
    k=1;
    for i=1:length(A) %seleziono la cella
        h = 1;
        for j=4:length(A{1})-1 %scorro gli elementi della cella
            if (strcmp(A{i}{j},'Err'))
                C(h,k) = -1;
            else 
                C(h,k)=str2num(A{i}{j});
            end
            h = h+1;
        end
        k=k+1;
    end
    % Coordinate tag
    x_tag_raw = C(:,1);
    y_tag_raw = C(:,2);
    z_tag_raw = C(:,3);

    % Plot
    % plot3(x_tag_raw,y_tag_raw,z_tag_raw,'*');
	
    plot(x_tag_raw,y_tag_raw,'*');
	hold on
	plot([0,0,21835,10865],[0,27407,-1157, 10927], 'ro', 'Linewidth', 3)
	hold on
    xlabel('x [mm]');
    ylabel('y [mm]');
    zlabel('z [mm]');
    hold on
    grid on
end

save_as('prova','tutti_dati_prova')