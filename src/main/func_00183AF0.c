/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_6(void* self, int* it);

/* Iterator dereferences (return *it). */
int cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_3(void* self, int* it) {
    return it[0];
}

/* Surface index of a collision triangle (research COL_GATHER_NATIVE.md). */
unsigned char cCollisionModel_Face_GetPropertiesIndex(Tri* t) {
    return t->b10 >> 1;
}

int cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_4(void* self, int* it) {
    return it[0];
}

int cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(void* self, int* it) {
    return it[0];
}

/* Pass a copy of the iterator to cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_6. */
int cCollisionModel_Data_GetFaceIndices(void* self, int* it) {
    int copy[1];

    copy[0] = it[0];
    return cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_6(self, copy);
}
