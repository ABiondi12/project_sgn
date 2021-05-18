%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo          %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Dopo aver definito cd, lanciare questo script che analizza i dati
% in termini di frequenza al variare del valore del plen. In questi esperimenti,
% per ogni dispositivo è
% stato settato il seguente set di parametri:
% bitrate = 6.81 Mbit/s;
% prf = 64 MHz;
% channel = 5;
% gain = 11.5.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd 'Dati'
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ESPERIMENTO 1 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\channel5bitrate6.81PRF64plen64.txt');
C64 = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C64;
[f64, dev1, max1, min1 ]  = calcolafreqUWB(C64{1,16});
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\channel5bitrate6.81PRF64plen128.txt');
C128 = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C128;
[f128, dev2, max2, min2] = calcolafreqUWB(C128{1,16});
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\channel5bitrate6.81PRF64plen256.txt');
C256 = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C256;
[f256,dev3, max3, min3] = calcolafreqUWB(C256{1,16});
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\channel5bitrate6.81PRF64plen512.txt');
C512 = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C512;
[f512,dev4, max4, min4] = calcolafreqUWB(C512{1,16});
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\channel5bitrate6.81PRF64plen1024.txt');
C1024 = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C1024;
[f1024,dev5, max5, min5] = calcolafreqUWB(C1024{1,16});
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\channel5bitrate6.81PRF64plen1536.txt');
C1536 = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C1536;
[f1536,dev6, max6, min6] = calcolafreqUWB(C1536{1,16});
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\channel5bitrate6.81PRF64plen2048.txt');
C2048 = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C2048;
[f2048,dev7, max7, min7] = calcolafreqUWB(C2048{1,16});
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
plen = [64, 128, 256, 512, 1024, 1536, 2048];
f = [f64 f128 f256 f512 f1024 f1536 f2048];
massi = [max1, max2, max3, max4, max5, max6, max7];
mini = [min1, min2, min3, min4, min5, min6, min7];
dev =[dev1,dev2,dev3,dev4,dev5,dev6, dev7];
figure;
plot(plen,f,'-s','MarkerSize',10,...
            'MarkerEdgeColor','red',...
            'MarkerFaceColor',[1 .6 .6])
        legend('channel5bitrate6.81prf64');
        xlabel('plen');
        ylabel('frequenza');
        axis([64 2048 0 50])
             hold on
     plot(plen,massi,'-*');
     hold on
     plot(plen,mini,'-*');