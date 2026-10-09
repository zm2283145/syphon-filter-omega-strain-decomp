/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003E97B0(int a0, int a1, int a2) {
    *(int*)((char*)a0 + 104) = *(int*)(char*)a1;
    *(char*)((char*)a0 + 100) = 1;
    *(int*)((char*)a0 + 128) = a2;
}
