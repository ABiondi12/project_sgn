%%% DISTANZA MASSIMA DI LAVORO

% LAUREA MAGISTRALE ING.ROBOTICA E DELL'AUTOMAZIONE
% CORSO: SISTEMI DI GUIDA E NAVIGAZIONE
% AUTORI: CRISTIAN TESCONI/LUCA CROSATO


%**************************************************************************
% Questo script importa il file.txt della distanza fra due ancore, ne 
% realizza l'istogramma delle misure acquisite e ne calcola gli indici
% statistici.
%**************************************************************************

%% CARICAMENTO E SALVATAGGIO DATI
clearvars
close all
clc

filename = './Dati/PosTag_19.txt';
file = fopen(filename);
A = textscan(file,'%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s');
fclose(file);

%% SALVATAGGIO IMAMGINI
global save
save = 'y';

%% RIPULITURA DATI DA 'Err'
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


%% COORDINATE TAG (valor medio e varianza)
x_tag_raw = C(:,1);
y_tag_raw = C(:,2);
z_tag_raw = C(:,3);

h = 1;
for i = 1:length(x_tag_raw)
    if(x_tag_raw(i)~=-1)
        x_tag_clear(h)=x_tag_raw(i);
        h = h+1;
    end
end
mean_x = mean(x_tag_clear);
sigma_x = sqrt(var(x_tag_clear)); 
figure('name','istogramma x')
hist(x_tag_clear,30)

h = 1;
for i = 1:length(y_tag_raw)
    if(y_tag_raw(i)~=-1)
        y_tag_clear(h)=y_tag_raw(i);
        h = h+1;
    end
end
mean_y = mean(y_tag_clear);
sigma_y = sqrt(var(y_tag_clear));
figure('name','istogramma y')
hist(y_tag_clear,30)

h = 1;
for i = 1:length(z_tag_raw)
    if(z_tag_raw(i)~=-1)
        z_tag_clear(h)=z_tag_raw(i);
        h = h+1;
    end
end
mean_z = mean(z_tag_clear);
sigma_z = sqrt(var(z_tag_clear));
figure('name','istogramma z')
hist(z_tag_clear,30)

%% RSS
% RSS medio A0
mean_RSS_A0 = mean(C(:,5));
sigma_RSS_A0 = sqrt(var(C(:,5)));

% RSS medio A1
mean_RSS_A1 = mean(C(:,8));
sigma_RSS_A1 = sqrt(var(C(:,8)));

% RSS medio A2
mean_RSS_A2 = mean(C(:,11));
sigma_RSS_A2 = sqrt(var(C(:,11)));

% RSS medio A3
mean_RSS_A3 = mean(C(:,14));
sigma_RSS_A3 = sqrt(var(C(:,14)));
