/*
 * main/ska: 2 files, 003BA840-003BA9A0
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
extern "C" SkelNode* SkelNode_CopyConstruct(SkelNode* d, SkelNode* s);
SkelNode* SkelNode_CopyConstruct(SkelNode* d, SkelNode* s)
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
#pragma pop /* merge_units */
/* merge_units: end func_003BA840 */

/* merge_units: begin func_003BA9A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Obj3BA9A0 { VPAD16(a) VPAD1(b) virtual void Clear(int f); virtual void s18(); virtual void Remove(void* e, int f);
    char pad[0xA0]; char mA4[0xC]; };
extern "C" {
extern char D_004DF640[];
int func_003BAA80(void* l);
void** func_003BAA90(void* l);
void func_0036FB30(void* p, int f);
void func_0036FC80(void* p, int f);
void operator_delete(void* p);
}
static inline bool Empty3BA9A0(void* l) { return func_003BAA80(l); }
static inline void Base3BA9A0(Obj3BA9A0* self)
{
    if (self) {
        *(void**)self = D_004DF640;
        self->Clear(1);
        while (!Empty3BA9A0(self->mA4)) self->Remove(*func_003BAA90(self->mA4), 1);
        func_0036FB30(self->mA4, -1);
        func_0036FC80(self, 0);
    }
}
extern "C" Obj3BA9A0* func_003BA9A0(Obj3BA9A0* self, short del)
{
    if (self) {
        Base3BA9A0(self);
        if (del > 0) operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003BA9A0 */
