/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00282D90(int a0) {
    int loc[1];
    int v0;
    float f0;
    int cond;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)a0;
    v0 = *(int*)(char*)(v0 + 108);
    cond = v0 == 0;
    f0 = *(float*)(char*)loc;
    if (cond) goto L00282DB0;
    *(float*)(char*)(v0 + 44) = f0;
L00282DB0:;
    v0 = 0;
    goto ret;
ret:
    return v0;
}
