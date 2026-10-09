/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00104418(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)(char*)a0;
    *(int*)((char*)a0) = a1;
    return (((unsigned int)(tmp0) >> 8) & 1);
}
