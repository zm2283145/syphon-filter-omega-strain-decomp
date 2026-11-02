/*
 * SFOGame/Source/taser: 3 files, 00265790-00265B90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00265790 */
#pragma push /* merge_units */
/* 00265790 cAirTaser::SmoothLine(float amt, bool decay) (taser.cc) */
#pragma cplusplus on
#include "types.h"
#pragma inline_depth(8)
#pragma opt_propagation off

struct V;
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void ScaleV(V* rp, const V* tp, float k) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(rp), "r"(tp), "f"(k) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    // 128-bit lq/sq quadword copy idiom
    V(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    // 128-bit lq/sq quadword copy idiom
    V& operator=(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    V operator*(float k) const { return Scaled(k); }
    V Scaled(float k) const { V r; ScaleV(&r, this, k); return r; }
} __attribute__((aligned(16)));

// VU0 macro-mode vector op (COP2), not expressible in C
static inline V operator+(const V& a, const V& b) { V r; V* rp = &r; const V* ap = &a; const V* bp = &b; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(ap), "r"(bp) : "memory"); return r; }
struct Seg { V p; char pad[0x30]; };
struct cArray { char pad0[4]; int count; Seg* data; char padC[4]; Seg& operator[](int i) { return data[i]; } int Count() { return count; } };
struct cAirTaser { char pad0[0x10]; cArray mPoints; void SmoothLine(float amt, bool decay); };

extern "C" {
extern float D_0048B1A8;
extern float D_0048B1B0;
void cAirTaser_SmoothLine(cAirTaser* self, bool decay, float amt);
}

void cAirTaser_SmoothLine(cAirTaser* self, bool decay, float amt)
{
    int cnt = self->mPoints.Count() - 1;
    if (decay) {
        cnt = (int)((float)cnt * D_0048B1A8);
    }
    for (int i = 1; i < cnt; i++) {
        V mid = (self->mPoints.data[i - 1].p + self->mPoints.data[i + 1].p) * 0.5f;
        float factor;
        if (decay) {
            factor = (float)(cnt - i) / (float)(cnt - 1);
        } else {
            factor = 1.0f;
        }
        factor *= D_0048B1B0;
        float adjustPct = amt * factor;
        self->mPoints[i].p.x = mid.x * adjustPct + (1.0f - adjustPct) * self->mPoints[i].p.x;
        self->mPoints[i].p.y = (1.0f - adjustPct) * self->mPoints[i].p.y + mid.y * adjustPct;
        self->mPoints[i].p.z = (1.0f - adjustPct) * self->mPoints[i].p.z + mid.z * adjustPct;
    }
}
static inline void merge_flush_func_00265790(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00265790 */

/* merge_units: begin func_00265910 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cAirTaser_LosBlocked: LOS ray from just behind the first trail segment to the last one; returns the hit flag */
#include "vslot_pad.h"
#pragma inline_depth(8)
#pragma opt_propagation off

struct V_00265910;
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void ScaleV_00265910(V_00265910* rp, const V_00265910* tp, float k) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(rp), "r"(tp), "f"(k) : "memory"); }
static inline void SubV(V_00265910* d, V_00265910* a, V_00265910* b);
struct V_00265910 {
    float x, y, z, w;
    V_00265910() {}
    // 128-bit lq/sq quadword copy idiom
    V_00265910(const V_00265910& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    // 128-bit lq/sq quadword copy idiom
    V_00265910& operator=(const V_00265910& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V_00265910 operator-(const V_00265910& o) const { V_00265910 r; V_00265910* rp = &r; const V_00265910* tp = this; const V_00265910* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
    V_00265910 operator*(float k) const { V_00265910 r; ScaleV_00265910(&r, this, k); return r; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V_00265910& operator-=(V_00265910 o) { SubV(this, this, &o); return *this; }
    void Set(V_00265910 o) { *this = o; }
} __attribute__((aligned(16)));
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void SubV(V_00265910* d, V_00265910* a, V_00265910* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline void SubV2(V_00265910* d, V_00265910* a, V_00265910* b) { SubV(d, a, b); }
static inline V_00265910 operator/(V_00265910 v, float s) { V_00265910* pv = &v; return *pv * (1.0f / s); }

// VU0 macro-mode vector op (COP2), not expressible in C
static inline float Len0(V_00265910* a) { int rv0; float ret = 0.0f; asm { lqc2 vf1, 0x0(a); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni rv0, vf4; mtc1 rv0, ret } return ret; }

static inline float Len(V_00265910* a) { return Len0(a); }
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct LosHit {
    VP arr[3];
    V_00265910 normal;
    unsigned char b40; char p41; unsigned char b42; char p43[0x1D];
    int x60;
    void* x64;
    char pad68[0x18];
    void Init() { LosHit* q = this; VP* i = q->arr; do { i++; } while (i != q->arr + 3); q->b40 = 0; q->b42 = 0; q->x60 = 0; q->x64 = 0; }
};
struct LosRes {
    bool hit;
    char pad1[0xF];
    V_00265910 pt;
    LosHit h;
    LosRes() { LosRes* p = this; p->h.Init(); }
};
struct Svc { VPAD1(a) virtual void Post(void* m); };
struct Seg_00265910 { V_00265910 p; char pad[0x30]; };
struct HeldItem { char pad0[4]; void* ctl; char pad8[0xC]; int idx; Seg_00265910* segs; Seg_00265910* Back() { Seg_00265910** d = &segs; return *d + idx - 1; } };

extern "C" {
extern float D_0048B1C8;
extern char g_LosRequestMsgClass[];
extern char D_004D9180[];
extern char g_Game[];
extern char g_LosCheckService[];
void cMessage_ctor_cMessageNameR(void*, void*);
void cMessage_dtor(void*, int);
Svc* cSystemContainer_GetSystem(void* a, void* b);
int cAirTaser_LosBlocked(HeldItem* h);
}

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct LosMsg : MsgB {
    int x24;
    int x28;
    LosRes* res;
    V_00265910 from;
    V_00265910 dir;
    void* self;
    int x54;
    int mask;
    unsigned char b5C;
    LosMsg(LosRes* r, const V_00265910& f, const V_00265910& d, void* o)
    {
        LosMsg* m = this;
        cMessage_ctor_cMessageNameR(m, g_LosRequestMsgClass);
        m->vtable = D_004D9180;
        m->x24 = 0;
        m->x28 = 0;
        m->res = r;
        m->from = f;
        m->dir = d;
        m->self = o;
        m->x54 = 0;
        m->mask = 0x10;
        m->b5C = 0;
        m->from.w = 1.0f;
        m->dir.w = 0.0f;
    }
    __declspec(weak) __declspec(MSG_DTOR) ~LosMsg() { vtable = D_004D9180; }
};

int cAirTaser_LosBlocked(HeldItem* h)
{
    int hit = 0;
    if (h->idx > 1) {
        V_00265910 from = h->segs[0].p;
        V_00265910* last = &h->Back()->p;
        V_00265910 d = *last - from;
        float len = Len(&d);
        from -= d * D_0048B1C8 / len;
        d.Set(*last - from);
        LosRes res;
        LosMsg msg(&res, from, d, h->ctl);
        cSystemContainer_GetSystem(g_Game, g_LosCheckService)->Post(&msg);
        hit = res.hit;
    }
    return hit;
}
static inline void merge_flush_func_00265910(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00265910 */

/* merge_units: begin func_00265B90 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
struct V_00265B90 {
    float x, y, z, w;
    V_00265B90() {}
    V_00265B90(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V_00265B90(float a, float b, float c, float d, int) { V_00265B90* t = this; x = a; y = b; z = c; w = d; }
    V_00265B90(const V_00265B90& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(&o)); asm { sq t, 0(this) } }
    V_00265B90& operator=(const V_00265B90& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    float GetLength() const { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory"); return r; }
    float GetLengthSq() const { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory"); return r; }
    static void VU0Subtract(V_00265B90& vecOut, const V_00265B90& vecIn0, const V_00265B90& vecIn1) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&vecOut), "r"(&vecIn0), "r"(&vecIn1) : "memory"); }
    V_00265B90 operator-(const V_00265B90& vector) const { V_00265B90 result; VU0Subtract(result, *this, vector); return result; }
    void CopyFrom(const __int128* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); asm { sq t, 0(this) } }
} __attribute__((aligned(16)));
struct M { V_00265B90 r0, r1, r2, r3; };
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
struct Pt { V_00265B90 pos; V_00265B90 vel; V_00265B90 b; V_00265B90 c;
    Pt(const V_00265B90& p) {
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
struct cAirTaser_00265B90 {
    void* mWpnEntry; Human* mOwner; unsigned char mMode; Light* mLight;
    Arr mPoints; char mPulses[0xC]; SafePtr mTarget; unsigned char mManualAim; int mSubTarget; int mHitBone;
    V_00265B90 mHitBoneOffset; Euler mLastSteerAng; M mAimMat; V_00265B90 mTargetPos; float mDistTraveled; float f[3]; void* mTipGlowParticle;
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
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char g_LightMgr[];
extern char D_0053B540[];
void Alloc_Lock(int id);
void EnableIntc(int id);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
V_00265B90 cVector_Cross(V_00265B90*, V_00265B90*);
int cVector_IsZeroXYZ(V_00265B90*);
V_00265B90 cVector_GetNormalized_void(V_00265B90*);
V_00265B90* cVector_Normalize_void(V_00265B90*);
void cVector_ctor_cVectorR(V_00265B90*, V_00265B90*);
V_00265B90* cVector_ctor_float_float_float_float(V_00265B90*, float, float, float, float);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(M*, V_00265B90*, V_00265B90*, V_00265B90*, V_00265B90*);
void cMatrix_MakeLookAtMatrix_cVectorR(M*, V_00265B90*);
void cMatrix_SetUnit(M*);
void cPlaySoundMsg_ctor_cSndFxR_cGOBJP(Msg* m, void* preset, V_00265B90* pos);
void QueueMessage_cMessageR_cSystemP_int(Msg* m, void* svc, int k);
void std_vector_deleter_TaserPoint_clear(Arr* a);
void std_vector_imp_TaserPoint_insert(Arr* a, Pt* where, int n, Pt* p);
Light* cLightMan_AddLight(void* mgr, int k);
V_00265B90* tRGBA_ctor_tRGBR_float(float w, V_00265B90* out, RGB* v);
void cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(Light* l, int k, V_00265B90* c, Pt* seg, int n);
void LightEffect_SetInner(float f, Light* l);
void LightEffect_SetOuter(float f, Light* l);
void* cParticleSystem_GetEffectID(void* a, void* b);
void* cParticle_ctor(float f, void* mem, void* tex, M* m);
void cFileMan_dtor(void* p, int k);
void cMessage_dtor(void* p, int k);
}

static inline void LookAt2(M* mat, V_00265B90& dir, V_00265B90& up)
{
    V_00265B90 side = cVector_Cross(&dir, &up);
    if (!cVector_IsZeroXYZ(&side)) {
        V_00265B90 fwd = cVector_GetNormalized_void(&dir);
        V_00265B90 right; cVector_ctor_cVectorR(&right, cVector_Normalize_void(&side));
        V_00265B90 up2 = cVector_Cross(&right, &fwd);
        V_00265B90 w;
        cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(mat, &right, &fwd, &up2, cVector_ctor_float_float_float_float(&w, 0.0f, 0.0f, 0.0f, 1.0f));
    } else if (!cVector_IsZeroXYZ(&dir)) {
        cMatrix_MakeLookAtMatrix_cVectorR(mat, &dir);
    } else {
        cMatrix_SetUnit(mat);
    }
}
static inline void LookAt3(M* mat, V_00265B90& dir, V_00265B90& up) { LookAt2(mat, dir, up); }
static inline void LookAt4(M* mat, V_00265B90& dir, V_00265B90& up) { LookAt3(mat, dir, up); }
static inline void LookAt(M* mat, V_00265B90& dir, V_00265B90 up) { LookAt4(mat, dir, up); }

static inline bool IEq(int a, int b) { return a == b; }
static inline bool HValid(SafePtr* h) { return !h->p || IEq(h->p->serial, h->serial); }
static inline GOBJ* Get(SafePtr* h) { return HValid(h) ? h->p : 0; }
static inline bool IEq2(int a, int b) { return b == a; }
static inline GOBJ* IsA(GOBJ* g) { bool ok = false; if (g) { if (IEq2(g_HumanActorClassKey, g->mSubclassId) != false) ok = true; } if (ok) return g; return 0; }

static inline void SetColor(Light* l, const RGB& c)
{
    RGBA lc(c, 0.0f);
    l->col = lc;
    V_00265B90 lc2;
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
        V_00265B90 col;
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
extern "C" void cAirTaser_Shoot_cGOBJP_bool_int_cVector(cAirTaser_00265B90* self, GOBJ* target, unsigned char manualAim, int subTarget, V_00265B90& targetPos)
{
    int none __attribute__((aligned(8)));
    RGB black __attribute__((aligned(8)));
    RGB c __attribute__((aligned(8)));
    self->mMode = 1;
    self->mTargetPos = targetPos;
    self->mLastSteerAng.x = self->mLastSteerAng.y = self->mLastSteerAng.z = 0.0f;
    self->mOwner->mController->GetXform(&self->mAimMat, 0, 0);
    V_00265B90 pos(self->mAimMat.r3);
    V_00265B90 dir = self->mTargetPos - pos;
    float len = dir.GetLength();
    float adj = D_0048B0F8 * dir.GetLengthSq();
    adj = Min(adj, D_0048B130 * len);
    dir.z += adj;
    LookAt(&self->mAimMat, dir, V_00265B90(0.0f, 0.0f, 1.0f, 1.0f, 0));
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
static inline void merge_flush_func_00265B90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00265B90 */
