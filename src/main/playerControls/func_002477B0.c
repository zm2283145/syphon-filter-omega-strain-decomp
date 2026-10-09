/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001BE090(int, int, int, int);

int func_002477B0(int a0) {
    return (*(int*)((char*)a0 + 92) + -1);
}

int func_002477C0(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return func_001BE090(a0, (tmp1 + (tmp0 << 3)), 1, a1);
}

int func_002477E0(int a0, float f12) {
    *(char*)((char*)a0) = 1;
    *(float*)((char*)a0 + 4) = f12;
    return a0;
}
