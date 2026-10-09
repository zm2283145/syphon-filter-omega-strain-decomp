/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

/* Initializes an empty vector header (also used as a member initializer by func_0036E5D0). */
L4OwnedVec* func_003EBEF0(L4OwnedVec* self) {
    self->vec.unk0 = 0;
    self->vec.data = 0;
    self->vec.count = 0;
    self->owned = 0;
    return self;
}
