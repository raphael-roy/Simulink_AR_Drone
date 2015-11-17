/*
 * File: Navigation_KF_Subsystem_child_types.h
 *
 * Code generated for Simulink model 'Navigation_KF_Subsystem_child'.
 *
 * Model version                  : 1.63
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Nov 17 10:17:47 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Navigation_KF_Subsystem_child_types_h_
#define RTW_HEADER_Navigation_KF_Subsystem_child_types_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#ifndef _DEFINED_TYPEDEF_FOR_Drone_StateModeType_
#define _DEFINED_TYPEDEF_FOR_Drone_StateModeType_

typedef enum {
  Drone_StateModeType_None = 0,        /* Default value */
  Drone_StateModeType_WaitForHost,
  Drone_StateModeType_Controlled_Flight,
  Drone_StateModeType_Landing_Sequence,
  Drone_StateModeType_Landing_Terminate
} Drone_StateModeType;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_Measurement_Calculation_Bus_
#define _DEFINED_TYPEDEF_FOR_Measurement_Calculation_Bus_

typedef struct {
  real_T UltraSound_Calculation;
  real_T AccelNorm_Calculation[3];
  real_T Gyro_Calculation[3];
  real_T Magnetometer_Calculation[3];
} Measurement_Calculation_Bus;

#endif

/* Parameters (auto storage) */
typedef struct P_Navigation_KF_Subsystem_chi_T_ P_Navigation_KF_Subsystem_chi_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Navigation_KF_Subsyst_T RT_MODEL_Navigation_KF_Subsys_T;

#endif                                 /* RTW_HEADER_Navigation_KF_Subsystem_child_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
