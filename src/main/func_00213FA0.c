/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00213FE0(int);
extern int func_00214080(int);

int func_00213FA0(int a0) {
    int s0, v0;
    int cond;

    s0 = a0;
    v0 = func_00214080(a0);
    v0 = (unsigned int)0 < (unsigned int)v0;
    cond = v0 != 0;
    a0 = s0;
    if (cond) goto L00213FCC;
    v0 = func_00213FE0(a0);
    v0 = (unsigned int)0 < (unsigned int)v0;
L00213FCC:;
    goto ret;
ret:
    return v0;
}
