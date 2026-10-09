/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001830D0(int a0) {
    int v0;
    int cond;

    v0 = *(unsigned char*)(char*)(a0 + 45);
    v0 = (unsigned int)0 < (unsigned int)v0;
    cond = v0 == 0;
    if (cond) goto L001830E8;
    v0 = *(unsigned char*)(char*)(a0 + 44);
    v0 = (unsigned int)0 < (unsigned int)v0;
L001830E8:;
    cond = v0 == 0;
    if (cond) goto L001830FC;
    v0 = *(unsigned char*)(char*)(a0 + 46);
    v0 = (unsigned int)0 < (unsigned int)v0;
    v0 = v0 ^ 1;
L001830FC:;
    goto ret;
ret:
    return v0;
}
