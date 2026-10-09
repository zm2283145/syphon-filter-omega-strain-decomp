/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005381F0[];
extern char D_00538C60[];
extern int func_003E7670(int);

int func_0027A7F0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)D_00538C60;
    *(int*)((char*)((int)D_005381F0 + (tmp0 * 272)) + 736) = 0;
    *(int*)((char*)((int)D_005381F0 + (tmp0 * 272)) + 744) = 1120403456;
    *(char*)((char*)((int)D_005381F0 + (tmp0 * 272)) + 758) = 1;
    *(char*)((char*)((int)D_005381F0 + (tmp0 * 272)) + 756) = 1;
    tmp1 = *(int*)(char*)a0;
    return func_003E7670(tmp1);
}
