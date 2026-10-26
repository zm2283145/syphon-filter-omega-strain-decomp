/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00497DD8[];
extern char D_00497DDC[];

int MediusUniqueCallbackSetLocalizationParamsResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DD8;
    cond = v0 == 0;
    if (cond) goto L0046DBE4;
    v0 = ((int (*)(void))v0)();
L0046DBE4:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}

int MediusUniqueCallbackSetMessageAsReadRequestHandler(void) {
    return 48;
}

int MediusUniqueCallbackSetMessageAsReadResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00497DDC;
    cond = v0 == 0;
    if (cond) goto L0046DC1C;
    v0 = ((int (*)(void))v0)();
L0046DC1C:;
    v0 = 0 + 28;
    goto ret;
ret:
    return v0;
}
