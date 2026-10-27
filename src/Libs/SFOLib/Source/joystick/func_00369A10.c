/* cJoyPad_ApplyDeadZone (proto cJoyPad::ApplyDeadZone(const cJoyXYVector&, eDeadZoneType) const):
 * applies the pad's dead zone to an analog stick vector, either per axis (type 0) or radially
 * on the vector length (type 1), rescales by the dead-zone multiplier and clamps to +-127.5. */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on

typedef struct cJoyXYVector {
    float jx;
    float jy;
} cJoyXYVector;
typedef struct cVector {
    float x, y, z, w;
} __attribute__((aligned(16))) cVector;
typedef struct cJoyPad {
    char pad0[0x11C];
    float deadZone[2];
    float deadZoneMultiplier[2];
} cJoyPad;

static inline void SetV(cVector* v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }
/* VU0 length of the xyz part (vsqrt through Q). */
static inline float Length(cVector* v)
{
    float len;
    int t;
    __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2 %1, $vf4; mtc1 %1, %0" : "=f"(len), "=&r"(t) : "r"(v) : "memory");
    return len;
}
/* VU0 scale of all four components. noreorder: retail has no hazard nop between the mfc1 and the qmtc2. */
static inline void Scale(cVector* v, float s)
{
    int t;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %2; qmtc2 %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(v), "f"(s) : "memory");
}
/* max.s/min.s: C has no expression that emits these. */
static inline float Clamp(float v)
{
    float r;
    float lo = -127.5f;
    float hi = 127.5f;
    asm {
        max.s r, v, lo
        min.s r, r, hi
    }
    return r;
}
static inline float Axis(const cJoyPad* self, const float& vr, int i, float z)
{
    float r = z;
    float v = vr;
    if (v < r) {
        if (v < -self->deadZone[i])
            r = self->deadZoneMultiplier[i] * (v + self->deadZone[i]);
    } else if (!(v <= self->deadZone[i])) {
        r = self->deadZoneMultiplier[i] * (v - self->deadZone[i]);
    }
    return Clamp(r);
}

extern "C" void cJoyPad_ApplyDeadZone(cJoyXYVector* out, const cJoyPad* self, const cJoyXYVector* vec, unsigned char deadZoneType)
{
    float zero = 0.0f; /* one zero register shared by the radial path (retail keeps it across the VU0 asm) */
    cJoyXYVector resultVec;
    resultVec.jx = 0.0f;
    resultVec.jy = 0.0f;
    switch (deadZoneType) {
    case 0:
        resultVec.jx = Axis(self, vec->jx, 0, 0.0f);
        resultVec.jy = Axis(self, vec->jy, 0, 0.0f);
        break;
    case 1: {
        cVector vector;
        float length;
        SetV(&vector, vec->jx, vec->jy, zero, zero);
        cVector* pv = &vector;
        length = Length(pv);
        if (zero != length) {
            Scale(pv, 1.0f / length);
            length = Axis(self, length, 1, zero);
            Scale(&vector, length);
            resultVec.jx = vector.x;
            resultVec.jy = vector.y;
        }
    } break;
    }
    *out = resultVec;
}
