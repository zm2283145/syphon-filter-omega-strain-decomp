/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EA350[];
extern int func_00186360(int, int, int, int, int, float);

void func_0014B340(int a0) {
    *(int*)D_004EA350 = a0;
}

int func_0014B350(int a0, float f12) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 48);
    return func_00186360(tmp0, 1, 0, 0, 0, f12);
}
