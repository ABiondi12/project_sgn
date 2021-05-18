%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo          %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Questo sript analizza i dati temporali relativi al vario utilizzo delle
% funzioni di interesse.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd 'prova1'
%% tag2
%%%%%%%
fileID = fopen('tag2\doPositioning.txt');
C = textscan(fileID,' %f32 %f32 %f32 %f32 %f32 %f32 %f32');
whos C;
aux = zeros(length(C{7}),1); aux = (C{7});
fclose(fileID);
timedoPos = zeros(length(aux) - 2,1);

for i = length(timedoPos):-1:3
    timedoPos(length(timedoPos) - i +1) = aux(i)-aux(i-1);
end
timedoPos = timedoPos(1:length(timedoPos)-2);
fdoPos = 10^6./(timedoPos);
fdoPos_m = mean(fdoPos);
dev_doPos = std(fdoPos);


%%
fileID = fopen('tag2\doPositioningconGet.txt');
C = textscan(fileID,' %f32  %f32  %f32 %f32 %f32 %f32  %f32 %f32  %f32  %f32 %f32  %f32 %f32 %f32  %f32');
whos C;
aux = zeros(length(C{15}),1); aux = (C{15});
fclose(fileID);

timedoPosGet = zeros(length(aux)-2,1);

for i = length(timedoPosGet):-1:3
    timedoPosGet(length(timedoPosGet) - i +1) = aux(i)-aux(i-1);
end
timedoPosGet = timedoPosGet(1:length(timedoPosGet)-2);
fdoPosGet = 10^6./(timedoPosGet);
fdoPosGet_m = mean(fdoPosGet);
dev_doPosGet = std(fdoPosGet);

%%
fileID = fopen('tag2\Get.txt');
C = textscan(fileID,' %f32  %f32  %f32 %f32 %f32 %f32  %f32 %f32  %f32  %f32 %f32  %f32 %f32 %f32  %f32');
whos C;
aux = zeros(length(C{9}),1); aux = (C{9});
fclose(fileID);

timeGet = zeros(length(aux)-2,1);

for i = length(timeGet):-1:3
    timeGet(length(timeGet) - i +1) = aux(i)-aux(i-1);
end
timeGet = timeGet(1:length(timeGet)-2);
fGet = 10^6./(timeGet);
fGet_m = mean(fGet);
dev_Get = std(fGet);

%%

fileID = fopen('tag2\doRanging.txt');
C = textscan(fileID,' %f32 %f32  %f32  %f32 %f32  %f32 %f32 %f32  %f32');
whos C;
aux = zeros(length(C{9}),1); aux = (C{9});
fclose(fileID);

timedoRang = zeros(length(aux) -2,1);

for i = length(timedoRang):-1:3
    timedoRang(length(timedoRang) - i +1) = aux(i)-aux(i-1);
end
timedoRang = timedoRang(1:length(timedoRang)-2);
fdoRang = 10^6./(timedoRang);
fdoRang_m = mean(fdoRang);
dev_doRang = std(fdoRang);

%% tag1
%%%%%%%
%%
fileID = fopen('tag1\doPositioning.txt');
C = textscan(fileID,' %f32  %f32  %f32 %f32');
whos C;
aux = zeros(length(C{4}),1); aux = (C{4});
fclose(fileID);
timedoPos1 = zeros(length(aux) - 2,1);

for i = length(timedoPos1):-1:3
    timedoPos1(length(timedoPos1) - i +1) = aux(i)-aux(i-1);
end
timedoPos1 = timedoPos1(1:length(timedoPos1)-2);
fdoPos1 = 10^6./(timedoPos1);
fdoPos1_m = mean(fdoPos1);
dev_doPos1 = std(fdoPos1);
%%
fileID = fopen('tag1\doPositioningconGet.txt');
C = textscan(fileID,' %f32  %f32  %f32 %f32 %f32 %f32  %f32 %f32');
whos C;
aux = zeros(length(C{8}),1); aux = (C{8});
fclose(fileID);

timedoPosGet1 = zeros(length(aux)-2,1);

for i = length(timedoPosGet1):-1:3
    timedoPosGet1(length(timedoPosGet1) - i +1) = aux(i)-aux(i-1);
end
timedoPosGet1 = timedoPosGet1(1:length(timedoPosGet1)-2);
fdoPosGet1 = 10^6./(timedoPosGet1);
fdoPosGet1_m = mean(fdoPosGet1);
dev_doPosGet1 = std(fdoPosGet1);

%%
fileID = fopen('tag1\Get.txt');
C = textscan(fileID,' %f32  %f32  %f32 %f32 %f32');
whos C;
aux = zeros(length(C{5}),1); aux = (C{5});
fclose(fileID);

timeGet1 = zeros(length(aux)-2,1);

for i = length(timeGet1):-1:3
    timeGet1(length(timeGet1) - i +1) = aux(i)-aux(i-1);
end
timeGet1 = timeGet1(1:length(timeGet1)-2);
fGet1 = 10^6./(timeGet1);
fGet1_m = mean(fGet1);
dev_Get1 = std(fGet1);

%%
fileID = fopen('tag1\doRanging.txt');
C = textscan(fileID,' %f32 %f32  %f32  %f32 %f32');
whos C;
aux = zeros(length(C{5}),1); aux = (C{5});
fclose(fileID);

timedoRang1 = zeros(length(aux) -2,1);

for i = length(timedoRang1):-1:3
    timedoRang1(length(timedoRang1) - i +1) = aux(i)-aux(i-1);
end
timedoRang1 = timedoRang1(1:length(timedoRang1)-2);
fdoRang1 = 10^6./(timedoRang1);
fdoRang1_m = mean(fdoRang1);
dev_doRang1 = std(fdoRang1);

%%
% nome1 = ["fdoPos1"; "fdoPosGet1"; "fGet1"; "fdoPosCal1"; "fCal1"; "fdoRang1"]; 
f1tag = [fdoPos1_m; fdoPosGet1_m; fGet1_m;  fdoRang1_m];
dev1tag = [dev_doPos1; dev_doPosGet1; dev_Get1; dev_doRang1];
% un_tag = [nome1'; f1tag'; dev1tag']
% %un_tag = [f1tag'; dev1tag']

% nome2 = ["fdoPos2"; "fdoPosGet2"; "fGet2"; "fdoPosCal2"; "fCal2"; "fdoRang2"]; 
f2tag = [fdoPos_m; fdoPosGet_m; fGet_m;  fdoRang_m];
dev2tag = [dev_doPos; dev_doPosGet; dev_Get; dev_doRang];
% due_tag = [nome2'; f2tag'; dev2tag']
% %due_tag = [f2tag'; dev2tag']
