/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497DFC[];
extern char D_0059849C[];

int func_0046DD18(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DFC;
    cond = v0 == 0;
    if (cond) goto L0046DD34;
    v0 = ((int (*)(void))v0)();
L0046DD34:;
    v0 = 0 + 208;
    goto ret;
ret:
    return v0;
}

int func_0046DD48(void) {
    return 36;
}

int func_0046DD50(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_0059849C;
    cond = v0 == 0;
    if (cond) goto L0046DD6C;
    v0 = ((int (*)(void))v0)();
L0046DD6C:;
    v0 = 0 + 476;
    goto ret;
ret:
    return v0;
}
