%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo          %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [media, dev] = calcolo_dist(col)
global metri;
[a, b, c] = find (col > 100000);
col(a) = 0; 
[a, b, c] = find (col);
media =  mean(c)/(1+999*metri);
dev = std(c)/(1+999*metri);

end