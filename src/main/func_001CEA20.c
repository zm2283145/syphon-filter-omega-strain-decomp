/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_001CEA20(int a0) {
    int v0;
    int cond;

    v0 = *(unsigned char*)(char*)(a0 + 896);
    v0 = (unsigned int)0 < (unsigned int)v0;
    v0 = v0 ^ 1;
    cond = v0 == 0;
    if (cond) goto L001CEA3C;
    v0 = *(unsigned char*)(char*)(a0 + 897);
    v0 = (unsigned int)0 < (unsigned int)v0;
L001CEA3C:;
    goto ret;
ret:
    return v0;
}

void func_001CEA50(int a0, int a1) {
    *(char*)((char*)a0) = a1;
    *(char*)((char*)a0 + 1) = ((unsigned int)(0) < (unsigned int)((a1 & 255)));
}
