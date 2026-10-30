// 00250AE0 LimitManualAimAngularAcceleration_ByScale: asm-lq copy ctor, free operator+ (tp;r;rp;op), Dot tp-before-bp,
// operator* delegating to Mul0 wrapper (fixes stack slot order), CSE on.
#pragma cplusplus on
#include "types.h"
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