/*
 * SFOGame/Source/game: 2 files, 00133190-00133200
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00133190 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

typedef struct Mtx { float m[4][4]; } Mtx;

struct Transform {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual void Update(); /* +0x58 */
    char pad04[0x10 - 4];
    Mtx matrix;          /* +0x10 */
    unsigned char dirty; /* +0x50 */
};

extern "C" Mtx* cMatrix_ctor_cMatrixR(Mtx* dst, Mtx* src);
extern "C" Mtx* cMatrix_InvertRotTrans(Mtx* m);

/* Writes the inverse of the transform world matrix to out (updating it first when dirty). */
extern "C" void cXform_GetInverseMatrix(Mtx* out, Transform* xf)
{
    Mtx tmp;
    if (xf->dirty)
    xf->Update();
    cMatrix_ctor_cMatrixR(out, cMatrix_InvertRotTrans(cMatrix_ctor_cMatrixR(&tmp, &xf->matrix)));
}
static inline void merge_flush_func_00133190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00133190 */

/* merge_units: begin func_00133200 */
#pragma push /* merge_units */
/* cMatrix_InvertRotTrans: in-place inverse of a rigid transform (transpose the 3x3, translation = -(R^T t)). */
#pragma opt_lifetimes off
#pragma cplusplus on

typedef struct V4 { float x, y, z, w; } __attribute__((aligned(16))) V4;

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

extern "C" Mtx* cMatrix_InvertRotTrans(Mtx* m) {
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
static inline void merge_flush_func_00133200(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00133200 */
