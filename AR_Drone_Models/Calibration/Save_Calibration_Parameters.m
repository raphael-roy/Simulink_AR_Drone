% Values come from calibration procedures

%% Accelerometer Calibration Structure

% Calibration Values (gains and offsets) from a 360 degrees calibration
Accelerometer_360deg_calibration = Simulink.Parameter;
Accelerometer_360deg_calibration.Value = struct('Gains',[-0.9954 -1.0068 -1.0323],'Offsets',[-0.0056 0.0633 0.0367]);
Accelerometer_360deg_calibration.StorageClass = 'ExportedGlobal';
Accelerometer_360deg_calibration.CoderInfo.CustomStorageClass = 'Const';
%Note, that gain might need to be multiplied by -1 depending on how the calibration.
%This is becaues -g is up and +g might be down if you look at the raw data.

% Offsets values from a quick calibration, when the drone is perfectly horizontal
Accelerometer_quick_calibration = [0.003485 ; 0.008674 ; -0.9985];

%% Magnetometer calibration structure 
%Values for the magnetomer values come from the magnetometer calibration script
%which returns a struct of gain and offset values. Populate these pairs of
%values into the right entry values here
                                                 
% Mag_Calib_Offset_Vector.Gain_X = -23;
% Mag_Calib_Offset_Vector.Gain_Y = 4.3;
% Mag_Calib_Offset_Vector.Gain_Z = 1.44;
% 
% Mag_Calib_Gain_Vector.Gain_X = 187;
% Mag_Calib_Gain_Vector.Gain_Y = 163;
% Mag_Calib_Gain_Vector.Gain_Z = 139;

Magnetometer_calibration = Simulink.Parameter;
Magnetometer_calibration.Value = struct('Gains',[0 0 0.00971],'Offsets',[-0.7020 0.7059 -0.1563]);
Magnetometer_calibration.StorageClass = 'ExportedGlobal';
Magnetometer_calibration.CoderInfo.CustomStorageClass = 'Const';

%% Gyrometer_Temp calibration structure
%Parameters for polynomial fit of gyro drift versus temperature
% P1 = quadratic gain, P2 = multiply gain, P3 = offset

% Gyro_Correction_Roll.P1 = 0 ;
% Gyro_Correction_Roll.P2 = -0.0619 ;
% Gyro_Correction_Roll.Offset = -8.7013 ;
% 
% Gyro_Correction_Pitch.P1 = 0 ;
% Gyro_Correction_Pitch.P2 = 2.1842 ;
% Gyro_Correction_Pitch.Offset = -86.9644 ;
% 
% Gyro_Correction_Yaw.P1 = 0 ;
% Gyro_Correction_Yaw.P2 = -0.1189 ;
% Gyro_Correction_Yaw.Offset = 5.2364 ;

% Offsets values from a quick calibration, when the drone is perfectly horizontal
Gyrometer_quick_calibration = [-10.63 ; 2.778 ; -0.1868] ;

%% Save & Clear

save ('../Flight_Models/Calibration_Parameters.mat','Accelerometer_360deg_calibration','Accelerometer_quick_calibration','Magnetometer_calibration','Gyrometer_quick_calibration')
save ('Calibration_Parameters.mat','Accelerometer_360deg_calibration','Accelerometer_quick_calibration','Magnetometer_calibration','Gyrometer_quick_calibration')
clear all