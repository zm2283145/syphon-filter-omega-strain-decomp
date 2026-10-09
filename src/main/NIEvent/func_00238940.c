/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "NIEvent_types.h"

extern NIEventVec3* func_00238970(NIEventVec3* vec);

/* Constructs an empty vector that owns its storage. */
NIEventOwnedVec* func_00238940(NIEventOwnedVec* self) {
    func_00238970(&self->vec);
    self->owned = 1;
    return self;
}
