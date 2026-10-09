/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004AB5B0[];
extern char D_004DD9D0[];
extern int func_00128BD0(int, int, int, int, int, int, int, int, float, float, float, float, float, float, float, float);
extern void func_0041F690(int);

int func_002A8740(int a0, int a1, int a2) {
    int a3, s0, t0, t1, t2, t3, v0;
    float f12, f13, f14, f15, f16, f17, f18, f19;

    a3 = a1;
    a1 = (int)D_004AB5B0;
    s0 = a2;
    a2 = a0;
    a0 = s0;
    v0 = func_00128BD0(a0, a1, a2, a3, t0, t1, t2, t3, f12, f13, f14, f15, f16, f17, f18, f19);
    v0 = s0;
    goto ret;
ret:
    return v0;
}

int func_002A8780(int a0) {
    func_0041F690(a0);
    *(int*)((char*)a0) = (int)D_004DD9D0;
    *(int*)((char*)a0 + 88) = 0;
    *(int*)((char*)a0 + 92) = 0;
    *(int*)((char*)a0 + 96) = 0;
    *(int*)((char*)a0 + 100) = 0;
    *(int*)((char*)a0 + 104) = 0;
    *(int*)((char*)a0 + 108) = 0;
    *(int*)((char*)a0 + 112) = 0;
    *(int*)((char*)a0 + 116) = 0;
    *(int*)((char*)a0 + 120) = 0;
    *(int*)((char*)a0 + 124) = 0;
    *(int*)((char*)a0 + 128) = 0;
    *(int*)((char*)a0 + 132) = 0;
    *(int*)((char*)a0 + 136) = 0;
    *(int*)((char*)a0 + 140) = 0;
    *(int*)((char*)a0 + 144) = 0;
    *(int*)((char*)a0 + 72) = 0;
    *(int*)((char*)a0 + 76) = 0;
    *(int*)((char*)a0 + 80) = 0;
    *(int*)((char*)a0 + 84) = 0;
    return a0;
}
