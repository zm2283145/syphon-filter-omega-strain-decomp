/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0025F270(int, int, int);

void func_0025F230(int a0) {
    int a1, a2, v0, v1;
    int cond;

    v1 = 0 + 1;
    a2 = *(int*)(char*)a0;
    cond = a2 == v1;
    v1 = 0 + 2;
    if (cond) goto L0025F250;
    cond = a2 != v1;
    if (cond) goto L0025F258;
L0025F250:;
    a2 = 0 + 1;
    v0 = func_0025F270(a0, a1, a2);
L0025F258:;
    goto ret;
ret:;
}
