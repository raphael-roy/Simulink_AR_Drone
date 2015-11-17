/*
 * File: Navigation_KF_Subsystem_child_private.h
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

#ifndef RTW_HEADER_Navigation_KF_Subsystem_child_private_h_
#define RTW_HEADER_Navigation_KF_Subsystem_child_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
# define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

extern P_Navigation_KF_Subsystem_chi_T Navigation_KF_Subsystem_child_P;

#endif                                 /* RTW_HEADER_Navigation_KF_Subsystem_child_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
