/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EA0B8[];

int func_001AE360(void) {
    int tmp0;

    tmp0 = *(int*)D_004EA0B8;
    return tmp0;
}

void func_001AE370(int a0) {
    int v1;

    v1 = 0x3f800000;
    *(int*)(char*)(a0 + 60) = v1;
    *(int*)(char*)(a0 + 76) = 0;
    goto ret;
ret:;
}
