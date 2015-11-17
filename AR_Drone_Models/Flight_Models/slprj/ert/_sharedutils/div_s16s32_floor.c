/*
 * File: div_s16s32_floor.c
 *
 * Code generated for Simulink model 'AR_Drone_Flight_Control'.
 *
 * Model version                  : 1.1216
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Nov 17 10:18:08 2015
 */

#include "rtwtypes.h"
#include "div_s16s32_floor.h"

int16_T div_s16s32_floor(int32_T numerator, int32_T denominator)
{
  int16_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? (int32_T)MAX_int16_T : (int32_T)MIN_int16_T;

    /* Divide by zero handler */
  } else {
    absNumerator = (uint32_T)(numerator >= 0 ? numerator : -numerator);
    absDenominator = (uint32_T)(denominator >= 0 ? denominator : -denominator);
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? (int32_T)(int16_T)-(int32_T)
      tempAbsQuotient : (int32_T)(int16_T)tempAbsQuotient;
  }

  return quotient;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
