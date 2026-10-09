/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00182260(int, int);

int func_00182120(int a0, int a1) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a1;
    *(int*)(char*)loc = v0;
    a1 = (int)loc;
    v0 = func_00182260(a0, a1);
    goto ret;
ret:
    return v0;
}
