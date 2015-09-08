% Values come from calibration procedures

%% Accelerometer Calibration Structure

Accel_Calib_Offset_Vector = [-0.0056 0.0633 0.0367] ;
Accel_Calib_Gain_Vector = [-0.9954 -1.0068 -1.0323] ;
%Note, that gain might need to be multiplied by -1 depending on how the calibration.
%This is becaues -g is up and +g might be down if you look at the raw data.

%% Magnetometer calibration structure 
%Values for the magnetomer values come from the magnetometer calibration script
%which returns a struct of gain and offset values. Populate these pairs of
%values into the right entry values here
                                                 
Mag_Calib_Offset_Vector.Gain_X = -23;
Mag_Calib_Offset_Vector.Gain_Y = 4.3;
Mag_Calib_Offset_Vector.Gain_Z = 1.44;

Mag_Calib_Gain_Vector.Gain_X = 187;
Mag_Calib_Gain_Vector.Gain_Y = 163;
Mag_Calib_Gain_Vector.Gain_Z = 139;

%% Gyrometer_Temp calibration structure
%Parameters for polynomial fit of gyro drift versus temperature
% P1 = quadratic gain, P2 = multiply gain, P3 = offset

Gyro_Correction_Roll.P1 = 0 ;
Gyro_Correction_Roll.P2 = -0.0619 ;
Gyro_Correction_Roll.Offset = -8.7013 ;

Gyro_Correction_Pitch.P1 = 0 ;
Gyro_Correction_Pitch.P2 = 2.1842 ;
Gyro_Correction_Pitch.Offset = -86.9644 ;

Gyro_Correction_Yaw.P1 = 0 ;
Gyro_Correction_Yaw.P2 = -0.1189 ;
Gyro_Correction_Yaw.Offset = 5.2364 ;

%% Save & Clear
save ('Calibration_Parameters.mat','Accel_Calib_Offset_Vector','Accel_Calib_Gain_Vector','Mag_Calib_Offset_Vector','Mag_Calib_Gain_Vector','Gyro_Correction_Roll','Gyro_Correction_Pitch','Gyro_Correction_Yaw')
save ('../Flight_Models/Calibration_Parameters.mat','Accel_Calib_Offset_Vector','Accel_Calib_Gain_Vector','Mag_Calib_Offset_Vector','Mag_Calib_Gain_Vector','Gyro_Correction_Roll','Gyro_Correction_Pitch','Gyro_Correction_Yaw')
clear Accel_Calib_Offset_Vector
clear Accel_Calib_Gain_Vector
clear Mag_Calib_Offset_Vector
clear Mag_Calib_Gain_Vector
clear Gyro_Correction_Roll
clear Gyro_Correction_Pitch
clear Gyro_Correction_Yaw