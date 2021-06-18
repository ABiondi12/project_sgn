function out = norm_array(in)
%NORM_ARRAY Calcola la norma riga per riga. Vettore ingresso di tipo:
%nsamples x dim

l	= size(in,1);
dim = size(in,2);

if l < dim
	error('Check input dimensions!!')
end

%init
out = zeros(l,dim);
for i = 1:l
	out(i,:) = norm(in(i,:),2);
end

end

