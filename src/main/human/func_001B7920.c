/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

void cSplinedMotion_cVector_SetDamp(char* self, float value) {
    *(float*)(self + 80) = value;
}

void cSplinedMotion_float_SetDamp(CurveChannel* self, float value) {
    self->damping = value;
}
