#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 rot; V4 pos; } Plc;
static inline V4 QMul_5DE0(V4* a, V4* b) {
    V4 r; V4* p = &r;
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(a)
        vmul.xyzw vf3, vf1, vf2
        vopmula.xyz ACC, vf1, vf2
        vmaddaw.xyz ACC, vf1, vf2w
        vmaddaw.xyz ACC, vf2, vf1w
        vopmsub.xyz vf4, vf2, vf1
        vsubaz.w ACC, vf3, vf3z
        vmsubay.w ACC, vf0, vf3y
        vmsubx.w vf4, vf0, vf3x
        sqc2 vf4, 0x0(p)
    }
    return r;
}
static inline void QRot_5DE0(V4* v, V4* q) {
    asm {
        lqc2 vf1, 0x0(v)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(q)
        vmove.w vf3, vf2
        vsub.xyz vf3, vf0, vf2
        vmul.xyzw vf4, vf2, vf1
        vopmula.xyz ACC, vf2, vf1
        vmaddaw.xyz ACC, vf1, vf2w
        vopmsub.xyz vf5, vf1, vf2
        vsubaz.w ACC, vf4, vf4z
        vmsubay.w ACC, vf0, vf4y
        vmsubx.w vf5, vf0, vf4x
        vopmula.xyz ACC, vf5, vf3
        vmaddaw.xyz ACC, vf5, vf3w
        vmaddaw.xyz ACC, vf3, vf5w
        vopmsub.xyz vf6, vf3, vf5
        sqc2 vf6, 0x0(v)
    }
}
static inline void VAdd3_5DE0(V4* s, V4* d) {
    asm {
        lqc2 vf1, 0x0(d)
        lqc2 vf2, 0x0(s)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}
static inline void Q_5DE0(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void Placement_ApplyParent(Plc* o, Plc* l, Plc* b) {
    Plc t;
    Plc* a;
    V4* v;
    { void* xx = &t; /* dead on purpose: retail keeps this addiu */ }
    { Plc* d = &t; Q_5DE0(&d->rot, &l->rot); }
    Q_5DE0(&t.pos, &l->pos);
    a = &t;
    { V4 r; V4* tp; r = QMul_5DE0(&a->rot, &b->rot); tp = &r; a->rot = *tp; }
    v = &a->pos;
    QRot_5DE0(v, &b->rot);
    VAdd3_5DE0(&b->pos, &a->pos);
    Q_5DE0(&o->rot, &a->rot);
    Q_5DE0(&o->pos, &a->pos);
}
#pragma pop


