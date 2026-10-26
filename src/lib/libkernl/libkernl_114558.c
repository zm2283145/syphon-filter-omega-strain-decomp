/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int sceSifFreeSysMemory(int);

int sceSifFreeIopHeap(int a0) {
    int tmp0;

    tmp0 = sceSifFreeSysMemory(a0);
    return tmp0;
}
