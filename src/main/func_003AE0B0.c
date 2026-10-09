/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003AE0B0(int a0, int a1) {
    *(int*)((char*)a0) = *(int*)(char*)a1;
    *(int*)((char*)a0 + 4) = *(int*)((char*)a1 + 4);
    *(int*)((char*)a0 + 8) = *(int*)((char*)a1 + 8);
    *(int*)((char*)a0 + 12) = *(int*)((char*)a1 + 12);
    *(int*)((char*)a0 + 16) = *(int*)((char*)a1 + 16);
    *(int*)((char*)a0 + 20) = *(int*)((char*)a1 + 20);
    return a0;
}
