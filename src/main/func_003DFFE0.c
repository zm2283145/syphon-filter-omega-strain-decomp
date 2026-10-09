/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003DFFE0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 20080);
    *(int*)((char*)a0 + 20080) = (tmp0 + 4);
    tmp1 = *(int*)(char*)tmp0;
    return tmp1;
}
