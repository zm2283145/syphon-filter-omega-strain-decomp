/*
 * main/game: range (6 files, 00131B10-00131C70)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00131B10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cLosRequestMessage_dtor, D_004D9180, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00131B10 */

/* merge_units: begin func_00131B70 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cCollisionFace_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00131B70 */

/* merge_units: begin func_00131BC0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cCollisionModel_FaceProperties_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00131BC0 */

/* merge_units: begin func_00131C10 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { __int128 q[4]; } M31C10_;
typedef struct { char pad[0x10]; M31C10_ m; } S31C10_;
#pragma peephole off
void TransformNode_SetMatrix(S31C10_* dst, M31C10_* src)
{
    M31C10_* d = &dst->m;
    __int128 qa, qb;
    qa = src->q[0]; qb = src->q[1];
    d->q[0] = qa; qa = src->q[2];
    d->q[1] = qb; qb = src->q[3];
    d->q[2] = qa;
    d->q[3] = qb;
}
#pragma peephole reset
#pragma pop /* merge_units */
/* merge_units: end func_00131C10 */

/* merge_units: begin func_00131C40 */
#pragma push /* merge_units */
#include "vu0_ops.h"
typedef struct { float m[4][4]; } __attribute__((aligned(16))) Mtx;
Mtx* Mtx_SetIdentity(Mtx* m) {
    VU0_UnitMatrix(m);
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_00131C40 */

/* merge_units: begin func_00131C70 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
static inline float Fabs(float x) { float r; asm { abs.s r, x } return r; }
static inline void Nrm_(void* p) { __asm__ volatile("lqc2 vf1, 0x0(%0); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vrsqrt Q, vf0w, vf3w; vwaitq; vmulq.xyz vf1, vf1, Q; sqc2 vf1, 0x0(%0)" : : "r"(p) : "memory"); }
static inline void Crs_(void* d, const void* l, const void* r) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vopmula.xyz ACC, vf1, vf2; vopmsub.xyz vf3, vf2, vf1; vsubw.w vf3, vf0, vf0w; sqc2 vf3, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { void* xx = this; x = a; y = b; z = c; w = d; }
    V(const V& o) { V* d = this; const V* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
    V(const V& a, const V& b, int) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vopmula.xyz ACC, vf1, vf2; vopmsub.xyz vf3, vf2, vf1; vsubw.w vf3, vf0, vf0w; sqc2 vf3, 0x0(%0)" : : "r"(this), "r"(&a), "r"(&b) : "memory"); }
    V& operator=(const V& o) { Q16(this, &o); return *this; }
    V& NormalizeR() { V* p = this; __asm__ volatile("lqc2 vf1, 0x0(%0); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vrsqrt Q, vf0w, vf3w; vwaitq; vmulq.xyz vf1, vf1, Q; sqc2 vf1, 0x0(%0)" : : "r"(p) : "memory"); return *p; }
    void Normalize() { Nrm_(this); }

} __attribute__((aligned(16)));
static inline V Cross(const V& a, const V& b) { V c; Crs_(&c, &a, &b); return c; }
struct M;
extern "C" void Mtx_SetBasis(M* m, V* a, V* b, V* c);
extern "C" void Mtx_SetTranslation(M* m, V* t);
struct M { V r[3]; V t; void Set(const V& a, const V& b, const V& c, const V& d) { Mtx_SetBasis(this, (V*)&a, (V*)&b, (V*)&c); Mtx_SetTranslation(this, (V*)&d); } };
static inline V Normalized(V v) { v.Normalize(); return v; }
static inline V NormalizedL(const V& v) { V t(v); V* p = &t; p->Normalize(); return *p; }
static inline void CrossTo(V* c, const V* a, const V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vopmula.xyz ACC, vf1, vf2; vopmsub.xyz vf3, vf2, vf1; vsubw.w vf3, vf0, vf0w; sqc2 vf3, 0x0(%0)" : : "r"(c), "r"(a), "r"(b) : "memory"); }
extern "C" {
extern signed char D_004E1DA0;
extern signed char D_004E1DA8;
extern V D_00497F20;
extern V D_00497F30;
void Mtx_SetBasis(M* m, V* a, V* b, V* c);
void Mtx_SetTranslation(M* m, V* t);
}
static inline V& XAxis()
{
    if (!D_004E1DA0) {
        D_00497F20.x = 1.0f; D_00497F20.y = 0.0f; D_00497F20.z = 0.0f; D_00497F20.w = 0.0f;
        D_004E1DA0 = 1;
    }
    return D_00497F20;
}
static inline V& ZAxis()
{
    if (!D_004E1DA8) {
        D_00497F30.x = 0.0f; D_00497F30.y = 0.0f; D_00497F30.z = 1.0f; D_00497F30.w = 0.0f;
        D_004E1DA8 = 1;
    }
    return D_00497F30;
}
extern "C" M* Mtx_FrameFromAxis(M* m, V* axis)
{
    XAxis();
    ZAxis();
    const V* up = Fabs(axis->z) < 0.70700002f ? &D_00497F30 : &D_00497F20;
    V f = NormalizedL(*axis);
    V r = Normalized(Cross(*axis, *up));
    V u = Cross(r, f);
    m->Set(r, f, u, V(0.0f, 0.0f, 0.0f, 1.0f));
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_00131C70 */
