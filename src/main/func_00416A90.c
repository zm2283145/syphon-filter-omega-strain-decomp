/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E0960[];
extern char D_004E09B0[];
extern char D_00572130[];

int func_00416A90(int a0) {
    int tmp0;

    *(int*)((char*)a0) = (int)D_004E09B0;
    tmp0 = *(int*)D_00572130;
    *(int*)D_00572130 = (tmp0 + 1);
    *(int*)((char*)a0) = (int)D_004E0960;
    *(int*)((char*)a0 + 4) = 0;
    return a0;
}
