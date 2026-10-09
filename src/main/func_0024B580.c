/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_0024B580(char* self) {
    self[38] = 0;
}

void func_0024B590(int a0, int a1, int a2) {
    *(char*)((char*)a0 + 38) = 1;
    *(char*)((char*)a0 + 39) = a1;
    *(int*)((char*)a0 + 40) = *(int*)(char*)a2;
}
