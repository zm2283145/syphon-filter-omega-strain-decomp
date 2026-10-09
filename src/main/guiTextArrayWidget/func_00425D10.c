/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00414790(void);
extern int func_00418420(int, int);
extern int func_00426590(int, int, int);

void func_00425D10(void) {
    int a0, a1, a2, v0, v1;
    int cond;

    v0 = func_00426590(a0, a1, a2);
    cond = v0 == 0;
    if (cond) goto L00425D38;
    a0 = *(int*)(char*)(v0 + 12);
    v1 = 0 + -3;
    v1 = a0 & v1;
    *(int*)(char*)(v0 + 12) = v1;
L00425D38:;
    goto ret;
ret:;
}

void func_00425D50(int a0, int a1, int a2, int a3) {
    int s0, s1, v0, v1;
    int cond;

    s1 = a3;
    v0 = func_00426590(a0, a1, a2);
    s0 = v0;
    cond = s0 == 0;
    if (cond) goto L00425D98;
    v0 = func_00414790();
    a1 = s1;
    a0 = v0;
    v0 = func_00418420(a0, a1);
    *(int*)(char*)(s0 + 20) = v0;
    v1 = *(int*)(char*)(s0 + 12);
    v1 = v1 | 2;
    *(int*)(char*)(s0 + 12) = v1;
L00425D98:;
    goto ret;
ret:;
}
