%% set current figure
f_width		= 1200;
f_heigth	= 650;
dim_font	= 13;

FolderName = 'fig_biologi';   % Your destination folder
figHandles = findall(0,'Type','figure');
for iFig = 1:length(figHandles)
	current_fig = figHandles(iFig);
	set(current_fig, 'Position',  [200, 0, f_width, f_heigth])
	set(findall(current_fig,'type','text'),'FontSize', dim_font)           
%	set(gca,'FontSize', dim_font) 

	filename = ['figure' num2str(iFig) '.png'];
	exportgraphics(current_fig, filename, 'BackgroundColor','white', 'ContentType','image')
%	exportgraphics(f, filename, 'BackgroundColor','none', 'ContentType','image') 
end
%% supersizeme
% fh = figure(24);
% supersizeme(1.5, fh)
