#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"
typedef struct { __int128 r[4]; } M44;
struct V4c { float x, y, z, w; } __attribute__((aligned(16)));
struct Obj { VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e) virtual V4c GetPos(); };
struct Msg;
extern "C" {
extern char D_004F7C00[];
extern char D_004DBAC0[];
extern char D_004DCF10[];
extern void Event_Construct(Msg* v, void* arg);
extern void Event_Send(Msg* v, Obj* target, int a2);
extern void cMessage_dtor(Msg* v, int flags);
extern void Game_SpawnLight(M44* m, float a, float b);
}
struct Msg { void* vtable; char pad4[0x1C]; unsigned char b20; char pad21[3]; Obj* target; float a; float b;
    Msg(Obj* o, float a0, float b0) { Msg* s = this; Event_Construct(s, D_004F7C00); s->vtable = D_004DCF10; s->vtable = D_004DBAC0; s->target = o; s->a = a0; s->b = b0; s->b20 = 4; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Msg() { vtable = D_004DCF10; cMessage_dtor(this, 0); }
    void Send(Obj* o) { Event_Send(this, o, 0); }
};
static inline void UnitMtx(void* m0) { void* m = m0; int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
static inline void CpC(void* d0, const void* s) { void* d = d0; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }

extern "C" void Global_SpawnLight(Obj* o, int notify, float a, float b)
{
    M44 m;
    UnitMtx(&m);
    CpC(&m.r[3], &o->GetPos());
    Game_SpawnLight(&m, a, b);
    if (notify) {
        Msg(o, a, b).Send(o);
    }
}
