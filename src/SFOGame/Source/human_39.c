/*
 * SFOGame/Source/human: 3 files, 001B16C0-001B1710
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001B16C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

int cHuman_IsHoldingGun(Actor* actor) {
    return actor->unk3524->state != 6;
}
static inline void merge_flush_func_001B16C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B16C0 */

/* merge_units: begin func_001B16E0 */
#pragma push /* merge_units */
extern int cSKM_GOBJ_Render(int);

void cHuman_Render(int a0) {
    int v0, v1;
    int cond;

    v1 = *(int*)((char*)a0 + 13236);
    cond = v1 != 0;
    if (cond) goto L001B1700;
    v0 = cSKM_GOBJ_Render(a0);
L001B1700:;
    goto ret;
ret:;
}
static inline void merge_flush_func_001B16E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B16E0 */

/* merge_units: begin func_001B1710 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#include "vslot_pad.h"
extern "C" void QueueMessage_cMessageR_cSystemP_int(void*, void*, int);

struct V { float x, y, z, w;
    V() {}
    V(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    float Length() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct M { V r[4]; } __attribute__((aligned(16)));

struct Ctrl { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char IsPlayer() const; virtual int IsB(); virtual int IsA(); VPAD8(d) virtual void Set(float, struct H*); };
struct Cml { VPAD2(a) virtual void Add(const V&); };
struct Sub33F0 { VPAD16(a) virtual void Tick(float); };
struct Net { char pad0[0x28]; unsigned char active; char pad29[0xC]; unsigned char b35; char pad36[2]; float hp; char pad3C[0x14];
    unsigned char flags; unsigned char mode; unsigned char flash; char pad53; int time; };
struct Flash { unsigned char on; };
struct Pick { char pad0[0xDD]; unsigned char bDD; char padDE[0x310 - 0xDE]; V v310; };
struct Att { char pad0[0x480]; V q480; V v490; void Blend(const V& q, const V& p, float dt); void Blend0(const V& q, const V& p, float dt); };
struct Fx { char pad0[0x80]; float pct; };
struct H;
struct Hdl { H* obj; int serial;
    Hdl() {}
    Hdl(H* a);
    int IsValid();
    H* Get() { return IsValid() ? obj : 0; } };
struct FxHdl { Fx* obj; int serial;
    int IsValid();
    Fx* Get() { return IsValid() ? obj : 0; } };

struct H {
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) virtual V Shape(); VPAD4(e) VPAD2(f) VPAD1(g)
    virtual void Damage(float, H*, int, int, int, int, int); VPAD1(h) virtual unsigned char Stance();
    char pad4[8];
    int serial;             /* 0xC */
    char pad10[4];
    unsigned char remote;   /* 0x14 */
    char pad15[0x2B];
    float health;           /* 0x40 */
    char pad44[0x14];
    Ctrl* ctrl;             /* 0x58 */
    char pad5C[4];
    char man[0x2DF6 - 0x60]; /* 0x60 */
    short fireCount;        /* 0x2DF6 */
    char pad2DF8[0x2FE0 - 0x2DF8];
    Cml* cml;               /* 0x2FE0 */
    char pad2FE4[0x3030 - 0x2FE4];
    char hist[0x20];        /* 0x3030 */
    char smf[0xA0];         /* 0x3050 */
    char smv[0xC0];         /* 0x30F0 */
    unsigned char b31B0;    /* 0x31B0 */
    unsigned char b31B1;
    char pad31B2;
    unsigned char b31B3;
    unsigned char b31B4;
    unsigned char b31B5;
    char pad31B6[0x31F4 - 0x31B6];
    float f31F4;            /* 0x31F4 */
    char pad31F8[8];
    int h3200[3];           /* 0x3200 */
    char pad320C[0x3248 - 0x320C];
    unsigned int flags3248; /* 0x3248 */
    char pad324C[0x3268 - 0x324C];
    unsigned char b3268;
    unsigned char b3269;
    unsigned char b326A;
    char pad326B[0x3290 - 0x326B];
    void* anchor;           /* 0x3290 */
    char pad3294[0x3310 - 0x3294];
    Pick* pick;             /* 0x3310 */
    Att* att;               /* 0x3314 */
    char pad3318[0x33A5 - 0x3318];
    unsigned char b33A5;    /* 0x33A5 */
    char pad33A6[2];
    float f33A8;
    float f33AC;
    int i33B0;
    char pad33B4[8];
    float f33BC;
    float f33C0;
    char pad33C4[4];
    unsigned char b33C8;
    char pad33C9[0x33EC - 0x33C9];
    Flash* flash;           /* 0x33EC */
    Sub33F0 sub33F0;        /* 0x33F0 */
    char pad33F4[0x3480 - 0x33F4];
    Hdl h3480;              /* 0x3480 */
    char pad3488[0x34E0 - 0x3488];
    void* fire;             /* 0x34E0 */
    char pad34E4[0x3524 - 0x34E4];
    void* weapon;           /* 0x3524 */
    char pad3528[4];
    float f352C;
    char pad3530[8];
    unsigned char b3538;
    char pad3539[0x354C - 0x3539];
    FxHdl fx[3];            /* 0x354C */
    char pad3564[0x3584 - 0x3564];
    Net* net;               /* 0x3584 */
};
static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline int DiffNV(int a, int b) { return a ^ b; }
static inline int SameNV(int a, int b) { return (unsigned)DiffNV(a, b) < 1; }
inline int Hdl::IsValid() { unsigned char ok = 1; if (!IsNullNV(obj) && !SameNV(obj->serial, serial)) ok = 0; return ok; }
inline int FxHdl::IsValid() { unsigned char ok = 1; if (!((obj != 0) ^ 1)) { int os = *(int*)((char*)obj + 0xC); if (!SameNV(os, serial)) ok = 0; } return ok; }
inline Hdl::Hdl(H* a) { obj = a; serial = -1; int m; serial = *(a ? &a->serial : (m = -1, &m)); }

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
extern "C" { extern char g_ActorActionMsgClass[]; extern char D_004E0840[], D_004D9320[], D_004E01E0[]; extern int D_0048A230;
void cMessage_ctor_cMessageNameR(void*, void*); void cMessage_dtor(void*, int); }
struct MsgB {
    void* vtable; void* type; int pad8[6]; unsigned char kind; char pad21[3];
    MsgB(void* t) { cMessage_ctor_cMessageNameR(this, t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct MsgI : MsgB {
    int id; unsigned char sub; char pad29[3];
    MsgI(int i, unsigned char s) : MsgB(g_ActorActionMsgClass) { vtable = D_004E0840; id = i; sub = s; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgI() { vtable = D_004E0840; }
};
struct MsgBool : MsgI {
    unsigned char val;
    MsgBool(int i, bool v) : MsgI(i, 1) { vtable = D_004D9320; val = v; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgBool() {}
};
struct MsgInt : MsgI {
    int val;
    MsgInt(int i, const int& v) : MsgI(i, 2) { vtable = D_004E01E0; val = v; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgInt() {}
};
static inline void Post(const MsgB& m, void* to, int p) { ((MsgB&)m).kind = 1; QueueMessage_cMessageR_cSystemP_int((void*)&m, to, p); }
struct StopMsg { void* vtable; char pad4[0x1C]; unsigned char kind; char pad21[0x57]; char s78[0x9C]; char s114[0x9C]; char pad1B0[0x20]; } __attribute__((aligned(16)));

extern "C" {
extern unsigned char g_IsMultiplayer;
extern float OnFireDmgPerSecond;
extern float D_0048A1D8, D_0048A1E8, D_0048A200;
extern char D_0049E850[], D_0049E880[];
extern char g_ActorActionMsgClass[], g_Game[];
extern char D_004E0840[], D_004D9320[], D_004E01E0[], D_004DADF0[];
extern char D_004F12D0[];
extern signed char D_004E1D88;
extern V D_004E1D90;
void cGOBJ_SetHitpoints(H*, int, int);
void cFlashlight_SetState(Flash*, bool);
void cHuman_CheckForChangedWeapons(H*);
int printf(const char*, ...);
void cNetHuman_Deactivate(Net*);
void cNetHuman_Activate(Net*);
int cDME_GetTime(int);
void cHuman_CheckForDisconnectedNetworkedPlayer(H*);
void cHuman_ActionModes_NextFrame(H*, float);
int ActorModel_FindAttachedModel(void*);
V cMan_GetGun2ndHand(void*);
V cMan_GetGun2ndHandOrient(void*);
float Math_Clampf(float, float, float);
V LerpAndNormalize(const V&, const V&, float);
V Vec4_Lerp(float, const V&, const V&);
void cQuaternion_opAssign(V*, const V&);
void cVector_opAssign(V*, const V&);
void cHuman_PreventRemotePlayerFromFallingThroughDeactivatedTerrain(H*);
void Actor_UpdateAnimationState(H*, float);
void cHuman_Choke_NextFrame(H*, float);
void cHuman_DetectForAnimationEvents(H*);
void cWeapon_NextFrame(void*, float);
M cMan_GetGunBarrelMatrix(void*, int);
void cFlashlight_Update(Flash*, float, const M&);
void cHuman_SetWeaponPickupLoc(H*);
void Actor_Ignite(H*, float, int, int, int, int);
void cHuman_SetParticleEffect(H*, int, int, float);
void cFireObj_SetIntensity(void*, float);
void ActorModel_GlowDown(void*);
void cSplinedMotion_float_NextFrame(void*, float, float);
float cSkaAnimAnchor_GetWeight(void*);
V* cSkaAnimAnchor_GetPosition(void*);
void cSkaAnimAnchor_SetPosition(void*, V*);
void cSplinedMotion_cVector_ResetCurrValWhileRetainingVelocity(void*, V*);
void cSplinedMotion_cVector_ResetCurrValAndZeroOutCurrVelocity(void*, V*);
void cSplinedMotion_cVector_RestartTransition(void*, float);
float nGameUnits_Sec(float);
void cSplinedMotion_cVector_NextFrame(void*, float, float);
V* cSplinedMotion_cVector_GetCurrVal(void*);
void cStatesWithHistory_1_NextFrame(void*);
void cStatesWithHistory_1_ClearAllStates(void*);
void cSKM_GOBJ_NextFrame(H*, float);
void cStopSoundMsg_ctor_cSndFxR_cGOBJP(StopMsg*, void*, H*);
void cFileMan_dtor(void*, int);
void cHuman_SetVisionEffect(H*);
}

static inline bool IsHuman(H* a) { bool r = 0; if (a->ctrl && a->ctrl->IsPlayer()) r = 1; return r; }
static inline bool IsHC(Ctrl* p) { bool r = 0; if (p && p->IsPlayer()) r = 1; return r; }
static inline bool IsHuman2(H* a) { return IsHC(a->ctrl); }
static inline bool IsA(H* a) { bool r = 0; if (a->ctrl && a->ctrl->IsA()) r = 1; return r; }
static inline bool IsB(H* a) { bool r = 0; if (a->ctrl && a->ctrl->IsB()) r = 1; return r; }
static inline bool Dying(H* a) { bool r; unsigned char s = a->Stance(); r = 1; if (s != 3 && s != 2) r = 0; return r; }
static inline bool FlashOn(H* a) { bool r = 0; if (a->flash && a->flash->on) r = 1; return r; }
static inline bool CanPick(H* a) { bool r = 0; if (a->pick && a->pick->bDD) r = 1; return r; }
static inline unsigned char NetFlash(H* a) { Net* n = a->net; return n->flash; }
static inline void SetFlash(H* a, bool on) { if (a->flash) cFlashlight_SetState(a->flash, on); }
static inline bool NetBit(Net* n, int m) { bool r = (n->flags & m) != 0; return r; }
static inline V Point(const V& v) { V p = v; V* t = &p; t->w = 1.0f; return *t; }
static inline const V& ZeroV() {
    if (!D_004E1D88) { D_004E1D88 = 1; D_004E1D90.x = 0; D_004E1D90.y = 0; D_004E1D90.z = 0; D_004E1D90.w = 0; }
    return D_004E1D90;
}
static inline const V& PickPos(H* a) { if (a->pick) return a->pick->v310; return ZeroV(); }

inline void Att::Blend0(const V& q, const V& p, float dt)
{
    float t = Math_Clampf(10.5f * dt, 0.0f, 1.0f);
    cQuaternion_opAssign(&q480, LerpAndNormalize(q480, q, t));
    cVector_opAssign(&v490, Vec4_Lerp(t, v490, p));
}

inline void Att::Blend(const V& q, const V& p, float dt) { Blend0(q, p, dt); }
/* Original human.cc has earlier two-GPR soft-double comparisons (e.g. HandleBlast).
   Reproduce MW implicit-helper TU state using the discarded-context convention
   already used for loadingThread/onWake; this helper contributes no retail code. */
#pragma define_section HUMAN_CTX ".dtors_drop" far_absolute RX
__declspec(weak) __declspec(HUMAN_CTX) int human_softdouble_context(double a, double b) { return a >= b; }

extern "C" void cHuman_NextFrame(H* self, float timeStep)
{
    if (self->b3269) return;
    if (g_IsMultiplayer) {
        if (self->net) {
            if (!self->remote) {
                int nhp = (int)self->net->hp; if ((int)self->health != nhp) {
                    if (!IsA(self) || ((int)self->health > 0 && (int)self->net->hp > 0)) {
                        cGOBJ_SetHitpoints(self, (int)self->net->hp, 1);
                    }
                }
                { unsigned char w = self->net->b35; if (self->b33A5 != w) self->b33A5 = w; }
                if (FlashOn(self) != NetFlash(self)) SetFlash(self, self->net->flash);
            } else {
                self->net->hp = (float)(int)self->health;
                self->net->flash = FlashOn(self);
                { unsigned char v = self->b33A5; Net* n = self->net; n->b35 = v; }
            }
        }
        cHuman_CheckForChangedWeapons(self);
        if (IsA(self)) {
            if (self->net && self->net->active) {
                printf(D_0049E850, self->serial);
                cNetHuman_Deactivate(self->net);
            }
            if (self->remote) {
                printf(D_0049E880, self->serial);
                self->remote = 0;
            }
        } else if (IsB(self)) {
            Net* n = self->net;
            if (n) {
                n->time = cDME_GetTime(1);
                if (!self->net->active) cNetHuman_Activate(self->net);
            }
        }
        if (IsHuman(self) && !self->remote) cHuman_CheckForDisconnectedNetworkedPlayer(self);
        if (self->net && !self->remote) {
            if (NetBit(self->net, 1)) self->flags3248 |= 1; else self->flags3248 &= ~1;
            if (NetBit(self->net, 2)) self->flags3248 |= 2; else self->flags3248 &= ~2;
            self->b31B3 = NetBit(self->net, 4);
            self->b31B4 = NetBit(self->net, 8);
            self->b31B5 = NetBit(self->net, 0x20);
            switch (self->net->mode) {
            case 11:
                self->flags3248 &= ~0x80000000;
                self->flags3248 |= 0x40000000;
                break;
            case 12:
                self->flags3248 &= ~0x40000000;
                self->flags3248 |= 0x80000000;
                break;
            default:
                self->flags3248 &= ~0x40000000;
                self->flags3248 &= ~0x80000000;
                break;
            }
            Post(MsgBool(0x43, !NetBit(self->net, 0x40)), self, 1);
        }
    }
    cHuman_ActionModes_NextFrame(self, timeStep);
    {
        Cml* collisionModelList = self->cml;
        collisionModelList->Add(self->Shape());
    }
    if (self->att && ActorModel_FindAttachedModel(self->man)) {
        void* man = self->man;
        self->att->Blend(cMan_GetGun2ndHandOrient(man), Point(cMan_GetGun2ndHand(man)), timeStep);
    }
    cHuman_PreventRemotePlayerFromFallingThroughDeactivatedTerrain(self);
    Actor_UpdateAnimationState(self, timeStep);
    cHuman_Choke_NextFrame(self, timeStep);
    cHuman_DetectForAnimationEvents(self);
    { int j; for (j = 0; j < 1; j++) self->h3200[j] = self->h3200[j + 1]; }
    { int j; for (j = 0; j < 1; j++) self->h3200[j + 1] = self->h3200[j + 2]; }
    cWeapon_NextFrame(self->weapon, timeStep);
    if (FlashOn(self)) {
        { void* man = self->man; cFlashlight_Update(self->flash, timeStep, cMan_GetGunBarrelMatrix(man, 7)); }
    }
    if (CanPick(self)) cHuman_SetWeaponPickupLoc(self);
    if (self->remote) self->sub33F0.Tick(timeStep);
    {
        int i;
        float pctOn;
        for (i = 0; i < 3; i++) {
            if (self->fx[i].Get()) {
                pctOn = self->fx[i].Get()->pct;
                if (pctOn == 0.0f) {
                    if (i == 0) Actor_Ignite(self, -1.0f, 0, 0, 0, 0);
                    else cHuman_SetParticleEffect(self, (unsigned char)i, 0, 1.0f);
                } else if (i == 0 && self->fire) {
                    cFireObj_SetIntensity(self->fire, pctOn * D_0048A1D8);
                    if (self->remote && self->b326A && !Dying(self)) {
                        H* src = (self->h3480.Get() ? self->h3480 : Hdl(self)).Get();
                        self->Damage(pctOn * (OnFireDmgPerSecond * timeStep), src, 1, 4, 0, 0, 0);
                    }
                    if (IsHuman2(self) && self->remote) {
                        Ctrl* c = self->ctrl;
                        c->Set((float)(pctOn / 2.0f + 0.5), self);
                    }
                }
            }
        }
    }
    if (self->fire) self->fireCount++;
    else if (!Dying(self)) ActorModel_GlowDown(self->man);
    if (!(self->f31F4 < 0.0f)) {
        self->f31F4 -= timeStep;
        if (self->f31F4 < 0.0f) self->Damage((float)(int)self->health, self, 2, 0, 0, 0, 0);
    }
    {
        float inv = 1.0f / timeStep;
        void* anchor = self->anchor;
        cSplinedMotion_float_NextFrame(self->smf, timeStep, inv);
        if (self->b31B0) {
            unsigned char close = cSkaAnimAnchor_GetWeight(anchor) >= 0.98f;
            if (close) cSplinedMotion_cVector_ResetCurrValWhileRetainingVelocity(self->smv, cSkaAnimAnchor_GetPosition(anchor));
            else {
                cSplinedMotion_cVector_RestartTransition(self->smv, nGameUnits_Sec(0.2f));
                cSplinedMotion_cVector_ResetCurrValAndZeroOutCurrVelocity(self->smv, cSkaAnimAnchor_GetPosition(anchor));
            }
            cSplinedMotion_cVector_NextFrame(self->smv, timeStep, inv);
            if (close) cSkaAnimAnchor_SetPosition(anchor, cSplinedMotion_cVector_GetCurrVal(self->smv));
        }
    }
    cStatesWithHistory_1_NextFrame(self->hist);
    cStatesWithHistory_1_ClearAllStates(self->hist);
    cSKM_GOBJ_NextFrame(self, timeStep);
    self->b3268 = 0;
    if (!(self->f33A8 <= 0.0f)) {
        self->f33A8 -= timeStep;
        if (self->f33A8 < 0.0f) self->f33A8 = 0.0f;
    }
    if (!(self->f33AC <= 0.0f)) {
        self->f33AC -= timeStep;
        if (self->f33AC < 0.0f) self->f33AC = 0.0f;
    }
    if (self->i33B0 > 0) {
        self->i33B0 = (int)((float)self->i33B0 - timeStep * D_0048A1E8);
        if (self->i33B0 < 0) self->i33B0 = 0;
    }
    if (!(self->f33BC < 0.0f)) {
        self->f33BC += timeStep;
        if (!(self->f33BC <= self->f33C0)) {
            self->f33BC = -1.0f;
            cHuman_SetParticleEffect(self, 2, 0, 1.0f);
            MsgInt msg2(7, D_0048A230);
            Post(msg2, self, 1);
            StopMsg msg;
            cStopSoundMsg_ctor_cSndFxR_cGOBJP(&msg, D_004F12D0, self);
            msg.kind = 1;
            QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
            if (self->b33C8) self->Damage(10000.0f, self, 1, 4, 0, 0, 0);
            else self->Damage(0.0f, self, 1, 7, 0, 0, 0);
            msg.vtable = D_004DADF0;
            cFileMan_dtor(msg.s114, -1);
            cFileMan_dtor(msg.s78, -1);
            cMessage_dtor(&msg, 0);
        }
    }
    if (!(self->f352C <= 0.0f)) {
        self->f352C -= timeStep * D_0048A200;
        if (self->f352C < 0.0f) self->f352C = 0.0f;
    }
    cHuman_SetVisionEffect(self);
    if (self->b31B1) {
        float spd = PickPos(self).Length();
        self->b3538 = spd < 0.25f;
    }
}
static inline void merge_flush_func_001B1710(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B1710 */
