/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFC04[];
extern int func_002CA160(int);

void func_0028A430(int a0) {
    int s0, v0, v1;
    int cond;

    v1 = *(unsigned char*)(char*)(a0 + 128);
    cond = v1 == 0;
    s0 = a0;
    if (cond) goto L0028A458;
    a0 = *(int*)(char*)D_004FFC04;
    v0 = func_002CA160(a0);
    *(char*)(char*)(s0 + 128) = 0;
L0028A458:;
    goto ret;
ret:;
}
