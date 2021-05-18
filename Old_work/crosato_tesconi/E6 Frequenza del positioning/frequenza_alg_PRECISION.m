%%% FREQUENZA DEL POSITIONING (PROTOCOLLO PRECISION)

% LAUREA MAGISTRALE ING.ROBOTICA E DELL'AUTOMAZIONE
% CORSO: SISTEMI DI GUIDA E NAVIGAZIONE
% AUTORI: CRISTIAN TESCONI/LUCA CROSATO


%**************************************************************************
% Questo script importa i file .txt relativi al cambiamento dei parametri
% UWB ( con utilizzo del protocollo PRECISION )e ne effettua un plot dei 
% risultati medi.
%**************************************************************************

%% CLEAR 
clear all
close all
clc

%% SALVATAGGIO 
global save
save = 'y';

%% CARICAMENTO DATI 
%**************************** UWB_settings ********************************
% Channel: 5
% Bitrate: 110 kb/s
% PRF: 64 MHz
% Preamble length: 64 symbols
% Gain: 11.5
%**************************************************************************
channel = 'Canale5';
protocol = 'PROTOCOL_PRECISION';
path = strcat('./', channel, '/', protocol, '/');
name = 'frequenza_';
num_el = numel(dir(strcat(path,'*.txt'))); % numero di file .txt relativi all'algoritmo FAST

dt_pp = zeros(num_el,1);
for t=0:(num_el - 1)
        % apertura del file e salvatagggio del contenuto in una matrice
        number = num2str(t);
        filename = strcat(path,name,number,'.txt'); 
        file = fopen(filename,'r');
        A = textscan(file,'%s %s %s %s %s %s %s %s');
        fclose(file);
        [nrows, ncols] = cellfun(@size, A);
        n = nrows(1); % numero di righe di una singola cella  
        m = length(ncols); % numero di colonne
        C = zeros(n,m);
        h=1; % indice di riga
        k=1; % indice di colonna
        for i=1:m %seleziono la cella
        h = 1;
        for j=20:n-1 %scorro gli elementi della cella
            C(h,k)=str2num(A{i}{j}); % converto da string a numerico
            h = h+1;
        end
        k=k+1;
        end
        dt = C(:,4);
        mean_dt = mean(dt); % valor medio
        var_dt = sqrt(var(dt)); % varianza
        dt_pp(t+1)= mean_dt;  % vettore contenente i vari dt (ognuno differisce per almeno
                              % un parametri UWB )
        var_pp(t+1)=var_dt; % vettore contenente le varianze
end


%% PLOT : PRECISION PROTOCOL

%************************ UWB SETTINGS ************************************
% Ranging protocol: PRECISION
% Channel: 5
% Bitrate: 110 kb/s
% PRF: 64 MHz
% Preamble length: 1024 symbols
% Gain: 11.5
% *************************************************************************

% CASISTICA: 
% freq_1 :  1-7 : channel,bitrate=110,PRF=64 MHz,gain ----> costanti
%                 Preamble length ----> 64,128,256,512,1024,1536,2048,4096
%
% freq_2 :  8-16 : channel,bitrate=850,PRF=64 MHz,gain ----> costanti
%                  Preamble length ----> 64,128,256,512,1024,1536,2048,4096
%
% freq_3 : 17:24 : channel,bitrate=6810,PRF=64 MHz,gain ----> costanti
%                  Preamble length ----> 64,128,256,512,1024,1536,2048,4096
%
% freq_1_1 :  1-7 : channel,bitrate=110,PRF=16 MHz,gain ----> costanti
%                 Preamble length ----> 64,128,256,512,1024,1536,2048,4096
%
% freq_2_1 :  8-16 : channel,bitrate=850,PRF=16 MHz,gain ----> costanti
%                  Preamble length ----> 64,128,256,512,1024,1536,2048,4096
%
% freq_3_1 : 17:24 : channel,bitrate=6810,PRF=16 MHz,gain ----> costanti
%                  Preamble length ----> 64,128,256,512,1024,1536,2048,4096

freq_1 = dt_pp(1:8);
freq_2 = dt_pp(9:16);
freq_3 = dt_pp(17:24);
freq_1_1 = dt_pp(25:32);
freq_2_1 = dt_pp(33:40);
freq_3_1 = dt_pp(41:48);
pl = [64,128,256,512,1024,1536,2048,4096]'; % preamble length

% open figure
figure ('name','update rate PRECISION PROTOCOL')
fig = gcf;
for i =1:8
    % freq_1
    plot1 = plot (pl(i),freq_1(i),'--bs',...
                                  'LineWidth',1,...
                                  'MarkerSize',7,...
                                  'MarkerEdgeColor','b',...
                                  'MarkerFaceColor',[0.5,0.5,0.5])
    hold on
    line(pl,freq_1,'Color','blue','LineStyle','--');
    hold on
    
    % freq_2
    plot2 = plot (pl(i),freq_2(i),'--ks',...
                                  'LineWidth',1,...
                                  'MarkerSize',7,...
                                  'MarkerEdgeColor','k',...
                                  'MarkerFaceColor',[0.4,0.4,0.4])
    hold on
    line(pl,freq_2,'Color','black','LineStyle','-.');
    hold on 
    
     % freq_3
    plot3 = plot (pl(i),freq_3(i),'--rs',...
                                  'LineWidth',1,...
                                  'MarkerSize',7,...
                                  'MarkerEdgeColor','r',...
                                  'MarkerFaceColor',[0.4,0.4,0.4])
    hold on
    line(pl,freq_3,'Color','red','LineStyle','-.');
    hold on 
    
     % freq_4
    plot4 = plot (pl(i),freq_1_1(i),'--cs',...
                                    'LineWidth',1,...
                                    'MarkerSize',7,...
                                    'MarkerEdgeColor','c',...
                                    'MarkerFaceColor',[0.4,0.4,0.4])
    hold on
    line(pl,freq_1_1,'Color','cyan','LineStyle','-.');
    hold on 
    
     % freq_5
    plot5 = plot (pl(i),freq_2_1(i),'--ms',...
                                    'LineWidth',1,...
                                    'MarkerSize',7,...
                                    'MarkerEdgeColor','m',...
                                    'MarkerFaceColor',[0.4,0.4,0.4])
    hold on
    line(pl,freq_2_1,'Color','magenta','LineStyle','-.');
    hold on 
    
     % freq_6
    plot6 = plot (pl(i),freq_3_1(i),'--gs',...
                                    'LineWidth',1,...
                                    'MarkerSize',7,...
                                    'MarkerEdgeColor','g',...
                                    'MarkerFaceColor',[0.4,0.4,0.4])
    hold on
    line(pl,freq_3_1,'Color','green','LineStyle','-.');
    hold on 
    
        
end
grid on
title('update rate PROTOCOL PRECISION')
xlabel('Preamble length')
ylabel('Positioning duration [ms]')
lgb = legend([plot1,plot2,plot3,plot4,plot5,plot6],'bitrate=110 kb/s, PRF=64 MHz',...
                                                   'bitrate=850 kb/s, PRF=64 MHz',...
                                                   'bitrate=6810kb/s, PRF=64 MHz',...
                                                   'bitrate=110 kb/s, PRF=16 MHz',...
                                                   'bitrate=850 kb/s, PRF=16 MHz',...
                                                   'bitrate=6810 kb/s,PRF=16 MHz','Location','northwest');
lgb.FontSize = 6;

%% SALVATAGGIO IMMAGINE
figure_name = strcat(channel, '_', protocol);
saveas(fig, strcat(channel, '_', protocol), 'png')
movefile(strcat(figure_name,'.png'), './IMMAGINI')





