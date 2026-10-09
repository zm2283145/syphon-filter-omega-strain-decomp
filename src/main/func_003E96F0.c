/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_003E8180(int, int);
extern void func_003E9A60(int);
extern float func_003F44E0(int, float);
extern void func_003F45A0(int, float);

void func_003E96F0(int a0) {
    int tmp2;

    func_003E9A60((a0 + 112));
    tmp2 = *(int*)((char*)a0 + 96);
    func_003E8180(tmp2, (a0 + 112));
}

void func_003E9730(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 96);
    func_003F45A0(tmp0, 0.0f);
    *(char*)((char*)a0 + 132) = 1;
}

void func_003E9770(int a0) {
    int s0, v1;
    float f0, f12;

    f12 = 0.0f;
    s0 = a0;
    a0 = *(int*)(char*)(a0 + 96);
    f0 = func_003F44E0(a0, f12);
    v1 = 0 + 1;
    *(char*)(char*)(s0 + 132) = v1;
    goto ret;
ret:;
}

void func_003E97B0(int a0, int a1, int a2) {
    *(int*)((char*)a0 + 104) = *(int*)(char*)a1;
    *(char*)((char*)a0 + 100) = 1;
    *(int*)((char*)a0 + 128) = a2;
}
