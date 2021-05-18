%%%%%%%%%%%%%% PROGETTO DI GUIDA E NAVIGAZIONE %%%%%%%%%%%%%%
%%          Avantaggiato Sabrina e Bagalà Alfredo          %%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% dopo aver caricato i file, tale script crea una tabella che riassume
% l'esito degli esperimenti per ogni tag al variare del guadagno. Vengono
% infatti riportati i risultati del positioning e dei ranging e l'update
% rate

cd 'C:\Users\PC\Desktop\progetto Bagala_Avantaggiato\Esperimenti\accuratezza\variazione_guadagno\1esperimento'
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% gain = 11.5
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\2 tag con guadagno 11.5.txt');
C = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C;
C11_1 = eliminaoverflow(1, C);
C11_2 = eliminaoverflow(2, C);
C = [C11_1 C11_2 C{1,15} C{1,16}];
[med11_1,dev11_1,fal11_1] = analizza(1,C);
[med11_2,dev11_2,fal11_2] = analizza(2,C);
f11 = calcolafreqUWB(C);
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% gain = 15
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\2 tag con guadagno 15.txt');
C = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C;
C15_1 = eliminaoverflow(1, C);
C15_2 = eliminaoverflow(2, C);
C = [C15_1 C15_2 C{1,15} C{1,16}];
[med15_1,dev15_1,fal15_1] = analizza(1,C);
[med15_2,dev15_2,fal15_2] = analizza(2,C);
f15 = calcolafreqUWB(C);
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% gain = 20
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\2 tag con guadagno 20.txt');
C = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C;
C20_1 = eliminaoverflow(1, C);
C20_2 = eliminaoverflow(2, C);
C = [C20_1 C20_2 C{1,15} C{1,16}];
[med20_1,dev20_1,fal20_1] = analizza(1,C);
[med20_2,dev20_2,fal20_2] = analizza(2,C);
f20 = calcolafreqUWB(C);
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% gain = 25
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\2 tag con guadagno 25.txt');
C = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C;
C25_1 = eliminaoverflow(1, C);
C25_2 = eliminaoverflow(2, C);
C = [C25_1 C25_2 C{1,15} C{1,16}];
[med25_1,dev25_1,fal25_1] = analizza(1,C);
[med25_2,dev25_2,fal25_2] = analizza(2,C);
f25 = calcolafreqUWB(C);
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% gain = 30
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\2 tag con guadagno 30.txt');
C = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C;
C30_1 = eliminaoverflow(1, C);
C30_2 = eliminaoverflow(2, C);
C = [C30_1 C30_2 C{1,15} C{1,16}];
[med30_1,dev30_1,fal30_1] = analizza(1,C);
[med30_2,dev30_2,fal30_2] = analizza(2,C);
f30 = calcolafreqUWB(C);

fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% gain = 33
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fileID = fopen('\2 tag con guadagno 33.txt');
C = textscan(fileID,'%f32  %f32 %f32 %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32  %f32 %f32');
whos C;
C33_1 = eliminaoverflow(1, C);
C33_2 = eliminaoverflow(2, C);
C = [C33_1 C33_2 C{1,15} C{1,16}];
[med33_1,dev33_1,fal33_1] = analizza(1,C);
[med33_2,dev33_2,fal33_2] = analizza(2,C);
f33 = calcolafreqUWB(C);
fclose(fileID);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 
f = [f11 f15 f20 f25 f30 f33];
frequenza = [f11;f11; f15; f15; f20; f20; f25; f25; f30; f30; f33; f33];
posizioni_x = [med11_1(1) dev11_1(1) ; med11_2(1) dev11_2(1);...
    med15_1(1) dev15_1(1) ; med15_2(1) dev15_2(1);...
    med20_1(1) dev20_1(1) ; med20_2(1) dev20_2(1);...
    med25_1(1) dev25_1(1) ; med25_2(1) dev25_2(1);...
    med30_1(1) dev30_1(1) ; med30_2(1) dev30_2(1);...
    med33_1(1) dev33_1(1) ; med33_2(1) dev33_2(1)];

posizioni_y = [med11_1(2) dev11_1(2) ; med11_2(2) dev11_2(2);...
    med15_1(2) dev15_1(2) ; med15_2(2) dev15_2(2);...
    med20_1(2) dev20_1(2) ; med20_2(2) dev20_2(2);...
    med25_1(2) dev25_1(2) ; med25_2(2) dev25_2(2);...
    med30_1(2) dev30_1(2) ; med30_2(2) dev30_2(2);...
    med33_1(2) dev33_1(2) ; med33_2(2) dev33_2(2)];
    
posizioni_z = [med11_1(3) dev11_1(3) ; med11_2(3) dev11_2(3);...
    med15_1(3) dev15_1(3) ; med15_2(3) dev15_2(3);...
    med20_1(3) dev20_1(3) ; med20_2(3) dev20_2(3);...
    med25_1(3) dev25_1(3) ; med25_2(3) dev25_2(3);...
    med30_1(3) dev30_1(3) ; med30_2(3) dev30_2(3);...
    med33_1(3) dev33_1(3) ; med33_2(3) dev33_2(3)];

distanza0 = [med11_1(4) dev11_1(4) ; med11_2(4) dev11_2(4);...
    med15_1(4) dev15_1(4) ; med15_2(4) dev15_2(4);...
    med20_1(4) dev20_1(4) ; med20_2(4) dev20_2(4);...
    med25_1(4) dev25_1(4) ; med25_2(4) dev25_2(4);...
    med30_1(4) dev30_1(4) ; med30_2(4) dev30_2(4);...
    med33_1(4) dev33_1(4) ; med33_2(4) dev33_2(4)];

distanza1 = [med11_1(5) dev11_1(5) ; med11_2(5) dev11_2(5);...
    med15_1(5) dev15_1(5) ; med15_2(5) dev15_2(5);...
    med20_1(5) dev20_1(5) ; med20_2(5) dev20_2(5);...
    med25_1(5) dev25_1(5) ; med25_2(5) dev25_2(5);...
    med30_1(5) dev30_1(5) ; med30_2(5) dev30_2(5);...
    med33_1(5) dev33_1(5) ; med33_2(5) dev33_2(5)];

distanza2 = [med11_1(6) dev11_1(6) ; med11_2(6) dev11_2(6);...
    med15_1(6) dev15_1(6) ; med15_2(6) dev15_2(6);...
    med20_1(6) dev20_1(6) ; med20_2(6) dev20_2(6);...
    med25_1(6) dev25_1(6) ; med25_2(6) dev25_2(6);...
    med30_1(6) dev30_1(6) ; med30_2(6) dev30_2(6);...
    med33_1(6) dev33_1(6) ; med33_2(6) dev33_2(6)];


distanza3 = [med11_1(7) dev11_1(7) ; med11_2(7) dev11_2(7);...
    med15_1(7) dev15_1(7) ; med15_2(7) dev15_2(7);...
    med20_1(7) dev20_1(7) ; med20_2(7) dev20_2(7);...
    med25_1(7) dev25_1(7) ; med25_2(7) dev25_2(7);...
    med30_1(7) dev30_1(7) ; med30_2(7) dev30_2(7);...
    med33_1(7) dev33_1(7) ; med33_2(7) dev33_2(7)];

fallimenti = [ fal11_1; fal11_2; fal15_1; fal15_2; fal20_1; fal20_2;...
            fal25_1; fal25_2; fal30_1; fal30_2; fal33_1; fal33_2];
prima_colonna ={'tag1,gain11';'tag2,gain11';'tag1,gain15';'tag2,gain15';...
    'tag1,gain20';'tag2,gain20';'tag1,gain25';'tag2,gain25';'tag1,gain30';'tag2,gain30';
    'tag1,gain33';'tag2,gain33'};
%% creazione tabella
t = table(prima_colonna,frequenza,posizioni_x, posizioni_y, posizioni_z,...
        distanza0, distanza1, distanza2, distanza3, fallimenti);

