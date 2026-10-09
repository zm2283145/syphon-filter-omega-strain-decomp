/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void VecCurve_SetDamping(char* self, float value) {
    *(float*)(self + 80) = value;
}

void AngleCurve_SetDamping(char* self, float value) {
    *(float*)(self + 20) = value;
}
