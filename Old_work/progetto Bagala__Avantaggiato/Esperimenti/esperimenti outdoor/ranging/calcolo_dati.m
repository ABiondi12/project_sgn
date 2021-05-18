%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo          %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [f_m, dev, maxf, minf, d1_m, d1_d, d2_m, d2_d, fal_1, fal_2, C1, C2] = calcolo_dati(C)
fal_1= calcola_fallimenti(C{1});
fal_2 = calcola_fallimenti(C{3});
C1 = eliminaoverflow(1, C);
C2 = eliminaoverflow(2, C);
C = [C{1,1} C1 C{1,3} C2 C{1,5}];
[f_m, dev, maxf, minf] = calcolafreqUWB (C);
[d1_m, d1_d]= calcolo_dist(C1); [d2_m, d2_d] = calcolo_dist(C2);
end