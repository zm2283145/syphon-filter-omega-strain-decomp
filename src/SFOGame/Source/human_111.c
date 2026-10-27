/*
 * SFOGame/Source/human: 3 files, 001B2750-001B2850
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001B2750 */
#pragma push /* merge_units */
// cVector_Transform_cQuatVecR: rotate point by placement quat, then add (w-scaled) position (VU0). Same idioms as cBoneIk_LimbPose_CalculateSkelSpacePos.c.
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
#pragma opt_propagation off

static inline void Add_(void* d, const void* o) { __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(d), "r"(o) : "memory"); }
static inline void Add2_(void* d, const void* o) { Add_(d, o); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; __int128 t; const V* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
    V& Rotate(const V& q) { __asm__ volatile("lqc2 vf1, 0x0(%0); vmove.w vf6, vf1; vmr32.w vf1, vf0; lqc2 vf2, 0x0(%1); vmove.w vf3, vf2; vsub.xyz vf3, vf0, vf2; vmul.xyzw vf4, vf2, vf1; vopmula.xyz ACC, vf2, vf1; vmaddaw.xyz ACC, vf1, vf2w; vopmsub.xyz vf5, vf1, vf2; vsubaz.w ACC, vf4, vf4z; vmsubay.w ACC, vf0, vf4y; vmsubx.w vf5, vf0, vf4x; vopmula.xyz ACC, vf5, vf3; vmaddaw.xyz ACC, vf5, vf3w; vmaddaw.xyz ACC, vf3, vf5w; vopmsub.xyz vf6, vf3, vf5; sqc2 vf6, 0x0(%0)" : : "r"(this), "r"(&q) : "memory"); return *this; }
    void Add3(const V& o) { __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(this), "r"(&o) : "memory"); }
    V operator*(float k) const;
    void AddP(V o) { const void* po = &o; Add2_(this, po); float* pw = &w; *pw = o.w; }
} __attribute__((aligned(16)));

// .set noreorder keeps the VU0 block intact (retail ends it with the scheduler nop).
static inline void ScaleTo(V* d, const V* s, float k) { int r; V* dd = d; asm {
        .set noreorder
        lqc2 vf1, 0x0(s)
        mfc1 r, k
        qmtc2.ni r, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(dd)
        .set reorder
    } }
inline V V::operator*(float k) const { V t; ScaleTo(&t, this, k); return t; }
struct Plc { V q; V pos; };
extern "C" V* cVector_Transform_cQuatVecR(V* p, Plc* m)
{
    const V& ppos = m->pos;
    p->Rotate(m->q);
    float* w = &p->w;
    float wv = *w;
    if (wv == 1.0f) {
        p->Add3(ppos);
    } else {
        p->AddP(ppos * wv);
    }
    return p;
}
static inline void merge_flush_func_001B2750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B2750 */

/* merge_units: begin func_001B2830 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* VecCurve_GetPrevious(char* self) {
    return self + 16;
}

void* cSplinedMotion_cVector_GetCurrVal(char* self) {
    return self + 32;
}
static inline void merge_flush_func_001B2830(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B2830 */

/* merge_units: begin func_001B2850 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma exceptions off
struct V4C4 { float x, y, z, w; V4C4() {} };
struct VecCurveBaseD4 {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual V4C4 get();
};
struct VecCurveD4 : VecCurveBaseD4 { char pad[0x1C]; V4C4 start; V4C4 cur; V4C4 rate; V4C4 x50; char x60[0x10]; };
extern "C" void cVector_opAssign(V4C4* d, V4C4* s);
extern "C" void cHermiteSplineWithScaledDuration_cVector_Reset(void* a, V4C4* b, V4C4* c, V4C4* d, V4C4* e);
extern "C" void cSplinedMotion_cVector_ResetCurrValAndZeroOutCurrVelocity(VecCurveD4* c, V4C4* v)
{
    V4C4 a = c->get();
    cVector_opAssign(&c->start, v);
    cVector_opAssign(&c->cur, &a);
    V4C4 b = c->get();
    cHermiteSplineWithScaledDuration_cVector_Reset(c->x60, &c->start, &c->cur, &c->rate, &b);
}
static inline void merge_flush_func_001B2850(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B2850 */
