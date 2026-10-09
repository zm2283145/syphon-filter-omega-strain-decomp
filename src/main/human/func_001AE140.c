/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_001AE140(char* self) {
    return self + 96;
}

void func_001AE150(int a0, int a1) {
    int v1;

    a1 = a1 & 255;
    v1 = a1 << 3;
    v1 = v1 - a1;
    v1 = v1 << 4;
    v1 = v1 + a0;
    *(char*)(char*)(v1 + 933) = 0;
    goto ret;
ret:;
}
