/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

float func_00319D08(int a0, int a1, int a2, int a3) {
    float f0, f1;

    a2 = (unsigned int)a0 < (unsigned int)a2;
    if (a2 == 0) a0 = 0;
    a0 = a0 << 3;
    a1 = a1 + a0;
    f0 = *(float*)(char*)a1;
    *(float*)(char*)a3 = f0;
    f1 = *(float*)((char*)a1 + 4);
    *(float*)((char*)a3 + 4) = f1;
    goto ret;
ret:
    return f0;
}
