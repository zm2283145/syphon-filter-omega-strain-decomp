/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* table[index] = *value (128-bit copy). */
void func_003C01B0(Q* table, int index, Q* value) {
    Q tmp;

    tmp = *value;
    table[index] = tmp;
}

void func_003C01D0(Counted* self) {
    self->count = self->count - 1;
}
