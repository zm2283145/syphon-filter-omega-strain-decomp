/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFD30[];
extern int func_00147840(int, int);
extern int func_001861F0(int, int);

int func_00142AE0(int a0, int a1) {
    int s0, s1, v0, v1;

    v0 = a1 & 255;
    v0 = v0 << 4;
    v0 = a0 + v0;
    s0 = a0;
    a1 = *(int*)(char*)(v0 + 8);
    a0 = *(int*)(char*)D_004FFD30;
    s1 = v0 + 4;
    v0 = func_00147840(a0, a1);
    a0 = *(int*)(char*)(s0 + 136);
    a1 = *(int*)(char*)(v0 + 116);
    s0 = v0;
    v0 = func_001861F0(a0, a1);
    a0 = *(int*)(char*)(s0 + 112);
    v1 = *(int*)(char*)(s1 + 12);
    v0 = a0 * v0;
    v0 = v0 - v1;
    goto ret;
ret:
    return v0;
}
