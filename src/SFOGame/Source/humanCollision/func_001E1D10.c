/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Iterator dereference (returns *it). */
extern char* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_4(TableOwner* owner, char** it);

float cCollisionFace_NormalScale(Unk001E1D10* self) {
    return self->unk3C;
}

void cCollisionModel_FaceLocator_Set(IntPair* self, int a, int b) {
    self->a = a;
    self->b = b;
}

/* Bit 7 of byte +0x0C. */
int cCollisionModel_Face_IsReceiveReflection(unsigned char* flags) {
    return (flags[12] & 128) != 0;
}

/* Bit 7 of byte +0x0B. */
int cCollisionModel_Face_IsReceiveShadow(unsigned char* flags) {
    return (flags[11] & 128) != 0;
}

int cCollisionModel_Face_IsCamPassThru(void) {
    return 0;
}

int cCollisionModel_GetXform(Unk001E1D60** self) {
    return (*self)->unk50;
}

void* cVector_W(char* self) {
    return self + 12;
}

/* Address of 16-byte entry index of the owner's table. */
char* cCollisionModel_GetVertex(TableOwnerRef* self, int index) {
    char* it[1];
    TableOwner* owner;

    owner = *self->owner;
    it[0] = owner->table;
    return cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_4(owner, it) + (index << 4);
}
