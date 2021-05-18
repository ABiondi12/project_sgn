function [ A0, A1, A2, A3 ] = rangesToPos( R_mis )
% RANGESTOPOS Returns the coordinates of points, elaborating the
% mean ranges, given as input.

    r01 = R_mis(1);
    r02 = R_mis(2);
    r03 = R_mis(3);
    r12 = R_mis(4);
    r13 = R_mis(5);
    r23 = R_mis(6);
    
    % angle [rad] between r01 and r02.
    % condition C is to verify that the ranges among A0 A1 A2 form a
    % triangle. Otherwise CARNOT FORMULA cannot be used to obtain the angles
    % and the estimated coordinates, corresponding to this set of ranges, are set to 0.
    % In this case discard the result.
    C = (r01^2+r02^2-r12^2)/(2*r01*r02);
    alpha = acos((r01^2+r02^2-r12^2)/(2*r01*r02));
    
    % angle [rad] between r01 and r12
    beta = acos((r01^2+r12^2-r02^2)/(2*r01*r12));
    
    % angle [rad] between r02 and r12
    gamma = acos((r02^2+r12^2-r01^2)/(2*r02*r12));
    
    % Assuming ANCHOR0 as the origin of the coordinate system A0 = [0 0 0]
    % and ANCHOR1 along (positive) Y axis, the Y axis direction is given by the
    % line passing through A0 and A1. As A0, A1, A2 must be placed at the same
    % height from the ground, A2 can be computed.
    if abs(C)<= 1
        
        A0 = [0 0 0];
        A1 = [0 r01 0]';
        y1 = A1(2);
        y2 = (r01^2 - r12^2 + r02^2)/ (2*r01);
        x2 = sqrt(r02^2 - y2^2);
        A2 = [x2 y2 0];
        
        % A3 COMPUTATION [x3 y3 z3]';
        y3 = (r03^2 - r13^2 + y1^2)/(2*y1);
        x3 = (x2^2 - 2*y3*y2 + y2^2 - r23^2 + r03^2)/(2*x2);
        z3 = sqrt(r03^2 - x3^2 - y3^2);
        A3 = [x3 y3 z3];
        
    else
        A0=[0 0 0];
        A1=[0 0 0];
        A2=[0 0 0];
        A3=[0 0 0];
    end



end

