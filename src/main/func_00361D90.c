/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DF350[];
extern int func_00298690(int);
extern int func_0033D580(int);

int func_00361D90(int a0) {
    int s0, s1, v0, v1;

    s1 = a0;
    v0 = func_0033D580(a0);
    s0 = s1 + 136;
    v0 = (int)D_004DF350;
    a0 = s0 + 48;
    *(int*)(char*)s1 = v0;
    v0 = func_00298690(a0);
    a0 = s0 + 60;
    v0 = func_00298690(a0);
    v1 = 0 + 8;
    v0 = s1;
    *(int*)(char*)(s1 + 132) = v1;
    *(int*)(char*)(s1 + 252) = 0;
    goto ret;
ret:
    return v0;
}
