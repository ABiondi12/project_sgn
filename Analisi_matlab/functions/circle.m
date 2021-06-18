function out = circle(centre, rad, n)

    % compute points on circumference
	th = [0:n-1]'/ n*2*pi;
    x = rad*cos(th) + centre(1);
    y = rad*sin(th) + centre(2);

    out = [x y]';

    end
