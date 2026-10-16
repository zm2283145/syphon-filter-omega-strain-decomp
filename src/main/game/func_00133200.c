/* Mtx_InvertRigid: in-place inverse of a rigid transform (transpose the 3x3, translation = -(R^T t)). */
#pragma opt_lifetimes off
#pragma cplusplus on
#include "types.h"

typedef struct V4 { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct Mtx { float m[4][4]; } Mtx;

static inline bool XY0(const float* v) { bool r = false; if (v[0] == 0.0f && v[1] == 0.0f) r = true; return r; }
static inline bool XYZ0(const float* v) { bool r = false; if (XY0(v) && v[2] == 0.0f) r = true; return r; }

static inline void VCopyA(void* d, const void* s) {
    __int128 t;
    __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s));
    asm { sq t, 0(d) }
}

static inline void V4_Neg(V4* d, const V4* s) {
    __asm__ volatile("lqc2 vf1, 0x0(%1); vsub.xyz vf1, vf0, vf1; sqc2 vf1, 0x0(%0)" : : "r"(d), "r"(s) : "memory");
}

static inline void V4_MulRot(V4* d, const V4* s, const Mtx* b) {
    __asm__ volatile("lqc2 vf8, 0x0(%1); lqc2 vf4, 0x0(%2); lqc2 vf5, 0x10(%2); lqc2 vf6, 0x20(%2); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; sqc2 vf8, 0x0(%0)" : : "r"(d), "r"(s), "r"(b) : "memory");
}

extern "C" Mtx* Mtx_InvertRigid(Mtx* m) {
    float t;
    t = m->m[0][1]; m->m[0][1] = m->m[1][0]; m->m[1][0] = t;
    t = m->m[0][2]; m->m[0][2] = m->m[2][0]; m->m[2][0] = t;
    t = m->m[1][2]; m->m[1][2] = m->m[2][1]; m->m[2][1] = t;
    if (!XYZ0(m->m[3])) {
        V4 v;
        const float* src = m->m[3];
        VCopyA(&v, src);
        V4_Neg(&v, &v);
        V4_MulRot(&v, &v, m);
        VCopyA(m->m[3], &v);
    }
    return m;
}


