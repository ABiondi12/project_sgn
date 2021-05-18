%%% AUTOCALIBRAZIONE 2D
%
% LAUREA MAGISTRALE ING.ROBOTICA E DELL'AUTOMAZIONE
% CORSO: SISTEMI DI GUIDA E NAVIGAZIONE
% AUTORI: CRISTIAN TESCONI/LUCA CROSATO

%**************************************************************************
% Questo script importa il file.txt relativo alla calibrazione 2D
% Calcola inoltre gli indici statistici ed esegue il plot 3D dei risultati
%**************************************************************************

%% CLEAR 
clear all;
close all;
clc;

%% CARICAMENTO E SALVATAGGIO DATI

filename = './dati/auto_calibrazione_2D_geometria_1.txt';
file = fopen(filename);
A = textscan(file,'%s %s %s %s %s %s %s');
fclose(file);

for i=3:2:7
    for j=1:400
        A{i}{j}=erase(A{i}{j},',');  
    end 
end

h=1;
k=1;
C = zeros(400,2);
whos C

for i=3:2:5
    for j=1:400
        C(h,k)=str2num(A{i}{j});
        h=h+1;
    end
    k=k+1;
    h=1;
end

% Antenna 2
for i=2:4:400
    antenna2(i,1)=C(i,1);
    antenna2(i,2)=C(i,2);
end

% Antenna 3
for i=3:4:400
    antenna3(i,1)=C(i,1);
    antenna3(i,2)=C(i,2);
end

% Antenna 4
for i=4:4:400
    antenna4(i,1)=C(i,1);
    antenna4(i,2)=C(i,2);
end

figure('name','antenna2')
plot(antenna2(:,1),antenna2(:,2),'.')

figure('name','antenna3')
plot(antenna3(:,1),antenna3(:,2),'.')

figure('name','antenna4')
plot(antenna4(:,1),antenna4(:,2),'.')

%Raggruppamento misurazioni

h1=1; h2=1; h3=1;
gruppo1 = zeros(400,2);
gruppo2 = zeros(400,2);
gruppo3 = zeros(400,2);

for i=1:4:400
   if (C(i+1,1)<4500)
       gruppo1(h1:(h1+3),1:2) = C(i:i+3,:);
       h1 = h1+4;
   elseif ((C(i+1,1)<6000)&&(C(i+1,1)>5000))
       gruppo2(h2:h2+3,1:2) = C(i:i+3,:);
       h2 = h2+4;
   else
       gruppo3(h3:h3+3,1:2) = C(i:i+3,:);
       h3 = h3+4;
   end
end


figure('name','gruppi')
plot(gruppo1(:,1),gruppo1(:,2),'b.')
hold on
plot(gruppo2(:,1),gruppo2(:,2),'g.')
hold on
plot(gruppo3(:,1),gruppo3(:,2),'r.')
hold on


%% Indici statistici
% Ripulitura dei dati
i = 0;
while (gruppo2(400-i,1) == 0)
    gruppo2(400-i,:)=[];
    i=i+1;
end

% antenna 2
indici = zeros(3,4); %prima colonna = valor medio, seconda colonna = varianza
val_medio_X = 0;
val_medio_Y = 0;
N = length(gruppo2)/4;
for i = 2:4:length(gruppo2)
    val_medio_X = val_medio_X + gruppo2(i,1)/N;
    val_medio_Y = val_medio_Y + gruppo2(i,2)/N;
end
indici(1,1)=val_medio_X;
indici(1,3)= val_medio_Y;
varX = 0;
varY = 0;
for i = 2:4:length(gruppo2)
    varX =varX + (gruppo2(i,1)-val_medio_X)^2/(N-1);
    varY =varY + (gruppo2(i,2)-val_medio_Y)^2/(N-1);
end
indici(1,2) = sqrt(varX);
indici(1,4) = sqrt(varY);

% antenna 3
val_medio_X = 0;
val_medio_Y = 0;
for i = 3:4:length(gruppo2)
    val_medio_X = val_medio_X + gruppo2(i,1)/N;
    val_medio_Y = val_medio_Y + gruppo2(i,2)/N;
end
indici(2,1)=val_medio_X;
indici(2,3)= val_medio_Y;
varX = 0;
varY = 0;
for i = 3:4:length(gruppo2)
    varX =varX + (gruppo2(i,1)-val_medio_X)^2/(N-1);
    varY =varY + (gruppo2(i,2)-val_medio_Y)^2/(N-1);
end
indici(2,2) = sqrt(varX);
indici(2,4) = sqrt(varY);

% antenna 4
val_medio_X = 0;
val_medio_Y = 0;
for i = 4:4:length(gruppo2)
    val_medio_X = val_medio_X + gruppo2(i,1)/N;
    val_medio_Y = val_medio_Y + gruppo2(i,2)/N;
end
indici(3,1)= val_medio_X;
indici(3,3)= val_medio_Y;
varX = 0;
varY = 0;
for i = 4:4:length(gruppo2)
    varX =varX + (gruppo2(i,1)-val_medio_X)^2/(N-1);
    varY =varY + (gruppo2(i,2)-val_medio_Y)^2/(N-1);
end
indici(3,2) = sqrt(varX);
indici(3,4) = sqrt(varY);

% formato indici:
% x dx y dy
% dx = incertezza su x
indici



