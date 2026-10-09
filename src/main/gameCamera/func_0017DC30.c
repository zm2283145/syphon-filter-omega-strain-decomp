/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_0017DC30(void* self) {
    return self;
}

/* Address of 32-byte element i. */
char* func_0017DC40(char* base, int i) {
    return base + (i << 5);
}

float func_0017DC50(char* self) {
    return *(float*)(self + 64);
}
