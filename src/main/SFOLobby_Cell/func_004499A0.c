/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497800[];
extern int func_00443E70(void);
extern int func_00449A00(int);

void func_004499A0(int a0) {
    int at, s0, s1, v0, v1;
    int cond;

    s0 = *(int*)(char*)(a0 + 9608);
    s1 = a0;
    v0 = func_00443E70();
    cond = s0 == 0;
    a0 = v0 - s0;
    if (cond) goto L004499D8;
    v1 = *(int*)(char*)D_00497800;
    at = v1 < a0;
    cond = at == 0;
    if (cond) goto L004499E0;
L004499D8:;
    a0 = s1;
    v0 = func_00449A00(a0);
L004499E0:;
    goto ret;
ret:;
}
