/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiAgentInfo_types.h"

/* Adds *delta to each float field of the range. */
void func_00364AB0(ShiftRange* self, float* delta) {
    self->unk04 = self->unk04 + *delta;
    self->unk08 = self->unk08 + *delta;
    self->unk10 = self->unk10 + *delta;
    self->unk18 = self->unk18 + *delta;
    self->unk20 = self->unk20 + *delta;
}
