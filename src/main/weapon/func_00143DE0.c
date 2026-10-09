/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001861F0(int, int);

int func_00143DE0(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 136);
    return func_001861F0(tmp0, a1);
}
