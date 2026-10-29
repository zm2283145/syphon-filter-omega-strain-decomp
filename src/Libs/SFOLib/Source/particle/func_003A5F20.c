#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
typedef __int128 u_long128;
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& source) { u_long128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(this), "r"(&source) : "memory"); }
    cVector& operator=(const cVector& source) { void* xx = this; cVector& refThis = *this; u_long128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(&source) : "memory"); return refThis; }
    static void SubTo(cVector* a, const cVector* pv) {
        asm {
            lqc2 vf1, 0(a)
            lqc2 vf2, 0(pv)
            vsub.xyzw vf1, vf1, vf2
            sqc2 vf1, 0(a)
        }
    }
    cVector& operator-=(const cVector& vector) {
        SubTo(this, &vector);
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
        u_long128 t = 0;
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
    cVector(float vx, float vy, float vz, float vw) { x = vx; y = vy; z = vz; w = vw; }
    cVector operator+(const cVector& vector) const {
        cVector result;
        cVector* pr = &result;
        const cVector* pv = &vector;
        asm {
            lqc2 vf1, 0(this)
            lqc2 vf2, 0(pv)
            vadd.xyzw vf1, vf1, vf2
            sqc2 vf1, 0(pr)
        }
        return result;
    }
} __attribute__((aligned(16)));
struct cRandomVector {
    int index;
    float seedList[259];
    cVector& Vector(int index) const { return *(cVector*)&seedList[index & 0xff]; }
};
extern cRandomVector D_0053B6A0;
struct cWind {
    cVector wind[4];
    cVector periodRand[4];
    float minX, minY, max, period, periodMask, time;
    int frameLastUpdated;
};
extern "C" void cWind_Set(cWind* self, float minX, float minY, float maxVelocity, float period, float periodMask);
void cWind_Set(cWind* self, float minX, float minY, float maxVelocity, float period, float periodMask)
{
    int i;
    cVector randVector;
    self->minX = 0.0244444441f * minX;
    self->minY = 0.0244444441f * minY;
    self->max = 0.0244444441f * maxVelocity;
    self->period = period;
    self->periodMask = periodMask;
    self->frameLastUpdated = -1;
    for (i = 0; i < 4; i++) {
        randVector = D_0053B6A0.Vector(++D_0053B6A0.index);
        randVector -= cVector(0.5f, 0.5f, 0.5f, 0.0f);
        self->periodRand[i] = cVector(period, period, period, 0.0f) + randVector * (2.0f * periodMask);
    }
    self->time = 0.0f;
}
