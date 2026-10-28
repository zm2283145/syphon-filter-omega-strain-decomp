/*
 * SFOGame/Source/gameCamera: 3 files, 0017CEE0-0017D070
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0017CEE0 */
#pragma push /* merge_units */
/* cHermiteSpline::Evaluate(u): Hermite basis h0..h3 times P0, P1, T0, T1 summed with by-value operator+; product temps one inline level deeper (Scaled) to get retail's stack layout. */
#pragma cplusplus on
#pragma exceptions off
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; __int128 t; const V* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
    V operator*(float k) const;
} __attribute__((aligned(16)));
static inline void ScaleTo(V* d, const V* s, float k) { __int128 r = 0; V* dd = d; asm {
        .set noreorder
        lqc2 vf1, 0x0(s)
        mfc1 r, k
        qmtc2.ni r, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(dd)
        .set reorder
    } }
static inline V Scaled(const V& v, float k) { V t; ScaleTo(&t, &v, k); return t; } inline V V::operator*(float k) const { return Scaled(*this, k); }
static inline void AddTo(V* d, const V* a, const V* b) { asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    } }
static inline V operator+(V a, V b) { V t; const V* pa = &a; AddTo(&t, pa, &b); return t; }
struct CP {
    V position;
    V tangent;
    CP() {}
};
struct Arr { CP d[2]; const CP& operator[](int i) const { return d[i]; } };
struct HS {
    Arr mPoints;
    V Evaluate(float u) const;
};
inline V HS::Evaluate(float u) const
{
    float uSquared = u * u;
    float uCubed = uSquared * u;
    float h0 = 1.0f + (2.0f * uCubed - 3.0f * uSquared);
    float h1 = -2.0f * uCubed + 3.0f * uSquared;
    float h2 = u + (uCubed - 2.0f * uSquared);
    float h3 = uCubed - uSquared;
    return mPoints[0].position * h0 + mPoints[1].position * h1 + mPoints[0].tangent * h2 + mPoints[1].tangent * h3;
}
extern "C" V cHermiteSpline_cVector_Evaluate(const HS* s, float u)
{
    return s->Evaluate(u);
}
static inline void merge_flush_func_0017CEE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017CEE0 */

/* merge_units: begin func_0017D070 */
#pragma push /* merge_units */
#include "types.h"
#include "curve_count_down.h"

typedef struct { char pad[0xB4]; float fB4; } S17D070;
int cSplinedMotion_cVector_IsTransitionInProgress(S17D070* s) {
    return !(s->fB4 == 0.0f);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017D070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017D070 */

/* merge_units: begin func_0017D0A0 */
#pragma push /* merge_units */
/* Count a curve's remaining time down to zero. */
DEFINE_CURVE_COUNT_DOWN(cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_NextFrame)
static inline void merge_flush_func_0017D0A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017D0A0 */
