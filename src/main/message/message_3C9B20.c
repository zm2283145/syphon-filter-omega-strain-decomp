/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

Word* func_003C9B20(Word* self, int value) {
    self->value = value;
    return self;
}

void* func_003C9B30(char* self) {
    return self + 4;
}

void* func_003C9B40(void* self) {
    return self;
}
