/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00175FA0(int);
extern int func_0022E080(int, int, int);
extern int func_003CC820(int);

int func_0022E030(int a0) {
    int loc[1];
    int a1, a2, s0, v0;

    v0 = *(int*)(char*)(a0 + 8);
    s0 = a0;
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = func_00175FA0(a0);
    a0 = *(int*)(char*)(s0 + 4);
    s0 = v0;
    v0 = func_003CC820(a0);
    a2 = *(int*)(char*)loc;
    a0 = s0;
    a1 = v0;
    v0 = func_0022E080(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
