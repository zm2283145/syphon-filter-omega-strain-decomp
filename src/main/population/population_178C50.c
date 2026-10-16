/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Subtract from the word at +0x0C. */
void func_00178C50(Unk0013BDE0* self, int amount) {
    self->unk0C = self->unk0C - amount;
}
