/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_003E8180(int, int);
extern void func_003E9A60(int);
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
