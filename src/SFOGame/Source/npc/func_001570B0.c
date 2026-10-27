#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"
/* cNPC::RecommendAIMode: weigh the NPC's chance to hit against the target's threat (plus a
   penalty while reloading or when the target is out of range) and recommend an attack mode. */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& o) { cVector* d = this; const cVector* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    /* VU0 macro-mode vector ops (COP2), not expressible in C */
    cVector& operator-=(const cVector& o) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(this), "r"(this), "r"(&o) : "memory"); return *this; }
    float Length() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct cMatrix { cVector r[4]; cMatrix() {} const cVector& GetTranslation() const { return r[3]; } };
struct cGOBJ { char pad[0xC]; int id; };
static inline bool IsNullNV(void* p) { return !(p != 0); }
static inline int SameRef(const int& a, const int& b) { return (unsigned)(a ^ b) < 1; }
struct cSafePtr {
    cGOBJ* ptr; int id;
    int IsValid() { unsigned char ok = 1; if (!IsNullNV(ptr) && !SameRef(ptr->id, id)) ok = 0; return ok; }
    cGOBJ* Get() { return IsValid() ? ptr : 0; }
};
struct cAITarget {
    cVector targetPositionLastSeen;
    float viewConeRadius, viewConeHalfAngle;
    int nodeGroup, priority;
    unsigned char targetInViewConeFlag : 1, targetInBodyViewConeFlag : 1, targetLOSFlag : 1, targetSeenFlag : 1, targetPositionValid : 1, targetDirectionValid : 1, prevVisibleFlag : 1, targetLOSCheckedLastUpdate : 1;
    char pad21[0x40 - 0x21];
    cSafePtr targetGobj;
    cGOBJ* GetTargetGobj() { return targetGobj.Get(); }
};
struct cWeapon { char pad[0xA0]; unsigned char reloading; };
struct cHuman {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e)
    virtual cMatrix GetMatrix() const;
    char pad4[0x3524 - 4];
    cWeapon* weapon;
};
struct cNPC {
    VPAD32(a) VPAD32(b) VPAD32(c) VPAD4(d) VPAD2(e) VPAD1(f)
    virtual int GetCurrentMode();
    VPAD4(g) VPAD2(h)
    virtual int GetModeForState(int s);
    char pad4[0x1C];
    float accuracy;             /* 0x20 */
    float accuracyScale;        /* 0x24 */
    float GetAccuracy() const { float s = accuracyScale; float a = accuracy; return a * s; }
    char pad28[8];
    cHuman* owner;              /* 0x30 */
    char pad34[0x6C - 0x34];
    float aggression;           /* 0x6C */
    char pad70[0xA4 - 0x70];
    int reloadThreshold;        /* 0xA4 */
    char padA8[0xB8 - 0xA8];
    float attackRange;          /* 0xB8 */
    char padBC[0x1AC - 0xBC];
    cAITarget* target;          /* 0x1AC */
};
extern "C" {
float cAITarget_GetAwarenessThreat(cAITarget* t, cGOBJ* g);
int cWeapon_GetClipAmmo(cWeapon* w, int kind);
int cNPC_RecommendAIMode(cNPC* self);
}
static inline float Scale2(float x, float k) { return x * k; }
static inline bool NeedsReload(cNPC* self) { return self->owner->weapon->reloading || cWeapon_GetClipAmmo(self->owner->weapon, 6) < self->reloadThreshold; }
static inline unsigned char OutOfRange(cNPC* self)
{
    unsigned char outOfRange = 0;
    int currState = self->GetModeForState(0);
    if (!(self->attackRange <= 0.0f) && self->target->targetPositionValid && currState >= 0) {
        cVector delta = self->owner->GetMatrix().GetTranslation();
        float dist;
        dist = (delta -= self->target->targetPositionLastSeen).Length();
        if (currState == self->GetCurrentMode())
            outOfRange = 10.0f + dist > self->attackRange;
        else
            outOfRange = dist < self->attackRange;
    }
    return outOfRange;
}
int cNPC_RecommendAIMode(cNPC* self)
{
    float threat;
    float toHit;
    float d;
    float reloadAdjustment;
    reloadAdjustment = toHit = threat = 0.0f;
    if (self->target->GetTargetGobj()) {
        threat = 0.1f + cAITarget_GetAwarenessThreat(self->target, self->target->GetTargetGobj());
        toHit = 0.1f + Scale2(self->GetAccuracy(), 15.0f);
    }
    if (NeedsReload(self) || OutOfRange(self))
        reloadAdjustment = 1.0f;
    d = toHit * self->aggression - threat - reloadAdjustment;
    if (d < -0.2f)
        return 2;
    if (d > 0.45f)
        return 4;
    return 3;
}
