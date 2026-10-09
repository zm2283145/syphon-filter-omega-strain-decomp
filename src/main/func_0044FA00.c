/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00585FA8[];

int func_0044FA00(int a0) {
    *(int*)((char*)a0 + 16) = 0;
    *(int*)((char*)a0 + 12) = 0;
    *(int*)((char*)a0 + 8) = 0;
    *(int*)((char*)a0 + 4) = 0;
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 20) = 0;
    *(char*)((char*)a0 + 24) = 1;
    *(char*)((char*)a0 + 25) = 0;
    *(char*)((char*)a0 + 26) = 0;
    *(char*)((char*)a0 + 24) = 1;
    return a0;
}

int func_0044FA40(int a0) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_00585FA8;
    v0 = (unsigned int)0 < (unsigned int)v0;
    cond = v0 == 0;
    if (cond) goto L0044FA60;
    v0 = *(unsigned char*)(char*)(a0 + 380);
    v0 = (unsigned int)0 < (unsigned int)v0;
    v0 = v0 ^ 1;
L0044FA60:;
    goto ret;
ret:
    return v0;
}
