/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00139BD0(int, int, int);

int func_00136020(int a0, int a1, int a2) {
    *(int*)((char*)a0) = 0;
    *(int*)((char*)a0 + 4) = 0;
    *(int*)((char*)a0 + 8) = 0;
    func_00139BD0(a0, a1, a2);
    return a0;
}

int func_00136060(int a0) {
    *(char*)((char*)a0 + 96) = 0;
    *(char*)((char*)a0 + 98) = 0;
    *(int*)((char*)a0 + 128) = 0;
    *(int*)((char*)a0 + 132) = 0;
    return a0;
}
