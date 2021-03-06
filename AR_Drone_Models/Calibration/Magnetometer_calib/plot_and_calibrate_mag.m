% Copyright 2014 The MathWorks, Inc.
function MagCurveFit_Results_Struct = plot_and_calibrate_mag(MagData)
close all

Mag_3d = MagData.signals.values;


Mag_X = Mag_3d(:,1);
Mag_Y = Mag_3d(:,2);
Mag_Z = Mag_3d(:,3);
shiftx = 1;
shifty = 2;
shiftz = 3;
% scatter(Mag_X,Mag_Z)

plot3(Mag_X,Mag_Y,Mag_Z, '.r' )


[ MagCurveFit_Results_Struct.center, MagCurveFit_Results_Struct.radii, evecs, v ] = ellipsoid_fit( [Mag_X Mag_Y Mag_Z ] );
fprintf( 'Ellipsoid center: %.3g %.3g %.3g\n', MagCurveFit_Results_Struct.center );
fprintf( 'Ellipsoid radii : %.3g %.3g %.3g\n', MagCurveFit_Results_Struct.radii );
fprintf( 'Ellipsoid evecs :\n' );
fprintf( '%.3g %.3g %.3g\n%.3g %.3g %.3g\n%.3g %.3g %.3g\n', ...
    evecs(1), evecs(2), evecs(3), evecs(4), evecs(5), evecs(6), evecs(7), evecs(8), evecs(9) );
fprintf( 'Algebraic form  :\n' );
fprintf( '%.3g ', v );
fprintf( '\n' );

% draw data
plot3( Mag_X, Mag_Y, Mag_Z, '.r' );
hold on;

%draw fit
maxd = max( [  800  ] );
step = maxd / 50;
[ x, y, z ] = meshgrid( -maxd:step:maxd + shiftx, -maxd:step:maxd + shifty, -maxd:step:maxd + shiftz );

Ellipsoid = v(1) *x.*x +   v(2) * y.*y + v(3) * z.*z + ...
          2*v(4) *x.*y + 2*v(5)*x.*z + 2*v(6) * y.*z + ...
          2*v(7) *x    + 2*v(8)*y    + 2*v(9) * z;
p = patch( isosurface( x, y, z, Ellipsoid, 1 ) );
set( p, 'FaceColor', 'g', 'EdgeColor', 'none' );
view( -70, 40 );
axis vis3d;
camlight;
lighting phong;


%---------------------------------
%attempt to transform to sphere?
%---------------------------------
hold on
transformed_data = evecs'*[Mag_X' - MagCurveFit_Results_Struct.center(1) ;Mag_Y' - MagCurveFit_Results_Struct.center(2);Mag_Z' - MagCurveFit_Results_Struct.center(3)]; %-  repmat(center,1,length(Mag_X));
% plot3(transformed_data(1,:), transformed_data(2,:),transformed_data(3,:),'.g')

%% try fitting transformed data to see what it looks like:




%unit_sphere(:, k) = (raw(:, k) - c)./r

figure
unit_sphere = diag((1./MagCurveFit_Results_Struct.radii))*(Mag_3d(:,:) - repmat(MagCurveFit_Results_Struct.center',length(Mag_X),1))';
plot3(unit_sphere(1,:),unit_sphere(2,:),unit_sphere(3,:),'.r')

end

%% first run
% Ellipsoid center: -1.26 20.1 65.4
% Ellipsoid radii : 158 145 136
% Ellipsoid evecs :
% 0.532 -0.842 -0.0856
% 0.369 0.322 -0.872
% 0.762 0.432 0.483
% Algebraic form  :
% 6.42e-05 5.66e-05 6.39e-05 7.25e-06 3.65e-06 1.11e-06 -0.000304 -0.0012 -0.0042 

%% 2nd run

% Ellipsoid center: 4.32 24.5 66.6
% Ellipsoid radii : 155 145 137
% Ellipsoid evecs :
% -0.222 -0.962 0.158
% 0.446 -0.245 -0.861
% 0.867 -0.121 0.484
% Algebraic form  :
% 6.8e-05 5.59e-05 6.42e-05 -2.37e-06 3.43e-06 6.83e-07 -0.000464 -0.00141 -0.00431 

%% third run

% Ellipsoid center: 2.16 1.02 70.6
% Ellipsoid radii : 144 122 116
% Ellipsoid evecs :
% -0.283 0.809 0.515
% -0.956 -0.194 -0.221
% -0.079 -0.555 0.828
% Algebraic form  :
% 9.91e-05 8.51e-05 0.0001 7.12e-06 3.66e-06 -1.65e-05 -0.00048 0.00106 -0.00706 

%% in MW Cafeteria
% Ellipsoid center: 2.93 18.9 77.5
% Ellipsoid radii : 167 135 132
% Ellipsoid evecs :
% 0.782 -0.622 0.0272
% 0.359 0.486 0.797
% -0.509 -0.614 0.604
% Algebraic form  :
% 6.77e-05 7.49e-05 8.63e-05 1.58e-05 -1.99e-06 -1.14e-06 -0.000343 -0.00137 -0.00666 


%% home drone:
% Ellipsoid center: -23.5 16.2 6.94
% Ellipsoid radii : 196 164 140
% Ellipsoid evecs :
% -0.321 0.259 0.911
% -0.264 0.899 -0.349
% -0.91 -0.352 -0.22
% Algebraic form  :
% 4.93e-05 3.94e-05 2.95e-05 5.68e-06 6.32e-06 -1.59e-06 0.00102 -0.000493 -3e-05 

%% home drone 2:
% Ellipsoid center: -23 4.3 1.44
% Ellipsoid radii : 187 163 139
% Ellipsoid evecs :
% 0.258 0.275 0.926
% 0.866 0.36 -0.348
% -0.429 0.891 -0.145
% Algebraic form  :
% 4.04e-05 4.92e-05 3.09e-05 -6.24e-06 -1.23e-06 -4.18e-06 0.000956 -0.000349 -5.48e-05 


%% home drone 3
% 
% Ellipsoid center: -13.4 8.16 9.09
% Ellipsoid radii : 149 138 136
% Ellipsoid evecs :
% -0.507 -0.855 -0.11
% 0.735 -0.496 0.463
% 0.45 -0.154 -0.88
% Algebraic form  :
% 5.19e-05 4.81e-05 5.47e-05 -3.31e-06 -1.1e-06 -4.54e-07 0.000733 -0.000432 -0.000508 