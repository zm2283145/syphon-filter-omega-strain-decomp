/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D28[];
extern char D_00497D48[];

int func_0046CD28(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D48;
    cond = v0 == 0;
    if (cond) goto L0046CD44;
    v0 = ((int (*)(void))v0)();
L0046CD44:;
    v0 = 0 + 104;
    goto ret;
ret:
    return v0;
}

int func_0046CD58(void) {
    return 44;
}

int func_0046CD60(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D28;
    cond = v0 == 0;
    if (cond) goto L0046CD7C;
    v0 = ((int (*)(void))v0)();
L0046CD7C:;
    v0 = 0 + 332;
    goto ret;
ret:
    return v0;
}
