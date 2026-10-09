/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0013B480(int, int);
extern float func_001D10A0(float, float);

int func_001F12D0(int a0, int a1) {
    func_0013B480(a0, a1);
    return a0;
}

int func_001F1300(int a0, float f12, float f13) {
    int s0, v0;
    float f0;

    *(float*)(char*)a0 = f12;
    *(float*)(char*)(a0 + 4) = f13;
    f12 = *(float*)(char*)a0;
    f13 = 0.0f;
    s0 = a0;
    f0 = func_001D10A0(f12, f13);
    *(float*)(char*)s0 = f0;
    f13 = *(float*)(char*)s0;
    f12 = *(float*)(char*)(s0 + 4);
    f0 = func_001D10A0(f12, f13);
    *(float*)(char*)(s0 + 4) = f0;
    v0 = s0;
    goto ret;
ret:
    return v0;
}
