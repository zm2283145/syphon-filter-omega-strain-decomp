/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497DEC[];

int func_0046E588(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DEC;
    cond = v0 == 0;
    if (cond) goto L0046E5A4;
    v0 = ((int (*)(void))v0)();
L0046E5A4:;
    v0 = 0 + 36;
    goto ret;
ret:
    return v0;
}
