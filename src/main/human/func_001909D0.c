/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Address of field +0x10 in 32-byte element i. */
char* func_001909D0(char* base, int i) {
    return base + (i << 5) + 16;
}

int func_001909E0(char* self) {
    return *(int*)(self + 0);
}

void* func_001909F0(void* self) {
    return self;
}
