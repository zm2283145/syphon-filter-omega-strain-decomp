/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E1DB0[];

int func_00100B30(int a0, int a1, int a2) {
    int tmp0;

    tmp0 = *(int*)D_004E1DB0;
    *(int*)((char*)a2) = tmp0;
    *(int*)((char*)a2 + 4) = a1;
    *(int*)((char*)a2 + 8) = a0;
    *(int*)D_004E1DB0 = a2;
    return a0;
}
