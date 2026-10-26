/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "collision_types.h"

void cCollisionModelMaster_UnLoad(ColRef* self) {
    self->unk0 = 0;
    self->unk4 = 1;
}
