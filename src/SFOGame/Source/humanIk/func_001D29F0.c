/* 001D29F0 nIk_ApplyJointLimits -- nIk::ApplyJointLimits (humanIk.cc). l5 match. */
#pragma cplusplus on
#include "types.h"
typedef __int128 u_long128;
#pragma inline_depth(10)
#pragma peephole on
#pragma opt_propagation off
#pragma opt_common_subs on
#pragma opt_dead_assignments off

class cVector {
public:
    float x, y, z, w;
    cVector() {}
    cVector(float ax, float ay, float az, float aw) {  x = ax; y = ay; z = az; w = aw; }
    cVector(const cVector& source) { cVector& refThis = *this; u_long128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(&source) : "memory"); }
    float X() const { return x; }
    float Y() const { return y; }
    float Z() const { return z; }
} __attribute__((aligned(16)));

class cQuaternion {
public:
    float x, y, z, w;
    cQuaternion& operator=(const cQuaternion& o) { u_long128 reg; const cQuaternion* s = &o; cQuaternion* d = this; asm volatile { lq reg, 0(s); sq reg, 0(d) } return *this; }
    unsigned char IsZeroXYZ() const
    {
        int k, f, r;
        const cQuaternion* v = this;
        asm volatile {
            .set noreorder
            lqc2 vf1, 0(v)
            vaddx.xyz vf1, vf1, vf0x
            and r, zero, zero
            ori k, zero, 0xE
            vnop
            vnop
            vnop
            vnop
            cfc2.ni f, vi17
            bne k, f, done
            nop
            ori r, zero, 1
        done:
            .set reorder
        }
        return r;
    }
    float X() const { return x; }
    float Y() const { return y; }
    float Z() const { return z; }
    float W() const { return w; }
    float& X() { return x; }
    float& Y() { return y; }
    float& Z() { return z; }
    float& W() { return w; }
} __attribute__((aligned(16)));

static inline cVector& Normalize(const cVector& vv, float& returnLength)
{
        cVector* v = (cVector*)&vv; u_long128 reg = 0; float* pl = &returnLength;
        asm {
            lqc2 vf1, 0(v)
            vmul.xyz vf2, vf1, vf1
            vmulax.w ACC, vf0, vf2x
            vmadday.w ACC, vf0, vf2y
            vmaddz.w vf3, vf0, vf2z
            vsqrt Q, vf3w
            vwaitq
            vaddq.x vf4, vf0, Q
            vdiv Q, vf0w, vf4x
            vwaitq
            vmulq.xyz vf1, vf1, Q
            sqc2 vf1, 0(v)
            qmfc2.ni reg, vf4
            sw reg, 0(pl)
        }
    return (cVector&)vv;
}
class cJointLimits {
public:
    float x, y, z, pad;
} __attribute__((aligned(16)));

static inline float SQUARE(float f) { return f * f; }
static inline float SQRT(float x) { float r = 0.0f; asm volatile { sqrt.s r, x } return r; }
static inline float CLAMP_LOW(float a, float b) { float r = 0.0f; float bb = b; asm volatile { max.s a, bb, a } r = a; return r; }

extern "C" unsigned char nIk_ApplyJointLimits(cQuaternion& output, const cQuaternion& input, const cJointLimits& oneOverLimitSinHalfAngleSquared)
{
    if (input.IsZeroXYZ()) {
        output = input;
        return false;
    }
    float sinHalfAngle;
    
    cVector axis(Normalize(cVector(input.X(), input.Y(), input.Z(), 0.0f), sinHalfAngle));
    float limitSinSquared = 0.0f;
    u_long128 reg;
    __asm__ volatile("lqc2 vf1, 0(%1)\n lqc2 vf2, 0(%2)\n vmul.xyz vf3, vf1, vf1\n vmul.xyz vf4, vf3, vf2\n vmulax.w ACC, vf0, vf4x\n vmadday.w ACC, vf0, vf4y\n vmaddz.w vf5, vf0, vf4z\n vdiv Q, vf0w, vf5w\n vwaitq\n vaddq.x vf6, vf0, Q\n qmfc2.ni %0, vf6" : "=r"(reg) : "r"(&axis), "r"(&oneOverLimitSinHalfAngleSquared));
    __asm__ volatile("mtc1 %1, %0" : "=f"(limitSinSquared) : "r"(reg));
    if (SQUARE(sinHalfAngle) > limitSinSquared || input.W() < 0.0f) {
        float limitCosSquared = CLAMP_LOW(1.0f - limitSinSquared, 0.0f);
        output.W() = SQRT(limitCosSquared);
        float limitSin = SQRT(limitSinSquared);
        output.X() = limitSin * axis.X();
        output.Y() = limitSin * axis.Y();
        output.Z() = limitSin * axis.Z();
        return true;
    }
    output = input;
    return false;
}
