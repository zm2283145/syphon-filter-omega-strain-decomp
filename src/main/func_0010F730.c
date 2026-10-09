/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E2D58[];

int func_0010F730(int a0, int a1) {
    int tmp0;

    tmp0 = *(int*)((char*)(int)D_004E2D58 + 12);
    *(int*)((char*)(int)D_004E2D58 + 16) = a1;
    *(int*)((char*)(int)D_004E2D58 + 12) = a0;
    return tmp0;
}
