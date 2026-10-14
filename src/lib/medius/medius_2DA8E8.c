/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_002DA8E8(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 104);
    *(int*)((char*)a0 + 120) = a1;
    *(int*)((char*)tmp0 + 52) = a1;
    return 0;
}
