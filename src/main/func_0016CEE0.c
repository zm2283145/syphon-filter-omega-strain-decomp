/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00138EA0(int, int, int, int);

int func_0016CEE0(int a0, int a1) {
    int loc[2];
    int a2, a3, v0;

    a3 = a1;
    a1 = a0;
    v0 = *(int*)(char*)(a0 + 8);
    a2 = (int)loc;
    *(int*)(char*)loc = v0;
    a0 = (int)((char*)loc + 4);
    v0 = func_00138EA0(a0, a1, a2, a3);
    goto ret;
ret:
    return v0;
}
