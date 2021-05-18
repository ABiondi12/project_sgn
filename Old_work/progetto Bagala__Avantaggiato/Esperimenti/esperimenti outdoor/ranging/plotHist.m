%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo          %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% funzione che stampa gli istogrammi relativi ad ogni elemento del set di
% misure
function[] = plotHist(t1, t2, n, i)
global metri
if(metri == 1)
    t1 = t1/1000;
    t2 = t2/1000;
end
nome1 = strcat('tag_1', int2str(i*5) , 'm');
subplot(4,n/2,i);
hold on,
hist(t1)
title(nome1)

nome2 = strcat('tag_2',int2str(i*5) , 'm');
subplot(4,n/2,n+i);
hold on,
hist(t2);
title(nome2)

end