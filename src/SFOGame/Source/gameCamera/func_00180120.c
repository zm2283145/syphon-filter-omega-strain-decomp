#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma opt_common_subs off
#pragma peephole off

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct cQuaternion {
    float x, y, z, w;
    cQuaternion() {}
    cQuaternion(const cQuaternion& source) { cQuaternion* refThis = this; const cQuaternion* ps = &source; asm { lq ps, 0(ps); sq ps, 0(refThis) } }
    cQuaternion& operator=(const cQuaternion& source) { cQuaternion* refThis = this; const cQuaternion* ps = &source; { u_long128 reg; asm { lq reg, 0(ps); sq reg, 0(refThis) } } return *refThis; }
    static void VU0Multiply(cQuaternion* result, const cQuaternion* quat0, const cQuaternion* quat1)
    {
        asm {
            lqc2 vf1, 0x0(quat0)
            lqc2 vf2, 0x0(quat1)
            vmul.xyzw vf3, vf1, vf2
            vopmula.xyz ACC, vf1, vf2
            vmaddaw.xyz ACC, vf1, vf2w
            vmaddaw.xyz ACC, vf2, vf1w
            vopmsub.xyz vf4, vf2, vf1
            vsubaz.w ACC, vf3, vf3z
            vmsubay.w ACC, vf0, vf3y
            vmsubx.w vf4, vf0, vf3x
            sqc2 vf4, 0x0(result)
        }
    }
    cQuaternion operator*(const cQuaternion& quaternion) const { cQuaternion result; VU0Multiply(&result, this, &quaternion); return result; }
} __attribute__((aligned(16)));
struct cHermiteSplineControlPoint { cQuaternion mPosition; cQuaternion mTangent; };
struct cControlPoints { cHermiteSplineControlPoint a[2]; cHermiteSplineControlPoint& operator[](int i) { return a[i]; } };
struct cSplinedMotion_QuaternionLERP {
    void* vtable; char pad4[0xC];
    cQuaternion prev;
    cQuaternion curr;
    cQuaternion vel;
    cQuaternion target;
    float damp;
    cControlPoints mControlPoints; /* spline at 0x60 */
    void TeleportByDelta(const cQuaternion& delta);
};
inline void cSplinedMotion_QuaternionLERP::TeleportByDelta(const cQuaternion& delta)
{
    prev = delta * prev;
    curr = delta * curr;
    target = delta * target;
    { cQuaternion& p = mControlPoints[0].mPosition; p = delta * p; }
    { cQuaternion& p = mControlPoints[1].mPosition; p = delta * p; }
}
extern "C" void cSplinedMotion_QuaternionLERP_1_TeleportByDelta(cSplinedMotion_QuaternionLERP* o, const cQuaternion& d) { o->TeleportByDelta(d); }
