/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00183B10(int, int);

int func_00231EC0(int a0, int a1) {
    int loc[1];
    int s0, v0, v1;

    v0 = *(int*)(char*)(a0 + 32);
    s0 = a1;
    a1 = (int)loc;
    *(int*)(char*)loc = v0;
    v0 = func_00183B10(a0, a1);
    v1 = s0 << 4;
    v0 = v0 + v1;
    goto ret;
ret:
    return v0;
}
