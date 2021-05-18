%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo          %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% PRECISIONE E ACCURATEZZA%%
% Questo script analizza i dati presenti nella stessa cartella nei file:
% Esperimento_accuratezza_precisione1.txt
% Esperimento_accuratezza_precisione2.txt
% Esperimento_accuratezza_precisione3.txt
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Dati reali :

% I TAG
dist11_reale=233 ; dist21_reale=2704 ; dist31_reale= 2421; dist41_reale=1712 ;
distanze11_reale = [dist11_reale, dist21_reale, dist31_reale, dist41_reale];

% II TAG
dist12_reale=240; dist22_reale=2698 ; dist32_reale=2413 ; dist42_reale=1719 ; 
distanze12_reale = [dist12_reale, dist22_reale, dist32_reale, dist42_reale];

%%%%%%%%'%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ESPERIMENTO 1 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\Esperimento_accuratezza_precisione1.txt');

C = textscan(fileID,' %f32  %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32');
whos C;

posx1= (C{1}); posy1= (C{2}); posz1= (C{3});
posx2= (C{8}); posy2= (C{9}); posz2= (C{10});

dist11= (C{4}); dist21= (C{5}); dist31= (C{6}); dist41= (C{7}); 
dist12= (C{11}); dist22= (C{12}); dist32= (C{13}); dist42= (C{14}); 

%distanze primo tag primo esperimento
distanze1_1 =[dist11, dist21, dist31, dist41];

%distanze secondo tag primo esperimento
distanze2_1 =[dist12, dist22, dist32, dist42];

%
diffposx = posx1 - posx2;       diffposx_m = mean(diffposx);
diffposy = posy1 - posy2;       diffposy_m = mean(diffposy);
diffposz = posz1 - posz2;       diffposz_m = mean(diffposz);
diffdist1= dist11 - dist12;     diffdist1_m = mean(diffdist1);
diffdist2= dist21 - dist22;     diffdist2_m = mean(diffdist2);
diffdist3= dist31 - dist32;     diffdist3_m = mean(diffdist3);
diffdist4= dist41 - dist42;     diffdist4_m = mean(diffdist4);
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% ESPERIMENTO 2 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

fileID = fopen('\Esperimento_accuratezza_precisione2.txt');
C = textscan(fileID,' %f32  %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32');
whos C;
posx1_2= (C{1}); posy1_2= (C{2}); posz1_2= (C{3});
posx2_2= (C{8}); posy2_2= (C{9}); posz2_2= (C{10});

dist11_2= (C{4}); dist21_2= (C{5}); dist31_2= (C{6}); dist41_2= (C{7}); 
dist12_2= (C{11}); dist22_2= (C{12}); dist32_2= (C{13}); dist42_2= (C{14}); 

%distanze primo tag secondo esperimento
distanze1_2 =[dist11_2, dist21_2, dist31_2, dist41_2];

%distanze secondo tag secondo esperimento
distanze2_2 =[dist12_2, dist22_2, dist32_2, dist42_2];

diffposx_2 = posx1_2 - posx2_2;       diffposx_m2 = mean(diffposx_2);
diffposy_2 = posy1_2 - posy2_2;       diffposy_m2 = mean(diffposy_2);
diffposz_2 = posz1_2 - posz2_2;       diffposz_m2 = mean(diffposz_2);
diffdist1_2= dist11_2 - dist12_2;     diffdist1_m2 = mean(diffdist1_2);
diffdist2_2= dist21_2 - dist22_2;     diffdist2_m2= mean(diffdist2_2);
diffdist3_2= dist31_2 - dist32_2;     diffdist3_m2 = mean(diffdist3_2);
diffdist4_2= dist41_2 - dist42_2;     diffdist4_m2 = mean(diffdist4_2);
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ESPERIMENTO 3 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

fileID = fopen('Esperimento_accuratezza_precisione3.txt');
C = textscan(fileID,'%f32 %f32  %f32 %f32  %f32  %f32  %f32 %f32  %f32   %f32  %f32  %f32  %f32  %f32');
whos C;
posx1_3= (C{1}); posy1_3= (C{2}); posz1_3= (C{3});
posx2_3= (C{8}); posy2_3= (C{9}); posz2_3= (C{10});

dist11_3= (C{4}); dist21_3= (C{5}); dist31_3= (C{6}); dist41_3= (C{7}); 
dist12_3= (C{11}); dist22_3= (C{12}); dist32_3= (C{13}); dist42_3= (C{14}); 

%distanze primo tag terzo esperimento
distanze1_3 =[dist11_3, dist21_3, dist31_3, dist41_3];

%distanze secondo tag terzo esperimento
distanze2_3 =[dist12_3, dist22_3, dist32_3, dist42_3];

diffposx_3 = posx1_3 - posx2_3;       diffposx_m3 = mean(diffposx_3);
diffposy_3 = posy1_3 - posy2_3;       diffposy_m3 = mean(diffposy_3);
diffposz_3 = posz1_3 - posz2_3;       diffposz_m3 = mean(diffposz_3);
diffdist1_3= dist11_3 - dist12_3;     diffdist1_m3 = mean(diffdist1_3);
diffdist2_3= dist21_3 - dist22_3;     diffdist2_m3 = mean(diffdist2_3);
diffdist3_3= dist31_3 - dist32_3;     diffdist3_m3 = mean(diffdist3_3);
diffdist4_3= dist41_3 - dist42_3;     diffdist4_m3 = mean(diffdist4_3);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% ANALISI ESPERIMENTI %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%% differenza tra le due posizioni dei due tag 
vett_differenza_posizioni = [diffposx_m, diffposx_m2, diffposx_m3; diffposy_m  diffposy_m2, diffposz_m3];

%% differenza tra le quattro distanze dei due tag 
differenza_distanze = [diffdist1_m, diffdist2_m, diffdist3_m, diffdist4_m; diffdist1_m2, diffdist2_m2, diffdist3_m2, diffdist4_m2;diffdist1_m3, diffdist2_m3, diffdist3_m3, diffdist4_m3];

%% CONFRONTO STESSO TAG, STESSI VALORI, DIVERSO ESPERIMENTO
%% distanze mediei_j nei 3 esperimenti; i = distanza considerata; j = 1 o 2 tag;

%tag2
distanze_medie1_2 = [mean(dist12), mean(dist12_2), mean(dist12_3)];
distanze_medie2_2 = [mean(dist22), mean(dist22_2), mean(dist22_3)];
distanze_medie3_2 = [mean(dist32), mean(dist32_2), mean(dist32_3)];
distanze_medie4_2 = [mean(dist42), mean(dist42_2), mean(dist42_3)];
distanze_medie_tag2 = [distanze_medie1_2; distanze_medie2_2;distanze_medie3_2;distanze_medie4_2];

distanze_dev1_2 = [std(dist12), std(dist12_2), std(dist12_3)];
distanze_dev2_2 = [std(dist22), std(dist22_2), std(dist22_3)];
distanze_dev3_2 = [std(dist32), std(dist32_2), std(dist32_3)];
distanze_dev4_2 = [std(dist42), std(dist42_2), std(dist42_3)];
distanze_dev_tag2 = [distanze_dev1_2;distanze_dev2_2;distanze_dev3_2;distanze_dev4_2]


%tag1
distanze_medie1_1 = [mean(dist11), mean(dist11_2), mean(dist11_3)];
distanze_medie2_1 = [mean(dist21), mean(dist21_2), mean(dist21_3)];
distanze_medie3_1 = [mean(dist31), mean(dist31_2), mean(dist31_3)];
distanze_medie4_1 = [mean(dist41), mean(dist41_2), mean(dist41_3)];
distanze_medie_tag1 =[distanze_medie1_1; distanze_medie2_1;distanze_medie3_1;distanze_medie4_1];

distanze_dev1_1 = [std(dist11), std(dist11_2), std(dist11_3)];
distanze_dev2_1 = [std(dist21), std(dist21_2), std(dist21_3)];
distanze_dev3_1 = [std(dist31), std(dist31_2), std(dist31_3)];
distanze_dev4_1 = [std(dist41), std(dist41_2), std(dist41_3)];
distanze_dev_tag1 = [distanze_dev1_1;distanze_dev2_1;distanze_dev3_1;distanze_dev4_1]

%% posizioni medie e deviazione standard
%tag1
posx_media1 = [mean(posx1), mean(posx1_2), mean(posx1_3)];
devx_1 = [std(posx1), std(posx1_2), std(posx1_3)];

posy_media1 = [mean(posy1), mean(posy1_2), mean(posy1_3)];
devy_1 = [std(posy1), std(posy1_2), std(posy1_3)];

posz_media1 = [mean(posz1), mean(posz1_2), mean(posz1_3)];
devz_1 = [std(posz1), std(posz1_2), std(posz1_3)];

%%tag2
posx_media2 = [mean(posx2), mean(posx2_2), mean(posx2_3)];
devx_2 = [std(posx2), std(posx2_2), std(posx2_3)];

posy_media2 = [mean(posy2), mean(posy2_2), mean(posy2_3)];
devy_2 = [std(posy2), std(posy2_2), std(posy2_3)];

posz_media2 = [mean(posz2), mean(posz2_2), mean(posz2_3)];
devz_2 = [std(posz2), std(posz2_2), std(posz2_3)];

%%grafico medie delle posizioni
figure;
plot3(mean(posx1),mean(posy1),mean(posz1),'r-*',mean(posx1_2),mean(posy1_2),mean(posz1_2),'b-*',mean(posx1_3),mean(posy1_3),mean(posz1_3),'g-*');
hold on
plot3(mean(posx2),mean(posy2),mean(posz2),'r-*',mean(posx2_2),mean(posy2_2),mean(posz2_2),'b-*',mean(posx2_3),mean(posy2_3),mean(posz2_3),'g-*');
%%piano x-y
%%
%%da qui in poi valori sistemati per la tabella

figure;
plot(mean(posx1),mean(posy1),'r-*',mean(posx1_2),mean(posy1_2),'b-*',mean(posx1_3),mean(posy1_3),'g-*');

%% CONFRONTO DATI STESSA PROVA

%tag1_prova1
coord1_1=[ mean(posx1),mean(posy1),mean(posz1)];
dev1_1= [std(posx1),std(posy1),std(posz1)];
a1= [coord1_1; dev1_1 ]
distanze1_1 = [distanze_medie_tag1(:,1)]';
deviazione1_1 = [distanze_dev_tag1(:,1)]';
b1=[distanze1_1 ;deviazione1_1 ]


%tag1_prova2
coord1_2=[mean(posx1_2),mean(posy1_2),mean(posz1_2)];
dev1_2 = [std(posx1_2),std(posy1_2),std(posz1_2)];
distanze1_2 = [distanze_medie_tag1(:,2)]';
deviazione1_2 = [distanze_dev_tag1(:,2)]';

%tag1_prova3
coord1_3=[mean(posx1_3),mean(posy1_3),mean(posz1_3)];
dev1_3 = [std(posx1_3),std(posy1_3),std(posz1_3)];
distanze1_3 = [distanze_medie_tag1(:,3)]';
deviazione1_3 = [distanze_dev_tag1(:,3)]';

%tag2_prova1
coord2_1=[mean(posx2),mean(posy2),mean(posz2)];
dev2_1= [std(posx2),std(posy2),std(posz2)];
distanze2_1 = [distanze_medie_tag2(:,1)]';
deviazione2_1 = [distanze_dev_tag2(:,1)]';
%tag2_prova2
coord2_2=[mean(posx2_2),mean(posy2_2),mean(posz2_2)];
dev2_2= [std(posx2_2),std(posy2_2),std(posz2_2)];
distanze2_2 = [distanze_medie_tag2(:,2)]';
deviazione2_2 = [distanze_dev_tag2(:,2)]';
%tag2_prova3
coord2_3=[mean(posx2_3),mean(posy2_3),mean(posz2_3)];
dev2_3 = [std(posx2_3),std(posy2_3),std(posz2_3)];
distanze3_3 = [distanze_medie_tag2(:,3)]';
deviazione3_3 = [distanze_dev_tag2(:,3)]';


% 
% 
% 
% 
% 
