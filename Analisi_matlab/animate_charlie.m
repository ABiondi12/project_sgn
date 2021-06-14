%% Questo script esegue l'animazione di charlie


ris_t		= 0.2;	%time step dell'animazione.
time_anim	= 0:ris_t:time_end;	% vettore temporale per l'animazione



figure(1000)
clf
for i = 1:length(time_anim)
	
	%start stuff
	time_now = time_anim(i);
	if i ~=1
		% delete(charlie_box)
	end
	
	
	% vicon
	index_vicon = floor(mean(find(abs(charlie_vicon_pos(:,1) - time_now) < ris_t)));
	charlie_box = draw_charlie( charlie_vicon_pos(index_vicon, 2:4), vicon_yaw(index_vicon,2));
	
	hold on
	%tag
	
	% DA FINIRE
	
	
	
	
	%end stuff
	hold off
	xlim([-5, 5])
	ylim([-5, 5])
	axis equal
	grid on
	title_str = sprintf("Animazione, tempo: %5.2f s di %5.2f ", time_now, time_end);
	title(title_str)
	drawnow
	
end