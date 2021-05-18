function [ P ] = rotateSet( A0, A1R, A2R, A3R )
%ROTATESET

% Consider the point A given from the projection of A1R on the xy plane.
A = [A1R(1) A1R(2) 0];

% Rotation axis
axis = normr(cross(A1R, A));

alpha = acos(norm(A)/norm(A1R));

R_1 = rotmatAA(axis, alpha);

% Rotation of point A1R to align to A
A1Rproj = R_1*A1R';

% Rotation around Z axis to align A1R to A1, requires finding the angle
% between A1Rproj and its projection on Y axis.

condY = A1Rproj(2);
B = [0 condY 0];
theta = acos(norm(B)/norm(A1Rproj));

if condY < 0
    angZ = pi + (A1Rproj(1)*A1Rproj(2))/abs(A1Rproj(1)*A1Rproj(2))*theta;
else
    angZ = (A1Rproj(1)*A1Rproj(2))/abs(A1Rproj(1)*A1Rproj(2))*theta;
end

R_2 = rotmatAA([0, 0, 1], angZ);

A1Rfin = R_2*A1Rproj;

% To guarantee that the reconstruction of A0 A1 A2 mantains them at the
% same height from the ground, another rotation is needed.
% First verify which are the coords for all the other points, applying the
% same transformation.

A2RR = R_2*R_1*A2R';
A3RR = R_2*R_1*A3R';

axis3 = normr(cross(A2RR, [0 1 0]));
nu = acos(axis3(3));

if axis3(1)>0
    R_3 = rotmatAA([0, 1, 0], -nu);
else
    R_3 = rotmatAA([0, 1, 0], nu);
end

A2Rfin = R_3*R_2*R_1*A2R';
A3Rfin = R_3*R_2*R_1*A3R';

P = [A0', A1Rfin, A2Rfin, A3Rfin]';

end

