clear all

% Load Simulink Parameters Reference
load ../Config_Set.mat

% Load constants needed for "TempCorrect_Offline" Simulink
Gyro_Correction_Pitch.Offset = 0 ;
Gyro_Correction_Pitch.P1 = 0 ;
Gyro_Correction_Pitch.P2 = 0 ;
Gyro_Correction_Roll.Offset = 0 ;
Gyro_Correction_Roll.P1 = 0 ;
Gyro_Correction_Roll.P2 = 0 ;
Gyro_Correction_Yaw.Offset = 0 ;
Gyro_Correction_Yaw.P1 = 0 ;
Gyro_Correction_Yaw.P2 = 0 ;


% Load IMU Bus Object
LibPath = which('AR_Drone_2_Library') ;
MagicValue = regexp(LibPath,'AR_Drone_2_Library.slx') ;
load([LibPath(1:(MagicValue-1)) 'Save_IMU_struct.mat'])
clear MagicValue
clear LibPath