function[med,dev,fal] = analizza(tag,x,y,z,d1,d2,d3,d4,flag)
global metri
if(metri == 1)
    n = 1000;
else
    n = 1;
end
l = length(flag);
[~,~,aux] = find(flag == tag);
n_1 = length(aux);
[~,~,aux] = find(flag == 3);
n_12 = length(aux);
fal = (n_1 + n_12)*100/l;

[~,~,aux] = find(x);
med(1,1) = mean(aux)/n;
dev(1,1) = std(aux)/n;
[~,~,aux] = find(y);
med(2,1) = mean(aux)/n;
dev(2,1) = std(aux)/n;
[~,~,aux] = find(z);
med(3,1) = mean(aux)/n;
dev(3,1) = std(aux)/n;

[~,~,aux] = find(d1);
med(4,1) = mean(aux)/n;
dev(4,1) = std(aux)/n;
[~,~,aux] = find(d2);
med(5,1) = mean(aux)/n;
dev(5,1) = std(aux)/n;
[~,~,aux] = find(d3);
med(6,1) = mean(aux)/n;
dev(6,1) = std(aux)/n;
[~,~,aux] = find(d4);
med(7,1) = mean(aux)/n;
dev(7,1) = std(aux)/n;