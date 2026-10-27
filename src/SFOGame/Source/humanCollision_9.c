/*
 * SFOGame/Source/humanCollision: 3 files, 001E1D00-001E1DC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E1D00 */
#pragma push /* merge_units */
#include "types.h"
#pragma peephole off

typedef struct { char pad[0x30]; Q v; } Obj30;

/* Copies a quadword into the object's field at +0x30. */
void cCollisionFace_SetUnitNormal(Obj30* obj, Q* v)
{
    obj->v = *v;
}
static inline void merge_flush_func_001E1D00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1D00 */

/* merge_units: begin func_001E1D10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

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
static inline void merge_flush_func_001E1D10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1D10 */

/* merge_units: begin func_001E1DC0 */
#pragma push /* merge_units */
typedef struct SurfE6 {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
} SurfE6;

typedef struct SurfOwnerE6 {
    char pad0[3];
    unsigned char kind;
    char pad4[0x28];
    int key;
} SurfOwnerE6;

extern signed char D_004E9F98;
extern int D_004F4FD0;
extern SurfE6 D_004E9FA0;
extern unsigned char D_004E9FA2;
extern void cCollisionModel_FaceProperties_dtor(void);
extern void __register_global_object(void*, void*, void*);
extern char* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_3(SurfOwnerE6* owner, int* key);

/* Returns the surface entry for an index, or a static default for old formats. */
typedef struct { SurfOwnerE6* owner; } SurfRefE6;
typedef struct { int pad; SurfRefE6* ref; } SurfCtxE6;
SurfE6* cCollisionModel_GetFaceProperties(SurfCtxE6* ctx, int index)
{
    int key[1];
    SurfOwnerE6* owner = ctx->ref->owner;
    if (owner->kind < 3) {
        if (D_004E9F98 == 0) {
            D_004E9FA0.a = 0;
            D_004E9FA2 = 0;
            __register_global_object(&D_004E9FA0, cCollisionModel_FaceProperties_dtor, &D_004F4FD0);
            D_004E9F98 = 1;
        }
        return &D_004E9FA0;
    }
    key[0] = owner->key;
    return (SurfE6*)(cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_3(owner, key) + index * 16);
}
static inline void merge_flush_func_001E1DC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1DC0 */
