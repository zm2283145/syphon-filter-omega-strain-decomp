/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void SetPlayerStatus(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 2128);
    *(int*)((char*)a0 + 2128) = (tmp0 | a1);
}

void ResetPlayerStatus(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 2128);
    *(int*)((char*)a0 + 2128) = (tmp0 & ~((0) | (a1)));
}
