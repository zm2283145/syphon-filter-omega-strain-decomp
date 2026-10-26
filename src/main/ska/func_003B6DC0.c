#pragma cplusplus on
#include "types.h"
static inline void Q6DC0(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V& operator=(const V& o) { V* d = this; Q6DC0(d, &o); return *this; } } __attribute__((aligned(16)));
struct W { float x, y, z, w; W& operator=(const W& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ Q6DC0(this, &o); return *this; } } __attribute__((aligned(16)));
struct S6DC0 {
    char pad0[0xD0];
    float fD0;
    V vE0;
    W vF0;
    float f100;
    V v110[4];
    W v150;
    int i160;
    int i164;
    V& Get(int i) { return ((V*)((char*)this + 0x110))[i]; }
};
extern "C" void cTreeNode_cSkaAnimAnchor_TreeNodeData_opAssign(S6DC0* d, S6DC0* s);
extern "C" S6DC0* cSkaAnimAnchor_opAssign(S6DC0* d, S6DC0* s)
{
    cTreeNode_cSkaAnimAnchor_TreeNodeData_opAssign(d, s);
    d->fD0 = s->fD0;
    { V* p = &d->vE0; *p = s->vE0; }
    d->vF0 = s->vF0;
    d->f100 = s->f100;
    for (int i = 0; i <= 3; i++)
        d->Get(i) = s->Get(i);
    d->v150 = s->v150;
    d->i160 = s->i160;
    d->i164 = s->i164;
    return d;
}



