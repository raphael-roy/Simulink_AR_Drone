/*
 * File: fkngnophecjebaai_norm.c
 *
 * Code generated for Simulink model 'Navigation_KF_Subsystem_child'.
 *
 * Model version                  : 1.63
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Nov 17 10:17:47 2015
 */

#include "rtwtypes.h"
#include <math.h>
#include "fkngnophecjebaai_norm.h"

/* Function for MATLAB Function: '<S26>/Compensate  for Magnetic Declination  (~67 degrees in Boston)_2' */
real_T fkngnophecjebaai_norm(const real_T x[2])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 2.2250738585072014E-308;
  absxk = fabs(x[0]);
  if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
