#pragma cplusplus on
#include "types.h"
#pragma inline_depth(8)
/* NiEvent_ComputeWorld: world matrix of an event node: billboarded for
 * type-3 nodes, otherwise parent world (recursively, or the parent's
 * billboard) times the local matrix at +0xF0. Types follow
 * NiEvent_BillboardWorld (NiEvent_BillboardWorld.c) and NiEvent_MulParentMatrix. */
struct V {
    float x, y, z, w;
    V() {}
} __attribute__((aligned(16)));
struct Mtx {
    V r0, r1, r2, t;
    Mtx() {}
    Mtx(const Mtx& o) { void* d = this; __int128 qa; __int128 qb; const void* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
    Mtx& operator=(const Mtx& o) { void* d = this; __int128 qa; __int128 qb; const void* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
};
struct NiEv {
    char pad0[0x2C];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x60 - 0x2F];
    int type;
    char pad64[0x94 - 0x64];
    NiEv* parent;
    char pad98[0xF0 - 0x98];
    Mtx local;
};
extern "C" {
Mtx NiEvent_BillboardWorld(NiEv* ev);
Mtx NiEvent_ComputeWorld(NiEv* ev);
void NiEvent_MulParentMatrix(Mtx* out, Mtx* a, Mtx* b);
void func_001D3E20(Mtx* m);
void Mtx_Copy_23E150(Mtx* d, Mtx* s);
void Mtx_Copy(Mtx* d, Mtx* s);
int GameObject_IsCollisionEnabled(NiEv* ev);
}
static inline bool Not(unsigned char x) { return !x; }
static inline bool Ready(NiEv* t) { bool r = false; bool a = false; if (t->b2D && t->b2C) a = true; if (a && Not(t->b2E)) r = true; return r; }
/* matrix class whose copy constructor is the out-of-line Mtx_Copy (retail copies
 * the parent world into MulM's by-value parameter with it) */
struct MP : Mtx { MP() {} MP(const MP& o) { Mtx_Copy(this, (Mtx*)&o); } };
static inline Mtx MulM(MP a, const Mtx& b)
{
    const Mtx* pa = &a;
    Mtx t;
    Mtx* p = &t;
    __asm__ volatile(
        "lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1);"
        "lqc2 $vf8, 0x0(%2); lqc2 $vf9, 0x10(%2); lqc2 $vf10, 0x20(%2); lqc2 $vf11, 0x30(%2);"
        "vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w;"
        "vmulax.xyzw $ACC, $vf4, $vf9x; vmadday.xyzw $ACC, $vf5, $vf9y; vmaddaz.xyzw $ACC, $vf6, $vf9z; vmaddw.xyzw $vf13, $vf7, $vf9w;"
        "vmulax.xyzw $ACC, $vf4, $vf10x; vmadday.xyzw $ACC, $vf5, $vf10y; vmaddaz.xyzw $ACC, $vf6, $vf10z; vmaddw.xyzw $vf14, $vf7, $vf10w;"
        "vmulax.xyzw $ACC, $vf4, $vf11x; vmadday.xyzw $ACC, $vf5, $vf11y; vmaddaz.xyzw $ACC, $vf6, $vf11z; vmaddw.xyzw $vf15, $vf7, $vf11w;"
        "sqc2 $vf12, 0x0(%0); sqc2 $vf13, 0x10(%0); sqc2 $vf14, 0x20(%0); sqc2 $vf15, 0x30(%0)"
        : : "r"(p), "r"(pa), "r"(&b) : "memory");
    return t;
}

static inline MP ParentWorld(NiEv* p)
{
    MP m;
    func_001D3E20(&m);
    if (p->type == 3) {
        if (GameObject_IsCollisionEnabled(p)) {
            Mtx t = NiEvent_BillboardWorld(p);
            Mtx_Copy_23E150(&m, &t);
        }
    } else if (p->parent) {
        Mtx t2;
        Mtx w = NiEvent_ComputeWorld(p->parent);
        NiEvent_MulParentMatrix(&t2, &w, &p->local);
        Mtx_Copy_23E150(&m, &t2);
    } else {
        Mtx_Copy_23E150(&m, &p->local);
    }
    return m;
}

extern "C" Mtx NiEvent_ComputeWorld(NiEv* ev)
{
    Mtx r;
    if (ev->type == 3) {
        if (Ready(ev)) {
            Mtx b = NiEvent_BillboardWorld(ev);
            r = b;
        }
    } else {
        NiEv* p = ev->parent;
        if (p)
            r = MulM(ParentWorld(p), ev->local);
        else
            r = ev->local;
    }
    return r;
}
