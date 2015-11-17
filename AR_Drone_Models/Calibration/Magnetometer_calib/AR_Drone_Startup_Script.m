clear all

% Load Simulink Parameters Reference
load ../Config_Set.mat

% Load IMU Bus Object
LibPath = which('AR_Drone_2_Library') ;
MagicValue = regexp(LibPath,'AR_Drone_2_Library.slx') ;
load([LibPath(1:(MagicValue-1)) 'Save_IMU_struct.mat'])
clear MagicValue
clear LibPath