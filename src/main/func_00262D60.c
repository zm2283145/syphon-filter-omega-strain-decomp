/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

Word* func_00262D60(Word* self, int value) {
    self->value = value;
    return self;
}

void* func_00262D70(char* self) {
    return self + 4;
}

void* func_00262D80(void* self) {
    return self;
}
