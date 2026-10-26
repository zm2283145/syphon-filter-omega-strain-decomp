/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_2(void* self, int* it);

/* Iterator dereference (returns *it). */
int cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress(void* self, int* it) {
    return it[0];
}

/* Pass a copy of the iterator to cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_2. */
int cCollisionModel_Data_GetTreeLeaf(void* self, int* it) {
    int copy[1];

    copy[0] = it[0];
    return cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_2(self, copy);
}
