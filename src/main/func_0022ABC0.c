#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(&o), "r"(this) : "memory"); return *this; }
    V operator-(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(this), "r"(&c), "r"(&b) : "memory");
        return c;
    }
} __attribute__((aligned(16)));
struct M {
    V r0, r1, r2, t;
    M() {}
    M& operator=(const M& o) { M* d = this; const M* s = &o; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
    M(const M& o) { const M* s = &o; M* d = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
};
static inline void MulV(V* v, M* m) { __asm__ volatile("lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
extern "C" {
V* Vec4_Assign(V* d, V* s);
void Mtx_Transpose3x3(M* m);
int Mtx_IsTranslationZero(M* m);
V* func_00133EC0(M* m);
void Vec3_Negate(V* v);
void Mtx_TransformByTranspose(V* v, M* m);
void Mtx_SetTranslation(M* m, V* v);
float Math_Atan2f(float y, float x);
float Combat_HitDirection(M* m, V* p, V* out);
}
static inline void InvertRigid(M* m)
{
    Mtx_Transpose3x3(m);
    if (!Mtx_IsTranslationZero(m)) {
        V t;
        Vec4_Assign(&t, func_00133EC0(m));
        Vec3_Negate(&t);
        Mtx_TransformByTranspose(&t, m);
        Mtx_SetTranslation(m, &t);
    }
}
static inline void CP1(V* d, const V* s) { __int128 t; asm volatile { lq t, 0(s); sq t, 0(d) } }
static inline void MulVO(V* o, V* v, M* m) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
static inline float Len(V* v) {
    float r = 0.0f;
    int t;
    asm {
        lqc2 vf1, 0x0(v)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        qmfc2 t, vf4
        mtc1 t, r
    }
    return r;
}
/* Combat_HitDirection: hit point in the target frame; yaw/pitch of it into out, returns the horizontal distance */
float Combat_HitDirection(M* m, V* p, V* out)
{
    M inv = *m;
    InvertRigid(&inv);
    V l;
    CP1(&l, p);
    MulVO(&l, &l, &inv);
    V h(l.x, l.y, 0.0f, 0.0f);
    float d = Len(&h);
    out->x = Math_Atan2f(l.z, d);
    out->y = 0.0f;
    out->z = Math_Atan2f(-l.x, l.y);
    return d;
}
