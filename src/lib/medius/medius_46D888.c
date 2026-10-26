/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D00[];
extern char D_00497D20[];

int MediusUniqueCallbackAccountDeleteResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D20;
    cond = v0 == 0;
    if (cond) goto L0046D8A4;
    v0 = ((int (*)(void))v0)();
L0046D8A4:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int MediusUniqueCallbackAccountGetIDRequestHandler(void) {
    return 70;
}

int MediusUniqueCallbackAccountGetIDResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D00;
    cond = v0 == 0;
    if (cond) goto L0046D8DC;
    v0 = ((int (*)(void))v0)();
L0046D8DC:;
    v0 = 0 + 32;
    goto ret;
ret:
    return v0;
}
