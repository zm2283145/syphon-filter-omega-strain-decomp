/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00106478(int a0) {
    int tmp0;

    tmp0 = *(int*)(char*)268443664;
    *(int*)((char*)268443664) = ((tmp0 & 0xff7fffff) | (a0 << 23));
}
