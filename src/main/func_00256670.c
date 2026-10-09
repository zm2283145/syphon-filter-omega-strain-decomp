/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFBD0[];
extern void func_00171050(int, int, int, int);
extern void func_003CDBE0(int);

void func_00256670(int a0) {
    int a1, a2, a3, s0;
    int cond;

    s0 = a0;
    func_003CDBE0(a0);
    a1 = *(int*)(char*)(s0 + 764);
    cond = a1 == 0;
    if (cond) goto L002566A0;
    a2 = s0;
    a0 = *(int*)(char*)D_004FFBD0;
    a3 = 0;
    func_00171050(a0, a1, a2, a3);
L002566A0:;
    goto ret;
ret:;
}
