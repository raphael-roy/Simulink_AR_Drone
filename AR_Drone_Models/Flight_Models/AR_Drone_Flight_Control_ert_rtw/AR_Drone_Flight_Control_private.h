/*
 * File: AR_Drone_Flight_Control_private.h
 *
 * Code generated for Simulink model 'AR_Drone_Flight_Control'.
 *
 * Model version                  : 1.1216
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Nov 17 10:18:08 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AR_Drone_Flight_Control_private_h_
#define RTW_HEADER_AR_Drone_Flight_Control_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error "Code was generated for compiler with different sized uchar/char. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compiler's limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, which will disable the preprocessor word size checks."
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error "Code was generated for compiler with different sized ushort/short. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized uint/int. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized ulong/long. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

extern void AR_Drone_Flig_AxisRotZeroR3(const real_T rtu_In1[7], real_T *rty_1,
  real_T *rty_2, real_T *rty_3);
extern void AR_Drone_Fli_AxisRotDefault(const real_T rtu_In1[7], real_T *rty_1,
  real_T *rty_2, real_T *rty_3);
extern void AR_Drone_Flig_MatrixReOrder(const real_T rtu_M_in[9],
  B_MatrixReOrder_AR_Drone_Flig_T *localB);
extern void AR_Drone_Flight_Phipi_Start(real_T rty_VRRot_Pi[3], real_T
  *rty_VRRot_Pi_d, P_Phipi_AR_Drone_Flight_Contr_T *localP);
extern void AR_Drone_Flight_Contr_Phipi(const real_T rtu_u[9], real_T
  rty_VRRot_Pi[3], real_T *rty_VRRot_Pi_d, P_Phipi_AR_Drone_Flight_Contr_T
  *localP, real_T rtp_maxzero);
extern void AR_Drone_Flight_Generalcase(real_T rtu_Traceu, const real_T rtu_u[9],
  real_T rty_VRRot_General[3], real_T *rty_VRRot_General_c,
  P_Generalcase_AR_Drone_Flight_T *localP);
extern void AR_Dr_Altitude_Control_Init(RT_MODEL_AR_Drone_Flight_Cont_T * const
  AR_Drone_Flight_Control_M, DW_Altitude_Control_AR_Drone__T *localDW,
  P_Altitude_Control_AR_Drone_F_T *localP);
extern void AR_Drone_F_Altitude_Control(RT_MODEL_AR_Drone_Flight_Cont_T * const
  AR_Drone_Flight_Control_M, const real_T rtu_HeightFeedback[2], real_T
  rtu_refHeight, B_Altitude_Control_AR_Drone_F_T *localB,
  DW_Altitude_Control_AR_Drone__T *localDW, P_Altitude_Control_AR_Drone_F_T
  *localP);
extern void AR_Dr_Attitude_Control_Init(RT_MODEL_AR_Drone_Flight_Cont_T * const
  AR_Drone_Flight_Control_M, DW_Attitude_Control_AR_Drone__T *localDW,
  P_Attitude_Control_AR_Drone_F_T *localP);
extern void AR_D_Attitude_Control_Start(B_Attitude_Control_AR_Drone_F_T *localB,
  P_Attitude_Control_AR_Drone_F_T *localP);
extern void AR_Drone_F_Attitude_Control(RT_MODEL_AR_Drone_Flight_Cont_T * const
  AR_Drone_Flight_Control_M, const real_T rtu_EulerAngle_Feedback_Deg[3], const
  real_T rtu_Desired_Attitude_Deg[3], const real_T rtu_RateGyro_Feedback_Deg[3],
  real_T rtu_Motor_Armed, B_Attitude_Control_AR_Drone_F_T *localB,
  DW_Attitude_Control_AR_Drone__T *localDW, P_Attitude_Control_AR_Drone_F_T
  *localP);
extern void AR_Drone__Motor_Mixing_Init(DW_Motor_Mixing_AR_Drone_Flig_T *localDW);
extern void AR_Drone_Motor_Mixing_Start(B_Motor_Mixing_AR_Drone_Fligh_T *localB,
  P_Motor_Mixing_AR_Drone_Fligh_T *localP);
extern void AR_Drone_Fligh_Motor_Mixing(real_T rtu_LandingPhase, real_T
  rtu_Motor_Armed, int16_T rtu_throttle, const int16_T rtu_RPYCmd[3],
  B_Motor_Mixing_AR_Drone_Fligh_T *localB, DW_Motor_Mixing_AR_Drone_Flig_T
  *localDW, P_Motor_Mixing_AR_Drone_Fligh_T *localP);
extern void AR_Drone_Flight__Chart_Init(DW_Chart_AR_Drone_Flight_Cont_T *localDW);
extern void AR_Drone_Flight_Contr_Chart(boolean_T rtu_if_transition, real_T
  rtu_HoldDataTicks, B_Chart_AR_Drone_Flight_Contr_T *localB,
  DW_Chart_AR_Drone_Flight_Cont_T *localDW);

#endif                                 /* RTW_HEADER_AR_Drone_Flight_Control_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
