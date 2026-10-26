/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005984D0[];
extern char D_005984D4[];

int MediusUniqueCallbackFileGetMetaDataResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_005984D0;
    cond = v0 == 0;
    if (cond) goto L0046E424;
    v0 = ((int (*)(void))v0)();
L0046E424:;
    v0 = 0 + 512;
    goto ret;
ret:
    return v0;
}

int MediusUniqueCallbackFileSearchByMetaDataRequestHandler(void) {
    return 333;
}

int MediusUniqueCallbackFileSearchByMetaDataResponseHandler(void) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_005984D4;
    cond = v0 == 0;
    if (cond) goto L0046E45C;
    v0 = ((int (*)(void))v0)();
L0046E45C:;
    v0 = 0 + 512;
    goto ret;
ret:
    return v0;
}
