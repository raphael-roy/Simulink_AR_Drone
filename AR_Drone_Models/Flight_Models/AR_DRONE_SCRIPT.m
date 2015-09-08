% Copyright 2014 The MathWorks, Inc.
%-------------------------------
% AR DRONE 2.0 Code Generation Data Dictionary
%-------------------------------
clear all

%load Navigation Bus Data Objects
load Navigation_Gain_Bus.mat

%load Sensor Data Bus
load SensorDataBus.mat

%load Simulink Parameters Reference
load Config_Set.mat

%Load offset corrections from Rate Gyro Temperature Drift experiment
% load GyroDrift_OffsetCorrections.mat

%Load IMU Bus Object
LibPath = which('AR_Drone_2_Library');
MagicValue = regexp(LibPath,'AR_Drone_2_Library.slx');
load([LibPath(1:(MagicValue-1)) 'Save_IMU_struct.mat'])
clear MagicValue
clear LibPath


%% All Variant Subsystems
% VariantChoice.SubSystem1=2;
% SubSystem1 = 1;

%% Calibration Parameters
load Calibration_Parameters.mat

%% Declare Navigation Offset and Gain Data Objects

%Magnetometer
Magnetometer_Calib_Offset = Simulink.Parameter; %should make bus exported global
Magnetometer_Calib_Offset.DataType ='Bus: Navigation_Gain_Bus';
Magnetometer_Calib_Offset.Value  = Mag_Calib_Offset_Vector;
Magnetometer_Calib_Offset.CoderInfo.StorageClass = 'ExportedGlobal';

Magnetometer_Calib_Gain = Simulink.Parameter; %should make bus exported global
Magnetometer_Calib_Gain.DataType ='Bus: Navigation_Gain_Bus';
Magnetometer_Calib_Gain.Value  = Mag_Calib_Gain_Vector;
Magnetometer_Calib_Gain.CoderInfo.StorageClass = 'ExportedGlobal';


% Accelerometer 
Accel_Calib_Offset = Simulink.Parameter; %should make bus exported global
Accel_Calib_Offset.DataType ='Bus: Navigation_Gain_Bus';
Accel_Calib_Offset.Value  = struct('Gain_X',Accel_Calib_Offset_Vector(1),'Gain_Y',Accel_Calib_Offset_Vector(2),'Gain_Z',Accel_Calib_Offset_Vector(3));
Accel_Calib_Offset.CoderInfo.StorageClass = 'ExportedGlobal';

Accel_Calib_Gain = Simulink.Parameter; %should make bus exported global
Accel_Calib_Gain.DataType ='Bus: Navigation_Gain_Bus';
Accel_Calib_Gain.Value  = struct('Gain_X',Accel_Calib_Gain_Vector(1),'Gain_Y',Accel_Calib_Gain_Vector(2),'Gain_Z',Accel_Calib_Gain_Vector(3));
Accel_Calib_Gain.CoderInfo.StorageClass = 'ExportedGlobal';


% RateGyro Temperature
Gyro_Calib_Temp_X = Simulink.Parameter; %should make bus exported global
Gyro_Calib_Temp_X.DataType ='Bus: Gyro_Offset_Bus';
Gyro_Calib_Temp_X.Value  = Gyro_Correction_Roll;
Gyro_Calib_Temp_X.CoderInfo.StorageClass = 'ExportedGlobal';

Gyro_Calib_Temp_Y = Simulink.Parameter; %should make bus exported global
Gyro_Calib_Temp_Y.DataType ='Bus: Gyro_Offset_Bus';
Gyro_Calib_Temp_Y.Value  = Gyro_Correction_Pitch;
Gyro_Calib_Temp_Y.CoderInfo.StorageClass = 'ExportedGlobal';

Gyro_Calib_Temp_Z = Simulink.Parameter; %should make bus exported global
Gyro_Calib_Temp_Z.DataType ='Bus: Gyro_Offset_Bus';
Gyro_Calib_Temp_Z.Value  = Gyro_Correction_Yaw;
Gyro_Calib_Temp_Z.CoderInfo.StorageClass = 'ExportedGlobal';



%% All Control Gains

