/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Slot20 constructor (element ctor used by XLib_ctor). */
Slot20* cUserFrameEnv_ctor(Slot20* self) {
    self->unk00 = -1;
    self->unk04 = -1;
    self->unk08 = 0;
    self->unk0C = 0;
    self->unk10 = 0;
    return self;
}
