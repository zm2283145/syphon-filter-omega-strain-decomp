#pragma opt_pulloutconstants off
#pragma cplusplus on
#pragma inline_depth(10)
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 r[4]; } M4;
typedef unsigned char u8;
extern "C" { void Ptr_Identity(void*); V4* Vec4_Assign(V4*, V4*); }
static inline void Q1D_L(void* d0, const void* s0) { const void* xx = s0; __int128 q; const void* s = s0; void* d = d0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
class VV { public: float x, y, z, w; VV() { Ptr_Identity(this); } VV(const VV& o) { Vec4_Assign((V4*)this, (V4*)&o); } VV& operator=(const VV& o) { Q1D_L(this, &o); return *this; } } __attribute__((aligned(16)));
#define AV(v) (*(VV*)&(v))
class Obj58 { public: virtual void F0(); virtual void F1(); virtual void F2(); virtual void F3(); virtual void F4(); virtual void F5(); virtual void F6(); virtual void F7(); virtual void F8(); virtual void F9(); virtual void F10(); virtual void F11(); virtual void F12(); virtual void F13(); virtual void F14(); virtual void F15(); virtual void F16(); virtual void F17(); virtual void F18(); virtual int IsPlayer(); };
typedef struct { char pad0[0x30]; char s30[8]; int i38; char pad3C[0xDC - 0x3C]; u8 bDC; u8 bDD; char padDE[0xE4 - 0xDE]; float fE4; char padE8[0x2C8 - 0xE8]; float f2C8; char pad2CC[0x3D1 - 0x2CC]; u8 b3D1; u8 b3D2; } Ctl;
typedef struct { char pad[0x311]; u8 b311; } Tgt;
typedef struct { char pad[0x84]; u8 b84; } Inv;
typedef struct { char pad[0x50]; u8 b50; } Nav;
typedef struct { char pad[0x160]; int i160; } Root;
typedef struct { char pad[0x10]; char anim[0x10]; } AnimBlk;
typedef struct { int mode; int flags; } St;
typedef struct {
    char pad0[0xC];
    char c0C[8];            /* 0xC */
    u8 b14;                 /* 0x14 */
    char pad15[0x58 - 0x15];
    Obj58* p58;             /* 0x58 */
    char pad5C[0x2EC0 - 0x5C];
    AnimBlk blk;            /* 0x2EC0 */
    char pad2EE0[0x3030 - 0x2EE0];
    char heading[4];        /* 0x3030 */
    int i3034;              /* 0x3034 */
    char pad3038[4];
    u8 b303C;               /* 0x303C */
    char pad303D[3];
    V4 v3040;               /* 0x3040 */
    char pad3050[8];
    float f3058;            /* 0x3058 */
    char pad305C[0x3088 - 0x305C];
    char hist[4];           /* 0x3088 */
    int i308C;              /* 0x308C */
    char pad3090[8];
    int i3098;              /* 0x3098 */
    float f309C;            /* 0x309C */
    char pad30A0[0x31B3 - 0x30A0];
    u8 b31B3;               /* 0x31B3 */
    u8 b31B4;               /* 0x31B4 */
    char pad31B5[2];
    u8 b31B7;               /* 0x31B7 */
    char pad31B8[8];
    V4 in;                  /* 0x31C0 */
    float f31D0;            /* 0x31D0 */
    float f31D4;            /* 0x31D4 */
    char pad31D8[4];
    u8 b31DC;               /* 0x31DC */
    char pad31DD[3];
    float rate;             /* 0x31E0 */
    char pad31E4[0x31F8 - 0x31E4];
    float f31F8;            /* 0x31F8 */
    char pad31FC[4];
    int i3200;              /* 0x3200 */
    int i3204;              /* 0x3204 */
    int i3208;              /* 0x3208 */
    St st;                  /* 0x320C */
    char pad3214[0x3220 - 0x3214];
    int i3220;              /* 0x3220 */
    char pad3224[0x3234 - 0x3224];
    int i3234;              /* 0x3234 */
    char pad3238[0x3248 - 0x3238];
    int i3248;              /* 0x3248 */
    int i324C;              /* 0x324C */
    char pad3250[0x3290 - 0x3250];
    Root* p3290;            /* 0x3290 */
    void* p3294;            /* 0x3294 */
    char pad3298[0x3310 - 0x3298];
    Ctl* ctl;               /* 0x3310 */
    Tgt* p3314;             /* 0x3314 */
    char pad3318[0x3524 - 0x3318];
    Inv* inv;               /* 0x3524 */
    char pad3528[0x3584 - 0x3528];
    Nav* p3584;             /* 0x3584 */
} Actor;
typedef struct { char* vt; char pad4[0x20]; int i24; int i28; int i2C; } Msg;
extern "C" {
extern u8 g_IsMultiplayer;
extern int g_VideoFrameCounter;
extern float D_0049CED8, D_0049CF48, D_0049CF50, D_0049CF58, D_0049CF60, D_0049CF68, D_0049CF70, D_0049CF78, D_0049CF80, D_0049CF88;
extern float D_0049CF90, D_0049CF98, D_0049CFA0, D_0049CFA8, D_0049CFB8, D_0049CFC0, D_0049CFC8, D_0049CFD0, D_0049CFD8, D_0049CFE0, D_0049CFE8;
extern float g_NegFltMax;
extern char D_004D92A0[];
extern char D_004DA950[];
extern char D_004EE5C0[];
extern char g_Game[];
extern char g_CasEventMsgClass[];
void Actor_SetPendingFlag(void* f, u8 bit, int on);
void Actor_PrepareNavigation(Actor* a, float dt);
int Inventory_GetEquipMode(Inv* inv);
int Inventory_HasAnyItem(Inv* inv);
float Math_Atan2f(float y, float x);
float Math_Sin(float);
float Math_SinThunk(float);
float Math_CosThunk(float);
void AnimChannel_SetTarget(void* a, int idx, unsigned int n, float target, float dur, float damping);
void AnimChannel_Approach(void* a, int idx, unsigned int n, float target, float rate);
void AnimChannel_SetDirect(void* a, int idx, float v);
float AnimChannel_GetCurrent(void* a, int idx);
float AnimChannel_GetCurrentValue(void* a, int idx);
float AnimChannel_GetTarget(void* a, int idx);
int BitArray_Test(void* a, int bit);
void Event_Construct(Msg* m, void* d);
void Event_Send(Msg* m, void* to, int f);
void cMessage_dtor(Msg* m, int f);
void* Service_Lookup(void* a, void* b);
void AiSound_SendFireNoise(Msg* m, int* sender, int action, float amp, float f);
void func_0019DC30(Actor* a, float dt);
void Ladder_Update(Actor* a, float dt);
void Actor_UpdatePairChannels(Actor* a, float dt);
void Actor_PrepareNeutralChannels(Actor* a, int b, int c, int d, int e);
void func_0019D6E0(void* p, int a, int b);
void func_0019D6C0(void* p, int a, int b);
float ActorPhysical_QueryWaterHeight(Ctl* c);
void Mtx44_SetRotation(M4* m, float, float, float, float, float, float, float, float, float);
V4* Root_GetWorldQuat(void* r);
void Root_SetWorldOrientation(Root* r, V4* q);
void* Root_ResolveWorldPlacement(Root* r);
M4* Placement_ToMatrix(M4* m, void* p);
float Mtx_GetHeading(M4* m);
float* History_At(char* h, int i);
void ActorHeading_RetargetLast(char* h, float f);
void* Actor_GetEdgeRoot2(Actor* a);
float* Mtx_ToEuler(V4* e, M4* m);
V4* Quat_FromYaw(V4* q, V4* aa);
int func_0019D230(char* h);
char** func_0019D220(char* h);
int Root_GetParent(Root* r);
void Root_RefreshWorldCache(Root* r);
char* Root_Identity(Root* r);
V4* Placement_GetPosition(void* p);
V4* Placement_GetQuat(void* p);
M4* Quat_ToMatrix(M4* m, V4* q);
void Mtx34_Copy(M4* d, M4* s);
void Mtx_SetTranslation(M4* m, V4* p);
V4* func_0019D1A0(M4* m);
V4* func_0019D190(M4* m);
float Vec4_GetZ(V4* v);
float Vec_HeadingFromYX(V4* v);
float Vec_HeadingFromNegXY(V4* v);
}
static inline float MinZ(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }
static inline float MinK(float a, float x) { float k; float b; k = 0.0f; a = 1.0f; k = 1.5f; b = k * x; asm { min.s k, a, b } return k; }
static inline float MinM(float x) { float a; return MinK(a, x); }
static inline float MinC(float a, float b) { float r = 0.0f; float x = a; asm { min.s r, x, b } x = r; return r; }
static inline float Clamp01(float x) { float r = 0.0f; float hi = 1.0f; asm { max.s r, x, r; min.s r, r, hi } return r; }
static inline float Clamp01L(float x) { float r = 0.0f; float lo = 0.0f; float hi = 1.0f; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline float Clamp01Q(float x) { float r = 0.0f; float y = x; float lo = 0.0f; float hi; hi = 1.0f; asm { max.s r, y, lo; min.s r, r, hi } return r; }
static inline float Clamp01H(float x) { float r = 0.0f; float hi = 1.0f; float lo = 0.0f; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline u8 AimOk(Ctl* c) { int r = c->f2C8 >= 0.025f; return r; }
static inline u8 AimF(Actor* a) { bool r = false; if (a->ctl) { if (AimOk(a->ctl)) r = true; } return r; }
static inline u8 MidF(float g) { bool r = false; if (g > 0.0f && g < 1.0f) r = true; return r; }
static inline float MinA(float a, float b) { float r = 0.0f; r = a; asm { min.s r, r, b } return r; }
static inline float MaxA(float a, float b) { float r = 0.0f; r = a; asm { max.s r, r, b } return r; }
static inline float MinB(float a, float b) { float r = 0.0f; r = b; asm { min.s r, a, r } return r; }
static inline float MaxZ(float a, float b) { float r = 0.0f; asm { max.s r, a, b } return r; }
static inline float AbsZ(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline float SqrtF(float x) { float r; asm { sqrt.s r, x } return r; }
static inline float SqrtZ(float x) { float r = 0.0f; asm { sqrt.s r, x } return r; }
static inline VV Lerp_L(const VV& a, const VV& b, float k)
{
    VV t; int tk;
    VV* pt = &t; const VV* pa = &a; const VV* pb = &b;
    __asm__ volatile("lqc2 vf1, 0x0(%2); lqc2 vf2, 0x0(%3); mfc1 %0, %4; qmtc2.ni %0, vf3; vaddax.xyzw ACC, vf1, vf0x; vmaddax.xyzw ACC, vf2, vf3x; vmsubx.xyzw vf4, vf1, vf3x; sqc2 vf4, 0x0(%1)" : "=&r"(tk) : "r"(pt), "r"(pa), "r"(pb), "f"(k) : "memory");
    return t;
}
static inline float LenSq(V4* v)
{
    float r = 0.0f; int t;
    asm {
        lqc2 vf1, 0x0(v)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni t, vf4
        mtc1 t, r
    }
    return r;
}
static inline void QuatToMtx(M4* a, V4* b)
{
    asm {
        lqc2 vf1, 0x0(b)
        vadd.xyzw vf2, vf1, vf1
        vaddw.xyz vf3, vf0, vf0w
        vmulx.w vf8, vf0, vf0x
        vmulx.w vf9, vf0, vf0x
        vmuly.xyzw vf5, vf1, vf2y
        vmulz.xyzw vf6, vf1, vf2z
        vmulx.xyzw vf4, vf1, vf2x
        vmulx.w vf10, vf0, vf0x
        vsubay.x ACC, vf3, vf5y
        vmsubz.x vf8, vf3, vf6z
        vsubw.x vf9, vf5, vf6w
        vaddw.x vf10, vf6, vf5w
        vaddw.y vf8, vf4, vf6w
        vsubax.y ACC, vf3, vf4x
        vmsubz.y vf9, vf3, vf6z
        vsubw.y vf10, vf6, vf4w
        vsubw.z vf8, vf4, vf5w
        vaddw.z vf9, vf5, vf4w
        vsubax.z ACC, vf3, vf4x
        vmsuby.z vf10, vf3, vf5y
        sqc2 vf0, 0x30(a)
        sqc2 vf8, 0x0(a)
        sqc2 vf9, 0x10(a)
        sqc2 vf10, 0x20(a)
    }
}
static inline void MulVec(V4* d, V4* s, M4* mp)
{
    __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; sqc2 vf8, 0x0(%0)" : : "r"(d), "r"(mp), "r"(s) : "memory");
}
static inline u8 InvArmed(Inv* i) { return i->b84 != 6; }
static inline bool Vt54(Actor* a) { bool r = false; if (a->p58 && a->p58->IsPlayer()) r = 1; return r; }
static inline bool HasCtlI(Actor* a) { bool r = false; if (a->ctl && a->ctl->bDC) r = 1; return r; }
static inline int HasCtl(Actor* a) { u8 r = 0; if (a->ctl && a->ctl->bDC) r = 1; return r; }
static inline bool HasCtlDD(Actor* a) { bool r = false; if (a->ctl && a->ctl->bDD) r = 1; return r; }
static inline u8 Flag0(Actor* a) { return (a->i3034 & 1) != 0; }
static inline u8 NFlag0(Actor* a) { return !Flag0(a); }
static inline u8 C1(Actor* a) { u8 r = 0; if (HasCtl(a)) { if (NFlag0(a)) r = 1; } return r; }
static inline u8 Bit4(Actor* a) { return ((a->st.flags >> 4) & 1) != 0; }
static inline u8 Bit5(Actor* a) { return ((a->st.flags >> 5) & 1) != 0; }
static inline u8 Bit10(Actor* a) { return ((a->st.flags >> 10) & 1) != 0; }
static inline u8 Bit11(Actor* a) { return ((a->st.flags >> 11) & 1) != 0; }
static inline u8 Bit15(Actor* a) { return ((a->i3248 >> 15) & 1) != 0; }
static inline u8 C2(Actor* a) { u8 r = 1; if (!C1(a)) { if (!Bit4(a)) r = 0; } return r; }
static inline u8 C3(Actor* a) { u8 r = 1; if (!C2(a)) { if (!Bit5(a)) r = 0; } return r; }
static inline u8 C4(Actor* a) { u8 r = 1; if (!C3(a)) { if (!Bit10(a)) r = 0; } return r; }
static inline u8 C5(Actor* a) { u8 r = 1; if (!C4(a)) { if (!Bit11(a)) r = 0; } return r; }
static inline int C6(Actor* a) { u8 r = 1; if (!C5(a)) { if (!Bit15(a)) r = 0; } return r; }
static inline void SendMsg(Actor* a, int id)
{
    Msg m;
    Msg* p = &m;
    Event_Construct(p, g_CasEventMsgClass);
    p->vt = D_004DA950;
    p->i24 = id;
    p->i28 = -1;
    p->i2C = 0;
    Event_Send(p, a->p58, 1);
    m.vt = D_004DA950;
    cMessage_dtor(p, 0);
}
static inline float AngA(float x, float y) { float r = Math_Atan2f(x, y); r += 3.1415927f; return r; }
static inline float MulF(float a, float b) { return a * b; }
static inline float HalfWrap(float c) { if (c > 0.5f) return c - 0.5f; return 0.5f + c; }
static inline bool BT(int* p, int i) { return BitArray_Test(p, i); }
static inline bool BitB(int v, int n) { return ((v >> n) & 1) != 0; }
struct VF { float x, y, z, w; VF(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } };
static inline float AbsR(const float& x) { const float* p = &x; float r = 0.0f; float v = *p; asm { abs.s r, v } return r; }
static inline float LerpF(float a, float b, float s) { return a + s * (b - a); }
static inline float LerpG(float a, float b, float s) { float d = b - a; return a + s * d; }
static inline float Ramp(float* pin, float* pprev)
{
    float t;
    if ((*pin <= 0.0f && *pin < *pprev) || (*pin < 0.0f && *pin == *pprev)) {
        t = 0.0f;
    } else if ((*pin >= 0.0f && *pin > *pprev) || (*pin > 0.0f && *pin == *pprev)) {
        t = 1.0f;
    } else if (*pin < *pprev) {
        t = LerpF(1.0f, 0.0f, MinZ(1.0f, *pprev - *pin));
    } else if (*pin > *pprev) {
        { float d = *pin - *pprev; t = LerpF(0.0f, 1.0f, MinZ(1.0f, d)); }
    } else {
        t = 0.5f;
    }
    return t;
}
static inline float Ramp2(float* pin, float* pprev)
{
    float t;
    if ((*pin <= 0.0f && *pin < *pprev) || (*pin < 0.0f && *pin == *pprev)) {
        t = 0.0f;
    } else if ((*pin >= 0.0f && *pin > *pprev) || (*pin > 0.0f && *pin == *pprev)) {
        t = 1.0f;
    } else if (*pin < *pprev) {
        { float* p = pprev; float* q = pin; t = LerpF(1.0f, 0.0f, MinA(1.0f, *p - *q)); }
    } else if (*pin > *pprev) {
        { float* p = pin; float* q = pprev; t = LerpF(0.0f, 1.0f, MinA(1.0f, *p - *q)); }
    } else {
        t = 0.5f;
    }
    return t;
}
static inline u8 Crossing(float c, float t) { return (c < 0.5f && t > 0.5f) || (c > 0.5f && t < 0.5f); }
static inline void Snap(float* v, float* tgt) { if (AbsZ(*v - *tgt) < 0.001f) *v = *tgt; }
static inline void UpdateLean(Actor* a, AnimBlk* blk)
{
    u8 ok = 1;
    float t, c;
    float dur;
    t = Ramp(&a->in.y, &a->v3040.y);
    c = AnimChannel_GetCurrent(blk->anim, 5);
    if ((c < 0.5f && t > 0.5f) || (c > 0.5f && t < 0.5f)) dur = D_0049CFE8; else dur = D_0049CFE0;
    if (ok) AnimChannel_SetTarget(blk->anim, 0, 0, t, dur, 3.0f);
    ok = 1;
    t = Ramp(&a->in.x, &a->v3040.x);
    c = AnimChannel_GetCurrent(blk->anim, 6);
    if ((c < 0.5f && t > 0.5f) || (c > 0.5f && t < 0.5f)) dur = D_0049CFE8; else dur = D_0049CFE0;
    if (ok) AnimChannel_SetTarget(blk->anim, 1, 0, t, dur, 3.0f);
}
static inline void UpdateLean2(Actor* a, AnimBlk* blk)
{
    u8 ok = 1;
    float t, c;
    float dur;
    t = Ramp2(&a->in.y, &a->v3040.y);
    c = AnimChannel_GetCurrent(blk->anim, 5);
    if ((c < 0.5f && t > 0.5f) || (c > 0.5f && t < 0.5f)) dur = D_0049CFE8; else dur = D_0049CFE0;
    if (ok) AnimChannel_SetTarget(blk->anim, 0, 0, t, dur, 3.0f);
    ok = 1;
    t = Ramp2(&a->in.x, &a->v3040.x);
    c = AnimChannel_GetCurrent(blk->anim, 6);
    if ((c < 0.5f && t > 0.5f) || (c > 0.5f && t < 0.5f)) dur = D_0049CFE8; else dur = D_0049CFE0;
    if (ok) AnimChannel_SetTarget(blk->anim, 1, 0, t, dur, 3.0f);
}
static inline void SmoothInput(Actor* a, float k)
{
    { void* d; __int128 q; float* v; float* t; const void* s; const void* xx;
      VV r = Lerp_L(AV(a->v3040), AV(a->in), k);
      xx = &r; d = &a->v3040; s = &r;
      __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory");
      v = &a->v3040.x; t = &a->in.x; if (AbsZ(*v - *t) < 0.001f) *v = *t; }
    { float* v = &a->v3040.y; float* t = &a->in.y; if (AbsZ(*v - *t) < 0.001f) *v = *t; }
    if (a->in.x != 0.0f && a->in.y == 0.0f) { float* p = &a->v3040.y; if (*p < 0.0f) *p = 0.0f; }
}
static inline void HeadingFromRoot(Actor* a)
{
    M4 m;
    float h = Mtx_GetHeading(Placement_ToMatrix(&m, Root_ResolveWorldPlacement(a->p3290)));
    History_At(a->hist, a->i3098)[1] = h;
    ActorHeading_RetargetLast(a->heading, -1.0f);
}
static inline void OrientYaw(Actor* a, float yaw)
{
    V4 q;
    V4 aa;
    aa.x = 0.0f;
    aa.y = 0.0f;
    aa.z = 1.0f;
    aa.w = yaw;
    { V4* pa = &aa; Quat_FromYaw(&q, pa); }
    Root* r = a->p3290;
    Root_SetWorldOrientation(r, &q);
    r->i160 = 0;
}
static inline void HistRest(Actor* a)
{
    int i = func_0019D230(a->hist) - 1;
    float h = ((float*)(*func_0019D220(a->hist) + i * 8))[1];
    History_At(a->hist, a->i3098)[1] = h;
    ActorHeading_RetargetLast(a->heading, -1.0f);
}
static inline char* GetWorld(Root* r)
{
    if (Root_GetParent(r)) {
        Root_RefreshWorldCache(r);
        return Root_Identity(r);
    }
    return Root_Identity(r) + 0x50;
}
static inline void DurTarget(Actor* a, AnimBlk* blk, int busy, int idx, float t, const float& hi, const float& lo)
{
    float c = AnimChannel_GetCurrent(blk->anim, idx);
    float g4 = AnimChannel_GetCurrent(blk->anim, 4);
    float dur;
    if (!busy && g4 == 0.0f) {
        dur = 0.0f;
    } else if (!busy && ((c < 0.5f && t > 0.5f) || (c > 0.5f && t < 0.5f)) && !((a->i3248 >> 4) & 1) && g4 < 1.0f) {
        dur = lo + g4 * (hi - lo);
    } else {
        dur = hi;
    }
    AnimChannel_SetTarget(blk->anim, idx, 0, t, dur, 3.0f);
}

static inline void RotIn(Actor* a, float c, float s)
{
    M4 m;
    Mtx44_SetRotation(&m, c, -s, 0.0f, s, c, 0.0f, 0.0f, 0.0f, 1.0f);
    MulVec(&a->in, &a->in, &m);
}
typedef struct { Msg m; int x[4]; } NMsg;
static inline void FireNoise(Actor* a)
{
    NMsg m;
    void* svc = Service_Lookup(g_Game, D_004EE5C0);
    { int* p = (int*)a->c0C; AiSound_SendFireNoise((Msg*)&m, p, 3, 1.0f, a->f31F8); }
    Event_Send((Msg*)&m, svc, 0);
    m.m.vt = D_004D92A0;
    cMessage_dtor((Msg*)&m, 0);
}
static inline void EdgeHeading(Actor* a)
{
    V4 e;
    M4 m;
    QuatToMtx(&m, Root_GetWorldQuat(Actor_GetEdgeRoot2(a)));
    M4* pm = &m;
    float h = Mtx_ToEuler(&e, pm)[2];
    History_At(a->hist, a->i3098)[1] = h;
    ActorHeading_RetargetLast(a->heading, 0.5f);
}
struct M4Q { V4 r[4]; M4Q(V4* q) { Quat_ToMatrix((M4*)this, q); } };
static inline void CopyM(M4* d, const M4Q& s) { Mtx34_Copy(d, (M4*)&s); }
static inline VV V1A0(M4* m) { return *(VV*)func_0019D1A0(m); }
static inline VV V190(M4* m) { return *(VV*)func_0019D190(m); }
static inline float PickH(const VV& a, const VV& b) { if (Vec4_GetZ((V4*)&a) < Vec4_GetZ((V4*)&b)) return Vec_HeadingFromYX((V4*)&a); return Vec_HeadingFromNegXY((V4*)&b); }
static inline void WorldM(M4* m, char* w) { M4 rot; Quat_ToMatrix(&rot, Placement_GetQuat(w)); Mtx34_Copy(m, &rot); }
static inline float PickH2(M4* m) { V4 va; V4 vb; Vec4_Assign(&va, func_0019D1A0(m)); Vec4_Assign(&vb, func_0019D190(m)); if (Vec4_GetZ(&va) < Vec4_GetZ(&vb)) return Vec_HeadingFromYX(&va); return Vec_HeadingFromNegXY(&vb); }
static inline void WorldMW(M4* m, char* w) { WorldM(m, w); }
static inline float PickHW(M4* m) { return PickH2(m); }
static inline float HeadingFromWorld(Actor* a, float dt)
{
    Root* root = a->p3290;
    char* w = GetWorld(root);
    V4* pos = Placement_GetPosition(w);
    M4 m;
    float h;
    WorldMW(&m, w);
    Mtx_SetTranslation(&m, pos);
    h = PickHW(&m);
    h = h + a->f31D4 * dt;
    for (;;) {
        if (!(h <= 3.1415927f)) { h += -6.2831855f; continue; }
        if (h < -3.1415927f) { h += 6.2831855f; continue; }
        break;
    }
    History_At(a->hist, a->i3098)[1] = h;
    ActorHeading_RetargetLast(a->heading, -1.0f);
    return h;
}

extern "C" void Actor_UpdateAnimationState(Actor* a, float dt)
{
    int busy;
    AnimBlk* blk;
    int eq;
    float f20, f23, f22, f21;
    a->i3208 &= ~1;
    a->i3208 &= ~2;
    a->i3208 &= ~4;
    a->i3208 &= ~0x20;
    a->i3208 &= ~0x40;
    a->i3208 &= ~0x80;
    if (a->st.mode == 5) {
        Actor_SetPendingFlag(&a->i3200, 6, 1);
    } else if (HasCtlI(a)) {
        Actor_SetPendingFlag(&a->i3200, 7, 1);
    }
    if (a->st.mode == 2) {
        Actor_SetPendingFlag(&a->i3200, 5, 1);
    }
    if ((g_IsMultiplayer && !a->b14) || !Vt54(a)) {
        Actor_PrepareNavigation(a, dt);
    }
    busy = C6(a);
    blk = &a->blk;
    a->rate = 1.875f * dt;
    f20 = 5.625f * dt;
    f23 = 0.28125f * dt;
    eq = Inventory_GetEquipMode(a->inv);
    {
        u8 flag;
        if (Vt54(a)) {
            u8 r = 0;
            if (Inventory_HasAnyItem(a->inv) && (u8)eq != 6) r = 1;
            flag = r;
        } else {
            u8 r = 0;
            if (InvArmed(a->inv) && (u8)eq != 6) r = 1;
            flag = r;
        }
        AnimChannel_Approach(blk->anim, 12, 0, flag ? 1.0f : 0.0f, f20);
        AnimChannel_Approach(blk->anim, 13, 0, (u8)eq == 6 ? 1.0f : 0.0f, f20);
    }
    if (!busy) {
        float c5, c6;
        f22 = MulF(AngA(a->in.x, a->in.y), 0.15915494f); f22 = Clamp01(f22);
        f21 = HalfWrap(f22);
        c5 = AnimChannel_GetCurrent(blk->anim, 5);
        c6 = AnimChannel_GetCurrent(blk->anim, 6);
        if (f22 < 0.1f && c5 < 0.5f && a->b31DC == 1) {
            f22 = 1.0f;
        } else if (f22 > 0.9f && c5 < 0.5f && a->b31DC == 0) {
            f22 = 0.0f;
        }
        if (f21 < 0.1f && c5 > 0.5f && c6 < 0.5f) {
            f21 = 1.0f;
        } else if (f21 > 0.9f && c5 > 0.5f && c6 > 0.5f) {
            f21 = 0.0f;
        }
        if ((a->st.flags >> 2) & 1) {
            if (a->f31D0 > 0.0f) {
                AnimChannel_Approach(blk->anim, 15, 0, f22, f23);
                AnimChannel_Approach(blk->anim, 16, 0, f21, f23);
            } else {
                AnimChannel_SetDirect(blk->anim, 15, AnimChannel_GetCurrentValue(blk, 15));
                AnimChannel_SetDirect(blk->anim, 16, AnimChannel_GetCurrentValue(blk, 16));
            }
        } else {
            if (a->f31D0 == 0.0f) {
                f22 = 0.5f;
                f21 = 0.0f;
            }
            AnimChannel_SetDirect(blk->anim, 15, f22);
            AnimChannel_SetDirect(blk->anim, 16, f21);
        }
    } else {
        AnimChannel_SetDirect(blk->anim, 15, AnimChannel_GetCurrentValue(blk, 15));
        AnimChannel_SetDirect(blk->anim, 16, AnimChannel_GetCurrentValue(blk, 16));
    }
    if (a->ctl && a->b14 && Vt54(a)) {
        a->ctl->b3D1 = 1;
        if (a->ctl->b3D2) {
            Actor_SetPendingFlag(&a->i3200, 4, 1);
        } else {
            Actor_SetPendingFlag(&a->i3200, 4, ((a->i3248 >> 1) & 1) != 0);
        }
    } else {
        Actor_SetPendingFlag(&a->i3200, 4, ((a->i3248 >> 1) & 1) != 0);
    }
    if (g_IsMultiplayer && a->p3584 && a->b14) {
        int b4 = ((a->i3204 >> 4) & 1) != 0;
        if (b4) {
            a->p3584->b50 |= 2;
        } else {
            a->p3584->b50 &= 0xFD;
        }
    }
    {
        u8 r = 0;
        if (((BitArray_Test(&a->i3200, 4) != 0) ^ 1) && BitArray_Test(&a->i3204, 4)) r = 1;
        if (r) {
            SendMsg(a, 2);
            SendMsg(a, 3);
        } else {
            u8 r2 = 0;
            if (BitArray_Test(&a->i3200, 4) && ((BitArray_Test(&a->i3204, 4) != 0) ^ 1)) r2 = 1;
            if (r2) {
                SendMsg(a, 4);
                SendMsg(a, 5);
            }
        }
    }
    Actor_SetPendingFlag(&a->i3200, 3, (a->i3248 & 1) != 0);
    if (a->ctl) {
        a->ctl->i38 &= ~1;
    }
    {
        St* st = &a->st;
        St* st2;
        int s = a->st.mode;
        if (s == 8 || s == 7) {
            func_0019DC30(a, dt);
        } else if (s == 16) {
            Ladder_Update(a, dt);
        } else if (((a->i324C >> 3) & 1) || ((a->i324C >> 6) & 1)) {
            Actor_UpdatePairChannels(a, dt);
        } else if (s != 0 && s != 2 && !((st->flags >> 27) & 1) && !((st->flags >> 5) & 1)) {
            if (s != 1 && !((st->flags >> 5) & 1)) {
                Actor_SetPendingFlag(&a->i3200, 0, 1);
            }
            Actor_PrepareNeutralChannels(a, 0, 0, 0, 0);
        } else if (a->f31D0 == 0.0f) {
            float g, g2, dur;
            if (!((a->i3204 >> 5) & 1) && !((a->i3204 >> 6) & 1) && !((a->i3204 >> 7) & 1)) {
                Actor_SetPendingFlag(&a->i3200, 0, 1);
            }
            if (a->ctl && ((a->i3204 >> 3) & 1)) {
                func_0019D6E0(a->ctl->s30, 0, 1);
            }
            func_0019D6C0(blk->anim, 3, 0);
            g = AnimChannel_GetCurrent(blk->anim, 4);
            g2 = g * g;
            dur = MulF(1.0f + 1.5f * (g2 * g2), 0.16f);
            if (!busy || ((a->i3248 >> 15) & 1)) {
                AnimChannel_SetTarget(blk->anim, 4, 0, 0.0f, dur, 3.0f);
            }
            if ((a->i3204 >> 3) & 1) {
                AnimChannel_SetTarget(blk->anim, 10, 0, 1.0f, D_0049CF90, 5.5f);
            } else {
                AnimChannel_SetTarget(blk->anim, 10, 0, 0.0f, D_0049CF90, 5.5f);
            }
            if ((a->i3204 >> 4) & 1) {
                AnimChannel_Approach(blk->anim, 11, 0, 1.0f, a->rate);
            } else {
                AnimChannel_Approach(blk->anim, 11, 0, 0.0f, a->rate);
            }
            if (!busy && AnimChannel_GetCurrent(blk->anim, 4) == 0.0f) {
                float d;
                AnimChannel_SetTarget(blk->anim, 5, 0, 0.5f, D_0049CF68, 3.0f);
                AnimChannel_SetTarget(blk->anim, 6, 0, 0.5f, D_0049CF58, 3.0f);
                { float cur = AnimChannel_GetCurrent(blk->anim, 4); float k = D_0049CFC0; d = MulF(cur, k); }
                AnimChannel_SetTarget(blk->anim, 7, 0, 0.0f, d, 3.0f);
                AnimChannel_SetTarget(blk->anim, 8, 0, 0.0f, d, 3.0f);
                AnimChannel_SetTarget(blk->anim, 9, 0, AnimChannel_GetTarget(blk, 6), D_0049CF58, 3.0f);
            } else if (busy) {
                AnimChannel_SetTarget(blk->anim, 3, 0, AnimChannel_GetCurrentValue(blk, 3), -1.0f, 0.0f);
                AnimChannel_SetTarget(blk->anim, 5, 0, AnimChannel_GetCurrentValue(blk, 5), -1.0f, 0.0f);
                AnimChannel_SetTarget(blk->anim, 6, 0, AnimChannel_GetCurrentValue(blk, 6), -1.0f, 0.0f);
                AnimChannel_SetTarget(blk->anim, 7, 0, AnimChannel_GetCurrentValue(blk, 7), -1.0f, 0.0f);
                AnimChannel_SetTarget(blk->anim, 8, 0, AnimChannel_GetCurrentValue(blk, 8), -1.0f, 0.0f);
                AnimChannel_SetTarget(blk->anim, 9, 0, AnimChannel_GetCurrentValue(blk, 9), -1.0f, 0.0f);
            } else {
                AnimChannel_SetTarget(blk->anim, 7, 0, AnimChannel_GetCurrentValue(blk, 7), -1.0f, 0.0f);
                AnimChannel_SetTarget(blk->anim, 8, 0, AnimChannel_GetCurrentValue(blk, 8), -1.0f, 0.0f);
            }
            if (a->b31B7 && HasCtlDD(a) && !((a->i3248 >> 4) & 1)) {
                AnimChannel_SetTarget(blk->anim, 14, 0, Clamp01(0.5f - a->f31D4 * MulF(1.0f, 0.22207667f)), D_0049CFB8, 6.5f);
            } else {
                AnimChannel_SetTarget(blk->anim, 14, 0, 0.5f, D_0049CFB8, 6.5f);
            }
            {
                if ((a->i3248 >> 30) & 1) AnimChannel_Approach(blk->anim, 17, 0, 0.0f, a->rate);
                else if ((a->i3248 >> 31) & 1) AnimChannel_Approach(blk->anim, 17, 0, 1.0f, a->rate);
                else AnimChannel_Approach(blk->anim, 17, 0, 0.5f, a->rate);
            }
            if (AnimChannel_GetCurrent(blk->anim, 4) == 0.0f) {
                AnimChannel_SetTarget(blk->anim, 2, 0, 0.0f, D_0049CF50, 3.0f);
            } else {
                AnimChannel_SetTarget(blk->anim, 2, 0, AnimChannel_GetCurrent(blk->anim, 2), -1.0f, 0.0f);
            }
            UpdateLean(a, blk);
            SmoothInput(a, MinZ(1.0f, MulF(dt, 1.5f)));
        } else {
            func_0019D6C0(blk->anim, 3, 0);
            if (a->b31B3 && a->in.y > 0.0f && AnimChannel_GetCurrent(blk->anim, 4) == 1.0f) {
                float k, A, ang, s, c;
                if (a->b31B3) k = 0.31666666f * a->f31D4; else k = 0.0f;
                A = 1.2217305f;
                VF v(-AbsR(a->in.x), AbsR(a->in.y), 0.0f, 0.0f);
                ang = Math_Atan2f(-v.x, v.y);
                f22 = Clamp01Q((1.0f / A) * (A - ang));
                s = Math_SinThunk(k * f22);
                c = Math_CosThunk(k * f22);
                RotIn(a, c, s);
            }
            if ((a->i3204 >> 3) & 1) {
                AnimChannel_SetTarget(blk->anim, 10, 0, 1.0f, D_0049CF98, 5.5f);
            } else {
                AnimChannel_SetTarget(blk->anim, 10, 0, 0.0f, D_0049CFA0, 5.5f);
            }
            if ((a->i3204 >> 4) & 1) {
                AnimChannel_Approach(blk->anim, 11, 0, 1.0f, a->rate);
            } else {
                AnimChannel_Approach(blk->anim, 11, 0, 0.0f, a->rate);
            }
            if (a->in.y < 0.0f) {
                f21 = LerpF(0.0f, 0.5f, AnimChannel_GetCurrent(blk->anim, 7) * AnimChannel_GetCurrent(blk->anim, 3));
            } else if (a->in.y > 0.0f) {
                f21 = 1.0f;
            } else if (a->in.x == 0.0f) {
                f21 = 0.5f;
            } else {
                f21 = 1.0f;
            }
            DurTarget(a, blk, busy, 5, f21, D_0049CF68, D_0049CF70);
            f21 = 0.0f;
            if (a->in.x < 0.0f) {
                a->b31DC = 0;
            } else if (a->in.x > 0.0f) {
                f21 = 1.0f;
                a->b31DC = 1;
            } else if (AnimChannel_GetCurrent(blk->anim, 7) > 0.0f) {
                if (!a->b31DC) f21 = 0.0f; else f21 = 1.0f;
            } else {
                f21 = 0.5f;
            }
            DurTarget(a, blk, busy, 6, f21, D_0049CF58, D_0049CF60);
            {
                float ay = AbsR(a->in.y);
                float ax = AbsR(a->in.x);
                float ang = Math_Atan2f(ax, ay);
                float c3, g4, d5, d6, w, hi, lo, h2, dur;
                u8 up;
                { float s1 = Math_Sin(ang); float s2 = Math_Sin(2.3561945f - ang);
                f22 = Clamp01H(s1 / s2 / SqrtZ(2.0f)); }
                c3 = AnimChannel_GetCurrent(blk->anim, 3);
                g4 = AnimChannel_GetCurrent(blk->anim, 4);
                d5 = 2.0f * AbsZ(AnimChannel_GetCurrent(blk->anim, 5) - 0.5f);
                d6 = 2.0f * AbsZ(AnimChannel_GetCurrent(blk->anim, 6) - 0.5f);
                w = d5 + f22 * (d6 - d5);
                up = f22 >= c3;
                lo = D_0049CF88;
                hi = up ? D_0049CF78 : D_0049CF80;
                h2 = lo + w * (hi - lo);
                if (!busy && g4 == 0.0f) {
                    dur = 0.0f;
                } else if (!busy && ((c3 < 0.5f && f22 > 0.5f) || (c3 > 0.5f && f22 < 0.5f)) && !((a->i3248 >> 4) & 1) && g4 < 1.0f) {
                    dur = D_0049CF88 + g4 * (h2 - D_0049CF88);
                } else {
                    dur = h2;
                }
                AnimChannel_SetTarget(blk->anim, 3, 0, f22, dur, 3.0f);
            }
            if (!HasCtlI(a)) {
                if (!HasCtlDD(a)) {
                    AnimChannel_SetTarget(blk->anim, 7, 0, 0.0f, D_0049CFC0, 3.0f);
                    AnimChannel_SetTarget(blk->anim, 8, 0, 0.0f, D_0049CFC0, 3.0f);
                } else if (!(a->f309C < 1.0f) && a->p3314 && a->p3314->b311 == 0x16) {
                    AnimChannel_SetTarget(blk->anim, 7, 0, 0.0f, D_0049CFD0, 3.0f);
                    AnimChannel_SetTarget(blk->anim, 8, 0, 0.0f, D_0049CFD0, 3.0f);
                } else if (!(a->f309C < 1.0f) && !((a->i3204 >> 3) & 1) && !((a->i3204 >> 4) & 1)) {
                    if (a->in.y < 0.0f) {
                        float d = D_0049CFC8;
                        AnimChannel_SetTarget(blk->anim, 7, 0, 1.0f, d, 3.0f);
                        AnimChannel_SetTarget(blk->anim, 8, 0, 1.0f, d, 3.0f);
                    } else {
                        float c = AnimChannel_GetCurrent(blk->anim, 3);
                        AnimChannel_SetTarget(blk->anim, 7, 0, 0.0f, D_0049CFC0, 3.0f);
                        AnimChannel_SetTarget(blk->anim, 8, 0, c, D_0049CFC0, 3.0f);
                    }
                } else {
                    float g, d;
                    if ((busy != 0) ^ 1) g = AnimChannel_GetCurrent(blk->anim, 4); else g = 1.0f;
                    int b3 = ((a->i3204 >> 3) & 1) != 0;
                    d = g * (b3 ? D_0049CFD8 : D_0049CFC0);
                    AnimChannel_SetTarget(blk->anim, 7, 0, 0.0f, d, 3.0f);
                    AnimChannel_SetTarget(blk->anim, 8, 0, 0.0f, d, 3.0f);
                }
            }
            if (AnimChannel_GetCurrent(blk->anim, 7) <= 0.0f || a->in.y <= 0.0f) {
                AnimChannel_SetTarget(blk->anim, 9, 0, AnimChannel_GetTarget(blk, 6), D_0049CF58, 3.0f);
            }
            {
                float g11;
                u8 aim, mid, s5, s4, fast;
                f20 = Clamp01L(a->f31D0);
                g11 = AnimChannel_GetCurrent(blk->anim, 11);
                aim = AimF(a);
                mid = MidF(g11);
                s5 = ((a->i3248 >> 28) & 1) != 0;
                s4 = ((a->i3248 >> 4) & 1) != 0;
                {
                    bool f = true;
                    bool x = true;
                    if (!aim && !mid) x = false;
                    if (!x && !(a->f31D0 < 0.5f)) f = false;
                    fast = f;
                }
                if (mid) {
                    f20 = 0.0f;
                } else {
                    if (aim) { float x = a->ctl->f2C8; float h = 0.5f; f20 = h * (1.0f - x); }
                    if (a->ctl && a->ctl->fE4 != g_NegFltMax) {
                        float r;
                        f21 = 2.25f;
                        r = ActorPhysical_QueryWaterHeight(a->ctl);
                        { float v = 0.5f + (0.5f / f21) * (f21 - r); v = Clamp01L(v); f20 = MinZ(v, f20); }
                    }
                    if (s5 || s4) f20 = MinZ(0.5f, f20);
                    f20 *= MinM(AnimChannel_GetCurrent(blk->anim, 4));
                }
                AnimChannel_SetTarget(blk->anim, 2, 0, f20, fast ? D_0049CF50 : D_0049CF48, 3.0f);
            }
            if (f20 > 0.5f && ((a->i3204 >> 1) & 1) && !(g_VideoFrameCounter & 0xF)) {
                FireNoise(a);
            }
            UpdateLean2(a, blk);
            {
                float g;
                if ((busy != 0) ^ 1) g = AnimChannel_GetCurrent(blk->anim, 4); else g = 1.0f;
                SmoothInput(a, MinZ(1.0f, MulF(dt, MulF(1.0f - 0.95f * g, 30.0f))));
            }
            AnimChannel_SetTarget(blk->anim, 14, 0, 0.5f, D_0049CFB8, 6.5f);
            AnimChannel_Approach(blk->anim, 17, 0, 0.5f, a->rate);
            if (!((a->i3204 >> 3) & 1) && !((a->i3204 >> 4) & 1)) {
                if (AnimChannel_GetCurrent(blk->anim, 2) > 0.8f) {
                    Actor_SetPendingFlag(&a->i3200, 1, 1);
                } else if (!(AnimChannel_GetCurrent(blk->anim, 2) < 0.5f)) {
                    Actor_SetPendingFlag(&a->i3200, 2, 1);
                }
            }
            if ((a->i3204 >> 4) & 1) {
                AnimChannel_SetTarget(blk->anim, 4, 0, 1.0f, D_0049CFA8, 3.0f);
            } else if ((a->i3204 >> 3) & 1) {
                AnimChannel_SetTarget(blk->anim, 4, 0, 1.0f, D_0049CFA8, 3.0f);
            } else {
                AnimChannel_SetTarget(blk->anim, 4, 0, 1.0f, D_0049CFA8, 3.0f);
            }
        }
    }
    {
        float step = dt * (1.0f / D_0049CED8);
        if (LenSq(&a->in) > 0.95f && a->b31B4) {
            a->f309C += step;
            a->f309C = MinA(1.0f, a->f309C);
        } else {
            a->f309C -= step;
            a->f309C = MaxA(0.0f, a->f309C);
        }
    }
    {
        St* st = &a->st;
        St* st2;
        if (a->st.mode == 16) {
            if (!((st->flags >> 12) & 1)) {
                Root* r;
                V4* q = Root_GetWorldQuat(a->p3294);
                r = a->p3290;
                Root_SetWorldOrientation(r, q);
                r->i160 = 0;
                HeadingFromRoot(a);
            }
        } else if (a->st.mode == 1 || a->st.mode == 7 || a->st.mode == 8) {
            HeadingFromRoot(a);
        } else if ((a->st.mode == 4 || a->st.mode == 5) && ((a->i3248 >> 10) & 1)) {
            u8 r = 0;
            { int p = a->i3234; if (p != 4) { int q = a->i3220; if (q == 4) r = 1; } }
            if (r) {
                EdgeHeading(a);
            }
            OrientYaw(a, a->f3058);
        } else if (a->st.mode == 0 || a->st.mode == 2 || (a->st.mode == 10 && !((a->i3248 >> 10) & 1) && !((a->i3248 >> 11) & 1) && !((a->i3248 >> 12) & 1)) || (st2 = &a->st, a->st.mode == 21) || ((st2->flags >> 22) & 1) || a->st.mode == 28) {
            if (((st2 = &a->st, a->st.mode == 0) || a->st.mode == 21 || ((st2->flags >> 22) & 1)) && a->st.mode != 28 && (a->i3204 & 1) && HasCtlDD(a)) {
                if (a->i308C - 1 != a->i3098) {
                    OrientYaw(a, a->f3058); HistRest(a);
                } else {
                    HeadingFromRoot(a);
                }
            } else if (a->i308C - 1 != a->i3098) {
                OrientYaw(a, a->f3058); HistRest(a);
            } else {
                float hh = HeadingFromWorld(a, dt); OrientYaw(a, hh);
            }
        } else if (a->st.mode == 27) {
            OrientYaw(a, a->f3058);
        } else if (a->i308C - 1 != a->i3098) {
            OrientYaw(a, a->f3058);
        } else {
            HeadingFromRoot(a);
        }
    }
    a->b303C = (a->i3204 & 1) != 0;
}





















































































