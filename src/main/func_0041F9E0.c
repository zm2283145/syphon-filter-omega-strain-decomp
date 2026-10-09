/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00572118[];

void func_0041F9E0(int a0) {
    int tmp0;

    tmp0 = *(int*)D_00572118;
    *(int*)((char*)a0 + 4) = tmp0;
    *(int*)D_00572118 = a0;
}
