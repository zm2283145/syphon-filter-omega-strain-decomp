/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497D3C[];

int MediusUniqueCallbackJoinGameRequestHandler(void) {
    return 196;
}

int MediusUniqueCallbackJoinGameResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497D3C;
    cond = v0 == 0;
    if (cond) goto L0046CC8C;
    v0 = ((int (*)(void))v0)();
L0046CC8C:;
    v0 = 0 + 188;
    goto ret;
ret:
    return v0;
}
