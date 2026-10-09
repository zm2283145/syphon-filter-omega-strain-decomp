/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

void LosResult_SetStatus(LosResult* self, char value) {
    self->status = value;
}

/* Clear flag bytes +0x40/+0x42 and words +0x60/+0x64. */
Unk0013AAE0* func_0013AAE0(Unk0013AAE0* self) {
    self->unk40 = 0;
    self->unk42 = 0;
    self->unk60 = 0;
    self->unk64 = 0;
    return self;
}

void* Ptr_Identity(void* self) {
    return self;
}
