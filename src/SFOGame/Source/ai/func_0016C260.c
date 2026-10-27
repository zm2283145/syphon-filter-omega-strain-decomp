#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"
/* cAITarget::TestPointInViewCone: whether a point lies inside the owner's view cone - within
   the (darkness-scaled) view radius of the eye position and inside the half angle around the
   facing direction (eye bone or the virtual eye transform). */
/* lq/sq quadword copies: 128-bit moves have no C equivalent */
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& o) { cVector* d = this; const cVector* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    cVector& operator=(const cVector& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
    /* VU0 macro-mode vector ops (COP2), not expressible in C */
    cVector& operator-=(const cVector& o) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(this), "r"(this), "r"(&o) : "memory"); return *this; }
    cVector& Normalize(float* len) {
        __int128 t = 0; int r; float* p;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; vdiv $Q, $vf0w, $vf4x; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%2); qmfc2.ni %0, $vf4" : "=r"(r), "=r"(p) : "r"(this), "0"(t), "1"(len) : "memory");
        *(int*)p = r;
        return *this;
    }
} __attribute__((aligned(16)));
static inline float Dot(const cVector& a, const cVector& b) {
    int t; float r = 0.0f;
    __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2 %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(&a), "r"(&b) : "memory");
    return r;
}
struct cMatrix { cVector r[4]; cMatrix() {} const cVector& GetTranslation() const { return r[3]; } const cVector& GetForward() const { return r[1]; } };
struct cSkeleton;
struct cHuman {
    VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d) virtual cVector GetTargetPosition(int sub) const;
    VPAD8(e) VPAD1(f) virtual cMatrix GetEyeTransform() const;
    char pad4[0x28];
    unsigned char b2C, b2D, b2E;
    char pad2F[0x33A8 - 0x2F];
    float x33A8;
};
struct cAI { char pad[0x30]; cHuman* human; };
struct cAITarget { cVector targetPositionLastSeen; float viewConeRadius; float viewConeHalfAngle; char pad18[0x3C - 0x18]; cAI* ai;
    cHuman* GetHuman() const { return ai->human; } };
extern "C" {
extern signed char g_HeadNodeCode;
cSkeleton* cSKM_GOBJ_GetSkeleton_void(cHuman* h);
cMatrix cSkeleton_GetBoneToWorldMatrix(cSkeleton* s, int node);
float Libc_Cosf(float a);
bool cAITarget_TestPointInViewCone(const cAITarget* self, const cVector& testPoint, bool useAimDirection, int darkness);
}
static inline bool Not(unsigned char x) { return !x; }
static inline bool Ready(cHuman* t) { bool r = false; bool a = false; if (t->b2D && t->b2C) a = true; if (a && Not(t->b2E)) r = true; return r; }

bool cAITarget_TestPointInViewCone(const cAITarget* self, const cVector& testPoint, bool useAimDirection, int darkness)
{
    bool res;
    cVector pos;
    float viewConeRadius = self->viewConeRadius;
    cHuman& human = *self->GetHuman();
    float distanceToTarget;
    res = false;
    if (human.x33A8 <= 0.0f) {
        if (!useAimDirection || !Ready(self->GetHuman()))
            pos = self->GetHuman()->GetTargetPosition(-1);
        else
            pos = cSkeleton_GetBoneToWorldMatrix(cSKM_GOBJ_GetSkeleton_void(&human), g_HeadNodeCode).GetTranslation();
        {
            cVector deltaToTarget = testPoint;
            (deltaToTarget -= pos).Normalize(&distanceToTarget);
            if (darkness > 0)
                viewConeRadius *= (100.0f - darkness) / 100.0f;
            if (distanceToTarget < viewConeRadius && distanceToTarget != 0.0f) {
                if (distanceToTarget > 1.0f) {
                    cVector direction;
                    float cosAngle;
                    if (!useAimDirection || !Ready(self->GetHuman()))
                        direction = self->GetHuman()->GetEyeTransform().GetForward();
                    else
                        direction = cSkeleton_GetBoneToWorldMatrix(cSKM_GOBJ_GetSkeleton_void(&human), g_HeadNodeCode).GetForward();
                    cosAngle = Dot(direction, deltaToTarget);
                    if (cosAngle + (1.0f - Libc_Cosf(self->viewConeHalfAngle)) > 1.0f)
                        res = true;
                } else {
                    res = true;
                }
            }
        }
    }
    return res;
}
