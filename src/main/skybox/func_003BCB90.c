#include "types.h"
#pragma cplusplus on
struct V4 {
    float x, y, z, w;
    V4 operator*(float s) const {
        V4 r; V4* q = &r; int t; const V4* v = this;
        asm {
            .set noreorder
            lqc2 vf1, 0x0(v)
            mfc1 t, s
            qmtc2.ni t, vf2
            vmulx.xyzw vf1, vf1, vf2x
            sqc2 vf1, 0x0(q)
            .set reorder
        }
        return *q;
    }
    V4& operator=(const V4& a) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&a; *d = *s; return *this; }
    V4& operator+=(const V4& a) {
        V4* d = this; const V4* p = &a;
        asm {
            lqc2 vf1, 0x0(d)
            lqc2 vf2, 0x0(p)
            vadd.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(d)
        }
        return *this;
    }
} __attribute__((aligned(16)));
struct Sky_BCB90 {
    char p0[0x1B0];
    V4 vel;
    V4 acc;
    char p1d0[0x10];
    V4 dir;
    V4 base;
    float ang;
    float angVel;
    float angMax;
    unsigned int flags;
};
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off
extern "C" void func_003BCB90(Sky_BCB90* o) {
    o->ang = o->ang + o->angVel;
    if (!(o->flags & 8)) {
        o->vel += o->acc;
    }
    if (o->flags & 4) {
        { float a = o->ang; float m = o->angMax; if (a > m) o->ang = -m; }
        { float a; float m = o->angMax; a = o->ang; if (a < -m) o->ang = m; }
    }
    {
        V4* d; /* dead store: retail keeps the unused &dir addiu */
        o->dir = o->base * o->ang;
        d = &o->dir;
    }
    o->dir.w = 1.0f;
}
#pragma pop

