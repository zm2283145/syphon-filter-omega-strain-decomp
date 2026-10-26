/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void _alalcSetDynamic(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 8);
    *(int*)((char*)a0 + 12) = tmp0;
}

void _alalcFree(int a0) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 12);
    *(int*)((char*)a0 + 8) = tmp0;
}
