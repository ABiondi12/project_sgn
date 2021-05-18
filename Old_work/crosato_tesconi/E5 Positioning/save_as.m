function [] = save_as( name, folder)
%**************************************************************************
% Questa funzione mi permette di salvare le immagini che desidero in quanto
% ogni volta utilizzare il comando print diventa noioso
% 
% INPUT :  1) name : nome della figura salvata
%          2) folder : nome della cartella in cui salvare l'immagine
%**************************************************************************                     
                     
global saving

if strcmpi(saving, 'y')
    set(gcf, 'InvertHardCopy', 'off');% salvo le figure preservando il colore di background
    print( name, '-dpng', '-r800');  %formato grafico -depsc
    movefile(strcat(name,'.png'),... 
    	strcat('./',folder));% muove il file con estensione.eps nella cartella corrente
end

end

