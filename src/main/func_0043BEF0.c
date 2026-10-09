/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E0F40[];
extern void func_0041F690(int);

int func_0043BEF0(int a0) {
    func_0041F690(a0);
    *(int*)((char*)a0) = (int)D_004E0F40;
    *(char*)((char*)a0 + 84) = 0;
    *(int*)((char*)a0 + 88) = 0;
    *(int*)((char*)a0 + 92) = 0;
    *(int*)((char*)a0 + 96) = 10;
    *(char*)((char*)a0 + 72) = 0;
    *(int*)((char*)a0 + 76) = 0;
    *(int*)((char*)a0 + 80) = 0;
    return a0;
}
