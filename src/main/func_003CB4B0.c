/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DFDE0[];

int func_003CB4B0(int a0, int a1) {
    *(int*)((char*)a0) = (int)D_004DFDE0;
    *(int*)((char*)a0 + 4) = 0xbebaafde;
    *(int*)((char*)a0 + 8) = a1;
    *(int*)((char*)a0 + 12) = -1;
    *(int*)((char*)a0 + 16) = -1;
    *(char*)((char*)a0 + 20) = 1;
    *(int*)((char*)a0 + 24) = 0;
    return a0;
}
