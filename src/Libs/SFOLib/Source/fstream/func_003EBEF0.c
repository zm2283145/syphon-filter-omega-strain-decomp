/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

/* Initializes an empty vector header (also used as a member initializer by cFileMan_ctor_void). */
L4OwnedVec* cFSHandle_ctor(L4OwnedVec* self) {
    self->vec.unk0 = 0;
    self->vec.data = 0;
    self->vec.count = 0;
    self->owned = 0;
    return self;
}
