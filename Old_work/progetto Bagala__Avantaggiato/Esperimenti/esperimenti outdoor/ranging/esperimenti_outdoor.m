%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo          %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Questo script carica tutti i vari file .txt presenti nella 
% cartella 'cd' relativi all'esperimento "misura del massimo 
% ranging di comunicazione ". 
% I file contengono rispettivamente [stato(tag1),ranging(tag1),
% stato(tag2), ranging(tag2), durata temporale].
% Le misure dei ranging, riportate nei file, sono in [mm].

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
global metri;
metri = 1; % porre la variabile metri a 0 se si volessero stampare 
           % i vari plot in [mm]
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% cartella in cui sono presenti i file. Specificare gain e bitrate
Current = cd;
cartella = 'dati\gain11.5\6810';
cd (cartella)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('5m.txt');
C = textscan(fileID,'%f32 %f32 %f32 %f32 %f32');
cd (Current);
[f_m5, dev5, mas5, mini5, d51_m, d51_d, d52_m, d52_d,tag1_5_fal,...
    tag2_5_fal, x1, x2] = calcolo_dati(C);
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd (cartella)
fileID = fopen('10m.txt');
C = textscan(fileID,' %f32 %f32 %f32 %f32 %f32 ');
cd (Current);
[f_m10, dev10, mas10, mini10, d101_m, d101_d, d102_m, d102_d,tag1_10_fal,...
    tag2_10_fal, y1, y2] = calcolo_dati(C);
x1 = [x1; y1];
x2 = [x2; y2];
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd (cartella)
fileID = fopen('15m.txt');
C= textscan(fileID,' %f32 %f32 %f32 %f32 %f32 ');
cd (Current);
[f_m15, dev15, mas15, mini15, d151_m, d151_d, d152_m, d152_d,tag1_15_fal,...
    tag2_15_fal, y1, y2] = calcolo_dati(C);
x1 = [x1; y1];
x2 = [x2; y2];
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd (cartella)
fileID = fopen('20m.txt');
C= textscan(fileID,' %f32 %f32 %f32 %f32 %f32 ');
cd (Current);
[f_m20, dev20, mas20, mini20, d201_m, d201_d, d202_m, d202_d,tag1_20_fal,...
    tag2_20_fal, y1, y2] = calcolo_dati(C);
x1 = [x1; y1];
x2 = [x2; y2];
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd (cartella)
fileID = fopen('25m.txt');
C = textscan(fileID,' %f32 %f32 %f32 %f32 %f32 ');
cd (Current);
[f_m25, dev25, mas25, mini25, d251_m, d251_d, d252_m, d252_d,tag1_25_fal,...
    tag2_25_fal, y1, y2] = calcolo_dati(C);
x1 = [x1; y1];
x2 = [x2; y2];
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd (cartella)
fileID = fopen('30m.txt');
C = textscan(fileID,' %f32 %f32 %f32 %f32 %f32 ');
cd (Current);
[f_m30, dev30, mas30, mini30, d301_m, d301_d, d302_m, d302_d,tag1_30_fal,...
    tag2_30_fal, y1, y2] = calcolo_dati(C);
x1 = [x1; y1];
x2 = [x2; y2];
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd (cartella)
fileID = fopen('35m.txt');
C = textscan(fileID,' %f32 %f32 %f32 %f32 %f32 ');
cd (Current);
[f_m35, dev35, mas35, mini35, d351_m, d351_d, d352_m, d352_d,tag1_35_fal,...
    tag2_35_fal, y1, y2] = calcolo_dati(C);
x1 = [x1; y1];
x2 = [x2; y2];
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd (cartella)
fileID = fopen('40m.txt');
C = textscan(fileID,' %f32 %f32 %f32 %f32 %f32 ');
cd (Current);
[f_m40, dev40, mas40, mini40, d401_m, d401_d, d402_m, d402_d,tag1_40_fal,...
    tag2_40_fal, y1, y2] = calcolo_dati(C);
x1 = [x1; y1];
x2 = [x2; y2];
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd (cartella)
fileID = fopen('45m.txt');
C = textscan(fileID,' %f32 %f32 %f32 %f32 %f32 ');
cd (Current);
[f_m45, dev45, mas45, mini45, d451_m, d451_d, d452_m, d452_d,tag1_45_fal,...
    tag2_45_fal, y1, y2] = calcolo_dati(C);
x1 = [x1; y1];
x2 = [x2; y2];
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd (cartella)
fileID = fopen('50m.txt');
C = textscan(fileID,' %f32 %f32 %f32 %f32 %f32 ');
cd (Current);
[f_m50, dev50, mas50, mini50, d501_m, d501_d, d502_m, d502_d,tag1_50_fal,...
    tag2_50_fal, y1, y2] = calcolo_dati(C);
x1 = [x1; y1];
x2 = [x2; y2];
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd (cartella)
fileID = fopen('55m.txt');
C = textscan(fileID,' %f32 %f32 %f32 %f32 %f32 ');
cd (Current);
[f_m55, dev55, mas55, mini55, d551_m, d551_d, d552_m, d552_d,tag1_55_fal,...
    tag2_55_fal, y1, y2] = calcolo_dati(C);
x1 = [x1; y1];
x2 = [x2; y2];
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd (cartella)
fileID = fopen('60m.txt');
C= textscan(fileID,' %f32 %f32 %f32 %f32 %f32 ');
cd (Current);
[f_m60, dev60, mas60, mini60, d601_m, d601_d, d602_m, d602_d,tag1_60_fal,...
    tag2_60_fal, y1, y2] = calcolo_dati(C);
x1 = [x1; y1];
x2 = [x2; y2];
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

name ={'5m';'10m'; '15m';'20m';'25m';'30m';'35m';'40m';'45m';'50m';'55m';'60m'}
frequenza_media =[f_m5;f_m10;f_m15;f_m20;f_m25; f_m30; f_m35; f_m40; f_m45; f_m50; f_m55; f_m60]; 
deviazione_frequenza =[dev5; dev10; dev15; dev20; dev25; dev30; dev35; dev40; dev45; dev50; dev55; dev60];
fallimenti = [tag1_5_fal tag2_5_fal;tag1_10_fal tag2_10_fal;
                tag1_15_fal tag2_15_fal;tag1_20_fal tag2_20_fal;
                tag1_25_fal tag2_25_fal;tag1_30_fal tag2_30_fal;
                tag1_35_fal tag2_35_fal;tag1_40_fal tag2_40_fal;
                tag1_45_fal tag2_45_fal;tag1_50_fal tag2_50_fal;
                tag1_55_fal tag2_55_fal;tag1_60_fal tag2_60_fal;];
posizioni = [d51_m d52_m; d101_m d102_m; d151_m d152_m; d201_m d202_m; d251_m d252_m;
               d301_m d302_m ; d351_m d352_m; d401_m d402_m; d451_m d452_m; d501_m d502_m;
               d551_m d552_m; d601_m d602_m];
deviazioni = [d51_d d52_d; d101_d d102_d; d151_d d152_d; d201_d d202_d; d251_d d252_d;
               d301_d d302_d ; d351_d d352_d; d401_d d402_d; d451_d d452_d; d501_d d502_d;
               d551_d d552_d; d601_d d602_d];

%%creazione tabella
t=table(name, posizioni, deviazioni,fallimenti, frequenza_media, deviazione_frequenza);
lunghezza = length(posizioni);
myPlot2d([double(posizioni(:,1)) zeros(lunghezza,1)] ,[double(posizioni(:,2)) zeros(lunghezza,1)],...
        [double(deviazioni(:,1)) zeros(lunghezza,1)],[double(deviazioni(:,2)) zeros(lunghezza,1)])
figure, 
plot(x1/1000,'r');
hold on,
plot(x2/1000,'b --');
title('Variazione temporale del ranging relativo ai due tag')
ylabel('Distanza Ancora 0 [m]')
legend('Ranging tag 1', 'Ranging tag 2')
grid MINOR,