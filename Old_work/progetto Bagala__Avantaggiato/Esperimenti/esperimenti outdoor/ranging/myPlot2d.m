function [] = myPlot2d (m1,m2,d1,d2)
global metri
set_dist = [5 10 15 20 25 30 35 40 45 50 55 60 65 70];
figure;
for i = 1:length(m1)
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
figure,
for i = 1:length(m2)
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
hold off,
figure,
for i = 1:length(set_dist)
    axis([0 set_dist(12) 0 set_dist(12)])
    hold on
    viscircles([0 0], set_dist(i), 'LineStyle','-.', 'Color','g', 'LineWidth', 0.5);
end
for i = 1:length(m1)
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