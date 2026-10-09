/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00318300(int a0, float f12) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 72);
    *(float*)((char*)tmp0 + 28) = f12;
    *(short*)((char*)tmp0 + 40) = 1;
    return tmp0;
}
