%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo          %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Dopo aver definito cd, lanciare questo script che analizza i dati
% in termini di frequenza. In questi esperimenti, per ogni dispositivo è
% stato settato il seguente set di parametri:
% plen = 64 symbols;
% prf = 64 MHz;
% channel = 5;
% gain = 11.5
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd 'Dati' % cartella in cui ci sono i dati da analizzare
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ESPERIMENTO 1 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\channel5bitrate850PRF64plen64.txt');
C850 = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C850;
[f850,dev1, max1, min1] = calcolafreqUWB(C850{1,16});
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\channel5bitrate110PRF64plen64.txt');
C110 = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C110;
[f110, dev2, max2, min2] = calcolafreqUWB(C110{1,16});
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\channel5bitrate6.81PRF64plen64.txt');
C681 = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C681;
[f681,dev3,max3,min3] = calcolafreqUWB(C681{1,16});
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

bitrate = [110 850 6810];
f = [f110 f850 f681];
massi = [max2,max1, max3];
mini = [min2, min1, min3];
dev = [dev1, dev2, dev3];
figure;
plot(bitrate,f,'-s','MarkerSize',10,...
            'MarkerEdgeColor','red',...
            'MarkerFaceColor',[1 .6 .6])
        legend('bitrate6.81prf64plen64');
        xlabel('bitrate[kbps]');
        ylabel('frequenza[Hz]');
          hold on
     plot(bitrate,massi,'-*');
     hold on
     plot(bitrate,mini,'-*');
        