/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497DB4[];
extern char D_00497DB8[];

int MediusUniqueCallbackLadderPositionFastResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DB4;
    cond = v0 == 0;
    if (cond) goto L0046D9F4;
    v0 = ((int (*)(void))v0)();
L0046D9F4:;
    v0 = 0 + 32;
    goto ret;
ret:
    return v0;
}

int MediusUniqueCallbackLadderListRequestHandler(void) {
    return 60;
}

int MediusUniqueCallbackLadderListResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DB8;
    cond = v0 == 0;
    if (cond) goto L0046DA2C;
    v0 = ((int (*)(void))v0)();
L0046DA2C:;
    v0 = 0 + 72;
    goto ret;
ret:
    return v0;
}
