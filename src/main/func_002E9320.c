/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0048C4CD[];
extern int String_Copy(int, int);

int func_002E9320(int a0) {
    int a1, v0;
    int cond;

    v0 = 0 + 23;
    cond = a0 == 0;
    if (cond) goto L002E9340;
    a1 = (int)D_0048C4CD;
    v0 = String_Copy(a0, a1);
    v0 = 0;
L002E9340:;
    goto ret;
ret:
    return v0;
}
