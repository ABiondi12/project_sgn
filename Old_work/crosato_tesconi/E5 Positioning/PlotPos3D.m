%%% PLOT POSIZIONE TAG E ANCORE 3D

% LAUREA MAGISTRALE : ING. ROBOTICA E DELL'AUTOMAZIONE
% CORSO: SISTEMI DI GUIDA E NAVIGAZIONE
% AUTORI: CRISTIAN TESCONI/LUCA CROSATO

%**************************************************************************
% Questo script effettua il plot del tag e delle ancore (3D) nei seguenti casi:
%   1) TAG:
%      A) posizione reale misurata col metro laser (con relativa
%        incertezza);
%      B) posizione tag ottenuta dall'algoritmo PosTag.py che prende in
%        ingresso le coordinate  delle ancore ottenute dall'algoritmo
%        geometrico di calibrazione rangeToPos.m il quale prende in ingresso 
%        i range fra le ancore misurati col metro laser;
%      C) posizione tag ottenuta dall'algoritmo PosTag.py che prende in
%        ingresso le coordinate  delle ancore ottenute dall'algoritmo
%        gemoetrico di calibrazione rangeToPos.m  il quale prende in ingresso 
%        i range fra le ancore ottenuti con lo script python 
%        acquisizioni_distanze_antenne.py;
%
%   2) ANCORE:
%      A) posizione ancore ottenute mediante calibrazione manuale
%      B) posizione ancore ottenute mediante calibrazione automatica
%**************************************************************************


%% CLEAR
clear all;
close all;
clc;

%% SALVATAGGIO IMMAGINI
global saving
saving = 'y';

%% CARICAMENTO POSIZIONI TAG E ANCORE
Pos_tag_B = load('./dati/PosTag_manuale.mat')
Pos_tag_C = load('./dati/PosTag_automatico.mat')

%% POSIZIONE TAG 2D
% A)
x_tag_A = 311;    inc_x = 36; 
y_tag_A = 2315;   inc_y = 16;
z_tag_A = 422;    inc_z = 60;
figure ('name','Posizione tag ')
plot3(x_tag_A,y_tag_A,z_tag_A,'ks',...
                              'LineWidth',1,...
                              'MarkerSize',3,...
                              'MarkerEdgeColor','k',...
                              'MarkerFaceColor',[0,0,0])
hold on

% B)
plot3 (Pos_tag_B.x_tag,Pos_tag_B.y_tag,Pos_tag_B.z_tag,'bs',...
                                      'LineWidth',1,...
                                      'MarkerSize',3,...
                                      'MarkerEdgeColor','b',...
                                      'MarkerFaceColor',[0.5,0.5,0.5])
hold on

% % C)
plot3 (Pos_tag_C.x_tag,Pos_tag_C.y_tag,Pos_tag_C.z_tag,'rs',...
                                                       'LineWidth',1,...
                                                       'MarkerSize',3,...
                                                       'MarkerEdgeColor','r',...
                                                       'MarkerFaceColor',[0.5,0.5,0.5])
%axis equal
grid on
hold off
lgb = legend('Posizione misurata col metro laser','Posizione algoritmo con ranging manuale',...
             'Posizione algoritmo con ranging automatico','Location','northeast',...
             'Orientation','vertical')
lgb.FontSize = 6;
title('Posizione tag 3D')
save_as( 'Posizione_tag_3D', 'IMMAGINI')

%% POSIZIONE ANCORE 3D
Cal_man = load('./dati/Calibrazione_manuale.mat'); %calibrazione manuale
Cal_aut = load('./dati/Calibrazione_automatica.mat'); %calibrazione atuomatica

%************************ Calibrazione manuale*****************************
figure ('name','Posizione ancore ')
cal_man = plot3(Cal_man.A0(1),Cal_man.A0(2),Cal_man.A0(3),'ms','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','m','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot3(Cal_man.A1(1),Cal_man.A1(2),Cal_man.A1(3),'ms','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','m','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot3(Cal_man.A2(1),Cal_man.A2(2),Cal_man.A2(3),'ms','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','m','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot3(Cal_man.A3(1),Cal_man.A3(2),Cal_man.A3(3),'ms','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','m','MarkerFaceColor',[0.5,0.5,0.5]);
hold on

%*********************** Calibrazione automatica***************************
cal_aut = plot3(Cal_aut.A0(1),Cal_aut.A0(2),Cal_aut.A0(3),'cs','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','c','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot3(Cal_aut.A1(1),Cal_aut.A1(2),Cal_aut.A1(3),'cs','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','c','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot3(Cal_aut.A2(1),Cal_aut.A2(2),Cal_aut.A2(3),'cs','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','c','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot3(Cal_aut.A3(1),Cal_aut.A3(2),Cal_aut.A3(3),'cs','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','c','MarkerFaceColor',[0.5,0.5,0.5]);
hold on

grid on
hold off
lgb = legend([cal_man,cal_aut],'Calibrazione manuale','Calibrazione automatica','Location','northeast',...
             'Orientation','vertical')
lgb.FontSize = 6;
title('Posizione ancore 3D')
save_as( 'Posizione_ancore_3D', 'IMMAGINI')


%% PLOT ANCORE E TAG INSIEME 3D
% TAG
% A)
x_tag_A = 311;    inc_x = 36; 
y_tag_A = 2315;   inc_y = 16;
z_tag_A = 422;    inc_z = 60;
figure ('name','Posizione tag e ancore ')
A = plot3(x_tag_A,y_tag_A,z_tag_A,'ks',...
                              'LineWidth',1,...
                              'MarkerSize',3,...
                              'MarkerEdgeColor','k',...
                              'MarkerFaceColor',[0,0,0])
hold on
% B)
B = plot3 (Pos_tag_B.x_tag,Pos_tag_B.y_tag,Pos_tag_B.z_tag,'bs',...
                                      'LineWidth',1,...
                                      'MarkerSize',3,...
                                      'MarkerEdgeColor','b',...
                                      'MarkerFaceColor',[0.5,0.5,0.5])
hold on
% C)
C = plot3 (Pos_tag_C.x_tag,Pos_tag_C.y_tag,Pos_tag_C.z_tag,'rs',...
                                                       'LineWidth',1,...
                                                       'MarkerSize',3,...
                                                       'MarkerEdgeColor','r',...
                                                       'MarkerFaceColor',[0.5,0.5,0.5])
% ANCORE
%************************ Calibrazione manuale*****************************
cal_man = plot3(Cal_man.A0(1),Cal_man.A0(2),Cal_man.A0(3),'ms','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','m','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot3(Cal_man.A1(1),Cal_man.A1(2),Cal_man.A1(3),'ms','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','m','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot3(Cal_man.A2(1),Cal_man.A2(2),Cal_man.A2(3),'ms','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','m','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot3(Cal_man.A3(1),Cal_man.A3(2),Cal_man.A3(3),'ms','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','m','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
%*********************** Calibrazione automatica***************************
cal_aut = plot3(Cal_aut.A0(1),Cal_aut.A0(2),Cal_aut.A0(3),'cs','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','c','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot3(Cal_aut.A1(1),Cal_aut.A1(2),Cal_aut.A1(3),'cs','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','c','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot3(Cal_aut.A2(1),Cal_aut.A2(2),Cal_aut.A2(3),'cs','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','c','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot3(Cal_aut.A3(1),Cal_aut.A3(2),Cal_aut.A3(3),'cs','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','c','MarkerFaceColor',[0.5,0.5,0.5]);
grid on
hold off
lgb = legend([A,B,C,cal_man,cal_aut],'Posizione tag misurata col metro laser','Posizione tag algoritmo con ranging manuale',...
             'Posizione tag algoritmo con ranging automatico','Calibrazione manuale','Calibrazione automatica','Location','southeast',...
             'Orientation','vertical');
lgb.FontSize = 6;
title('Posizione ancore e tag 3D')
save_as( 'Posizione_ancore_tag_3D', 'IMMAGINI')



