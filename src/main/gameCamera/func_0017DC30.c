/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* cHermiteSplineControlPoint_cVector_Position(void* self) {
    return self;
}

/* Address of 32-byte element i. */
char* cArray_FixedSize_cHermiteSplineControlPoint_cVector_2_opIndex(char* base, int i) {
    return base + (i << 5);
}

float cHermiteSplineWithScaledDuration_cVector_Duration(char* self) {
    return *(float*)(self + 64);
}
