/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003C01B0(int a0, int a1, int a2) {
    Q tmp0;

    tmp0 = *(Q*)(char*)a2;
    *(Q*)((char*)(a0 + (a1 << 4))) = tmp0;
}

void func_003C01D0(int a0) {
    *(int*)((char*)a0 + 4) = (*(int*)((char*)a0 + 4) + -1);
}
