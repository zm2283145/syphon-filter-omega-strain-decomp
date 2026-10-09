/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int LosRegion_FindLocal(int, int);

int func_0013E1A0(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)a0 + 8);
    return LosRegion_FindLocal(a1, tmp0);
}
