%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo                        %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%Questa funzione serve ad effettuare i plot per un'analisi delle distanze
%dalle ancore. Può risultare utile anche per verificare l'affidabilità del
%sistema. In particolare effettuando un esperimento in cui vengono salvati
%sia status che errore e le distanze ad ogni loop (sia che il positiong dia
%esito positivo che in caso contrario), le distanze possono essere
%raffrontate con l'esito del positioning ed anche con il codice di errore. 
%Nota: ci sono situazioni in cui l'algoritmo di positioning non rileva
%errori (status/status1 = 1), ma le coordinate calcolate saranno pari a
%zero (l'errore sarà diverso da 0)
% 
function [] = plotDist(dist,s,e,stato,err,tag)

color1 = ['r','k','c','g']; %set di colori utilizzato+
%nota: il grafico racchiude tutte le distanze, potenzialmente relative a
%due tag qualora fossero presenti nell'esperimento
divise = 0; %qualora si volessero sdoppiare le informazioni si può porre 
            %questa variabile a 1; questa seconda opzione fa però perdere
            %un plottaggio automatico della legenda
figure,
for i = 1:4
    plot(dist(:,i), color1(i));
    hold on,
end
if(err)
    plot((-0.40-0.15.*((e(:)==1)|(e(:)==3)))*10^4,'b');
end
if(stato)
    hold on
    plot((-0.65-0.15*((s(:)==0)|(s(:)==2)))*10^4,'r');
end

if(tag)
    if(divise)
        xlabel('NOTA: i segnali di controllo danno esito positivo quando sono in alto')
        hold off,
        figure,
    else
        hold on,
    end
    for i = 1:4
        plot(dist(:,4+i), strcat(color1(i), '--'));
        hold on,
    end
    if(err)
    plot((-1-0.15.*((e(:)>=2)))*10^4, 'b--');
    end
    if(stato)
        hold on
        plot((-1.25-0.15.*((s(:)==0)|(s(:)==1)))*10^4,'r--');
    end
    grid MINOR
end

hold off,
xlabel('NOTA: i segnali di controllo danno esito positivo quando sono in alto')

if(divise==0)
    if(tag)
        if(stato)
            if(err)
             legend('tag1d0','tag1d1','tag1d2','tag1d3','tag1err','tag1status',...
                'tag2d0','tag2d1','tag2d2','tag2d3','tag2err','tag2status')
            else
             legend('tag1d0','tag1d1','tag1d2','tag1d3','tag1status',...
                'tag2d0','tag2d1','tag2d2','tag2d3','tag2status')
            end
        else
            if(err)
             legend('tag1d0','tag1d1','tag1d2','tag1d3','tag1err',...
                'tag2d0','tag2d1','tag2d2','tag2d3','tag2err')
            else
             legend('tag1d0','tag1d1','tag1d2','tag1d3',...
                'tag2d0','tag2d1','tag2d2','tag2d3')
            end
        end
    else
        if(stato)
            if(err)
             legend('tag1d0','tag1d1','tag1d2','tag1d3','tag1err','tag1status')
            else
             legend('tag1d0','tag1d1','tag1d2','tag1d3','tag1status')
            end
        else
            if(err)
             legend('tag1d0','tag1d1','tag1d2','tag1d3','tag1err')
            else
             legend('tag1d0','tag1d1','tag1d2','tag1d3')
            end
        end
    end
end

end