/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D8C[];
extern char D_00497D90[];

int MediusUniqueCallbackSetGameListFilterResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D8C;
    cond = v0 == 0;
    if (cond) goto L0046D1A4;
    v0 = ((int (*)(void))v0)();
L0046D1A4:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int MediusUniqueCallbackClearGameListFilterRequestHandler(void) {
    return 44;
}

int MediusUniqueCallbackClearGameListFilterResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D90;
    cond = v0 == 0;
    if (cond) goto L0046D1DC;
    v0 = ((int (*)(void))v0)();
L0046D1DC:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}
