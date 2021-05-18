%%% PLOT POSIZIONE TAG E ANCORE 2D

% LAUREA MAGISTRALE : ING. ROBOTICA E DELL'AUTOMAZIONE
% CORSO: SISTEMI DI GUIDA E NAVIGAZIONE
% AUTORI: CRISTIAN TESCONI/LUCA CROSATO

%**************************************************************************
% Questo script effettua il plot del tag e delle ancore nei seguenti casi:
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
global save
save = 'y';

%% CARICAMENTO POSIZIONI TAG E ANCORE
Pos_tag_B = load('./dati/PosTag_manuale.mat')
Pos_tag_C = load('./dati/PosTag_automatico.mat')

%% POSIZIONE TAG 2D
% A)
x_tag_A = 311;    inc_x = 36; 
y_tag_A = 2315;   inc_y = 16;
z_tag_A = 422;    inc_z = 60;
figure ('name','posizione tag ')
plot(x_tag_A,y_tag_A,'ks',...
                     'LineWidth',1,...
                     'MarkerSize',3,...
                     'MarkerEdgeColor','k',...
                     'MarkerFaceColor',[0,0,0])
hold on
% B)
plot(Pos_tag_B.x_tag,Pos_tag_B.y_tag,'bs',...
                                      'LineWidth',1,...
                                      'MarkerSize',3,...
                                      'MarkerEdgeColor','b',...
                                      'MarkerFaceColor',[0.5,0.5,0.5])
hold on
% C)
plot(Pos_tag_C.x_tag,Pos_tag_C.y_tag,'rs',...
                                      'LineWidth',1,...
                                      'MarkerSize',3,...
                                      'MarkerEdgeColor','r',...
                                      'MarkerFaceColor',[0.5,0.5,0.5])
axis ([-200 3000 -200 3000])
grid on
lgb = legend('Posizione misurata col metro laser','Posizione algoritmo con ranging manuale',...
             'Posizione algoritmo con ranging automatico','Location','southeast',...
             'Orientation','vertical')
lgb.FontSize = 6;
title('Posizione tag')
save_as( 'Posizione_tag_2D', 'IMMAGINI')



%% POSIZIONE ANCORE 2D
Cal_man = load('./dati/Calibrazione_manuale.mat'); %calibrazione manuale
Cal_aut = load('./dati/Calibrazione_automatica.mat'); %calibrazione atuomatica

%************************ Calibrazione manuale*****************************
figure ('name','posizione ancore ')
cal_man = plot(Cal_man.A0(1),Cal_man.A0(2),'ms','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','m','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot(Cal_man.A1(1),Cal_man.A1(2),'ms','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','m','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot(Cal_man.A2(1),Cal_man.A2(2),'ms','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','m','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot(Cal_man.A3(1),Cal_man.A3(2),'ms','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','m','MarkerFaceColor',[0.5,0.5,0.5]);
hold on

%*********************** Calibrazione automatica***************************
cal_aut = plot(Cal_aut.A0(1),Cal_aut.A0(2),'cs','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','c','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot(Cal_aut.A1(1),Cal_aut.A1(2),'cs','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','c','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot(Cal_aut.A2(1),Cal_aut.A2(2),'cs','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','c','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot(Cal_aut.A3(1),Cal_aut.A3(2),'cs','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','c','MarkerFaceColor',[0.5,0.5,0.5]);
hold on

grid on
axis ([-500 7000' -500 7000])
lgb = legend([cal_man,cal_aut],'Calibrazione manuale','Calibrazione automatica','Location','southeast',...
             'Orientation','vertical')
lgb.FontSize = 6;
title('Posizione ancore')
save_as( 'Posizione_ancore_2D', 'IMMAGINI')


%% PLOT ANCORE E TAG INSIEME 2D
figure ('name','Posizione tag e ancore ')
% TAG:
% A)
A = plot(x_tag_A,y_tag_A,'ks',...
                     'LineWidth',1,...
                     'MarkerSize',3,...
                     'MarkerEdgeColor','k',...
                     'MarkerFaceColor',[0,0,0])
hold on
% B)
B = plot(Pos_tag_B.x_tag,Pos_tag_B.y_tag,'bs',...
                                      'LineWidth',1,...
                                      'MarkerSize',3,...
                                      'MarkerEdgeColor','b',...
                                      'MarkerFaceColor',[0.5,0.5,0.5])
hold on
% C)
C = plot(Pos_tag_C.x_tag,Pos_tag_C.y_tag,'rs',...
                                      'LineWidth',1,...
                                      'MarkerSize',3,...
                                      'MarkerEdgeColor','r',...
                                      'MarkerFaceColor',[0.5,0.5,0.5])
axis equal
grid on
% ANCORE:
%****************************** Calibrazione manuale***********************
cal_man = plot(Cal_man.A0(1),Cal_man.A0(2),'ms','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','m','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot(Cal_man.A1(1),Cal_man.A1(2),'ms','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','m','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot(Cal_man.A2(1),Cal_man.A2(2),'ms','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','m','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot(Cal_man.A3(1),Cal_man.A3(2),'ms','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','m','MarkerFaceColor',[0.5,0.5,0.5]);
hold on

   
%*********************** Calibrazione automatica **************************
cal_aut = plot(Cal_aut.A0(1),Cal_aut.A0(2),'cs','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','c','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot(Cal_aut.A1(1),Cal_aut.A1(2),'cs','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','c','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot(Cal_aut.A2(1),Cal_aut.A2(2),'cs','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','c','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
plot(Cal_aut.A3(1),Cal_aut.A3(2),'cs','LineWidth',1,'MarkerSize',3,'MarkerEdgeColor','c','MarkerFaceColor',[0.5,0.5,0.5]);
hold on
lgb = legend([A,B,C,cal_man,cal_aut],'Posizione tag misurata col metro laser','Posizione tag algoritmo con ranging manuale',...
             'Posizione tag algoritmo con ranging automatico','Calibrazione manuale','Calibrazione automatica','Location','southeast',...
             'Orientation','vertical');
lgb.FontSize = 6;
axis([-500 6000 -500 6000])
title('Posizione tag e ancore')
save_as( 'Posizione_ancore_tag_2D', 'IMMAGINI')


