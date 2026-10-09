/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0048C3E4[];
extern char D_0048C400[];

int func_002CF018(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_0048C3E4;
    cond = v0 == 0;
    if (cond) goto L002CF034;
    v0 = ((int (*)(void))v0)();
L002CF034:;
    v0 = 0 + 22;
    goto ret;
ret:
    return v0;
}

int func_002CF048(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_0048C400;
    cond = v0 == 0;
    if (cond) goto L002CF064;
    v0 = ((int (*)(void))v0)();
L002CF064:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}
