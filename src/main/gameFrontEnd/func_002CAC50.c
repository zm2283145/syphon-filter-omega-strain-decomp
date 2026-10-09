/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Single-word wrapper constructor. */
int* func_002CAC50(int* self, int value) {
    *self = value;
    return self;
}

void* func_002CAC60(char* self) {
    return self + 4;
}

void* func_002CAC70(void* self) {
    return self;
}
