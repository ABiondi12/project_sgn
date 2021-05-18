%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo          %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd 'Dati'
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ESPERIMENTO 1 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\channel1bitrate6.81PRF64plen64.txt');
C1 = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C1;
[f1,dev1, max1,min1] = calcolafreqUWB(C1{1,16});
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\channel2bitrate6.81PRF64plen64.txt');
C2 = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C2;
[f2,dev2, max2,min2] = calcolafreqUWB(C2{1,16});
fclose(fileID);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\channel3bitrate6.81PRF64plen64.txt');
C3 = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C3;
[f3,dev3, max3,min3] = calcolafreqUWB(C3{1,16});
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\channel4bitrate6.81PRF64plen64.txt');
C4 = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C4;
[f4,dev4, max4,min4] = calcolafreqUWB(C4{1,16});
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\channel5bitrate6.81PRF64plen64.txt');
C5 = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C5;
[f5,dev5, max5,min5] = calcolafreqUWB(C5{1,16});
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\channel7bitrate6.81PRF64plen64.txt');
C7 = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C7;
[f7,dev7, max7,min7] = calcolafreqUWB(C7{1,16});
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
channel = [1 2 3 4 5 7];
f = [f1 f2 f3 f4  f5 f7];
massi = [max1, max2, max3, max4, max5, max7];
mini = [min1, min2, min3, min4, min5, min7];
dev = [dev1, dev2, dev3, dev4, dev5, dev7];
figure;
plot(channel,f,'-s','MarkerSize',10,...
            'MarkerEdgeColor','red',...
            'MarkerFaceColor',[1 .6 .6])
        legend('bitrate6.81prf64plen64');
        xlabel('channel');
        ylabel('frequenza');
     hold on
     plot(channel,massi,'-*');
     hold on
     plot(channel,mini,'-*');
    
        