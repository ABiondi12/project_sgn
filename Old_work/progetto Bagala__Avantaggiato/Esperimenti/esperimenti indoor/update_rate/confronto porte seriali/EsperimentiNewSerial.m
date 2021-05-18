%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo          %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% e' uno script ausiliario per l'analisi di dati relativi all'utilizzo
% della libreria SerialPort.h con l'utilizzo di un tag e due tag.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd 'provanewSerial1'
%% 1tag

fileID = fopen('newserial2tag.txt');
C = textscan(fileID,' %f32  %f32 %f32 %f32 %f32  %f32 %f32  %f32 %f32  %f32');
whos C;
aux = zeros(4000,1); aux = (C{9}(1:4000));

fclose(fileID);
timeloop = zeros(length(aux) - 2,1);

for i = length(timeloop):-1:3
    timeloop(length(timeloop) - i +1) = aux(i)-aux(i-1);
end
timeloop = timeloop(1:length(timeloop)-2);
floop= 10^6./(timeloop);
floop_m = mean(floop);
dev_loop = std(floop);

%% 2tag

fileID = fopen('newserial.txt');
C = textscan(fileID,' %f32  %f32 %f32  %f32 %f32  %f32 %f32  %f32 %f32  %f32 %f32  %f32 %f32  %f32 %f32');
whos C;
aux = zeros(4000,1); aux = (C{9}(1:4000));

fclose(fileID);
timeloop2tag = zeros(length(aux) - 2,1);

for i = length(timeloop2tag):-1:3
    timeloop2tag(length(timeloop2tag) - i +1) = aux(i)-aux(i-1);
end
timeloop2tag = timeloop2tag(1:length(timeloop2tag)-2);
floop2tag = 10^6./(timeloop2tag);
floop2tag_m = mean(floop2tag);
dev_loop2tag = std(floop2tag);
