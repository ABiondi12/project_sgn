%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo                        %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%Questa funzione calcola la frequenza del loop
%
function [f_m,dev, mas, mini] = calcolafreqUWB (C)
time = zeros(length(C) - 2,1);

for i = length(time):-1:3
    time(length(time) - i +1) = C(i)- C(i-1);
end
time = time(1:length(time)-2);
f = 10^6./(time);
dev = std(f);
mas = max(f);
mini =min(f);
f_m = mean(f);
end