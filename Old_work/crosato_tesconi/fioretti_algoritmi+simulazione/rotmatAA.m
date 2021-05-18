function [ R_ ] = rotmatAA( axis, ang )
% ROTMATAA 
% Genera la matrice di rotazione relativa all'angolo e all'asse
% specificati.

nSkew = [0,      -axis(3),   axis(2);
        axis(3),    0,      -axis(1);
        -axis(2),  axis(1),   0    ];

nKro = [axis(1)*axis(1), axis(1)*axis(2), axis(1)*axis(3);
        axis(2)*axis(1), axis(2)*axis(2), axis(2)*axis(3);  
        axis(3)*axis(1), axis(3)*axis(2), axis(3)*axis(3)];
    
R_ = nKro + (eye(3) - nKro)*cos(ang) + nSkew*sin(ang);

end

