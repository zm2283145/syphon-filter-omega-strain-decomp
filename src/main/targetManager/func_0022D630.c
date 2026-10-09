/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "targetManager_types.h"

/* Constructor: clears the slot. */
TargetSlot* func_0022D630(TargetSlot* self) {
    self->unk4 = 0;
    self->unk0 = 0;
    self->unkC = 0;
    self->unkD = 0;
    return self;
}
