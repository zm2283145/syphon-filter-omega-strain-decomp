/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Iterator dereference (returns *it). */
int func_00182260(void* self, int* it) {
    return it[0];
}

int func_00182270(IntPair* self) {
    return self->a;
}

/* Store the gather source word at +0x04 (research COL_GATHER_NATIVE.md). */
void ColGather_SetSource(IntPair* self, int value) {
    self->b = value;
}
