/*
 * Libs/SFOLib/Source/physics: 1 file, 003A8C80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A8C80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { V* d = this; void* xx = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    V operator-(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory");
        return c;
    }
    V operator*(float s) const {
        V c; __int128 t = 0; V* q = &c; const V* v = this;
        __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory");
        return c;
    }
} __attribute__((aligned(16)));

static inline void CP(V* d, const V* s) { __asm__ volatile("lq %0, 0x0(%0); sq %0, 0x0(%1)" : "+r"(s) : "r"(d) : "memory"); }
static inline int IsZero(const V* v)
{
    int k, fl;
    unsigned char r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyzw vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline void NL_(V* pv, float* l) {
    __int128 t = 0;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; vdiv $Q, $vf0w, $vf4x; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%1); qmfc2.ni %0, $vf4" : "+r"(t) : "r"(pv), "r"(l) : "memory");
    __asm__ volatile("sw %0, 0x0(%1)" : : "r"(t), "r"(l) : "memory");
}
static inline void NLW(V* pv, float* l) { NL_(pv, l); }
static inline V NormalizeLen(const V& in, float* len)
{
    float* l = len;
    V v = in;
    V* pv = &v;
    NLW(pv, l);
    return *pv;
}
static inline void AddTo(float& a, float b) { a += b; }
static inline float Sq(float x) { return x * x; }
static inline void ZeroF(float* p) { *p = 0.0f; }
static inline float Sqrt(float x) { float r = 0.0f; __asm__ volatile("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline float MaxF(float a, float b) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float Clamp(float x, float lo, float hi) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2; min.s %0, %0, %3" : "+f"(r) : "f"(x), "f"(lo), "f"(hi)); return r; }

extern "C" float Libc_Atan2f(float y, float x);
extern "C" float Libc_Tanf(float x);
extern "C" void nPhysics_CalculateInitialVelocityForTrajectory(V* out, const V* from, const V* to, V* extra, float g, float k, float minAng);

void nPhysics_CalculateInitialVelocityForTrajectory(V* out, const V* from, const V* to, V* extra, float g, float k, float minAng)
{
    V e = *to - *from;
    V dh;
    V vel;
    V dir;
    V h;
    V res;
    float time;
    h = e;
    h.z = 0.0f;
    void* xx = &h;
    if (IsZero(&h)) {
        __asm__ volatile("sq $0, 0x0(%0)" : : "r"(&dir) : "memory");
        ZeroF(&dh.x);
    } else {
        dir = NormalizeLen(h, &dh.x);
    }
    dh.z = 0.0f;
    dh.y = e.z;
    if (dh.x != 0.0f) {
        float a = Libc_Atan2f(dh.y, dh.x);
        float t;
        if (a > 0.0f) t = k * (1.5707964f - a);
        else { float hp = 1.5707964f; t = k * hp; }
        t = MaxF(0.0f, t);
        a = a + t;
        a = MaxF(minAng, a);
        a = Clamp(a, -1.5707946f, 1.5707946f);
        if (a) {
            float tn = Libc_Tanf(a);
            float num = g * Sq(dh.x) * Sq(tn);
            float den = 2.0f * (dh.y - tn * dh.x);
            if (!(den < 0.0f)) den = -1.1754944e-38f;
            vel.y = Sqrt(num / den);
            if (tn < 0.0f) vel.y = -vel.y;
            vel.x = vel.y / tn;
        } else {
            vel.x = Sqrt(g * Sq(dh.x) / (2.0f * dh.y));
            vel.y = 0.0f;
        }
        time = g * dh.x / vel.x;
    } else {
        vel.x = 0.0f;
        if (dh.y > 0.0f) {
            vel.y = Sqrt(-2.0f * g * dh.y);
            time = -vel.y;
        } else {
            vel.y = 0.0f;
            time = Sqrt(2.0f * g * dh.y);
        }
    }
    res = dir * vel.x;
    res.z = vel.y;
    if (extra) {
        const V* s = &res;
        float* pz = &extra->z;
        CP(extra, s);
        *pz += time;
    }
    *out = res;
}
static inline void merge_flush_func_003A8C80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A8C80 */
