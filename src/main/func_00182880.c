/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress(void* self, int* it);
extern int cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_2(void* self, int* it);

int cCollisionModel_Data_GetTreeSoleLeaf(Unk00182880* self) {
    int it[1];

    it[0] = self->unk10;
    return cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress(self, it);
}

int cCollisionModel_Data_GetTreeRootNode(Unk00182880* self) {
    int it[1];

    it[0] = self->unk08;
    return cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_2(self, it);
}
