/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00337F90(int, int, int, int);

int func_0032E230(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 8);
    tmp1 = *(int*)((char*)a0 + 4);
    return func_00337F90(a0, (tmp0 + (tmp1 * 28)), 1, a1);
}
