%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo                        %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Questo script analizza e stampa graficamente i risultati provenienti
% dalle misure nei file .txt: outdoor2.txt, outdoor3.txt. A seconda di
% quale file si vuole analizzare, bisogna inizializzare la variabile
% 'nome'. 

nome = 'outdoor3.txt';
global metri
metri = 1;          %come un booleano se 1 voglio le misure in metri, 
                    %altrimenti in mm
                    %NOTA: la funzione myPlot2D viene lanciata solo per 
                    % metri = 1
Current = cd;
cd 'Dati';
fileID = fopen(nome);
C = textscan(fileID,'%f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32');
fclose(fileID);
cd (Current);
t = C{16};
e = C{15};
r1 = eliminaoverflow(1,C);
r2 = eliminaoverflow(2,C);
C = [r1 r2 e t];
if(strcmp(nome(8),'2'))
    set1 = [1 2000; 2500 3500; 4000 6000; 6500 8500; 9000 11000; 11500 12500; ...
        13000 14000; 14500 16500; 17500 19000; 20000 22000; 22500 23500; 24500 length(C)];
else
     set1 = [1 2000; 2500 4500; 5000 7000; 7500 8500; 9000 11000; 11500 13500;...
         15500 17500; 18000 19000; 19500 20500; 21500 23500; 25000 27000; 27500 length(C)];
end
n = length(set1);
medie = zeros(n,14);
deviazioni = zeros(n,14);
fallimenti = zeros(n,2);
f_m = zeros(n,1);
dev = zeros(n,1);
for i = 1:n
    [medie(i,1:7),deviazioni(i,1:7), fallimenti(i,1)] = ...
        analizza(1,C(set1(i,1):set1(i,2),1),C(set1(i,1):set1(i,2),2),...
        C(set1(i,1):set1(i,2),3),C(set1(i,1):set1(i,2),4),...
        C(set1(i,1):set1(i,2),5),C(set1(i,1):set1(i,2),6),...
        C(set1(i,1):set1(i,2),7),e(set1(i,1):set1(i,2)));
    [medie(i,8:14),deviazioni(i,8:14), fallimenti(i,2)] = ...
        analizza(2,C(set1(i,1):set1(i,2),8),C(set1(i,1):set1(i,2),9),...
        C(set1(i,1):set1(i,2),10),C(set1(i,1):set1(i,2),11),...
        C(set1(i,1):set1(i,2),12),C(set1(i,1):set1(i,2),13),...
        C(set1(i,1):set1(i,2),14),e(set1(i,1):set1(i,2)));
    [f_m(i),dev(i)] = ...
        calcolafreqUWB(t(set1(i,1):set1(i,2)));
    %plotHist(C(set1(i,1):set1(i,2),4),C(set1(i,1):set1(i,2),11),n,i);
end

if(metri)
    myPlot2d(medie(:,1:2), medie(:,8:9), deviazioni(:,1:2), deviazioni(:,8:9));
end
plotDist(C(:,4:7), C(:,11:14),C(:,15));
name = {'tag_1'; 'dev1'; 'dist1'; 'devdist1';...
        'tag_2'; 'dev2'; 'dist2'; 'devdist2';...
        'fallimenti'; 'frequenza'; 'devfreq'};
    
%tabella che riassume i dati statistici.
t = table(medie(:,1:3), deviazioni(:,1:3), medie(:,4:7), deviazioni(:,4:7),...
          medie(:,8:10), deviazioni(:,8:10), medie(:,11:14), deviazioni(:,11:14),...
          fallimenti, f_m, dev);
d = [sqrt(medie(:,1).^2 + medie(:,2).^2) medie(:,4) sqrt(medie(:,8).^2 + medie(:,9).^2) medie(:,11)];
for i = 1:11
    t.Properties.VariableNames{i} = name{i,1};
end