/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003CB1C0(int);
extern int func_003CC820(int);
extern int func_003E67C0(int, int, int, int, float);
extern int func_003E6910(int, int, int, int, int, float);

int func_003E64D0(int a0) {
    int loc[1];
    int a1, a2, a3, s0, s1, t0, v0;
    float f12;

    v0 = *(int*)(char*)(a0 + 12);
    s0 = a0;
    *(int*)(char*)loc = v0;
    s1 = *(signed char*)(char*)(a0 + 4);
    a0 = *(int*)(char*)a0;
    v0 = func_003CB1C0(a0);
    a0 = *(int*)(char*)(s0 + 8);
    s0 = v0;
    v0 = func_003CC820(a0);
    a3 = *(int*)(char*)loc;
    a2 = v0;
    v0 = 0xbf800000;
    a0 = s0;
    f12 = -1.0f;
    a1 = s1;
    t0 = 0;
    v0 = func_003E6910(a0, a1, a2, a3, t0, f12);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_003E6540(int a0) {
    int a1, a2, a3, s0, s1, v0;
    float f12;

    s1 = *(signed char*)(char*)(a0 + 4);
    s0 = a0;
    a0 = *(int*)(char*)a0;
    v0 = func_003CB1C0(a0);
    a0 = *(int*)(char*)(s0 + 8);
    s0 = v0;
    v0 = func_003CC820(a0);
    a2 = v0;
    a0 = s0;
    v0 = 0xbf800000;
    a1 = s1;
    f12 = -1.0f;
    a3 = 0;
    v0 = func_003E67C0(a0, a1, a2, a3, f12);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
