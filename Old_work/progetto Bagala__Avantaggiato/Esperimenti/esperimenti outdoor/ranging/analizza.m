%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo          %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Funzione ausiliaria che restituisce [media, deviazione e percentuale di
% fallimenti] a partire dal tag considerato(1 o 2) e dall'array C contente 
% tutti i dati
function[med,dev,fal] = analizza(tag,C)
if(tag == 1)
    x = C(:,1); y = C(:,2); z = C(:,3); d0 = C(:,4); d1 = C(:,5); d2 = C(:,6); d3 = C(:,7);
else
    x = C(:,8); y = C(:,9); z = C(:,10); d0 = C(:,11); d1 = C(:,12); d2 = C(:,13); d3 = C(:,14);
end
flag = C(:,15);
n = length(flag);
[~,~,aux] = find(flag ==tag);
n_1 = length(aux);
[~,~,aux] = find(flag==3);
n_12 = length(aux);
fal = (n_1 + n_12)*100/n;

[~,~,aux] = find(x);
med(1,1) = mean(aux);
dev(1,1) = std(aux);
[~,~,aux] = find(y);
med(2,1) = mean(aux);
dev(2,1) = std(aux);
[~,~,aux] = find(z);
med(3,1) = mean(aux);
dev(3,1) = std(aux);

[~,~,aux] = find(d0);
med(4,1) = mean(aux);
dev(4,1) = std(aux);
[~,~,aux] = find(d1);
med(5,1) = mean(aux);
dev(5,1) = std(aux);
[~,~,aux] = find(d2);
med(6,1) = mean(aux);
dev(6,1) = std(aux);
[~,~,aux] = find(d3);
med(7,1) = mean(aux);
dev(7,1) = std(aux);