/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void Curve_ForceWOne(int a0) {
    int v1;

    v1 = 0x3f800000;
    *(int*)(char*)(a0 + 44) = v1;
    goto ret;
ret:;
}
