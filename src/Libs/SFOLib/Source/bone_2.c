/*
 * Libs/SFOLib/Source/bone: 5 files, 003BA840-003BAA80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BA840 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* lq/sq quad copies written as GCC-style volatile asm; the unused xx reproduces retail's dead addiu */
struct V { float x, y, z, w; V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; } } __attribute__((aligned(16)));
struct M { __int128 q[4];
    M& operator=(const M& o) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
};
struct MN { __int128 q[4];
    MN& operator=(const MN& o) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); return *this; }
};
struct SkelNode {
    VPAD8(a) virtual int Get(); VPAD2(b) virtual void Set(int);
    char pad04[0xBC];
    int fC0;
    MN mD0;
    M m110;
    struct S150 { unsigned char b150, b151; float f154; V v160; float f170; } s150;
    V v180, v190, v1A0, v1B0, v1C0;
};
extern "C" SkelNode* cBone_opAssign(SkelNode* d, SkelNode* s);
SkelNode* cBone_opAssign(SkelNode* d, SkelNode* s)
{
    d->fC0 = s->fC0;
    d->mD0 = s->mD0;
    d->m110 = s->m110;
    d->s150 = s->s150;
    d->v180 = s->v180;
    d->v190 = s->v190;
    d->v1A0 = s->v1A0;
    d->v1B0 = s->v1B0;
    d->v1C0 = s->v1C0;
    d->Set(s->Get());
    return d;
}
static inline void merge_flush_func_003BA840(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BA840 */

/* merge_units: begin func_003BA9A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Obj3BA9A0 { VPAD16(a) VPAD1(b) virtual void Clear(int f); virtual void s18(); virtual void Remove(void* e, int f);
    char pad[0xA0]; char mA4[0xC]; };
extern "C" {
extern char D_004DF640[];
#if 0 /* merge_units */
int cArray_cXformNodePtr_Empty(void* l);
#endif /* merge_units */
int cArray_cXformNodePtr_Empty(int* self); /* merge_units */
#define cArray_cXformNodePtr_Empty(a0) (cArray_cXformNodePtr_Empty((int *)(a0))) /* merge_units */

#if 0 /* merge_units */
void** cArray_cXformNodePtr_Back(void* l);
#endif /* merge_units */
int* cArray_cXformNodePtr_Back(PtrVec* v); /* merge_units */
#define cArray_cXformNodePtr_Back(a0) ((void * *)cArray_cXformNodePtr_Back((PtrVec *)(a0))) /* merge_units */

void cArray_cXformNodePtr_dtor(void* p, int f);
void cXform_dtor(void* p, int f);
void operator_delete(void* p);
}
static inline bool Empty3BA9A0(void* l) { return cArray_cXformNodePtr_Empty(l); }
static inline void Base3BA9A0(Obj3BA9A0* self)
{
    if (self) {
        *(void**)self = D_004DF640;
        self->Clear(1);
        while (!Empty3BA9A0(self->mA4)) self->Remove(*cArray_cXformNodePtr_Back(self->mA4), 1);
        cArray_cXformNodePtr_dtor(self->mA4, -1);
        cXform_dtor(self, 0);
    }
}
extern "C" Obj3BA9A0* cBone_dtor(Obj3BA9A0* self, short del)
{
    if (self) {
        Base3BA9A0(self);
        if (del > 0) operator_delete(self);
    }
    return self;
}
#undef cArray_cXformNodePtr_Empty /* merge_units */
#undef cArray_cXformNodePtr_Back /* merge_units */
static inline void merge_flush_func_003BA9A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BA9A0 */

/* merge_units: begin func_003BAA80 */
#pragma push /* merge_units */
/* Returns whether the word at +4 is zero. */
int cArray_cXformNodePtr_Empty(int* self)
{
    return self[1] == 0;
}
static inline void merge_flush_func_003BAA80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BAA80 */

/* merge_units: begin func_003BAA90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* back(): address of the last element. */
int* cArray_cXformNodePtr_Back(PtrVec* v) {
    return v->data + v->count - 1;
}
static inline void merge_flush_func_003BAA90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BAA90 */

/* merge_units: begin func_003BAAB0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" void cXformNode_ctor_void(SkelNode* x);
extern "C" SkelNode* cBone_ctor_cBoneR(SkelNode* d, SkelNode* s);
SkelNode* cBone_ctor_cBoneR(SkelNode* d, SkelNode* s)
{
    cXformNode_ctor_void(d);
    d->fC0 = s->fC0;
    d->mD0 = s->mD0;
    d->m110 = s->m110;
    d->s150 = s->s150;
    d->v180 = s->v180;
    d->v190 = s->v190;
    d->v1A0 = s->v1A0;
    d->v1B0 = s->v1B0;
    d->v1C0 = s->v1C0;
    d->Set(s->Get());
    return d;
}
static inline void merge_flush_func_003BAAB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BAAB0 */
