% Copyright 2014 The MathWorks, Inc.
% This script assumes that you have: 
% a) First collected data of gyro drift and temperature
% b) Ran the TempCorrect_OfflineTest to filter the data

close all
Ts = 1/400 ;
StartTime =10 ;
StartTick = StartTime/Ts ;

%% Correct for Roll Drift First

GyroDrift_Roll = Roll_Gyro_filtered.signals.values(StartTick:end,2);
TempMeasureRefined = FilteredTemp.signals.values(StartTick:end,2);
PlotName = 'Roll Drift Estimation';
[fitresult, gof] = createFit_Automate(TempMeasureRefined,GyroDrift_Roll,PlotName);

Gyro_Correction_Roll.P1 = 0; % or =fitresult.p1 if ft = fittype('poly2')
Gyro_Correction_Roll.P2 = fitresult.p1; % or =fitresult.p2 if ft = fittype('poly2')
Gyro_Correction_Roll.Offset = fitresult.p2; % or =fitresult.p3 if ft = fittype('poly2')

%% Correct for Pitch Drift 

GyroDrift_Pitch = Pitch_Gyro_filtered.signals.values(StartTick:end,2);
TempMeasureRefined = FilteredTemp.signals.values(StartTick:end,2);
PlotName = 'Pitch Drift Estimation';
[fitresult, gof] = createFit_Automate(TempMeasureRefined,GyroDrift_Pitch,PlotName);

Gyro_Correction_Pitch.P1 = 0; % or =fitresult.p1 if ft = fittype('poly2')
Gyro_Correction_Pitch.P2 = fitresult.p1; % or =fitresult.p2 if ft = fittype('poly2')
Gyro_Correction_Pitch.Offset = fitresult.p2; % or =fitresult.p3 if ft = fittype('poly2')

%% Correct Yaw Drift

GyroDrift_Yaw = Yaw_Gyro_filtered.signals.values(StartTick:end,2);
TempMeasureRefined = FilteredTemp.signals.values(StartTick:end,2);
PlotName = 'Yaw Drift Estimation';
[fitresult, gof] = createFit_Automate(TempMeasureRefined,GyroDrift_Yaw,PlotName);

Gyro_Correction_Yaw.P1 = 0; % or =fitresult.p1 if ft = fittype('poly2')
Gyro_Correction_Yaw.P2 = fitresult.p1; % or =fitresult.p2 if ft = fittype('poly2')
Gyro_Correction_Yaw.Offset = fitresult.p2; % or =fitresult.p3 if ft = fittype('poly2')
