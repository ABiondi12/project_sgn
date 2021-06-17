% plot ancore UWB vs Vicon

% anchors position measured using UWB system, expressed in UWB frame
anchor0_uwb = [0.0		0.0 	0.0];
anchor1_uwb = [0.0		2.997 	0.0];	% y axis direction
anchor2_uwb = [5.121	-0.527	0.0];	% x axis direction
anchor3_uwb = [0.875	1.165 	1.295];

anchor0_uwb_2D = anchor0_uwb(1:2);
anchor1_uwb_2D = anchor1_uwb(1:2);		% y axis direction
anchor2_uwb_2D = anchor2_uwb(1:2);		% x axis direction
anchor3_uwb_2D = anchor3_uwb(1:2);		

% anchors position measured using Vicon system, expressed in UWB frame
anchor0_Vic = [0.000000	0.000000	0.000000];
anchor1_Vic = [0.000000	3.168643	0.032111];		% y axis direction
anchor2_Vic = [5.378095	-0.063190	-0.047064];		% x axis direction
anchor3_Vic = [0.826354	1.129845	1.239518];

anchor0_Vic_2D = anchor0_Vic(1:2);
anchor1_Vic_2D = anchor1_Vic(1:2);					% y axis direction
anchor2_Vic_2D = anchor2_Vic(1:2);					% x axis direction
anchor3_Vic_2D = anchor3_Vic(1:2);

axis_lim_full = [-0.5, 6, -0.7, 4];		% per vedere tutta la mappa
id_plot = 1;

figure('Name', ['figure ', num2str(id_plot), ' Anchors position: UWB vs Vicon'], 'NumberTitle','off'); id_plot = id_plot + 1;
clf
hold on
	plot(anchor0_uwb_2D(1),	anchor0_uwb_2D(2),	'k*', 'Markersize', 10,	'Linewidth', 1, 'DisplayName', 'Anchor 0 UWB')
	plot(anchor1_uwb_2D(1),	anchor1_uwb_2D(2),	'm*', 'Markersize', 10,	'Linewidth', 1, 'DisplayName', 'Anchor 1 UWB')
	plot(anchor2_uwb_2D(1),	anchor2_uwb_2D(2),	'c*', 'Markersize', 10,	'Linewidth', 1, 'DisplayName', 'Anchor 2 UWB')
	plot(anchor3_uwb_2D(1),	anchor3_uwb_2D(2),	'b*', 'Markersize', 10,	'Linewidth', 1, 'DisplayName', 'Anchor 3 UWB')
	plot(anchor0_Vic_2D(1),	anchor0_Vic_2D(2),	'kd', 'Markersize', 10,	'Linewidth', 1, 'DisplayName', 'Anchor 0 Vic')
	plot(anchor1_Vic_2D(1),	anchor1_Vic_2D(2),	'md', 'Markersize', 10,	'Linewidth', 1, 'DisplayName', 'Anchor 1 Vic')
	plot(anchor2_Vic_2D(1),	anchor2_Vic_2D(2),	'cd', 'Markersize', 10,	'Linewidth', 1, 'DisplayName', 'Anchor 2 Vic')
	plot(anchor3_Vic_2D(1),	anchor3_Vic_2D(2),	'bd', 'Markersize', 10,	'Linewidth', 1, 'DisplayName', 'Anchor 3 Vic')
	plot([anchor0_Vic_2D(1) anchor0_Vic_2D(1)], [anchor0_Vic_2D(2) anchor0_Vic_2D(2)+4], 'g--', 'Linewidth', 1, 'DisplayName', 'y axis UWB')
	plot([anchor0_uwb_2D(1) anchor0_uwb_2D(1)+6], [anchor0_uwb_2D(2) anchor0_uwb_2D(2)], 'r--', 'Linewidth', 1, 'DisplayName', 'x axis UWB')	
	hold off
	axis(axis_lim_full)
	grid on
	box on
	legend('Location', 'Best')

	title('Anchors position frame UWB: UWB vs Vicon')

