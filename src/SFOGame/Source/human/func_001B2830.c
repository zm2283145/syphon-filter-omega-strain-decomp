/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* VecCurve_GetPrevious(char* self) {
    return self + 16;
}

void* cSplinedMotion_cVector_GetCurrVal(char* self) {
    return self + 32;
}
