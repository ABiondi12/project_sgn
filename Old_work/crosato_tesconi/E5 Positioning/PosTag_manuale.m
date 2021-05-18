%%% POSIZIONAMENTO TAG E DISTANZA DALLE ANCORE
%
% LAUREA MAGISTRALE : ING. ROBOTICA E DELL'AUTOMAZIONE
% CORSO: SISTEMI DI GUIDA E NAVIGAZIONE
% AUTORI: CRISTIAN TESCONI/LUCA CROSATO

%**************************************************************************
% Questo script importa il file.txt relativo al posizionamento del tag e la
% relativa distanza dalle 4 ancore e ne calcola gli indici statistici delle
% varie grandezze considerate.
%**************************************************************************

%% CLEAR 
clear all;
close all;
clc;

%% SALVATAGGIO 
global saving
saving = 'y';

%% CARICAMENTO E SALVATAGGIO DATI

filename = './dati/PosTag_manuale.txt';
A = dlmread(filename,'',1,0);

% x-y-z del tag
pos_tag = A(:,1:3);
x_tag = pos_tag(:,1);
y_tag = pos_tag(:,2);
z_tag = pos_tag(:,3);

figure('name','istogramma x, dati raw ')
hist(x_tag,50)
figure('name','istogramma y, dati raw ')
hist(y_tag,50)
figure('name','istogramma z, dati raw ')
hist(z_tag,50)

% distanza ancora i-esima dal tag - RSS - timestamp
ancora0.d = A(:,4);  ancora0.RSS = A(:,5);  ancora0.time = A(:,6);
ancora1.d = A(:,7);  ancora1.RSS = A(:,8);  ancora1.time = A(:,9);
ancora2.d = A(:,10); ancora2.RSS = A(:,11); ancora2.time = A(:,12);
ancora3.d = A(:,13); ancora3.RSS = A(:,14); ancora3.time = A(:,15);


% Ripulisco i dati sulla distanza dall'ancora 2 in quanto sono presenti
% outlier che falsano i risultati
k = 1;
for i=1:length(ancora2.d)
   if ancora2.d(i)<3000
       ancora2.dist(k,1) = ancora2.d(i);
       k = k+1;
   end
end

% Pulizia outlier tag
k = 1;
for i=1:length(x_tag)
   if ((x_tag(i)>100))
       x_tag_2(k,1) = x_tag(i);
       k = k+1;
   end
end

k = 1;
for i=1:length(y_tag)
   if y_tag(i)>1500 && (y_tag(i)<2420)
       y_tag_2(k,1) = y_tag(i);
       k = k+1;
   end
end

k = 1;
for i=1:length(z_tag)
   if ((z_tag(i)<200) && (z_tag(i)>20))
       z_tag_2(k,1) = z_tag(i);
       k = k+1;
   end
end
close all
figure('name','istogramma x')
hist(x_tag_2,50)
save_as('istogramma_x_man','IMMAGINI')
figure('name','istogramma y')
hist(y_tag_2,35)
save_as('istogramma_y_man','IMMAGINI')
figure('name','istogramma z')
hist(z_tag_2,50)
save_as('istogramma_z_man','IMMAGINI')

%% INDICI STATISTICI
% valor medio e varianza delle distanze delle singole ancore dal tag e
% delle posizioni lungo gli assi cartesiani del tag

% ancora 0
val_medio_a0 = mean(ancora0.d);
sigma_a0 = sqrt(var(ancora0.d));

% ancora 2
val_medio_a1 = mean(ancora1.d);
sigma_a1 = sqrt(var(ancora1.d));

% ancora 3
val_medio_a2 = mean(ancora2.d);
sigma_a2 = sqrt(var(ancora2.d));

% ancora 4
val_medio_a3 = mean(ancora3.d);
sigma_a3 = sqrt(var(ancora3.d));

% tag
val_medio_x = mean(x_tag_2);
sigma_x = sqrt(var(x_tag_2));

val_medio_y = mean(y_tag_2);
sigma_y = sqrt(var(y_tag_2));

val_medio_z = mean(z_tag_2);
sigma_z = sqrt(var(z_tag_2));


%% DT fra i vari timestamp
% timestamp [ms] ancora 1
dt = zeros (length(ancora1.time));
for i=1:length(dt)-1
    dt(i)= ancora1.time(i+1,:)-ancora1.time(i,:);
end
% Ripulitura dei dati (vettore dt)
h= 1;
for i =1:length(dt)
        if(dt(i)<250 && dt(i)>0)
            dt_pulito(h,1)= dt(i);
            h = h+1;
        end
end
% indici statistici
val_medio_dt = mean(dt_pulito);
sigma_dt = sqrt(var(dt_pulito));

%% ISTOGRAMMA DEL DT
figure('name','istogramma Dt manuale')
hist(dt_pulito,30)
save_as('istogramma_dt_man','IMMAGINI')

%% SALVATAGGIO DATI
save ('PosTag_manuale.mat','x_tag','y_tag','z_tag','ancora0','ancora1',...
      'ancora2','ancora3','val_medio_x','val_medio_y','val_medio_z',...
      'sigma_x','sigma_y','sigma_z','val_medio_a0','val_medio_a1','val_medio_a2',...
      'val_medio_a3','sigma_a0','sigma_a1','sigma_a2','sigma_a3')
movefile('PosTag_manuale.mat', './dati/')