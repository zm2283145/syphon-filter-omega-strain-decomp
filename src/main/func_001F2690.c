/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int func_0013ADF0(void*);

int func_001F2690(char* self) {
    return func_0013ADF0(self + 4);
}

Word* func_001F26A0(Word* self, int value) {
    self->value = value;
    return self;
}
