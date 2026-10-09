/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D08[];
extern char D_00497D0C[];

int func_0046CA28(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D08;
    cond = v0 == 0;
    if (cond) goto L0046CA44;
    v0 = ((int (*)(void))v0)();
L0046CA44:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int func_0046CA58(void) {
    return 108;
}

int func_0046CA60(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D0C;
    cond = v0 == 0;
    if (cond) goto L0046CA7C;
    v0 = ((int (*)(void))v0)();
L0046CA7C:;
    v0 = 0 + 32;
    goto ret;
ret:
    return v0;
}
