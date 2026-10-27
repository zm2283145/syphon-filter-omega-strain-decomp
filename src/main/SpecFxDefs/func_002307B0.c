#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { __int128 r[4]; } M44;
struct V4c { float x, y, z, w; } __attribute__((aligned(16)));
struct Obj { VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e) virtual V4c GetPos(); };
struct Msg;
extern "C" {
extern char D_004F7BE8[];
extern char D_004DBB40[];
extern char D_004DCF10[];
extern void cMessage_ctor_cMessageNameR(Msg* v, void* arg);
extern void QueueMessage_cMessageR_cSystemP_int(Msg* v, Obj* target, int a2);
extern void cMessage_dtor(Msg* v, int flags);
extern void SfxParticleEffect_eEffectName_cMatrixR(int id, M44* m);
}
struct Msg { void* vtable; char pad4[0x1C]; unsigned char b20; char pad21[3]; Obj* target; unsigned char id; char pad29[7];
    Msg(Obj* o, int i) { Msg* s = this; cMessage_ctor_cMessageNameR(s, D_004F7BE8); s->vtable = D_004DCF10; s->vtable = D_004DBB40; s->target = o; s->id = i; s->b20 = 4; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Msg() { vtable = D_004DCF10; cMessage_dtor(this, 0); }
    void Send(Obj* o) { QueueMessage_cMessageR_cSystemP_int(this, o, 0); }
};
extern "C" {
}
static inline void UnitMtx(void* m0) { void* m = m0; int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
static inline void CpC(void* d0, const void* s) { void* d = d0; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }

extern "C" void Global_SpawnParticle(int id, Obj* o, int notify)
{
    M44 m;
    UnitMtx(&m);
    CpC(&m.r[3], &o->GetPos());
    SfxParticleEffect_eEffectName_cMatrixR(id, &m);
    if (notify) {
        Msg(o, id).Send(o);
    }
}
