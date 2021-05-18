% Distanze misurate al metro laser con relative incertezze

%Misurazioni effettuate al metro laser della distanza relativa tra l'ancore
%Rij = distanza misurata al metro laser tra l'ancora i e l'ancora j
R01 = 5950; D01 = 10; 
R02 = 5935; D02 = 10;
R03 = 3546; D03 = 20;
R12 = 4026; D12 = 10;
R13 = 3642; D13 = 10;
R23 = 2720; D23 = 15;

[Dx2, Dy2, Dx3, Dy3, Dz3] = prop_err(R01, R02, R03, R12, R13, R23, ... 
                                     D01, D02, D03, D12, D13, D23)
