/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D58[];
extern char D_00497D5C[];

int func_0046CE78(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D58;
    cond = v0 == 0;
    if (cond) goto L0046CE94;
    v0 = ((int (*)(void))v0)();
L0046CE94:;
    v0 = 0 + 144;
    goto ret;
ret:
    return v0;
}

int func_0046CEA8(void) {
    return 80;
}

int func_0046CEB0(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D5C;
    cond = v0 == 0;
    if (cond) goto L0046CECC;
    v0 = ((int (*)(void))v0)();
L0046CECC:;
    v0 = 0 + 112;
    goto ret;
ret:
    return v0;
}
