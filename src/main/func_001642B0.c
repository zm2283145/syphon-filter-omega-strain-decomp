/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00164150(int, int);

void func_001642B0(int a0, int a1) {
    int loc[1];
    int v0;

    a0 = a0 + 44;
    *(int*)(char*)loc = a1;
    a1 = (int)loc;
    v0 = func_00164150(a0, a1);
    goto ret;
ret:;
}
