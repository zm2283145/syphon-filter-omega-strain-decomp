/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

float func_00319C88(int a0, int a1, int a2) {
    float f0;

    a1 = a2 < a1;
    if (a1 == 0) a2 = 0;
    a2 = a2 << 2;
    a2 = a2 + a0;
    f0 = *(float*)(char*)a2;
    goto ret;
ret:
    return f0;
}
