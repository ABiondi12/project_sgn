function [ A0_, A1_, A2_, A3_ ] = rangesToPos( R_mis )
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
        A0 = [0 0 0]';
        A1 = [0 r01 0]';
        A2 = [r02*sin(alpha) r02*cos(alpha) 0]';
        
        % A3 COMPUTATION [x3 y3 z3]';
        syms y3
        x3 = (A2(1)^2-r23^2+(y3-A2(2))^2+r03^2-y3^2)/(2*A2(1));
        z3_2 = r03^2-x3^2-y3^2; % z3_2 is z3 squared
        eqn = sqrt(x3^2+(y3-A1(2))^2+z3_2)==r13;
        solY = solve(eqn, y3);
        solX = (A2(1)^2-r23^2+(solY-A2(2))^2+r03^2-solY^2)/(2*A2(1));
        solY;
        solZ = sqrt(r03^2-solX^2-solY^2);
        
        A0_= A0;
        A1_= A1;
        A2_= A2;
        A3_ = [double(solX) double(solY) double(solZ)]';
        C;
    else
        A0_=[0 0 0];
        A1_=[0 0 0];
        A2_=[0 0 0];
        A3_=[0 0 0];
    end

end

