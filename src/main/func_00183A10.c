/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int ColTri_FilterStub(void) {
    int loc[1];
    int v0, v1;
    int cond;

    *(char*)(char*)loc = 0;
    v1 = (int)((char*)loc + 1);
    v0 = (int)((char*)loc + 4);
L00183A20:;
    *(char*)(char*)v1 = 0;
    v1 = v1 + 1;
    cond = v1 != v0;
    if (cond) goto L00183A20;
    v0 = *(unsigned char*)(char*)loc;
    goto ret;
ret:
    return v0;
}
