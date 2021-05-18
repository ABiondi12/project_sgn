%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo                        %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%Questa funzione serve a effettuare i plot per un'analisi del positioning
%
function [] = myPlot2d (m1,m2,d1,d2,in,coor,dist,tag)

%distanze pari al raggio con cui verranno plottati i cerchi
%il vettore dovrà essere corrispondente al set di distanze testate
set_dist = [5 10 15 20 25 30 35 40 45 50 55 60 65 70];

%%  Confronto Ranging/Positioning
%stampo un confronto tra la distanza prodotta dalla triangolazione planare 
%e quella distanza riscontarta dal ranging rispetto alll'ancora zero
if(coor)     %lo faccio per un tag solo se sono state salvate le coordinate
    figure;
    x = in(:,1);
    y = in(:,2);
    d = sqrt(x.^2+y.^2);
    plot(d/1000,'r --');
    hold on
    plot(in(:,3)/1000,'b --')
    legend('Positioning', 'Ranging Ancora 0')
    title('Confronto ranging/posiotioning tag 1')
    ylabel('Distanze [m]')
    grid MINOR
    if(tag)  %eseguo le stesse operazioni nuovamente per un eventuale secondo tag
        figure;
        x = in(:,4);
        y = in(:,5);
        d = sqrt(x.^2+y.^2);
        plot(d/1000,'r --');
        hold on
        plot(in(:,6)/1000,'b --')
        legend('Positioning', 'Ranging Ancora 0')
        title('Confronto ranging/posiotioning tag 2')
        ylabel('Distanze [m]')
        grid MINOR
    end
end

%% Rumore sulle coordinate
%plotto le coordinate derivanti dalla trilaterazione nel piano
%vengono plottate come un ellisse di centro la media delle coordinate, e
%parametri dei semiassi dell'ellisse derivanti dalle deviazioni standard
%dei dati
if(dist)
    figure;
    [n1,~] = size(m1);
    for i = 1:n1
        a = max(d1(i,1),d1(i,2));
        if(d1(i,2) == 0)
            b = a;
        else
        b = min(d1(i,1),d1(i,2));
        end
        c = sqrt(a^2-b^2)/a;
        if (a == d1(i,2))
            angle = 90;
        else 
            angle = 0;
        end
        [x,y] = ellipse1(m1(i,1), m1(i,2), [a c], angle);
        plot(x,y,'LineStyle',':','Color','r', 'LineWidth', 1)
        hold on,
        plot(m1(i,1), m1(i,2), 'r-+'); 
        title('tag_1')
        hold on,
    end
    xlabel('Coordinata x [m]')
    ylabel('Coordinata y [m]')
    axis([0 set_dist(10) 0 set_dist(10)])
    grid MINOR,
    hold off,
    if(tag)
        figure,
        for i = 1:n1
            a = max(d2(i,1),d2(i,2));
            if(d1(i,2) == 0)
                b = a;
            else
            b = min(d2(i,1),d2(i,2));
            end
            c = sqrt(a^2-b^2)/a;
            if (a == d2(i,2))
                angle = 90;
            else 
                angle = 0;
            end
            [x,y] = ellipse1(m2(i,1), m2(i,2), [a c], angle);
            plot(x,y, 'LineStyle',':','Color','b', 'LineWidth', 1)
            hold on,
            plot(m2(i,1), m2(i,2), 'b-*'); 
            title('tag_2')
            hold on,
        end
        xlabel('Coordinata x [m]')
        ylabel('Coordinata y [m]')
        axis([0 set_dist(10) 0 set_dist(10)])
        grid MINOR,
    end
    hold off,
end

%% Plottaggio set di distanze
%NOTA: inserire in set_dist (inizio della funzione) il set di distanze 
%testate nell'esperimento
figure,
for i = 1:length(set_dist)
    axis([0 set_dist(12) 0 set_dist(12)])
    hold on
    viscircles([0 0], set_dist(i), 'LineStyle','-.', 'Color','g', 'LineWidth', 0.5);
end
for i = 1:n1
    plot(m1(i,1), m1(i,2), 'r-+');
    hold on,
    plot(m2(i,1), m2(i,2), 'b-*');
    hold on,
    title('entrambi i tag')
end
xlabel('Coordinata x [m]')
ylabel('Coordinata y [m]')
grid MINOR,
hold off,
end