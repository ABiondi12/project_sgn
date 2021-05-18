%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo          %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd 'provaRanging1'
%%
fileID = fopen('confrontoranging_wire400.txt');
C = textscan(fileID,' %f32  %f32');
whos C;
aux = zeros(length(C{1}),1); aux = (C{1});
timedoRang4 = zeros(length(C{2}),1); timedoRang4 = (C{2});

fclose(fileID);
timeloop4 = zeros(length(aux) - 2,1);

for i = length(timeloop4):-1:3
    timeloop4(length(timeloop4) - i +1) = aux(i)-aux(i-1);
end
timeloop4 = timeloop4(1:length(timeloop4)-2);
floop4 = 10^6./(timeloop4);
maxloop4 = max(floop4);
minloop4 = min(floop4);
floop4_m = mean(floop4);
dev_loop4 = std(floop4);

timedoRang4 = timedoRang4(1:length(timedoRang4)-2);
fdoRang4 = 10^6./(timedoRang4);
maxdoRang4 = max(fdoRang4);
mindoRang4 = min(fdoRang4);
fdoRang4_m = mean(fdoRang4);
dev_doRang4 = std(fdoRang4);


%%

fileID = fopen('confrontoranging_wire100.txt');
C = textscan(fileID,' %f32  %f32');
whos C;
aux = zeros(length(C{1}),1); aux = (C{1});
timedoRang1 = zeros(length(C{2}),1); timedoRang1 = (C{2});

fclose(fileID);
timeloop1 = zeros(length(aux) - 2,1);

for i = length(timeloop1):-1:3
    timeloop1(length(timeloop1) - i +1) = aux(i)-aux(i-1);
end
timeloop1 = timeloop1(1:length(timeloop1)-2);
floop1 = 10^6./(timeloop1);
maxloop1 = max(floop1);
minloop1 = min(floop1);
floop1_m = mean(floop1);
dev_loop1 = std(floop1);

timedoRang1 = timedoRang1(1:length(timedoRang1)-2);
fdoRang1 = 10^6./(timedoRang1);
maxdoRang1 = max(fdoRang1);
mindoRang1 = min(fdoRang1);
fdoRang1_m = mean(fdoRang1);
dev_doRang1 = std(fdoRang1);

%%

% nome = ["fdoRang1"; "floop1"; "fdoRangs4"; "floop4"]; 
f = [fdoRang1_m; floop1_m; fdoRang4_m; floop4_m];
dev = [dev_doRang1; dev_loop1; dev_doRang4; dev_loop4];
% f_ris = [nome'; f'; dev']