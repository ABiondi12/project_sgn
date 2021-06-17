%% Questo script esegue l'animazione di charlie 


ris_t		= 0.2;	%time step dell'animazione.
time_anim	= 0:ris_t:time_end;	% vettore temporale per l'animazione

figure(1000)
clf

for i = 1:length(time_anim)
	
	%start stuff
	time_now = time_anim(i);
	
	if i ~=1
		% delete plot handlers
		delete(trail_handl);
		delete(charlie_box);
		delete(charlie_dot);
		delete(charlie_tags);
		delete(tag0_handl);
		delete(tag1_handl);
	end
	
	
	% vicon
	col_vicon = [0,0,0];
	index_vicon = floor(mean(find(abs(charlie_vicon_pos(:,1) - time_now) < ris_t)));
	if ~(isempty(index_vicon) || isnan(index_vicon))
		trail_handl = plot(	charlie_vicon_pos(1:index_vicon, 2), charlie_vicon_pos(1:index_vicon, 3),...
							'c--');
		hold on
		[charlie_box, charlie_dot, charlie_tags] = draw_charlie(	...
												charlie_vicon_pos(index_vicon, 2:4), ...
												vicon_yaw(index_vicon,2), ...
												col_vicon);
	end
	%tag0
	index_tag0 = floor(mean(find(abs(tag0_pos(:,1) - time_now) < ris_t)));
	if ~(isempty(index_tag0) || isnan(index_tag0))
		hold on
		tag0_handl = plot(tag0_pos(index_tag0,2), tag0_pos(index_tag0,3), 'b*', 'MarkerSize', 6);
	end
	
	%tag1
	index_tag1 = floor(mean(find(abs(tag1_pos(:,1) - time_now) < ris_t)));
	if ~(isempty(index_tag1) || isnan(index_tag1))
		hold on
		tag1_handl = plot(tag1_pos(index_tag1,2), tag1_pos(index_tag1,3), 'r*', 'MarkerSize', 6);
	end
	
	
	%tag0_f
	index_tag0 = floor(mean(find(abs(tag0_f_pos(:,1) - time_now) < ris_t)));
	if ~(isempty(index_tag0) || isnan(index_tag0))
		hold on
		tag0_handl = plot(tag0_f_pos(index_tag0,2), tag0_f_pos(index_tag0,3), 'bd', 'MarkerSize', 3);
	end
	
	%tag1_f
	index_tag1 = floor(mean(find(abs(tag1_f_pos(:,1) - time_now) < ris_t)));
	if ~(isempty(index_tag1) || isnan(index_tag1))
		hold on
		tag1_handl = plot(tag1_f_pos(index_tag1,2), tag1_f_pos(index_tag1,3), 'rd', 'MarkerSize', 3);
	end
	
	%end stuff
	hold off
	xlim([0, 5])
	ylim([0.5, 3.5])
	axis equal
	grid on
	title_str = sprintf("Animazione, tempo: %5.2f s di %5.2f ", time_now, time_end);
	title(title_str)
	drawnow
	
end