/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003A74E0(int, int, int, int, int);

void func_003A80F0(int a0) {
    int loc[1];
    int a1, a2, a3, t0, v0;

    a1 = 0 + 4;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    a3 = 0;
    a0 = 0 + 11;
    t0 = 0;
    v0 = func_003A74E0(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}
