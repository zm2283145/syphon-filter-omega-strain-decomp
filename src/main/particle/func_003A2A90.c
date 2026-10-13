#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
} __attribute__((aligned(16)));
static inline V operator+(const V& a, const V& b) {
    V c;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&a), "r"(&b) : "memory");
    return c;
}
struct Box {
    __int128 q[2];
    void Add(const V& p) {
        __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); lqc2 $vf3, 0x0(%2); vmini.xyz $vf1, $vf1, $vf3; vmax.xyz $vf2, $vf2, $vf3; sqc2 $vf1, 0x0(%0); sqc2 $vf2, 0x0(%1)" : : "r"(&q[0]), "r"(&q[1]), "r"(&p) : "memory");
    }
    V& Min() { return *(V*)&q[0]; }
    V& Max() { return *(V*)&q[1]; }
} __attribute__((aligned(16)));
struct Data { char pad[0x890]; Box box; };
struct Obj { char pad[0x24]; Data* d; char pad28[0x18]; V pos; char pad50[0x19]; unsigned char f69; Box* Get() { return &d->box; } };
extern "C" Box D_0053B660;
extern "C" Box* func_003A2A90(Obj* o);
Box* func_003A2A90(Obj* o)
{
    if (!o->f69) return &o->d->box;
    {
        /* 32-byte box copy: both lq before both sq, as four GCC-style lq/sq statements */
        __int128 t0, t1;
        Box* d = &D_0053B660;
        const Box* s = &o->d->box;
        __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t0) : "r"(s) : "memory");
        __asm__ volatile("lq %0, 0x10(%1)" : "=r"(t1) : "r"(s) : "memory");
        __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t0), "r"(d) : "memory");
        __asm__ volatile("sq %0, 0x10(%1)" : : "r"(t1), "r"(d) : "memory");
    }
    V a = o->pos + *(V*)&o->d->box.q[0];
    D_0053B660.Add(a);
    V b = o->pos + *(V*)&o->d->box.q[1];
    D_0053B660.Add(b);
    return &D_0053B660;
}
