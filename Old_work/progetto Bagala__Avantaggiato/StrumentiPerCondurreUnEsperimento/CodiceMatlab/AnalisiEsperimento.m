%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo                        %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Questo script analizza e stampa graficamente i risultati provenienti
% dalle misure nei file .txt: outdoor2.txt, outdoor3.txt. A seconda di
% quale file si vuole analizzare, bisogna inizializzare la variabile
% 'nome'. 
%
% viene preso in considerazione un file nel formato seguente:
%
%-------------tag1------------||-------------tag2------------||--status-||-errore-||tempo||---caso--||
%x y z dist0 dist1 dist2 dist3||x y z dist0 dist1 dist2 dist3||{0,1,2,3}||{0,1,2,3}||[ms]||{0,1,2,3}||
%-----------------------------||-----------------------------||---------||---------||----||---------||
%
%%
close all;
clear all;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%porre a uno i booleani rispetto alle variabili utilizzate per l'analisi
%se poste a uno le variabili di seguito vorrà dire che fanno parte dell'
%analisi attuale
coordinate = 1;
distanze = 1;
tag = 1;        %0 = un tag; 1 = due tag
status = 0;
errore = 1;
tempo = 1;
caso = 0;       %specifica per l'esperimento in cui ci siano più configurazioni
                %da analizzare (vedi "sketch_case")
%nota: il codice analizza tutto i dati presenti nel .txt, qualora si
%volesse selezionare un set di campioni da analizzare bisognerà definirlo,
%appunto, nella variabile "set" scorrento nel codice. Un esempio è
%riportato qui come commento; esso si riferisce ai set utilizzati per
%l'esperimento del positioning ("outdoor2.txt" e "outdoor3.txt")
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Formazione del vettore ed eliminazione degli overfloow pre-analisi

global metri
metri = 1;          %come un booleano: se 1 voglio le misure in metri, 
                    %altrimenti in mm
                    %NOTA: la funzione myPlot2D viene lanciata solo per 
                    %metri = 1
                    
%%%%%%%%%%%% Parametri da settare opportunamente %%%%%%%%%%%%%%
param_coor = 70000;     %parametro di overfloow per coordinate
param_dist = 90000;     %parametro di overfloow per distanze ancora-tag 

Current = cd;
cd 'Dati';           %specificare la cartella in cui si trova il file da analizzare
nome = 'indoor_case.txt';   %specificare il nome del file da analizzare
fileID = fopen(nome);
D = textscan(fileID,'%f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32 %f32');
fclose(fileID);
cd (Current);

[~,l] = size(D);

while(isnan(D{1,l}(1)))
    l = l - 1;
end

C = eliminaoverflow(1,coordinate,distanze,D,param_coor, param_dist);
if(tag)
    r = eliminaoverflow(2,coordinate,distanze,D,param_coor, param_coor);
    C = [C r];
end
if(status)
    stat = D{l - caso - tempo - errore};
    C = [C stat];
else 
    stat = zeros(length(D));
end
if(errore)
    index_err = l - caso - tempo;
    e = D{index_err};
	C = [C e];
else 
    index_err = errore;
end
if(tempo)
    t = D{l - caso};
    C = [C t];
end
if(caso)
    c = D{l};
    C = [C c];
end

%% Analisi
%Set specifici per l'analisi dell'esperimento sul positioning outdoor
%Si possono scrivere set opportuni qualora si voglia analizzare solo parti
%dei dati presenti in un file
%Qualora si voglia stampare anche la figura con cerchi concentrici prodotta
%da myPlot2d in cui si testano le misure effettuate su un set di distanze,
%sarà necessario cambiare di conseguenza la variabile set_dist posta in
%cima alla funzione
%
% if(strcmp(nome(8),'2'))
%     set = [1 2000; 2500 3500; 4000 6000; 6500 8500; 9000 11000; 11500 12500; ...
%         13000 14000; 14500 16500; 17500 19000; 20000 22000; 22500 23500; 24500 length(C)];
% else
%      set = [1 2000; 2500 4500; 5000 7000; 7500 8500; 9000 11000; 11500 13500;...
%          15500 17500; 18000 19000; 19500 20500; 21500 23500; 25000 27000; 27500 length(C)];
%  end
set = [1 length(C)];
[n,~] = size(set);
l1 = (l - status - caso - tempo - errore)/(1 + tag);
medie = zeros(n,l1);
deviazioni = zeros(n,l1);
fallimenti = zeros(n,2);
if(tempo)
    f_m = zeros(n,1);
    dev = zeros(n,1);
end

index_m1 = coordinate*3+distanze*4;
for i = 1:n
    [medie(i,1:index_m1),deviazioni(i,1:index_m1), fallimenti(i,1)] = ...
        analizza(1,C(set(i,1):set(i,2),:),coordinate, distanze, errore, index_err);
     if(tempo)
          [f_m(i),dev(i)] = ...
               calcolafreqUWB(t(set(i,1):set(i,2)));
     end
end

if(tag)
    index_m2 = 2*index_m1;
    for i = 1:n
     [medie(i,index_m1+1:index_m2),deviazioni(i,index_m1+1:index_m2), fallimenti(i,1)] = ...
        analizza(1,C(set(i,1):set(i,2),:),coordinate, distanze, errore, index_err);
    end
end
   
%% Plottaggio
if(metri & coordinate)
    if(tag)
        myPlot2d(medie(:,1:2), medie(:,8:9), deviazioni(:,1:2), ...
            deviazioni(:,8:9),[C(:,1:2) C(:,4) C(:,8:9) C(:,11)],...
            coordinate,distanze,tag);
    else
        myPlot2d(medie(:,1:2), medie(:,8:9), deviazioni(:,1:2), ...
            deviazioni(:,8:9),[C(:,1:2) C(:,4)],coordinate,distanze,tag);
    end    
end

if(distanze)
    if(tag)
        plotDist([C(:,3*coordinate+1:index_m1) C(:,index_m1+3*coordinate+1:index_m2)],...
            stat, e, status, errore, tag);
    else
        plotDist([C(:,3*coordinate+1:index_m1)], stat, e, status, errore, tag);
    end
end

%% Formazione tabella dati
% t = table(medie(:,1:3), deviazioni(:,1:3), medie(:,4:7), deviazioni(:,4:7),...
%           medie(:,8:10), deviazioni(:,8:10), medie(:,11:14), deviazioni(:,11:14),...
%           fallimenti, f_m, dev);
% d = [sqrt(medie(:,1).^2 + medie(:,2).^2) medie(:,4) sqrt(medie(:,8).^2 + medie(:,9).^2) medie(:,11)];
% for i = 1:11
%     t.Properties.VariableNames{i} = name{i,1};
% end