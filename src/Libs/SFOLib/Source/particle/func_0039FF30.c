#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
typedef __int128 u_long128;
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& source) { void* xx = this; cVector& refThis = *this; u_long128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(&source) : "memory"); }
    cVector& operator=(const cVector& source) { void* xx = this; cVector& refThis = *this; u_long128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(&source) : "memory"); return refThis; }
    cVector& operator-=(const cVector& vector) {
        const cVector* pv = &vector;
        asm {
            lqc2 vf1, 0(this)
            lqc2 vf2, 0(pv)
            vsub.xyzw vf1, vf1, vf2
            sqc2 vf1, 0(this)
        }
        return *this;
    }
    unsigned char IsZeroXYZ() const {
        int k, fl;
        int r = 0;
        asm {
            .set noreorder
            lqc2 vf1, 0(this)
            vaddx.xyz vf1, vf1, vf0x
            and r, zero, zero
            ori k, zero, 0xE
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
    cVector& Normalize(float& returnLength) {
        cVector& refThis = *this; u_long128 reg = 0; float* pl = &returnLength;
        asm {
            lqc2 vf1, 0(this)
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
            sqc2 vf1, 0(this)
            qmfc2.ni reg, vf4
            sw reg, 0(pl)
        }
        
        return refThis;
    }
    cVector GetNormalized(float& returnLength) const { return cVector(*this).Normalize(returnLength); }
    cVector operator*(float scale) const {
        int t;
        cVector result;
        cVector* pr = &result;
        asm {
            .set noreorder
            lqc2 vf1, 0(this)
            mfc1 t, scale
            qmtc2.ni t, vf2
            vmulx.xyzw vf1, vf1, vf2x
            sqc2 vf1, 0(pr)
            .set reorder
        }
        return result;
    }
} __attribute__((aligned(16)));
static inline float fabs_(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
struct cParticleSpline;
extern "C" void cParticleSpline_SplineComputeForceNormal(cParticleSpline* o, cVector& force, const cVector& pt1, const cVector& pt2, float desiredDistance, float k);
void cParticleSpline_SplineComputeForceNormal(cParticleSpline* o, cVector& force, const cVector& pt1, const cVector& pt2, float desiredDistance, float k)
{
    force = pt1;
    force -= pt2;
    if (!force.IsZeroXYZ()) {
        cVector forceNormal; float distance; forceNormal = force.GetNormalized(distance);
        if (fabs_(distance - desiredDistance) > k) {
            force = forceNormal * k;
        }
    }
}
