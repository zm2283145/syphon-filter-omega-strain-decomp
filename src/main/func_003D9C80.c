/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003D9CC0(int, int);
extern int func_003E04C0(int);

void func_003D9C80(int a0, int a1) {
    int loc[1];
    int s0, v0;

    s0 = a0;
    a0 = a1;
    v0 = func_003E04C0(a0);
    a0 = s0;
    *(int*)(char*)loc = v0;
    a1 = (int)loc;
    v0 = func_003D9CC0(a0, a1);
    goto ret;
ret:;
}
