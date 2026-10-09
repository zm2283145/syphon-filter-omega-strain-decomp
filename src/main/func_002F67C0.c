/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_002F67C0(int a0) {
    int v0, v1;
    int cond;

    cond = a0 == 0;
    v0 = 0;
    if (cond) goto L002F67E8;
    v1 = *(unsigned char*)(char*)a0;
    cond = v1 == 0;
    if (cond) goto L002F67E8;
    v1 = *(unsigned char*)(char*)(a0 + 1);
    cond = v1 == 0;
    if (cond) goto L002F67E8;
    v0 = *(int*)(char*)(a0 + 8);
    v0 = (unsigned int)v0 < (unsigned int)4;
L002F67E8:;
    goto ret;
ret:
    return v0;
}
