%% Questo script esegue l'animazione di charlie nella stanza del volo con il sistema Vicon in funzione


ris_t		= 0.2;				%time step dell'animazione.
time_anim	= 0:ris_t:time_end;	% vettore temporale per l'animazione

figure(1000)
clf
show(map)

flag_tag_center = 0;	% flag diventa 1 appena si ha il primo disegno di un tag_center
flag_amcl		= 0;	% flag diventa 1 appena si ha il primo disegno di un amcl
flag_vicon		= 0;	% flag diventa 1 appena si ha il primo disegno di un Vicon_pos

for i = 1:length(time_anim)
	
	%start stuff
	time_now = time_anim(i);
	
	% vicon
	col_vicon = [0,0,0];
	index_vicon = floor(mean(find(abs(charlie_vicon_pos(:,1) - time_now) < ris_t)));
	if ~(isempty(index_vicon) || isnan(index_vicon))
		if flag_vicon == 1
			delete(box_vicon)
			delete(dot_vicon)
			delete(tags_vicon)
		else
			flag_vicon = 1;
		end
		
		hold on
		trail_handl = plot(	charlie_vicon_pos(1:index_vicon, 2), charlie_vicon_pos(1:index_vicon, 3),...
							'c--');
		hold on
		[box_vicon, dot_vicon, tags_vicon] =	draw_charlie(	...
													charlie_vicon_pos(index_vicon, 2:4), ...
													vicon_yaw(index_vicon,2), ...
													col_vicon);
	end
	
	% amcl
	col_amcl = [1,0,0];
% 	index_amcl = floor(mean(find(abs(amcl_pose_pos(:,1) - time_now) < ris_t)));
	index_amcl = floor(mean(find(abs(robot_pos(:,1) - time_now) < ris_t)));
	if ~(isempty(index_amcl) || isnan(index_amcl))
		if flag_amcl == 1
			delete(box_amcl)
			delete(dot_amcl)
			delete(tags_amcl)
		else
			flag_amcl = 1;
		end
		
		hold on
% 		[box_amcl, dot_amcl, tags_amcl] = draw_charlie(		amcl_pose_pos(index_amcl,2:end),...
% 															amcl_heading(index_amcl,2),...
% 															col_amcl);
		
		[box_amcl, dot_amcl, tags_amcl] = draw_charlie(		[robot_pos(index_amcl,2), robot_pos(index_amcl,3), 0],...
															robot_or(index_amcl,2),...
															col_amcl);
		
	end
	
	%tag_center
	col_tag_center = [0,0,1];
	index_tag_center = floor(mean(find(abs(tag_center_pos(:,1) - time_now) < ris_t)));
	if ~(isempty(index_tag_center) || isnan(index_tag_center))
		if flag_tag_center == 1
			delete(box_tag)
			delete(dot_tag)
			delete(tags_tag)
			delete(trail_tag)
		else
			flag_tag_center = 1;
		end
		
		hold on
		trail_tag = plot(tag_center_pos(1:index_tag_center,2), tag_center_pos(1:index_tag_center,3), 'b--');
		hold on
		[box_tag, dot_tag, tags_tag] = draw_charlie(	tag_center_pos(index_tag_center,2:end),...
																tag_center_heading(index_tag_center,2:end),...
																col_tag_center);
															
	end

	%end stuff
	hold off
	
	
	axis equal
	axis_lim_zoom = [-2, 3, -2, 3];		% per vedere solo il tracciato
	axis_lim_full = [-4, 6, -3, 3];		% per vedere tutta la mappa
	axis(axis_lim_full)
	
	grid on
	title_str = sprintf("Animazione, tempo: %5.2f s di %5.2f ", time_now, time_end);
	title(title_str)
	drawnow
	
end