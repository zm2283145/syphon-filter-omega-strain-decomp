/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_002E47B0(int);
extern int func_002E5860(int);

void func_002E4A00(void) {
    int a0, v0;
    int cond;

    a0 = 0;
    v0 = func_002E47B0(a0);
    cond = v0 != 0;
    a0 = 0;
    if (cond) goto L002E4A20;
    v0 = func_002E5860(a0);
L002E4A20:;
    goto ret;
ret:;
}
