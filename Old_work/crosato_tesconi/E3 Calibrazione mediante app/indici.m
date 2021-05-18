function [mean, sigma] = indici(v )
% Calcola valor medio e varianza ribaltando simmetricamente i dati rispetto
% al piano YZ.
sum = 0;
for k = 1:length(v)
    if v(k) < 0
        v(k) = -v(k);
    end
    sum = sum + v(k);
end

mean = sum / length(v);

var = 0;
for k = 1:length(v)
    var = var + (v(k) - mean)^2;
end

sigma = sqrt(var / (length(v) - 1));
end

