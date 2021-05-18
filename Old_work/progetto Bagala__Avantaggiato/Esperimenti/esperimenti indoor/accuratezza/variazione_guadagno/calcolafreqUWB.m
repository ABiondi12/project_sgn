%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo          %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [f_m,dev, mas, mini,pos_tag1,pos_tag2,dev1,dev2] = calcolafreqUWB (C)
[r,c] = size(C);
aux = zeros(r,1); 
aux = C(:,c);
time = zeros(length(aux) - 2,1);

for i = length(time):-1:3
    time(length(time) - i +1) = aux(i)-aux(i-1);
end
time = time(1:length(time)-2);
f = 10^6./(time);
dev = std(f);
mas = max(f);
mini = min(f);
f_m = mean(f);
