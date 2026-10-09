/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003797B0(int a0, int a1) {
    return (*(int*)(char*)(*(int*)((char*)a0 + 8) + (a1 << 2)) + 80);
}

int func_003797D0(char* self) {
    return *(int*)(self + 4184);
}
