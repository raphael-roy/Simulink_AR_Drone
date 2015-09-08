clear all

% Load Simulink Parameters Reference
load ../Config_Set.mat

% Load constants needed for "PlayBack_Data" Simulink
load ../Calibration_Parameters.mat
clear Accel_Calib_Offset_Vector
clear Accel_Calib_Gain_Vector
clear Mag_Calib_Offset_Vector
clear Mag_Calib_Gain_Vector

% Load IMU Bus Object
LibPath = which('AR_Drone_2_Library') ;
MagicValue = regexp(LibPath,'AR_Drone_2_Library.slx') ;
load([LibPath(1:(MagicValue-1)) 'Save_IMU_struct.mat'])
clear MagicValue
clear LibPath