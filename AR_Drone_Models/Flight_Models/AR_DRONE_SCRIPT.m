% Copyright 2014 The MathWorks, Inc.
%-------------------------------
% AR DRONE 2.0 Code Generation Data Dictionary
%-------------------------------
clear all

% DEFINE IP ADRESS OF HOST MACHINE FOR UDP RECEIVING
Host_IP_Adress = '192.168.1.5' ;

%load Sensor Data Bus
load SensorDataBus.mat

%load Simulink Parameters Reference
load Config_Set.mat

%load IMU Bus Object
LibPath = which('AR_Drone_2_Library');
MagicValue = regexp(LibPath,'AR_Drone_2_Library.slx');
load([LibPath(1:(MagicValue-1)) 'Save_IMU_struct.mat'])
clear MagicValue
clear LibPath

%load Calibration Parameters
load Calibration_Parameters.mat
