function [f_m,dev, mas, mini,pos_tag1,pos_tag2,dev1,dev2] = calcolafreqUWB (C)
aux = zeros(length(C),1); aux = (C);
time = zeros(length(aux) - 2,1);

for i = length(time):-1:3
    time(length(time) - i +1) = aux(i)-aux(i-1);
end
time = time(1:length(time)-2);
f = 10^6./(time);
dev = std(f);
mas = max(f);
mini =min(f);
% maxloop4 = max(floop4);
% minloop4 = min(floop4);
f_m = mean(f);

% err = C(:,15);
% X = C(:,1:15);
% index = 0;
% conta = 0;
% for i = 1:length(err)
%     if(err{1}(i,1)== 2 || err{1}(i,1) == 1 || err{1}(i,1) == 3 )
%         X(i - conta, :) = [];
%         conta = conta + 1;
%     end   
% end
% 
% posx1= mean(X{1}); posy1= mean(X{2}); posz1= mean(X{3}); pos_tag1= [posx1 posy1 posz1];
% posx2= mean(X{8}); posy2= mean(X{9}); posz2= mean(X{10});  pos_tag2= [posx2 posy2 posz2];
% 
% posx1_dev= std(X{1}); posy1_dev= std(X{2}); posz1_dev= std(X{3}); dev1 = [posx1_dev posy1_dev posz1_dev];
% posx2_dev= std(X{8}); posy2_dev= std(X{9}); posz2_dev= std(X{10}); dev2 = [posx2_dev posy2_dev posz2_dev];
% 
% dist11= mean(C{4}); dist21= mean(C{5}); dist31= mean(C{6}); dist41= mean(C{7}); 
% dist12= mean(C{11}); dist22= mean(C{12}); dist32= mean(C{13}); dist42= mean(C{14}); 
% 
% %distanze primo tag primo esperimento
% distanze1_1 =[dist11, dist21, dist31, dist41];
% 
% %distanze secondo tag primo esperimento
% distanze2_1 =[dist12, dist22, dist32, dist42];
