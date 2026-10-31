#include "types.h"
#include "vslot_pad.h"

#pragma cplusplus on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(float a, float b, float c, float d, int) { V* t = this; x = a; y = b; z = c; w = d; }
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(&o)); asm { sq t, 0(this) } }
    V& operator=(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    float GetLength() const { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory"); return r; }
    float GetLengthSq() const { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory"); return r; }
    static void VU0Subtract(V& vecOut, const V& vecIn0, const V& vecIn1) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&vecOut), "r"(&vecIn0), "r"(&vecIn1) : "memory"); }
    V operator-(const V& vector) const { V result; VU0Subtract(result, *this, vector); return result; }
    void CopyFrom(const __int128* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); asm { sq t, 0(this) } }
} __attribute__((aligned(16)));
struct M { V r0, r1, r2, r3; };
struct RGB { float r, g, b; };
struct RGBA { float r, g, b, a;
    RGBA() {}
    RGBA(float r_, float g_, float b_, float a_) { r = r_; g = g_; b = b_; a = a_; }
    RGBA(const struct RGB& c, float a_);
};
inline RGBA::RGBA(const RGB& c, float a_) { r = c.r; g = c.g; b = c.b; a = a_; }
static inline float Min(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }

struct Ctl { VPAD16(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual void GetXform(M* m, int a, int b); };
struct Human { char pad[0x58]; Ctl* mController; };
struct GOBJ { char pad0[0xC]; int serial; char pad10[0x3C]; int mSubclassId; };
struct LightBase { int pad0; };
struct Light : LightBase {
    VPAD8(a) VPAD1(b) virtual void Update();
    char pad8[0xC]; float f14; float f18; char pad1C[4]; RGBA col;
};
struct Pt { V pos; V vel; V b; V c;
    Pt(const V& p) {
        const __int128* s = (const __int128*)&p;
        c.x = 0.65f;
        c.y = 0.65f;
        c.z = 1.0f;
        b.x = 0.0f;
        b.y = 0.0f;
        b.z = 0.0f;
        b.w = 0.0f;
        c.w = 1.0f;
        pos.CopyFrom(s);
    }
};
extern "C" void std_vector_imp_TaserPoint_insert(struct Arr* a, struct Pt* where, int n, struct Pt* p);
struct Arr { int a; int count; Pt* data; int d; Pt*& Data() { return data; } Pt* End() { return Data() + count; } void PushBack(const Pt& p) { std_vector_imp_TaserPoint_insert(this, End(), 1, (Pt*)&p); } };
struct SafePtr { GOBJ* p; int serial; };
struct Euler { float x, y, z, w; };
struct cAirTaser {
    void* mWpnEntry; Human* mOwner; unsigned char mMode; Light* mLight;
    Arr mPoints; char mPulses[0xC]; SafePtr mTarget; unsigned char mManualAim; int mSubTarget; int mHitBone;
    V mHitBoneOffset; Euler mLastSteerAng; M mAimMat; V mTargetPos; float mDistTraveled; float f[3]; void* mTipGlowParticle;
};
struct Msg { char pad[0x20]; unsigned char send; char pad21[0xF3]; char p114[0x9C]; char p1B0[0x10]; } __attribute__((aligned(16)));

extern "C" {
extern float D_0048B0F8;
extern float D_0048B130;
extern float D_0048B180;
extern float D_0048B1A0;
extern int g_HumanActorClassKey;
extern char D_004A81E8[];
extern char D_004A8200[];
extern char D_004D9200[];
extern char D_004DAE30[];
extern char D_004F1130[];
extern char g_Game[];
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char g_LightMgr[];
extern char D_0053B540[];
void Alloc_Lock(int id);
void EnableIntc(int id);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
V cVector_Cross(V*, V*);
int cVector_IsZeroXYZ(V*);
V cVector_GetNormalized_void(V*);
V* cVector_Normalize_void(V*);
void cVector_ctor_cVectorR(V*, V*);
V* cVector_ctor_float_float_float_float(V*, float, float, float, float);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(M*, V*, V*, V*, V*);
void cMatrix_MakeLookAtMatrix_cVectorR(M*, V*);
void cMatrix_SetUnit(M*);
void cPlaySoundMsg_ctor_cSndFxR_cGOBJP(Msg* m, void* preset, V* pos);
void QueueMessage_cMessageR_cSystemP_int(Msg* m, void* svc, int k);
void std_vector_deleter_TaserPoint_clear(Arr* a);
void std_vector_imp_TaserPoint_insert(Arr* a, Pt* where, int n, Pt* p);
Light* cLightMan_AddLight(void* mgr, int k);
V* tRGBA_ctor_tRGBR_float(float w, V* out, RGB* v);
void cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(Light* l, int k, V* c, Pt* seg, int n);
void LightEffect_SetInner(float f, Light* l);
void LightEffect_SetOuter(float f, Light* l);
void* cParticleSystem_GetEffectID(void* a, void* b);
void* cParticle_ctor(float f, void* mem, void* tex, M* m);
void cFileMan_dtor(void* p, int k);
void cMessage_dtor(void* p, int k);
}

static inline void LookAt2(M* mat, V& dir, V& up)
{
    V side = cVector_Cross(&dir, &up);
    if (!cVector_IsZeroXYZ(&side)) {
        V fwd = cVector_GetNormalized_void(&dir);
        V right; cVector_ctor_cVectorR(&right, cVector_Normalize_void(&side));
        V up2 = cVector_Cross(&right, &fwd);
        V w;
        cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(mat, &right, &fwd, &up2, cVector_ctor_float_float_float_float(&w, 0.0f, 0.0f, 0.0f, 1.0f));
    } else if (!cVector_IsZeroXYZ(&dir)) {
        cMatrix_MakeLookAtMatrix_cVectorR(mat, &dir);
    } else {
        cMatrix_SetUnit(mat);
    }
}
static inline void LookAt3(M* mat, V& dir, V& up) { LookAt2(mat, dir, up); }
static inline void LookAt4(M* mat, V& dir, V& up) { LookAt3(mat, dir, up); }
static inline void LookAt(M* mat, V& dir, V up) { LookAt4(mat, dir, up); }

static inline bool IEq(int a, int b) { return a == b; }
static inline bool HValid(SafePtr* h) { return !h->p || IEq(h->p->serial, h->serial); }
static inline GOBJ* Get(SafePtr* h) { return HValid(h) ? h->p : 0; }
static inline bool IEq2(int a, int b) { return b == a; }
static inline GOBJ* IsA(GOBJ* g) { bool ok = false; if (g) { if (IEq2(g_HumanActorClassKey, g->mSubclassId) != false) ok = true; } if (ok) return g; return 0; }

static inline void SetColor(Light* l, const RGB& c)
{
    RGBA lc(c, 0.0f);
    l->col = lc;
    V lc2;
    lc2.w = 0.0f;
    lc2.z = c.b;
    float g = c.g;
    lc2.y = g;
    lc2.x = c.r;
    l->f18 = 1.0f / lc2.GetLengthSq();
}
static inline void LBody0(Light* m, RGB& black, Arr* pts)
{
        float f;
        Pt* seg;
        V col;
        black.r = 0;
        black.g = 0;
        black.b = 0;
        f = D_0048B180;
        seg = pts->data + pts->count - 1;
        cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(m, 4, tRGBA_ctor_tRGBR_float(0.0f, &col, &black), seg, 3);
        *(void**)((char*)m + 4) = D_004D9200;
        LightEffect_SetInner(0.0f, m);
        LightEffect_SetOuter(f, m);
}
static inline void LBody1(Light* m, RGB& black, Arr* pts) { LBody0(m, black, pts); }
static inline void LBody2(Light* m, RGB& black, Arr* pts) { LBody1(m, black, pts); }
inline void* operator new(unsigned int, void* p) { return p; }
struct TLight { TLight(RGB& black, Arr* pts) { LBody2((Light*)this, black, pts); } };
extern "C" void cAirTaser_Shoot_cGOBJP_bool_int_cVector(cAirTaser* self, GOBJ* target, unsigned char manualAim, int subTarget, V& targetPos)
{
    int none __attribute__((aligned(8)));
    RGB black __attribute__((aligned(8)));
    RGB c __attribute__((aligned(8)));
    self->mMode = 1;
    self->mTargetPos = targetPos;
    self->mLastSteerAng.x = self->mLastSteerAng.y = self->mLastSteerAng.z = 0.0f;
    self->mOwner->mController->GetXform(&self->mAimMat, 0, 0);
    V pos(self->mAimMat.r3);
    V dir = self->mTargetPos - pos;
    float len = dir.GetLength();
    float adj = D_0048B0F8 * dir.GetLengthSq();
    adj = Min(adj, D_0048B130 * len);
    dir.z += adj;
    LookAt(&self->mAimMat, dir, V(0.0f, 0.0f, 1.0f, 1.0f, 0));
    self->mAimMat.r3 = pos;
    Msg msg;
    cPlaySoundMsg_ctor_cSndFxR_cGOBJP(&msg, D_004F1130, &pos);
    msg.send = 1;
    QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
    std_vector_deleter_TaserPoint_clear(&self->mPoints);
    self->mPoints.PushBack(Pt(self->mAimMat.r3));
    self->mDistTraveled = 0.0f;
    target = IsA(target);
    self->mTarget.p = target;
    {
        int* id;
        if (target != 0) id = &target->serial;
        else { none = -1; id = &none; }
        self->mTarget.serial = *id;
        self->mSubTarget = subTarget;
        self->mManualAim = manualAim || !Get(&self->mTarget);
    }
    if (self->mLight == 0) {
        self->mLight = (Light*)new (cLightMan_AddLight(g_LightMgr, 4)) TLight(black, &self->mPoints);
    }
    if (self->mLight != 0) {
        self->mLight->f14 = D_0048B180;
        c.r = 0.5f;
        c.g = 0.5f;
        c.b = 1.0f;
        SetColor(self->mLight, c);
        self->mLight->Update();
    }
    {
        void* p;
        if (g_ProfileLockEnabled) Alloc_Lock(9);
        g_ProfileLockDepth++;
        p = cMemMan_Allocate(0, 0x70, D_004A81E8, 0xC6);
        if (g_ProfileLockEnabled) EnableIntc(9);
        g_ProfileLockDepth--;
        if (p != 0) p = cParticle_ctor(D_0048B1A0, p, cParticleSystem_GetEffectID(D_0053B540, D_004A8200), &self->mAimMat);
        self->mTipGlowParticle = p;
    }
    *(void**)&msg = D_004DAE30;
    cFileMan_dtor(msg.p114, -1);
    cFileMan_dtor((char*)&msg + 0x78, -1);
    cMessage_dtor(&msg, 0);
}
