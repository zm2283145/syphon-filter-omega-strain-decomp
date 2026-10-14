/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D14[];
extern char D_00497D18[];

int func_0046CB08(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D14;
    cond = v0 == 0;
    if (cond) goto L0046CB24;
    v0 = ((int (*)(void))v0)();
L0046CB24:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int func_0046CB38(void) {
    return 294;
}

int func_0046CB40(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D18;
    cond = v0 == 0;
    if (cond) goto L0046CB5C;
    v0 = ((int (*)(void))v0)();
L0046CB5C:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}
