/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00414790(void);
extern int func_00418E00(int, int, int);
extern int func_0041F090(int);

void func_0029EF30(int a0) {
    int a1, a2, s0, s1, v0;
    int cond;

    s1 = a0;
    v0 = func_0041F090(a0);
    s0 = *(int*)(char*)(s1 + 264);
    cond = s0 == 0;
    if (cond) goto L0029EF70;
    v0 = func_00414790();
    a1 = s0;
    a0 = v0;
    a2 = 0;
    v0 = func_00418E00(a0, a1, a2);
    *(int*)(char*)(s1 + 264) = 0;
L0029EF70:;
    goto ret;
ret:;
}
