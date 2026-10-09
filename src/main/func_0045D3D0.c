/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0041EF10(int, int, int);
extern int func_0045BDF0(int);

int func_0045D3D0(int a0, int a1, int a2) {
    int v0, v1;
    int cond;

    v1 = a2 & 65535;
    v0 = 0 + 19;
    cond = v1 != v0;
    if (cond) goto L0045D400;
    v0 = *(int*)(char*)(a0 + 232);
    cond = a1 != v0;
    if (cond) goto L0045D400;
    v0 = func_0045BDF0(a0);
    v0 = 0 + 1;
    goto L0045D408;
L0045D400:;
    v0 = func_0041EF10(a0, a1, a2);
L0045D408:;
    goto ret;
ret:
    return v0;
}
