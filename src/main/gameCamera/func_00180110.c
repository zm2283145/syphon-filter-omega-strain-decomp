/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Sets the float at +0x2C to 1.0f. */
void cSplinedMotion_Vector_FixUpResultOfSplineEvaluation(char* self) {
    *(float*)(self + 44) = 1.0f;
}
