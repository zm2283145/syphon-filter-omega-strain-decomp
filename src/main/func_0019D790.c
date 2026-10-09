/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0019D580(int, int);

float AnimChannel_GetCurrentValue(int a0) {
    int a1, v0;
    float f0;

    a0 = a0 + 136;
    v0 = func_0019D580(a0, a1);
    f0 = *(float*)(char*)(v0 + 8);
    goto ret;
ret:
    return f0;
}

float AnimChannel_GetCurrent(int a0, int a1) {
    return *(float*)((char*)(*(int*)((char*)a0 + 128) + (((a1 << 4) - a1) << 2)) + 8);
}
