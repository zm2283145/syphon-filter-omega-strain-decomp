/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004BCEE8[];
extern char D_00542C90[];

int func_003B9BD0(void) {
    int loc[1];
    int v0, v1;
    int cond;

    v0 = *(signed char*)(char*)D_00542C90;
    cond = v0 != 0;
    if (cond) goto L003B9C08;
    v0 = 0x1800000;
    v1 = (int)loc;
    *(int*)(char*)loc = v0;
    v1 = *(int*)(char*)v1;
    v0 = 0 + 1;
    *(char*)(char*)D_00542C90 = v0;
    v0 = v1 + -1;
    *(int*)(char*)D_004BCEE8 = v0;
L003B9C08:;
    v0 = *(int*)(char*)D_004BCEE8;
    goto ret;
ret:
    return v0;
}
