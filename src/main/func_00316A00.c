/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Resets the record to its empty state. */
void func_00316A00(Rec316A00* self) {
    self->unk08 = -1;
    self->unk00 = 0;
    self->unk01 = 0;
    self->unk04 = -1;
    self->unk08 = -1;
    self->unk0C = -1;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk18 = 0;
}
