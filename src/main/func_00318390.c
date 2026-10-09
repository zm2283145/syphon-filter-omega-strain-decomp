/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00318390(int a0, float f12, float f13) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 72);
    *(float*)((char*)tmp0 + 52) = f13;
    *(short*)((char*)tmp0 + 42) = 1;
    *(float*)((char*)tmp0 + 48) = f12;
    return tmp0;
}
