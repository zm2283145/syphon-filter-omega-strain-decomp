/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Accessors of the object built by func_001C5950. */
void func_001C5650(UnkGobj001C5950* self) {
    self->base.unk2C = 1;
}

void func_001C5660(UnkGobj001C5950* self) {
    self->base.unk2C = 0;
}

void func_001C5670(UnkGobj001C5950* self, float value) {
    self->unk70 = value;
}
