%%% CALIBRAZIONE MEDIANTE APP

% LAUREA MAGISTRALE ING.ROBOTICA E DELL'AUTOMAZIONE
% CORSO: SISTEMI DI GUIDA E NAVIGAZIONE
% AUTORI: CRISTIAN TESCONI/LUCA CROSATO

%**************************************************************************
% Questo script carica i dati relativi a calibrazioni manuali effettuate
% mediante app; si precisa che il file .txt contiene solamente le
% coordinate strettamente necessarie per effettuare una calibrazione
% mediante app; dunque NON sono contenute le coordinate dell'ancora
% collocata nell'origine, la coordinata x e z dell'ancora che individua
% l'asse y, e le coordinate z dell'ancora 2 e 3. In particolare l'ancora
% 0,1,2 si trovano sullo stesso piano (dunque z=0), mentre la coordinata z
% dell'ancora 3 viene fissata.
% In particolare viene effettuato un plot dei dati acquisiti.
%
%**************************************************************************
%% CLEAR 
clear all
close all
clc

%% SALVATAGGIO 
global save
save = 'y';

%% CARICAMENTO DATI
filename = 'acquisizioni_app_3D.txt';
file = fopen(filename);
A = textscan(file,'%s %s %s %s %s %s');
fclose(file);

C = zeros(30,5);
h=1; % indice di riga
k=1; % indice di colonna
for i=1:5 %seleziono la cella
    h = 1;
    for j=2:31 %scorro gli elementi della cella
        C(h,k)=str2num(A{i}{j}); % converto da string a numerico
        h = h+1;
    end
    k=k+1;
end
L = length(C);

%% COORDINATE ANCORA 0  (ID : 0x6e44)
anc_0_x = 0;
anc_0_y = 0;
anc_0_z = 0;

%% COORDINATE ANCORA 1  (ID : 0x6e7a)
anc_1_x = 0;
anc_1_y = C(:,5);
anc_1_z = 0;

[val_medio_1y,sigma_1y] = indici(anc_1_y);


%% COORDINATE ANCORA 2  (ID : 0x6934)
anc_2_x = C(:,1);
anc_2_y = C(:,2);
anc_2_z = 0;
[val_medio_2x,sigma_2x] = indici(anc_2_x);
[val_medio_2y,sigma_2y] = indici(anc_2_y);

%% COORDINATE ANCORA 3  (ID : 0x6e1d)
anc_3_x = C(:,3);
anc_3_y = C(:,4);
anc_3_z = 910;
[val_medio_3x,sigma_3x] = indici(anc_3_x);
[val_medio_3y,sigma_3y] = indici(anc_3_y);

figure('name','Calibrazione madiante app')
for i = 1:L
    plot3(anc_0_x, anc_0_y, anc_0_z,'b*')
    hold on
    plot3(anc_1_x, anc_1_y(i), anc_1_z,'r*')
    hold on
    plot3(anc_2_x(i), anc_2_y(i), anc_2_z,'k*')
    hold on
    plot3(anc_3_x(i), anc_3_y(i), anc_3_z,'g*')
    title('Calibrazione mediante app')
    legend('Posizione ancora 0','Posizione ancora 1',...
           'Posizione ancora 2','Posizione ancora 3')
    hold on
    grid on
end
% Salvataggio immagine
save_as('Calibrazione_mediante_app','IMMAGINI')



