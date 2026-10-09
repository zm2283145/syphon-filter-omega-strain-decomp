/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_002B5F48(int, int);

void func_0040D5D0(void) {
    int loc[2];
    int a0, a1, v0;
    int cond;

L0040D5D8:;
    a0 = (int)((char*)loc + 4);
    a1 = (int)loc;
    v0 = func_002B5F48(a0, a1);
    cond = v0 == 0;
    if (cond) goto L0040D5D8;
    goto ret;
ret:;
}
