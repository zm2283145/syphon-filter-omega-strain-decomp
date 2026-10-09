/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D60[];
extern char D_00497D64[];

int func_0046CEF8(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D60;
    cond = v0 == 0;
    if (cond) goto L0046CF14;
    v0 = ((int (*)(void))v0)();
L0046CF14:;
    v0 = 0 + 128;
    goto ret;
ret:
    return v0;
}

int func_0046CF28(void) {
    return 38;
}

int func_0046CF30(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D64;
    cond = v0 == 0;
    if (cond) goto L0046CF4C;
    v0 = ((int (*)(void))v0)();
L0046CF4C:;
    v0 = 0 + 72;
    goto ret;
ret:
    return v0;
}
