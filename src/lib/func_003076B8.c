/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0030EBC8(int);

int func_003076B8(int a0) {
    int v0;
    int cond;

    v0 = 0 + 2;
    cond = a0 == 0;
    if (cond) goto L003076D4;
    a0 = *(int*)((char*)a0 + 8);
    v0 = func_0030EBC8(a0);
    v0 = 0;
L003076D4:;
    goto ret;
ret:
    return v0;
}
