/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern float func_00192740(float, float, float);

int func_001EFE10(int a0, float f12, float f13) {
    int s0, v0;
    float f0, f14;

    v0 = 0x3f800000;
    f14 = 1.0f;
    *(float*)(char*)a0 = f12;
    *(float*)(char*)(a0 + 4) = f13;
    f12 = *(float*)(char*)a0;
    f13 = 0.0f;
    s0 = a0;
    f0 = func_00192740(f12, f13, f14);
    *(float*)(char*)s0 = f0;
    v0 = 0x3f800000;
    f13 = *(float*)(char*)s0;
    f14 = 1.0f;
    f12 = *(float*)(char*)(s0 + 4);
    f0 = func_00192740(f12, f13, f14);
    *(float*)(char*)(s0 + 4) = f0;
    v0 = s0;
    goto ret;
ret:
    return v0;
}
