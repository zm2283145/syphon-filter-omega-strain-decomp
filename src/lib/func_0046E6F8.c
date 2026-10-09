/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497E1C[];
extern char D_00497E48[];
extern char D_00497E4C[];

int func_0046E6F8(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497E48;
    cond = v0 == 0;
    if (cond) goto L0046E714;
    v0 = ((int (*)(void))v0)();
L0046E714:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int func_0046E728(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497E4C;
    cond = v0 == 0;
    if (cond) goto L0046E744;
    v0 = ((int (*)(void))v0)();
L0046E744:;
    v0 = 0 + 12;
    goto ret;
ret:
    return v0;
}

int func_0046E758(void) {
    return 21;
}

int func_0046E760(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497E1C;
    cond = v0 == 0;
    if (cond) goto L0046E77C;
    v0 = ((int (*)(void))v0)();
L0046E77C:;
    v0 = 0 + 72;
    goto ret;
ret:
    return v0;
}
