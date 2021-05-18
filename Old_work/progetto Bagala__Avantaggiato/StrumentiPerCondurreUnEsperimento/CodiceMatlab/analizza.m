%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo                        %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%Questa funzione elimina gli overflow dalle coordinate e/o dalle distanze
%
function[med,dev,fal] = analizza(tag,in,coor,dist,er,ind_err)
global metri
if(metri == 1)
    n = 1000;
else
    n = 1;
end

%% Calcolo percentuale di fallimenti differenziata per ogni tag
%si ricorda la codifica utilizzata per l'errore:
%1:fallimento del primo tag; 2:fallimento del secondo tag; 3:fallimenti di
%entrambi

if(er)
    l = length(flag);
    [~,~,aux] = find(in(ind_err,:) == tag);
    n_1 = length(aux);
    [~,~,aux] = find(in(ind_err,:) == 3);
    n_12 = length(aux);
    fal = (n_1 + n_12)*100/l;
else
    fal = 0;
end

%% Calcolo le medie e le deviazioni standar relative alle cordinate 
if(coor)
    [~,~,aux] = find(in(:,1));
    med(1,1) = mean(aux)/n;
    dev(1,1) = std(aux)/n;
    [~,~,aux] = find(in(:,2));
    med(2,1) = mean(aux)/n;
    dev(2,1) = std(aux)/n;
    [~,~,aux] = find(in(:,3));
    med(3,1) = mean(aux)/n;
    dev(3,1) = std(aux)/n;
end

%% Calcolo le medie e le deviazioni standar relative alle distanze
if(dist)
    index = coor*3;
    [~,~,aux] = find(in(:,1+index));
    med(4,1) = mean(aux)/n;
    dev(4,1) = std(aux)/n;
    [~,~,aux] = find(in(:,2+index));
    med(5,1) = mean(aux)/n;
    dev(5,1) = std(aux)/n;
    [~,~,aux] = find(in(:,3+index));
    med(6,1) = mean(aux)/n;
    dev(6,1) = std(aux)/n;
    [~,~,aux] = find(in(:,4+index));
    med(7,1) = mean(aux)/n;
    dev(7,1) = std(aux)/n;
end