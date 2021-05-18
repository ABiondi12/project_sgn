function [] = plotDist(d1,d2,e)
n = length(d1);
% n = floor(length(d1)/2);
color1 = ['r','k','c','g'];
figure,
for i = 1:4
    plot(d1(1:n,i), color1(i));
    hold on,
end
plot(-0.25.*((e(1:n)==1)|(e(1:n)==3))*10^4,'b');
hold on,
for i = 1:4
    plot(d2(1:n,i), strcat(color1(i), '--'));
    hold on,
end
plot((-0.5-0.25.*((e(1:n)>=2)))*10^4, 'b--');
legend('tag1d0','tag1d1','tag1d2','tag1d3','tag1err','tag2d0','tag2d1','tag2d2','tag2d3','tag2err')
hold off,
%figure,
% for i = 1:4
%     plot(d1(n:2*n,i), color1(i));
%     hold on,
% end
% plot(-0.25.*((e(n:2*n)==1)|(e(n:2*n)==3))*10^4, 'b');
% hold on,
% for i = 1:4
%     plot(d2(n:2*n,i), strcat(color1(i), '--'));
%     hold on,
% end
% plot((-0.5-0.25.*((e(n:2*n)>=2)))*10^4, 'b--');
% legend('tag1d0','tag1d1','tag1d2','tag1d3','tag1err','tag2d0','tag2d1','tag2d2','tag2d3','tag2err')
% hold off,
% figure,
% plot((abs(diff(d1(:,1:4)))>0.01));
% figure,
% plot((abs(diff(d1(:,1:4)))>0.01));
end