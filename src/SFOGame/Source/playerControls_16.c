/*
 * SFOGame/Source/playerControls: 5 files, 002507B0-00250E70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002507B0 */
#pragma push /* merge_units */
#include "types.h"

#pragma cplusplus on

typedef struct { int sel; int bits[1]; } Sel250;
static inline bool Sel250_Test(Sel250* s, int i) { return ((s->bits[i / 32] >> (i & 31)) & 1) ? true : false; }
extern "C" Sel250* cModeSwitch_2_ctor(Sel250* s, int n) {
    int i;
    s->bits[0] = 0;
    s->bits[0] |= 1;
    s->bits[0] &= ~2;
    s->bits[n / 32] |= 1 << (n & 31);
    i = 1;
    while (i >= 0 && !Sel250_Test(s, i)) i--;
    if (!Sel250_Test(s, i)) s->sel = -1;
    else s->sel = i;
    return s;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002507B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002507B0 */

/* merge_units: begin func_002508A0 */
#pragma push /* merge_units */
typedef struct { int top; int w[1]; } PS_2508A0;
static inline void BSet_2508A0(PS_2508A0* p, int i) { p->w[i / 32] |= 1 << (i & 31); }
static inline void BClr_2508A0(PS_2508A0* p, unsigned int i) { p->w[(int)i / 32] &= ~(1 << (i & 31)); }
static inline unsigned char BTest_2508A0(PS_2508A0* p, int i) { return ((p->w[i / 32] >> (i & 31)) & 1) != 0; }
#pragma opt_rotateloops off
PS_2508A0* cModeSwitch_12_ctor_uint_2(PS_2508A0* p, int v)
{
    int i;
    p->w[0] = 0;
    BSet_2508A0(p, 0);
    for (i = 1; i < 12; i++) BClr_2508A0(p, i);
    BSet_2508A0(p, v);
    for (i = 11; i >= 0 && !BTest_2508A0(p, i); i--) ;
    if (!BTest_2508A0(p, i)) p->top = -1; else p->top = i;
    return p;
}
#pragma opt_rotateloops reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002508A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002508A0 */

/* merge_units: begin func_00250AE0 */
#pragma push /* merge_units */
// 00250AE0 LimitManualAimAngularAcceleration_ByScale: asm-lq copy ctor, free operator+ (tp;r;rp;op), Dot tp-before-bp,
// operator* delegating to Mul0 wrapper (fixes stack slot order), CSE on.
#pragma cplusplus on
#pragma inline_depth(8)

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *(__int128*)d = t; }
    V& operator=(const V& o) { V* d = this; const V* s = &o; *(__int128*)d = *(const __int128*)s; return *this; }
    void Zero() { __asm__ volatile("sq $0, 0x0(%0)" : : "r"(this) : "memory"); }
    V operator-(const V& o) const { V r; V* rp = &r; const V* tp = this; const V* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }

    V Mul0(float k) const { V r; int t; V* q = &r; const V* p = this; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%2); .set reorder" : "=r"(t) : "r"(p), "r"(q), "f"(k) : "memory"); return *q; }
    V operator*(float k) const { return Mul0(k); }
    void Normalize() { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(this) : "memory"); }
    V GetNormalized() const { V r = *this; V* p = &r; p->Normalize(); return *p; }
    V Scale(float k) const { V r; V* q = &r; __int128 z = 0; const V* p = this; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%2); .set reorder" : "+r"(z) : "r"(p), "r"(q), "f"(k) : "memory"); return *q; }
    float Dot(const V& b) const { const V* tp = this; const V* bp = &b; int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=r"(t) : "r"(tp), "r"(bp) : "memory"); return r; }
    float LenSq() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "=f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
} __attribute__((aligned(16)));

static inline V operator+(const V& a, const V& b) { const V* tp = &a; V r; V* rp = &r; const V* op = &b; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
static inline float FMin(float a, float b) { float r = 0.0f; __asm__ volatile("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }


extern "C" void LimitManualAimAngularAcceleration_ByScale(V& modifiedVelocity, const V& currVelocity, const V& prevVelocity, float limitingScale_Accel, float limitingScale_Decel, float minDeltaVelocitySquared, float minNonZeroVelocitySquared, float deltaTime)
{
    V deltaVelocity = currVelocity - prevVelocity;
    if (deltaVelocity.LenSq() >= minDeltaVelocitySquared) {
        V dir;
        if (prevVelocity.LenSq() >= minNonZeroVelocitySquared) dir = prevVelocity.GetNormalized(); else dir.Zero();
        float deltaVelocityAlongDir = deltaVelocity.Dot(dir);
        V deltaVelocity_Decel;
        if (deltaVelocityAlongDir < 0.0f) deltaVelocity_Decel = dir * deltaVelocityAlongDir; else deltaVelocity_Decel.Zero();
        V deltaVelocity_Accel = deltaVelocity - deltaVelocity_Decel;
        V scaledDeltaVelocity_Accel = deltaVelocity_Accel.Scale(FMin(1.0f, limitingScale_Accel * deltaTime));
        V scaledDeltaVelocity_Decel = deltaVelocity_Decel.Scale(FMin(1.0f, limitingScale_Decel * deltaTime));
        modifiedVelocity = prevVelocity + scaledDeltaVelocity_Accel + scaledDeltaVelocity_Decel;
    } else {
        modifiedVelocity = currVelocity;
    }
}
static inline void merge_flush_func_00250AE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00250AE0 */

/* merge_units: begin func_00250D80 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
static inline void Q16(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& o) { V4* p = this; __int128 q; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(q) : "r"(&o) : "memory"); *(__int128*)p = q; }
} __attribute__((aligned(16)));
static inline V4 Sub(const V4& a, const V4& b) {
    V4 r;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void AddV(V4* r, const V4* a, const V4* b) {
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline V4 Add(const V4& a, const V4& b) { V4 r; AddV(&r, &a, &b); return r; }
static inline V4 Mul(const V4& v, float k) {
    V4 r; __int128 t = 0;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(&r), "r"(&v), "f"(k) : "memory");
    return r;
}
static inline float LenSq(V4* v) {
    float r = 0.0f; int t;
    asm {
        lqc2 vf1, 0x0(v)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni t, vf4
        mtc1 t, r
    }
    return r;
}
static inline float Min(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }
extern "C" V4 PlayerInput_SmoothAimVector(V4* a, V4* b, float f, float lim, float g);
V4 PlayerInput_SmoothAimVector(V4* a, V4* b, float f, float lim, float g)
{
    V4 d = Sub(*a, *b);
    if (LenSq(&d) >= lim) {
        float s = Min(1.0f, f * g);
        V4 t = Mul(d, s);
        V4 r = Add(*b, t);
        return r;
    }
    return *a;
}
static inline void merge_flush_func_00250D80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00250D80 */

/* merge_units: begin func_00250E70 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_resize.h"
DEFINE_RESIZE_ELEMENT(Elem8_0E70, 8)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(std_vector_imp_cTargetZRotationStackSlot_resize, Elem8_0E70, std_vector_imp_cTargetZRotationStackSlot_insert, std_vector_imp_cTargetZRotationStackSlot_erase)
#pragma opt_common_subs reset
static inline void merge_flush_func_00250E70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00250E70 */
