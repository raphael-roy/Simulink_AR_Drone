% Copyright 2014 The MathWorks, Inc.

% these values were obtained by running PlayBack_Data and obtaining
% a running average value in different configurations :
% up_data -> average value for the axis which is anti-parallel with gravity (axis facing opposite of gravity)
% down_data -> average value for the axis which is parallel with gravity (axis facing the same way as gravity)
X_up_data = -1.001 ;
X_down_data = 0.9897 ;
Y_up_data = -0.9435 ;
Y_down_data = 1.07 ;
Z_up_data = -0.9956 ;
Z_down_data = 1.069 ;

all_up_data = [X_up_data Y_up_data Z_up_data] ;
all_down_data = [X_down_data Y_down_data Z_down_data] ;

Accel_Calib_Offset_Vector = 0.5*(all_up_data + all_down_data) ; % find the center of the 2 data
Accel_Calib_Gain_Vector = 0.5*(all_up_data - all_down_data) ; % find the gain which normalizes data to 1 or -1