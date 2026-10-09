/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_0041F070(int a0) {
    int v1;

    v1 = *(unsigned short*)((char*)a0 + 20);
    v1 = v1 & 65531;
    *(short*)((char*)a0 + 20) = v1;
    goto ret;
ret:;
}

void func_0041F080(int a0) {
    int v1;

    v1 = *(unsigned short*)((char*)a0 + 20);
    v1 = v1 | 4;
    *(short*)((char*)a0 + 20) = v1;
    goto ret;
ret:;
}
