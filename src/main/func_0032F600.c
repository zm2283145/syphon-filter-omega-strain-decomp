/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0049D010[];
extern int func_00185C70(int);
extern int func_00333B10(int, int);

int func_0032F600(int a0, int a1) {
    int s0, v0, v1;
    int cond;

    v1 = *(int*)(char*)(a0 + 76);
    v0 = *(int*)(char*)D_0049D010;
    cond = v1 != v0;
    s0 = a1;
    if (cond) goto L0032F63C;
    v0 = func_00185C70(a0);
    a1 = s0;
    a0 = v0;
    v0 = func_00333B10(a0, a1);
    goto L0032F644;
L0032F63C:;
    v0 = 0;
L0032F644:;
    goto ret;
ret:
    return v0;
}
