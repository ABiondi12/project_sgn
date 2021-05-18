%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo          %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd 'provaPositioning1'
%%

fileID = fopen('confrontotime_wire400.txt');
C = textscan(fileID,' %f32  %f32');
whos C;
aux = zeros(length(C{1}),1); aux = (C{1});
timedoPos4 = zeros(length(C{2}),1); timedoPos4 = (C{2});

fclose(fileID);
timeloop4 = zeros(length(aux) - 2,1);

for i = length(timeloop4):-1:3
    timeloop4(length(timeloop4) - i +1) = aux(i)-aux(i-1);
end
timeloop4 = timeloop4(1:length(timeloop4)-2);
floop4 = 10^6./(timeloop4);
floop4_m = mean(floop4);
dev_loop4 = std(floop4);

timedoPos4 = timedoPos4(1:length(timedoPos4)-2);
fdoPos4 = 10^6./(timedoPos4);
fdoPos4_m = mean(fdoPos4);
dev_doPos4 = std(fdoPos4);


%%

fileID = fopen('confrontotime_wire100.txt');
C = textscan(fileID,' %f32  %f32');
whos C;
aux = zeros(length(C{1}),1); aux = (C{1});
timedoPos1 = zeros(length(C{2}),1); timedoPos1 = (C{2});

fclose(fileID);
timeloop1 = zeros(length(aux) - 2,1);

for i = length(timeloop1):-1:3
    timeloop1(length(timeloop1) - i +1) = aux(i)-aux(i-1);
end
timeloop1 = timeloop1(1:length(timeloop1)-2);
floop1 = 10^6./(timeloop1);
floop1_m = mean(floop1);
dev_loop1 = std(floop1);

timedoPos1 = timedoPos1(1:length(timedoPos1)-2);
fdoPos1 = 10^6./(timedoPos1);
fdoPos1_m = mean(fdoPos1);
dev_doPos1 = std(fdoPos1);

%%

% nome = ["fdoPos1"; "floop1"; "fdoPos4"; "floop4"]; 
f = [fdoPos1_m; floop1_m; fdoPos4_m; floop4_m];
dev = [dev_doPos1; dev_loop1; dev_doPos4; dev_loop4];
% f_ris = [nome'; f'; dev']