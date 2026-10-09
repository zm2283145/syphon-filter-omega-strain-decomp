/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DF0B0[];
extern void func_0041F690(int);

int func_00356FF0(int a0) {
    func_0041F690(a0);
    *(int*)((char*)a0) = (int)D_004DF0B0;
    *(int*)((char*)a0 + 72) = 0;
    *(int*)((char*)a0 + 76) = 0;
    *(int*)((char*)a0 + 80) = 0;
    *(int*)((char*)a0 + 92) = 0;
    *(int*)((char*)a0 + 96) = 0;
    *(int*)((char*)a0 + 84) = 0;
    *(int*)((char*)a0 + 88) = 0;
    *(int*)((char*)a0 + 104) = 1;
    return a0;
}
