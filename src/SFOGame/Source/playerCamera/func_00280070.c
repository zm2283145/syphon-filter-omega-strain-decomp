#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* cPlayerCamera::GetAngleToTarget: pitch/yaw from the pivot point (the camera position in
   third-person manual aim, else the given bone of the human) to the locked target's aim point;
   false when there is no live target. */
/* lq/sq quadword copies: 128-bit moves have no C equivalent */
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector Flat() const { return cVector(x, y, 0.0f, 0.0f); }
    cVector(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    cVector(const cVector& o) { cVector* d = this; const cVector* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    cVector& operator=(const cVector& o) { const void* xx = &o; cVector* d = this; const cVector* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
/* VU0 macro-mode vector ops (COP2), not expressible in C */
static inline cVector operator-(const cVector& a, const cVector& b) { cVector r; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory"); return r; }
static inline float Length(const cVector& v) { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(&v) : "memory"); return r; }
struct cEulerAngle_T { float x, y, z; };
struct cGOBJ {
    VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d) virtual cVector GetTargetPosition(int sub) const;
    int pad4[2];
    int id;
    char pad10[0x2C - 0x10];
    unsigned char b2C, b2D, b2E;
    char pad2F[0x50 - 0x2F];
    void* mXform;
};
struct cSkeleton;
static inline bool IsNullNV(void* p) { return !(p != 0); }
static inline int SameRef(const int& a, const int& b) { return (unsigned)(a ^ b) < 1; }
struct cSafePtr {
    cGOBJ* ptr; int id;
    int IsValid() { unsigned char ok = 1; if (!IsNullNV(ptr) && !SameRef(ptr->id, id)) ok = 0; return ok; }
    cGOBJ* Get() { return IsValid() ? ptr : 0; }
};
struct cPlayerCamera { char pad[0xD04]; cSafePtr target; int subTarget; };
extern "C" {
extern signed char ActorNodeCodeTable[];
cSkeleton* cSKM_GOBJ_GetSkeleton_void(const cGOBJ* h);
cVector cSkeleton_GetBoneToWorldTranslation(cSkeleton* s, int node);
float Libc_Atan2f(float y, float x);
bool cPlayerCamera_GetAngleToTarget(cPlayerCamera* self, cEulerAngle_T& angle, const cGOBJ* human, unsigned char pivotPoint_BoneIndex, bool isInThirdPersonManualAim, const cVector& cameraCurrPos);
}
static inline bool Not(unsigned char x) { return !x; }
static inline bool Ready(cGOBJ* t) { bool r = false; bool a = false; if (t->b2D && t->b2C) a = true; if (a && Not(t->b2E)) r = true; return r; }

bool cPlayerCamera_GetAngleToTarget(cPlayerCamera* self, cEulerAngle_T& angle, const cGOBJ* human, unsigned char pivotPoint_BoneIndex, bool isInThirdPersonManualAim, const cVector& cameraCurrPos)
{
    void* targetXform = self->target.Get() ? self->target.Get()->mXform : 0;
    if (targetXform && Ready(self->target.Get())) {
        cVector targetPoint = self->target.Get()->GetTargetPosition(self->subTarget);
        cVector targetFromPoint;
        if (isInThirdPersonManualAim)
            targetFromPoint = cameraCurrPos;
        else
            targetFromPoint = cSkeleton_GetBoneToWorldTranslation(cSKM_GOBJ_GetSkeleton_void(human), ActorNodeCodeTable[pivotPoint_BoneIndex]);
        {
            cVector targetDir = targetPoint - targetFromPoint;
            angle.x = Libc_Atan2f(targetDir.z, Length(targetDir.Flat()));
            angle.y = 0.0f;
            angle.z = Libc_Atan2f(-targetDir.x, targetDir.y);
        }
        return true;
    }
    return false;
}
