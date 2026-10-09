/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00301B40(int a0, int a1) {
    int v0, v1;
    int cond;

    cond = a0 == 0;
    v0 = 0 + 2;
    if (cond) goto L00301B6C;
    cond = a1 == 0;
    if (cond) goto L00301B6C;
    v1 = *(unsigned char*)(char*)a0;
    v0 = 0;
    v1 = v1 << 8;
    *(short*)(char*)a1 = v1;
    a0 = *(unsigned char*)((char*)a0 + 1);
    v1 = v1 | a0;
    *(short*)(char*)a1 = v1;
L00301B6C:;
    goto ret;
ret:
    return v0;
}
