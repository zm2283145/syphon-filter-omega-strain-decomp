/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001748F0(int, int, int);

int func_00173D20(int a0, int a1, int a2) {
    int loc[2];
    int s0, v0;

    *(int*)(char*)a0 = 0;
    s0 = a0;
    *(int*)(char*)(a0 + 4) = 0;
    *(int*)(char*)(a0 + 8) = 0;
    *(int*)(char*)loc = a2;
    a2 = (int)loc;
    *(char*)((char*)loc + 4) = 0;
    v0 = func_001748F0(a0, a1, a2);
    v0 = s0;
    goto ret;
ret:
    return v0;
}
