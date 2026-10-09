/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DF5C0[];
extern void func_0041F690(int);

int func_00368E10(int a0, int a1, int a2) {
    func_0041F690(a0);
    *(int*)((char*)a0) = (int)D_004DF5C0;
    *(int*)((char*)a0 + 92) = -1;
    *(int*)((char*)a0 + 88) = 0;
    *(int*)((char*)a0 + 120) = 0;
    *(int*)((char*)a0 + 124) = 0;
    *(int*)((char*)a0 + 132) = 0;
    *(char*)((char*)a0 + 136) = a1;
    *(char*)((char*)a0 + 137) = a2;
    return a0;
}
