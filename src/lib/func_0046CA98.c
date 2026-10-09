/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D10[];
extern char D_00497D1C[];

int func_0046CA98(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D1C;
    cond = v0 == 0;
    if (cond) goto L0046CAB4;
    v0 = ((int (*)(void))v0)();
L0046CAB4:;
    v0 = 0 + 460;
    goto ret;
ret:
    return v0;
}

int func_0046CAC8(void) {
    return 432;
}

int func_0046CAD0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D10;
    cond = v0 == 0;
    if (cond) goto L0046CAEC;
    v0 = ((int (*)(void))v0)();
L0046CAEC:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}
