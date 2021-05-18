%%% MULTIPOSITIONING

% LAUREA MAGISTRALE ING.ROBOTICA E DELL'AUTOMAZIONE
% CORSO: SISTEMI DI GUIDA E NAVIGAZIONE
% AUTORI: CRISTIAN TESCONI/LUCA CROSATO


%**************************************************************************
% Questo script importa i file .txt relativi all'acquisizione della
% distanza fra due tag fissati all'estremità di un asta rigida; la prova
% consiste nel muovere l'asta e vedere quanto ciò influisce sulla
% variazione della distanza fra i due tag.
%**************************************************************************

%% CLEAR
clear all
close all
clc

%%
% apertura del file e salvatagggio del contenuto del .txt in una matrice
filename = './dati/asta_0.txt'; 
file = fopen(filename,'r');
A = textscan(file,'%s %s %s %s %s %s %s %s %s');
fclose(file);
[nrows, ncols] = cellfun(@size, A);
n = nrows(1); % numero di righe di una singola cella  
m = length(ncols); % numero di colonne
h=1; % indice di riga
k=1; % indice di colonna
for i=1:m %seleziono la cella
h = 1;
for j=15:n-1 %scorro gli elementi della cella (e scarto i commenti iniziali)
    C(h,k)=str2num(A{i}{j}); % converto da string a numerico
    h = h+1;
end
k=k+1;
end

%******************* VALOR MEDIO & VARIANZA DISTANZA **********************

dist_tag_3D = C(:,9);  % acquisizioni distanza tra i due tag
mean_dist_tag_3D = mean(dist_tag_3D); % valore medio
var_dist_tag_3D = sqrt(var(dist_tag_3D)); %varianza
% open figure
figure('name','istogramma modulo distanza tag')
fig = gcf; %get current figure
hist(dist_tag_3D,50)
% salvataggio immagine
saveas(fig, 'istogramma_modulo_distanza', 'png')
movefile(strcat('istogramma_modulo_distanza','.png'), './IMMAGINI')


% Display dei risultati
fprintf('Valore medio modulo della distanza fra i due tag:   %d\n', mean_dist_tag_3D)
fprintf('Varianza modulo della distanza fra i due tag:   %d\n',var_dist_tag_3D)


%***************** VALOR MEDIO E VARIANZA TAG *****************************
% coordinate tag 1:
x1 = C(:,1);
y1 = C(:,2);
z1 = C(:,3);

% coordinate tag 2:
x2 = C(:,5);
y2 = C(:,6);
z2 = C(:,7);

Dx = x1-x2;
Dy = y1-y2;
Dz = z1-z2;
val_medio_Dx = mean(Dx);
val_medio_Dy = mean(Dy);
val_medio_Dz = mean(Dz);
sigma_Dx = sqrt(var(Dx));
sigma_Dy = sqrt(var(Dy));
sigma_Dz = sqrt(var(Dz));

figure('name','istogrammma distanza relativa x')
hist(Dx,30);
fig = gcf;
saveas(fig, 'istogramma_distanza_relativa_x', 'png')
movefile(strcat('istogramma_distanza_relativa_x','.png'), './IMMAGINI')

figure('name','istogrammma distanza relativa y')
hist(Dy,30);
fig = gcf;
saveas(fig, 'istogramma_distanza_relativa_y', 'png')
movefile(strcat('istogramma_distanza_relativa_y','.png'), './IMMAGINI')

figure('name','istogrammma distanza relativa z')
hist(Dz,30);
fig = gcf;
saveas(fig, 'istogramma_distanza_relativa_z', 'png')
movefile(strcat('istogramma_distanza_relativa_z','.png'), './IMMAGINI')



%*********************** TRAIETTORIA SEGUITA *******************************

L = length(x1);
% open figure
figure('name','traiettoria seguita')
f = gcf;  %get current figure
for i = 1:L
    point_i = [x1(i) x2(i)];
    point_ii = [y1(i) y2(i)];
    pl_1 = plot(x1(i),y1(i),'b.');
    hold on
    pl_2 = plot(x2(i),y2(i),'r.');
    hold on
    line(point_i,point_ii,'Color','black','LineStyle','--');
    hold on
end
title('Traiettoria seguita')
legend('tag 1','tag 2');
grid on
% salvataggio immagine
saveas(f, 'Traiettoria_seguita', 'png')
movefile(strcat('Traiettoria_seguita','.png'), './IMMAGINI')