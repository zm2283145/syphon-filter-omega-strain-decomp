/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497800[];
extern int func_00443E70(void);
extern int func_00449A00(int);

int func_0044A1D0(int a0) {
    int at, s0, s1, v0, v1;
    int cond;

    s0 = *(int*)(char*)(a0 + 9608);
    s1 = a0;
    v0 = func_00443E70();
    cond = s0 == 0;
    v1 = v0 - s0;
    if (cond) goto L0044A208;
    v0 = *(int*)(char*)D_00497800;
    at = v0 < v1;
    cond = at == 0;
    if (cond) goto L0044A210;
L0044A208:;
    a0 = s1;
    v0 = func_00449A00(a0);
L0044A210:;
    v0 = *(unsigned char*)(char*)(s1 + 9820);
    goto ret;
ret:
    return v0;
}

int func_0044A230(int a0) {
    int at, s0, s1, v0, v1;
    int cond;

    s0 = *(int*)(char*)(a0 + 9608);
    s1 = a0;
    v0 = func_00443E70();
    cond = s0 == 0;
    v1 = v0 - s0;
    if (cond) goto L0044A268;
    v0 = *(int*)(char*)D_00497800;
    at = v0 < v1;
    cond = at == 0;
    if (cond) goto L0044A270;
L0044A268:;
    a0 = s1;
    v0 = func_00449A00(a0);
L0044A270:;
    v0 = *(unsigned char*)(char*)(s1 + 9821);
    goto ret;
ret:
    return v0;
}
