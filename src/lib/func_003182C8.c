/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

float func_003182C8(int a0, int a1) {
    float tmp0;
    float tmp1;
    float tmp2;

    tmp0 = *(float*)(char*)a1;
    tmp1 = *(float*)((char*)a0 + 52);
    tmp2 = *(float*)((char*)a0 + 48);
    return ((tmp0 * tmp1) + tmp2);
}
