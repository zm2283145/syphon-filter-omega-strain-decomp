/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003F24A0(int, int, int, int);
extern int func_003F29B0(int, int);

int func_003F1860(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return func_003F24A0(a0, (tmp1 + (tmp0 << 3)), 1, a1);
}

int func_003F1880(int a0, int a1) {
    return func_003F29B0(a0, a1);
}
