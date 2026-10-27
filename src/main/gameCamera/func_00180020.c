/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Adds *delta to the floats at +0x04, +0x08, +0x10, +0x18 and +0x20. */
void cSplinedMotion_float_TeleportByDelta(char* self, float* delta) {
    *(float*)(self + 4) = *(float*)(self + 4) + *delta;
    *(float*)(self + 8) = *(float*)(self + 8) + *delta;
    *(float*)(self + 16) = *(float*)(self + 16) + *delta;
    *(float*)(self + 24) = *(float*)(self + 24) + *delta;
    *(float*)(self + 32) = *(float*)(self + 32) + *delta;
}

float cSplinedMotion_Scalar_InitPos(void) {
    return 0.0f;
}

float cSplinedMotion_Scalar_ZeroVel(void) {
    return 0.0f;
}
