#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* Quad copies as GCC-style volatile lq/sq asm (house idiom); the unused `xx` locals keep retail's dead address addius.
   M(const M&, int) is the same matrix copy without the dead addiu (retail has it on the parameter copy only). */
/* cParticleSpray_UpdateGravityVector: reset the emitter's gravity to the zero vector rotated into local space and refresh its rate */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { void* xx = this; const V* s = &o; __int128 q; V* d = this; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    float m[4][4];
    M() {}
    M(const M& o) { void* xx = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); }
    M(const M& o, int) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); }
    M& Transpose3() {
        M& s = *this;
        float t;
        t = s.m[0][1]; s.m[0][1] = s.m[1][0]; s.m[1][0] = t;
        t = s.m[0][2]; s.m[0][2] = s.m[2][0]; s.m[2][0] = t;
        t = s.m[1][2]; s.m[1][2] = s.m[2][1]; s.m[2][1] = t;
        return s;
    }
} __attribute__((aligned(16)));
static inline M Transposed(const M& a) { M r(a, 0); M& p = r.Transpose3(); return p; }
static inline V& Rot(V& v, M m) { __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; sqc2 vf8, 0x0(%0)" : : "r"(&v), "r"(&m), "r"(&v) : "memory"); return v; }
struct Def { char pad[0x64]; unsigned char rate; };
struct Emitter { char pad0[0xD0]; V grav; char padE0[0x120 - 0xE0]; Def* def; };
extern "C" V D_004BC550;
extern "C" void cParticleSpray_UpdateGravityVector(Emitter* e, const M* m)
{
    e->grav = D_004BC550;
    e->grav = Rot(e->grav, Transposed(*m));
    e->grav.w = e->def->rate;
}
