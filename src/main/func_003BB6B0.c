/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Attach an info header to a texture entry and mark it. */
void func_003BB6B0(TexEntry* self, TexInfo* info) {
    self->info = info;
    self->flags = self->flags | 0x1000;
    self->unk60 = 0;
    self->unk61 = 0;
}
