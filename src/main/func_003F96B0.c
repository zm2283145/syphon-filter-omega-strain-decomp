/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Archive_Open(int, int, int, int);

int func_003F96B0(int a0, int a1, int a2) {
    int tmp0;

    tmp0 = Archive_Open(a0, a1, a2, 0);
    *(char*)((char*)tmp0 + 360) = 1;
    return tmp0;
}
