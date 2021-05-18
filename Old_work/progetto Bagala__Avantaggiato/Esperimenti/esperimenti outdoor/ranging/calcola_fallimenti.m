%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo          %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [perc] = calcola_fallimenti(col)
conta_fal = 0;
    for i = 1 : length(col)
        if (col(i) == 0)
            conta_fal = conta_fal + 1;
        end
    end
    perc = (conta_fal/length(col))*100;
end
        
    