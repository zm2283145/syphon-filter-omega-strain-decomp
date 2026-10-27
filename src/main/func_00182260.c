/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Iterator dereference (returns *it). */
int cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_2(void* self, int* it) {
    return it[0];
}

int cCollisionModelMaster_GetData(IntPair* self) {
    return self->a;
}

/* Store the gather source word at +0x04 (research COL_GATHER_NATIVE.md). */
void cCollisionFaceCollector_ResetModelInstance(IntPair* self, int value) {
    self->b = value;
}
