/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00413370(int a0, int a1) {
    int v0;
    int cond;

    cond = a1 < 0;
    v0 = a1 < 20;
    if (cond) goto L00413380;
    cond = v0 != 0;
    if (cond) goto L00413388;
L00413380:;
    v0 = 0;
    goto L004133A0;
L00413388:;
    v0 = a1 << 1;
    v0 = v0 + a1;
    v0 = v0 << 3;
    v0 = v0 + a0;
    v0 = *(int*)(char*)(v0 + 12);
L004133A0:;
    goto ret;
ret:
    return v0;
}
