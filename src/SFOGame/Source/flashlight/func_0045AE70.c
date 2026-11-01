/* 0045AE70 cFlashlight::Update(float, const cMatrix&) (flashlight.cc), rebuilt from the prototype DWARF/.line data. */
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
    V& Normalize();
    float LengthSq() const;
    /* 128-bit lq/sq quadword copy: MW splits a C struct copy into words */
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct M {
    float m[4][4];
    M() {}
    V& R(int i) { return *(V*)m[i]; }
    const V& R(int i) const { return *(const V*)m[i]; }
    M(const M& o) { M* pd = this; const M* ps = &o; __int128 a, b; asm volatile { lq a, 0(ps); lq b, 16(ps); sq a, 0(pd); lq a, 32(ps); sq b, 16(pd); lq b, 48(ps); sq a, 32(pd); sq b, 48(pd) } }
} __attribute__((aligned(16)));

/* VU0 macro-mode vector ops (COP2), not expressible in C */
static inline void SubM(V* d, const V* p, const V* q) { asm volatile { lqc2 vf1, 0x0(p); lqc2 vf2, 0x0(q); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
static inline void NormM(V* v) { asm volatile { lqc2 vf1, 0x0(v); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vrsqrt Q, vf0w, vf3w; vwaitq; vmulq.xyz vf1, vf1, Q; sqc2 vf1, 0x0(v) } }
static inline float DotM(const V* a, const V* b)
{
    int rv0;
    float ret = 0.0f;
    asm volatile {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
static inline float LenSqM(const V* v)
{
    int rv0;
    float ret = 0.0f;
    asm volatile {
        lqc2 vf1, 0x0(v)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni rv0, vf4
        mtc1 rv0, ret
    }
    return ret;
}
/* max.s / min.s (EE FPU min/max), not expressible in C */
static inline float Clamp(float v, float lo, float hi) { float r = 0.0f; float l = lo; asm { max.s r, v, l; min.s r, r, hi } return r; }
static inline float Min(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }

inline V& V::Normalize() { V* t = this; NormM(t); return *this; }
inline float V::LengthSq() const { return LenSqM(this); }
static inline V operator-(const V& a, const V& b) { V r; const V* pa = &a; V* pd = &r; const V* pb = &b; SubM(pd, pa, pb); return r; }
static inline void XformM3(V* d, const M* m, const V* s) { asm volatile { lqc2 vf8, 0x0(s); lqc2 vf4, 0x0(m); lqc2 vf5, 0x10(m); lqc2 vf6, 0x20(m); lqc2 vf7, 0x30(m); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(d) } }
static inline float Dot(const V& a, const V& b) { return DotM(&a, &b); }

struct tRGB { float r, g, b; };
struct tRGBA { float r, g, b, a; tRGBA() {} tRGBA(const tRGB& c, float aa = 0.0f) : r(c.r), g(c.g), b(c.b), a(aa) {} };

struct cXform {
    VPAD16(a) VPAD4(b)
    virtual void Update();
    char pad4[0x10 - 4];
    M mat;
    unsigned char needsUpdate;
    const M& GetMatrix() { if (needsUpdate) Update(); return mat; }
};
struct cGOBJXform {
    VPAD2(a) VPAD1(b)
    virtual void SetPosition(const V& p);
};
struct cAITarget;
struct cNPC;
struct cGOBJ {
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual V GetPos();
    char pad4[0x50 - 4];
    cXform* mXform;
    char pad54[0x58 - 0x54];
    cNPC* mController;
};
struct cGobjX { char pad0[0x50]; cGOBJXform* mXform; };
struct cNPC { char pad0[0x1AC]; cAITarget* target; };
struct cCAMERA_GOBJ { char pad0[0x50]; cXform* mXform; };
struct cLightBase { signed char kind; unsigned char flag1; };
struct cLight : cLightBase {
    VPAD8(a)
    virtual void SetPosition(const V& p);
    char pad8[0x10 - 8];
    float mInner;
    float mOuter;
    float mInvIntensity;
    char pad1C[0x20 - 0x1C];
    tRGBA mColor;
    void SetInv(const V& v) { float len = 0.0f; int rv0; const V* pv = &v; asm volatile { lqc2 vf1, 0x0(pv); vaddw.x vf3, vf0, vf0w; vmul.xyz vf2, vf1, vf1; vmulax.x ACC, vf3, vf2x; vmadday.x ACC, vf3, vf2y; vmaddz.x vf4, vf3, vf2z; qmfc2.ni rv0, vf4; mtc1 rv0, len } mInvIntensity = 1.0f / len; }
    void SetColor(const tRGB& c)
    {
        mColor = tRGBA(c);
        SetInv(V(c.r, c.g, c.b, 0.0f));
    }
};
struct cDazzle : cLightBase {
    VPAD8(a)
    virtual void SetPosition(const V& p);
    char pad8[0x40 - 8];
    float mPct;
};
struct cHuman {
    char pad0[0x3204];
    int mFlags;
    char pad3208[0x3310 - 0x3208];
    unsigned char* mSub;
    char pad3314[0x3524 - 0x3314];
    void* mWeapon;
    bool Bit() const { return (mFlags >> 4) & 1; }
    bool HasSub() const { return Bit() && mSub; }
    bool InSub() const { bool r = false; if (HasSub() && mSub[978]) r = true; return r; }
};
struct tBulletCollisionInfo {
    cGOBJ* attacker;
    M* bulMat;
    cGOBJ* target;
    unsigned char shouldHitTarget;
    unsigned char manualAim;
    int subTarget;
    float travelDist;
    void* wpnEntry;
    float prevDist;
    unsigned char noDamage;
    int penetration;
    float hitRadius;
    unsigned char scoreHit;
    unsigned char b2D;
    int hitLocation;
    float hitDist;
    cGOBJ* hitGobj;
    int boneHit;
    float damage;
    tBulletCollisionInfo() { noDamage = 0; prevDist = 0.0f; subTarget = -1; scoreHit = 1; b2D = 1; }
};
struct cFlashlight {
    unsigned char mOn;
    cHuman* mOwner;
    cLight* mLight;
    cDazzle* mDazzle;
    float mOldDist;
    float mCurVel;
    cGobjX* mGobj;
};
struct FWord { int value; };
struct cLLItem { cGOBJ* p; int id; bool Same() const { return *(int*)((char*)p + 12) == id; } bool Valid() const { return !p || Same(); } };
struct cLLNode { int pad0; cLLNode* next; cLLItem* item; };

extern "C" {
extern float FlashDist, FlashShortDist, FlashHitRad, FlashAdjusty, FlashMinOuter, FlashMaxOuter, FlashMaxInner;
extern float FlashMinRG, FlashMinB, FlashVel, FlashAcc, FlashMinInner, FlashSqueeze;
extern float D_00497A00, D_00497A08; /* FlashMaxRG, FlashMaxB (unnamed in symbol_addrs) */
extern char g_CameraObject[];
extern char g_NpcThinkList[];
int func_00159570(void*);
cCAMERA_GOBJ** cLList_cCAMERA_GOBJPtr_Front(void*);
int cWeapon_GetEquipmentType(void*);
float GetCollisionDist(cHuman*, tBulletCollisionInfo*, int);
void cAITarget_AddAwareness(cAITarget*, cHuman*, int, float);
FWord std_list_deleter_voidPtr_begin_void_2(void*);
FWord std_list_deleter_voidPtr_end_void_2(void*);
void std_list_cActiveListItemPtr_generic_iterator_1_ctor(FWord*, int);
}

static inline cCAMERA_GOBJ* GetCam() { return func_00159570(g_CameraObject) ? *cLList_cCAMERA_GOBJPtr_Front(g_CameraObject) : 0; }

struct FIter {
    cLLNode* n;
    FIter() {}
    FIter(const FIter& o) : n(o.n) {}
    cGOBJ* Get() const { cLLItem* it = n->item; return it->Valid() ? it->p : 0; }
};
static inline int RawB(void* l) { return std_list_deleter_voidPtr_begin_void_2(l).value; }
static inline int RawE(void* l) { return std_list_deleter_voidPtr_end_void_2(l).value; }
static inline FIter Begin(void* l) { FIter b; std_list_cActiveListItemPtr_generic_iterator_1_ctor((FWord*)&b, RawB(l)); return b; }
static inline FIter End(void* l) { FIter b; std_list_cActiveListItemPtr_generic_iterator_1_ctor((FWord*)&b, RawE(l)); return b; }

extern "C" void cFlashlight_Update(cFlashlight* self, float timeStep, const M& matIn)
{
    M mat = matIn;
    if (!self->mLight) return;
    if (self->mDazzle) {
        cCAMERA_GOBJ* cam = GetCam();
        V camy = mat.R(3) - cam->mXform->GetMatrix().R(3);
        V flashy = mat.R(1);
        camy.Normalize();
        flashy.Normalize();
        float dot = Dot(camy, flashy);
        float pct;
        if (dot > 0.0f)
            pct = 0.0f;
        else
            pct = -dot;
        if (pct < FlashSqueeze)
            pct = 0.0f;
        else
            pct = (pct - FlashSqueeze) / (1.0f - FlashSqueeze);
        pct *= pct;
        pct *= pct;
        pct *= pct;
        pct *= pct;
        self->mDazzle->mPct = pct;
        self->mDazzle->SetPosition(mat.R(3));
    }
    V off(0.0f, -1.5f, 0.0f, 1.0f);
    XformM3(&off, &mat, &off);
    mat.R(3) = off;
    tBulletCollisionInfo inf;
    inf.bulMat = &mat;
    inf.noDamage = 1;
    inf.shouldHitTarget = 0;
    inf.target = 0;
    inf.penetration = 0;
    inf.hitRadius = FlashHitRad;
    inf.travelDist = FlashDist;
    cWeapon_GetEquipmentType(self->mOwner->mWeapon);
    if (self->mOwner->InSub())
        inf.travelDist = FlashShortDist;
    float dist = self->mOwner ? GetCollisionDist(self->mOwner, &inf, 0) - FlashAdjusty : 0.0f;
    dist = Clamp(dist, 0.0f, FlashDist);
    V pos(0.0f, 0.0f, 0.0f, 1.0f);
    if (self->mOldDist <= 0.0f) {
        self->mOldDist = dist;
        self->mCurVel = 0.0f;
    } else {
        float distDiff = dist - self->mOldDist;
        float vel = FlashVel * timeStep * (distDiff * distDiff);
        float veldiff = vel - self->mCurVel;
        float maxAcc = FlashAcc * timeStep;
        veldiff = Min(veldiff, maxAcc);
        self->mCurVel += veldiff;
        distDiff = Clamp(distDiff, -self->mCurVel, self->mCurVel);
        self->mOldDist += distDiff;
    }
    pos.y = self->mOldDist;
    { const M* pm = inf.bulMat; XformM3(&pos, pm, &pos); }
    float distPct = dist / FlashDist;
    float innerDist = FlashMinInner + distPct * (FlashMaxInner - FlashMinInner);
    float outerDist = FlashMinOuter + distPct * (FlashMaxOuter - FlashMinOuter);
    float colorRG = FlashMinRG + (1.0f - distPct) * (D_00497A00 - FlashMinRG);
    float colorB = FlashMinB + (1.0f - distPct) * (D_00497A08 - FlashMinB);
    tRGB col;
    col.r = colorRG;
    col.g = colorRG;
    col.b = colorB;
    self->mLight->SetPosition(pos);
    self->mGobj->mXform->SetPosition(pos);
    self->mLight->SetColor(col);
    self->mLight->mInner = innerDist;
    self->mLight->mOuter = outerDist;
    void* list = g_NpcThinkList;
    FIter iter = Begin(list);
    FIter end = End(list);
    float radSq = outerDist * outerDist;
    for (; iter.n != end.n; iter.n = iter.n->next) {
        cGOBJ* g = iter.Get();
        V d = g->GetPos() - pos;
        if (d.LengthSq() < radSq) {
            cNPC* npc = g->mController;
            if (npc)
                cAITarget_AddAwareness(npc->target, self->mOwner, 6, 0.0f);
        }
    }
}
