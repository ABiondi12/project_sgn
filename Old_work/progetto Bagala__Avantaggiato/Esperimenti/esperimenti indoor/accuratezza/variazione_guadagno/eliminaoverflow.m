%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo          %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% funzione ausiliaria che elimina eventuali valori al di fuori del range
% specificato dal parametro 'param' a partire dalla matrice C contenente i
% dati
function [R] = eliminaoverflow(tag, C)
if length (C) == 16
    if(tag == 1)
        x = C{1,1}; y = C{1,2}; z = C{1,3}; d0 = C{1,4}; d1 = C{1,5}; d2 = C{1,6}; d3 = C{1,7};
    else
        x = C{1,8}; y = C{1,9}; z = C{1,10}; d0 = C{1,11}; d1 = C{1,12}; d2 = C{1,13}; d3 = C{1,14};
    end
param = 60000;
[a,~,~] = find(x > param); 
[b,~,~] = find(y > param); 
[c,~,~] = find(z > param); 
[d,~,~] = find(d0 > param); 
[e,~,~] = find(d1 > param); 
[f,~,~] = find(d2 > param); 
[g,~,~] = find(d3 > param); 

index_p = [a' b' c'];
index_r = [d' e' f' g'];
index_p = unique(index_p);
index_r = unique(index_r);

r1 = [x y z];
r2 = [d0 d1 d2 d3];

start1 = 1; start2 = 1;
[~,~,aux] = find(index_p == 1);
if(aux) 
    r1(1,:) = zeros(1,3); 
    start1 = 2; 
end

[~,~,aux] = find(index_r == 1);
if(aux) 
    r2(1,:) = zeros(1,4); 
    start2 = 2;
end

for i = start1 : length(index_p)
    r1(index_p(i),:) = r1(index_p(i)-1,:);
end

for i = start2 : length(index_r)
    r2(index_r(i),:) = r2(index_r(i)-1,:);
end


R = [r1 r2];

else
    if(tag == 1)
        r1 = C{1,2}; 
    else 
        r1 = C{1,4};
    end
    param = 100000; 
    [d,~,~] = find(r1 > param); 

 
index_r = d';
index_r = unique(index_r);
dist = r1;

[~,~,aux] = find(index_r == 1);
start2 = 1;

if(aux) 
    dist(1,:) = zeros(1,1); 
    start2 = 2;
end

for i = start2 : length(index_r)
    dist(index_r(i),:) = dist(index_r(i)-1,:);
end

R = dist;


    
    
end
end
