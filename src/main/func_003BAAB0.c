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
extern "C" void Xform_Construct(SkelNode* x);
extern "C" SkelNode* SkelNode_Assign(SkelNode* d, SkelNode* s);
SkelNode* SkelNode_Assign(SkelNode* d, SkelNode* s)
{
    Xform_Construct(d);
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



