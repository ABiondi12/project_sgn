%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo                        %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%Questa funzione elimina gli overflow dalle coordinate e/o dalle distanze
%
function [R] = eliminaoverflow(tag,coor,dist,C,param_coor,param_dist)
if(tag == 1)
    if(coor)
        x = C{1,1}; y = C{1,2}; z = C{1,3}; 
    end
    if(dist)
        d0 = C{1,4}; d1 = C{1,5}; d2 = C{1,6}; d3 = C{1,7};
    end
else
    if(coor)
        x = C{1,8}; y = C{1,9}; z = C{1,10}; 
    end
    if(dist)
        d0 = C{1,11}; d1 = C{1,12}; d2 = C{1,13}; d3 = C{1,14};
    end
end
if(coor)
    [a,~,~] = find(x > param_coor); 
    [b,~,~] = find(y > param_coor); 
    [c,~,~] = find(z > param_coor); 
    index_p = [a' b' c'];
    index_p = unique(index_p);

    r1 = [x y z];
    start1 = 1; 
    [~,~,aux] = find(index_p == 1);
    if(aux) 
        r1(1,:) = zeros(1,3); 
        start1 = 2; 
    end
    
    for i = start1 : length(index_p)
        r1(index_p(i),:) = r1(index_p(i)-1,:);
    end
    R = r1;
end

if(dist)
    [d,~,~] = find(d0 > param_dist); 
    [e,~,~] = find(d1 > param_dist); 
    [f,~,~] = find(d2 > param_dist); 
    [g,~,~] = find(d3 > param_dist); 
    index_r = [d' e' f' g'];
    index_r = unique(index_r);

    start2 = 1;
    r2 = [d0 d1 d2 d3];
    [~,~,aux] = find(index_r == 1);
    if(aux) 
        r2(1,:) = zeros(1,4); 
        start2 = 2;
    end

    for i = start2 : length(index_r)
        r2(index_r(i),:) = r2(index_r(i)-1,:);
    end
    
    if(coor)
        R = [R r2];
    else 
        R = r2;
end

end