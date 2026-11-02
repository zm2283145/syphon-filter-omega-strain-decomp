/*
 * SFOGame/Source/human: 11 files, 001871C0-00188070
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001871C0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cNetUpdateStatsMsg_dtor, D_004DA990, D_004DCF10, cMessage_dtor)
static inline void merge_flush_func_001871C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001871C0 */

/* merge_units: begin func_00187230 */
#pragma push /* merge_units */
typedef struct { void* vtable; char base[0x20]; int id; unsigned char a; signed char b; char pad2A[6]; } Msg_187230;
extern char D_004EF008[];
extern char D_004DA990[];
extern char D_004DCF10[];
extern signed char* D_005061D0;
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg_187230* msg, void* name);
#endif /* merge_units */
void cMessage_ctor_cMessageNameR(void*, void*); /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Msg_187230* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

extern void cNetMsg_GetGOBJ(int* out);
extern void cHuman_UpdateStats(void* self, int id, int a, int b);
static inline void ReadU8_187230(unsigned char* out) { signed char v = *D_005061D0; D_005061D0++; *out = v; }
static inline void ReadS8_187230(signed char* out) { signed char v = *D_005061D0; D_005061D0++; *out = v; }
void cNetUpdateStatsMsg_NetReceive(void* self)
{
    Msg_187230 msg;
    cMessage_ctor_cMessageNameR(&msg, D_004EF008);
    msg.vtable = D_004DA990;
    cNetMsg_GetGOBJ(&msg.id);
    ReadU8_187230(&msg.a);
    ReadS8_187230(&msg.b);
    cHuman_UpdateStats(self, msg.id, msg.a, msg.b);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00187230(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00187230 */

/* merge_units: begin func_001872F0 */
#pragma push /* merge_units */
typedef struct {
    char p0[0x40];
    float f40;
    char p44[0x320C - 0x44];
    int state;
    char p3210[0x33A5 - 0x3210];
    unsigned char b33A5;
} S_1872F0;
int cHuman_GetHealthState(S_1872F0* p) {
    if (p->b33A5 || p->state == 0x1F)
        return 3;
    if (p->state == 0x1B)
        return 2;
    return (int)p->f40 ? 0 : 3;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001872F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001872F0 */

/* merge_units: begin func_00187360 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
#include "vslot_pad.h"

static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V() {} V(const V& o) { V* d = this; Q16(d, &o); } V& operator=(const V& o) { V* d = this; Q16(d, &o); return *this; } } __attribute__((aligned(16)));
static inline void VSub(V* r, V* a, V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline V Diff(const V& a, const V& b) { V t; VSub(&t, (V*)&a, (V*)&b); return t; }

struct Ctrl { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsHuman(); virtual int IsB(); virtual int IsA(); };
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct HitSub { VP v[3]; char pad30[0x10]; unsigned char b40; char pad41; unsigned char b42; char pad43[0x1D]; int i60; int i64; char pad68[0x18];
    /* empty walk over v[] mirrors the retail V[3] array-ctor loop on the materialized sub-object pointer */
    HitSub* Init() { HitSub* t = this; VP* q = t->v; do { q++; } while (q != t->v + 3); t->b40 = 0; t->b42 = 0; t->i60 = 0; t->i64 = 0; return t; } };
struct HitInfo { unsigned char hit; char pad1[0x1F]; HitSub s; HitSub* Init() { HitInfo* t = this; return t->s.Init(); } } __attribute__((aligned(16)));
struct Actor;
struct Hdl { Actor* obj; int serial;
    int IsValid();
    Actor* Get() { return IsValid() ? obj : 0; } };
struct Actor {
    VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d) virtual V Pos(int); VPAD8(e) virtual V AimFrom(HitSub*); VPAD8(f) virtual unsigned char Stance();
    char pad4[8];
    int serial;             /* 0xC */
    char pad10[4];
    unsigned char alive;    /* 0x14 */
    char pad15[0x2B];
    float health;           /* 0x40 */
    char pad44[0x14];
    Ctrl* ctrl;             /* 0x58 */
    char pad5C[0x3260 - 0x5C];
    unsigned char team;     /* 0x3260 */
    char pad3261[9];
    unsigned char burning;  /* 0x326A */
    char pad326B[0x33A0 - 0x326B];
    int armorHP;            /* 0x33A0 */
    unsigned char dead;     /* 0x33A4 */
    unsigned char b33A5;    /* 0x33A5 */
    char pad33A6[0xA];
    int fire;               /* 0x33B0 */
    char pad33B4[4];
    unsigned char b33B8;    /* 0x33B8 */
    char pad33B9[0x3480 - 0x33B9];
    Hdl h3480;              /* 0x3480 */
};
static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline int DiffNV(int a, int b) { return a ^ b; }
static inline int SameNV(int a, int b) { return (unsigned)DiffNV(a, b) < 1; }
inline int Hdl::IsValid() { unsigned char ok = 1; if (!IsNullNV(obj) && !SameNV(obj->serial, serial)) ok = 0; return ok; }
struct Svc { VPAD1(a) virtual void Post(void*); };

extern "C" {
extern int ArmorPenetrationResistance;
extern int BodyPenetrationResistance;
extern int HeadPenetrationResistance;
extern int FireDmgToIgnite;
extern int D_0048A2C0;
extern int g_Hud;
extern char D_0049D8F0[];
extern char D_004D9180[], D_004DAE30[], D_004DCC30[], D_004DCD70[], D_004E01E0[], D_004E0840[], D_004E08A0[];
extern char g_LosCheckService[], D_004EF0B0[], D_004EF250[], D_004EF730[], D_004EFF50[], D_004F0290[], D_004F05D0[], D_004F0910[];
extern char g_ScriptAIUnconsciousMsgKey[], g_Game[], g_LosRequestMsgClass[], g_ActorActionMsgClass[];
extern int g_MsgLibDamageRequestKey;
void cMessage_ctor_cMessageNameR(void*, void*);

void QueueMessage_cMessageR_cSystemP_int(void*, void*, int);
#if 0 /* merge_units */
void cMessage_dtor(void*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((a0), (short)(a1))) /* merge_units */


Svc* cSystemContainer_GetSystem(void*, void*);
void cPlaySoundMsg_ctor_cSndFxR(void*, void*, Actor*);
void cFileMan_dtor(void*, int);
void cHud_SetCallout(float, int, const int*, void*, int, float, int, int);
void Actor_Ignite(Actor*, float, int, int, int, int);
void cGOBJ_ReceiveDamage(Actor*, float, Actor*, unsigned char, unsigned char, int*, unsigned char, V*);
int Libc_Rand(void);
void nRumbleManager_Start(float, int, int, int, int);
int cHuman_ReceiveDamage(Actor* self, float dmg, Actor* src, unsigned char loc, unsigned char type, int* armor, unsigned char flag, V* hitPos);
}

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX

struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    MsgB() {}
    MsgB(void* t) { cMessage_ctor_cMessageNameR(this, t); }
    void SendF(void* to) { flags = 0x40; QueueMessage_cMessageR_cSystemP_int(this, to, 0); }
    void SendK(void* to, unsigned char k) { kind = k; QueueMessage_cMessageR_cSystemP_int(this, to, 0); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct MsgRay : MsgB {
    int a24; int a28; HitInfo* info; V pos; V dir; Actor* src; Actor* tgt; int n; unsigned char b5C;
    MsgRay(HitInfo* i, const V& p, V d, Actor* s, Actor* t) : MsgB(g_LosRequestMsgClass) {
        vtable = D_004D9180; a24 = 0; a28 = 0; info = i; V* dp = &pos; Q16(dp, &p); dir = d; src = s; tgt = t; n = 0x10; b5C = 0; pos.w = 1.0f; dir.w = 0.0f; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgRay() { vtable = D_004D9180; }
} __attribute__((aligned(16)));
struct MsgDmg : MsgB {
    int amount; Actor* src; unsigned char type; unsigned char loc; unsigned char b2E; char pad2F;
    MsgDmg(float a, Actor* s, unsigned char t, unsigned char l) : MsgB(&g_MsgLibDamageRequestKey) {
        vtable = D_004E08A0; amount = (int)a; src = s; type = t; loc = l; b2E = 1; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgDmg() { vtable = D_004E08A0; }
};
struct MsgI : MsgB {
    int id; unsigned char sub; char pad29[3];
    MsgI(int i, unsigned char s) : MsgB(g_ActorActionMsgClass) { vtable = D_004E0840; id = i; sub = s; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgI() { vtable = D_004E0840; }
};
struct MsgVal : MsgI {
    int val;
    MsgVal(const int& v) : MsgI(0x42, 2) { vtable = D_004E01E0; val = v; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgVal() {}
};
struct MsgWho : MsgB {
    Actor* who; int pad28[2];
    MsgWho(Actor* w) : MsgB(g_ScriptAIUnconsciousMsgKey) { vtable = D_004DCD70; who = w; kind = 2; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgWho() { vtable = D_004DCD70; }
};
struct MsgWho2 : MsgWho {
    MsgWho2(Actor* w) : MsgWho(w) { vtable = D_004DCC30; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgWho2() {}
};
struct SStr { char d[0x9C]; };
struct SEv {
    void* vtable; char pad4[0x1C]; unsigned char kind; char pad21[0x57]; SStr s78; SStr s114; char pad1B0[0x10];
} __attribute__((aligned(16)));

static inline bool IsHuman(Actor* a) { bool r = 0; if (a->ctrl && a->ctrl->IsHuman()) r = 1; return r; }
static inline bool IsA(Actor* a) { bool r = 0; if (a->ctrl && a->ctrl->IsA()) r = 1; return r; }
static inline bool IsB(Actor* a) { bool r = 0; if (a->ctrl && a->ctrl->IsB()) r = 1; return r; }
static inline bool Dying(Actor* a) { bool r; unsigned char s = a->Stance(); r = 1; if (s != 3 && s != 2) r = 0; return r; }

int cHuman_ReceiveDamage(Actor* self, float dmg, Actor* src, unsigned char loc, unsigned char type, int* armor, unsigned char flag, V* hitPos)
{
    int arm;
    if (type == 4 && self->h3480.Get()) {
        if (!src || !IsHuman(src))
            src = self->h3480.Get();
    }
    if (!src || self->dead || (type == 4 && self->b33B8))
        return 0;
    if (type == 2) {
        HitInfo info;
        V from = src->AimFrom(info.Init());
        if (hitPos) from = *hitPos;
        V to = self->Pos(0);
        MsgRay m(&info, from, Diff(to, from), src, self);
        cSystemContainer_GetSystem(g_Game, g_LosCheckService)->Post(&m);
        if (info.hit)
            return 0;
    }
    float pen = 0.0f;
    arm = armor ? *armor : 0;
    if (type == 4)
        pen = 1.0f;
    else if (arm > ArmorPenetrationResistance)
        pen = (float)(arm - ArmorPenetrationResistance) / (float)arm;
    float armorDmg = (1.0f - pen) * dmg;
    float bodyDmg = dmg - armorDmg;
    char* snd1 = 0;
    char* snd2;
    if (IsHuman(self)) snd2 = D_004EF0B0; else snd2 = D_004EF250;
    if (loc == 2) {
        if (type == 7) type = 0;
        if (!((IsA(src) || IsB(src)) && (IsA(self) || IsB(self))))
            bodyDmg = 100000.0f;
        else
            bodyDmg = dmg;
        arm -= HeadPenetrationResistance;
    } else if (loc == 3) {
        if (type == 7 && self->armorHP > 0) {
            bodyDmg = 0.0f;
            type = 0;
            armorDmg = 0.0f;
        }
        if (self->armorHP == 0 || !(armorDmg <= (float)self->armorHP)) {
            if (armorDmg)
                arm = (int)((float)arm - (float)ArmorPenetrationResistance * ((float)self->armorHP / armorDmg));
            bodyDmg += armorDmg - (float)self->armorHP;
            if (type != 9) self->armorHP = 0;
        } else {
            arm -= ArmorPenetrationResistance;
            if (type != 9) self->armorHP = (int)((float)self->armorHP - armorDmg);
            snd2 = D_004EF730;
            if (IsHuman(src) && !IsHuman(self))
                cHud_SetCallout(5.0f, g_Hud, &self->serial, D_0049D8F0, -1, 0.0f, 0, 0);
        }
        arm -= BodyPenetrationResistance;
    } else {
        bodyDmg = dmg;
        arm -= BodyPenetrationResistance;
    }
    if (type == 4) {
        self->fire = (int)((float)self->fire + bodyDmg);
        if (self->fire > FireDmgToIgnite && !self->burning && self->alive)
            Actor_Ignite(self, -1.0f, 1, 0, 0, 0);
        snd2 = 0;
    } else if (type == 11 || type == 10 || type == 5) {
        snd2 = 0;
    }
    unsigned char dying = Dying(self);
    cGOBJ_ReceiveDamage(self, bodyDmg, src, loc, type, &arm, flag, hitPos);
    if (!self->alive && !flag) {
        MsgDmg m(dmg, src, type, loc);
        m.kind = 8;
        m.b2E = 0;
        if (!Dying(self) && (int)self->health <= dmg)
            m.flags = 0x40;
        QueueMessage_cMessageR_cSystemP_int(&m, self, 0);
    }
    if (type == 7 && !self->dead) {
        self->b33A5 = 1;
        MsgVal(D_0048A2C0).SendF(self);
        if (self->alive) {
            MsgWho2 m(src);
            m.SendK(self, 2);
        }
    }
    if (!dying) {
        if (self->ctrl && type != 4 && type != 11) {
            if (Dying(self) && type == 7)
                self->b33A5 = 1;
            if (self->ctrl->IsHuman()) {
                snd1 = self->team == 1 ? D_004F0910 : D_004F05D0;
                if (self->alive) {
                    int vol;
                    if (dmg < 50.0f) vol = 0x7F; else vol = 0xE1;
                    float m = 2147483648.0f;
                    int r = (int)(5.0f * ((float)Libc_Rand() / (1.0f + m)));
                    int r2 = r + 5;
                    nRumbleManager_Start(0.033333335f * (float)r, 0, 1, 0, 1);
                    nRumbleManager_Start(0.033333335f * (float)r2, 0, 0, vol, 1);
                }
            } else if (!self->ctrl->IsHuman()) {
                snd1 = self->team == 1 ? D_004F0290 : D_004EFF50;
            }
        }
    }
    if (type == 9 && loc == 2) {
        snd1 = 0;
        snd2 = 0;
    }
    if (snd1 && type != 10) {
        SEv e;
        cPlaySoundMsg_ctor_cSndFxR(&e, snd1, self);
        e.kind = 1;
        QueueMessage_cMessageR_cSystemP_int(&e, g_Game, 1);
        e.vtable = D_004DAE30;
        cFileMan_dtor(&e.s114, -1);
        cFileMan_dtor(&e.s78, -1);
        cMessage_dtor(&e, 0);
    }
    if (snd2) {
        SEv e;
        cPlaySoundMsg_ctor_cSndFxR(&e, snd2, self);
        e.kind = 1;
        QueueMessage_cMessageR_cSystemP_int(&e, g_Game, 1);
        e.vtable = D_004DAE30;
        cFileMan_dtor(&e.s114, -1);
        cFileMan_dtor(&e.s78, -1);
        cMessage_dtor(&e, 0);
    }
    if (armor) *armor = arm;
    return self->Stance() == 3;
}
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_00187360(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00187360 */

/* merge_units: begin func_00188070 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#pragma pop
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop

#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cAIUnconsciousMsg_dtor, D_004DCC30, D_004DCD70, cMessage_dtor)
static inline void merge_flush_func_00188070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00188070 */

/* merge_units: begin func_001880E0 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cDamageMsg_dtor, D_004E08A0, cMessage_dtor)
static inline void merge_flush_func_001880E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001880E0 */

/* merge_units: begin func_00188140 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
static inline void RQ(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void RQn(void* d, const void* s) { __int128 t; __asm__("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void RQ4(void* d, const void* s) { __int128 a, b; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(a), "=&r"(b) : "r"(d), "r"(s) : "memory"); }
static inline void RQ4X(void* d, const void* s) { __int128 b, a; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(a), "=&r"(b) : "r"(d), "r"(s) : "memory"); }
struct V_00188140 {
    float x, y, z, w;
    V_00188140() {}
    V_00188140(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V_00188140(const V_00188140& o) { V_00188140* d = this; RQn(d, &o); }
    V_00188140& operator=(const V_00188140& o) { V_00188140* d = this; RQ(d, &o); return *this; }
    inline V_00188140(const V_00188140& a, const V_00188140& b, int);
    V_00188140(const V_00188140& v, long) { V_00188140* d = this; RQ(d, &v); }
    V_00188140(const V_00188140& v, short) { V_00188140* d = this; RQ(d, &v); }
    V_00188140& SetW(float f) { w = f; return *this; }
    V_00188140& NormalizeN() {
        __asm__("lqc2 vf1, 0x0(%0); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vrsqrt Q, vf0w, vf3w; vwaitq; vmulq.xyz vf1, vf1, Q; sqc2 vf1, 0x0(%0)" : : "r"(this) : "memory");
        return *this;
    }
    V_00188140& Normalize() {
        __asm__ volatile("lqc2 vf1, 0x0(%0); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vrsqrt Q, vf0w, vf3w; vwaitq; vmulq.xyz vf1, vf1, Q; sqc2 vf1, 0x0(%0)" : : "r"(this) : "memory");
        return *this;
    }
    V_00188140 operator-() const { V_00188140 r; __asm__ volatile("lqc2 vf1, 0x0(%1); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(%0)" : : "r"(&r), "r"(this) : "memory"); return r; }
} __attribute__((aligned(16)));
static inline void CrossTo(V_00188140& r, const V_00188140& a, const V_00188140& b) {
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vopmula.xyz ACC, vf1, vf2; vopmsub.xyz vf3, vf2, vf1; vsubw.w vf3, vf0, vf0w; sqc2 vf3, 0x0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
}
static inline V_00188140 Cross1(const V_00188140& a, const V_00188140& b) { V_00188140 r; CrossTo(r, a, b); return r; }
static inline V_00188140 Cross(const V_00188140& a, const V_00188140& b) { return Cross1(a, b); }
static inline const V_00188140* CrossP(const V_00188140& a, const V_00188140& b) { V_00188140 r; CrossTo(r, a, b); return &r; }
static inline const V_00188140* CrossP2(const V_00188140& a, const V_00188140& b) { return CrossP(a, b); }
inline V_00188140::V_00188140(const V_00188140& a, const V_00188140& b, int) { const V_00188140* r = CrossP2(a, b); V_00188140* d = this; RQn(d, r); }
struct Mtx {
    float r[4][4];
    Mtx() {}
    Mtx(const Mtx& o) { Mtx* d = this; RQ4(d, &o); } Mtx(const Mtx* o, char) { Mtx* d = this; RQ4X(d, o); }
    inline Mtx(const Mtx& m, int);
} __attribute__((aligned(16)));
static inline void Mul(void* d, void* a, void* b) {
    __asm__ volatile(
        "lqc2 $vf4, 0x0(%2)\n"
        "lqc2 $vf5, 0x10(%2)\n"
        "lqc2 $vf6, 0x20(%2)\n"
        "lqc2 $vf7, 0x30(%2)\n"
        "lqc2 $vf8, 0x0(%1)\n"
        "lqc2 $vf9, 0x10(%1)\n"
        "lqc2 $vf10, 0x20(%1)\n"
        "lqc2 $vf11, 0x30(%1)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x\n"
        "vmadday.xyzw $ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw $ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw $ACC, $vf4, $vf9x\n"
        "vmadday.xyzw $ACC, $vf5, $vf9y\n"
        "vmaddaz.xyzw $ACC, $vf6, $vf9z\n"
        "vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw $ACC, $vf4, $vf10x\n"
        "vmadday.xyzw $ACC, $vf5, $vf10y\n"
        "vmaddaz.xyzw $ACC, $vf6, $vf10z\n"
        "vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw $ACC, $vf4, $vf11x\n"
        "vmadday.xyzw $ACC, $vf5, $vf11y\n"
        "vmaddaz.xyzw $ACC, $vf6, $vf11z\n"
        "vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2 $vf12, 0x0(%0)\n"
        "sqc2 $vf13, 0x10(%0)\n"
        "sqc2 $vf14, 0x20(%0)\n"
        "sqc2 $vf15, 0x30(%0)\n"
        : : "r"(d), "r"(b), "r"(a) : "memory");
}
static inline void Xform(V_00188140* d, const Mtx* m, const V_00188140* v) {
    __asm__ volatile(
        "lqc2 $vf8, 0x0(%2)\n"
        "lqc2 $vf4, 0x0(%1)\n"
        "lqc2 $vf5, 0x10(%1)\n"
        "lqc2 $vf6, 0x20(%1)\n"
        "lqc2 $vf7, 0x30(%1)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x\n"
        "vmadday.xyzw $ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw $ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2 $vf12, 0x0(%0)\n"
        : : "r"(d), "r"(m), "r"(v) : "memory");
}
struct Hit {
    char pad[0x2D92];
    unsigned char b2D92;
    void Spawn(int kind, const V_00188140& d, const V_00188140& p);
};
extern "C" {
extern int WoundEffectTable[];
void SfxParticleEffect_int_cVectorR_cVectorR(int kind, V_00188140* p, const V_00188140* d);
int cMan_GetBloodEffect(int);
Mtx* cMatrix_ctor_cMatrixR(Mtx* d, const Mtx* s);
Mtx* cMatrix_InvertRotTrans(Mtx* m);
void cMatrix_SetAxes(Mtx* m, V_00188140* a, V_00188140* b, V_00188140* c);
void cMatrix_SetTranslation(Mtx* m, V_00188140* t);
}
inline void Hit::Spawn(int kind, const V_00188140& d, const V_00188140& p) { void* xx = this; SfxParticleEffect_int_cVectorR_cVectorR(kind, (V_00188140*)&p, &d); }
struct HNode {
    VPAD16(a) VPAD4(b)
    virtual void Refresh(); /* +0x58 */
    int pad4[3];
    Mtx m10;
    unsigned char b50;
};
struct HVQ { char pad[0x24]; float f24; int i28; char pad2C[0xC]; float f38; int i3C; };
struct NodeMats { int x; };
class Actor_00188140 {
public:
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual V_00188140 GetPos();
    VPAD4(f) VPAD2(h)
    virtual void Hurt();
    VPAD1(g)
    virtual unsigned char State(); /* +0x108 */
    char pad04[0x5C];
    Hit hit;                 /* 0x60 */
    char pad2DF3[0x2E50 - 0x2DF3];
    NodeMats nm;             /* 0x2E50 */
    char pad2E54[0x2E78 - 0x2E54];
    HNode* HNode;              /* 0x2E78 */
};
extern "C" {
void cSkeleton_GetMeshToSkeletonSpaceMatrices(NodeMats* nm, void* spr, const Mtx& m);
void cMan_BloodUpdate(Hit* h);
int cMan_BloodHit(Hit* h, HVQ* e, int d);
}
static inline Mtx* InvCopy(Mtx* b, Mtx* m) { Mtx a; return cMatrix_ctor_cMatrixR(b, cMatrix_InvertRotTrans(cMatrix_ctor_cMatrixR(&a, m))); }
static inline Mtx* InvCopy3(Mtx* b, Mtx* m) { return InvCopy(b, m); }
static inline Mtx* InvCopy2(Mtx* b, Mtx* m) { return InvCopy3(b, m); }
inline Mtx::Mtx(const Mtx& m, int) { InvCopy2(this, (Mtx*)&m); }

static inline V_00188140 Normalized(const V_00188140& v) { V_00188140 r(v); r.Normalize(); return r; }
static inline V_00188140 Normalized2(const V_00188140& v) { V_00188140 r(v, 0L); V_00188140* n = &r; n->Normalize(); return *n; }
static inline const Mtx& Refd(HNode* n) { if (n->b50) n->Refresh(); return n->m10; }
static inline const Mtx* RefdP(HNode* n) { if (n->b50) n->Refresh(); return &n->m10; }
static inline Mtx MulBy(Mtx t, const Mtx& inv) { Mtx* p = &t; Mul(p, (Mtx*)&inv, p); return *p; }
static inline Mtx MulByP(const Mtx* s, const Mtx& inv) { Mtx t(s, (char)0); Mtx* p = &t; Mul(p, (Mtx*)&inv, p); return *p; }
static inline Mtx MulByR(const Mtx& s, const Mtx& inv) { Mtx t(&s, (char)0); Mtx* p = &t; Mul(p, (Mtx*)&inv, p); return *p; }
static inline void NM(NodeMats* nm, void* spr, HNode* n, const Mtx& m) { cSkeleton_GetMeshToSkeletonSpaceMatrices(nm, spr, MulBy(Refd(n), Mtx(m, 0))); }
static inline void NMi(NodeMats* nm, void* spr, HNode* n, const Mtx& inv) { cSkeleton_GetMeshToSkeletonSpaceMatrices(nm, spr, MulBy(Refd(n), inv)); }
static inline Mtx RefdV(HNode* n) { if (n->b50) n->Refresh(); return n->m10; }
static inline Mtx MulByI(HNode* n, const Mtx& inv) { return MulBy(Refd(n), inv); }
static inline Mtx World(HNode* n, const Mtx& inv) { if (n->b50) n->Refresh(); Mtx* s = &n->m10; Mtx t(s, (char)0); Mtx* p = &t; Mul(p, (Mtx*)&inv, p); return *p; }
static inline bool Downed(Actor_00188140* a) { bool r; unsigned char s = a->State(); r = true; if (s != 3 && s != 2) r = false; return r; }
extern "C" int cHuman_BulletBlood(Actor_00188140* a, V_00188140* pos, V_00188140* dir, int d, HVQ* e)
{
    void* spr = (void*)0x70000000;
    Mtx m;
    V_00188140 fwd(Normalized2(*dir));
    V_00188140 side;
    V_00188140 up;
    if (fwd.z < 0.707f) {
        V_00188140 zv(0.0f, 0.0f, 1.0f, 0.0f);
        side = V_00188140(fwd, zv, 0).Normalize();
        up = Cross(side, fwd);
    } else {
        V_00188140 xv(1.0f, 0.0f, 0.0f, 0.0f);
        up = V_00188140(xv, fwd, 0).Normalize();
        side = Cross(fwd, up);
    }
    const V_00188140& p = V_00188140(*pos).SetW(1.0f);
    cMatrix_SetAxes(&m, &side, &fwd, &up);
    cMatrix_SetTranslation(&m, (V_00188140*)&p);
    NodeMats* nm = &a->nm;
    cSkeleton_GetMeshToSkeletonSpaceMatrices(nm, spr, MulByI(a->HNode, Mtx(m, 0)));
    cMan_BloodUpdate(&a->hit);
    if (cMan_BloodHit(&a->hit, e, d)) {
        int flags = 0x100;
        int idx = 1;
        if (e->i28 == 0xC) { idx = 2; flags |= 0x80; }
        if (e->i28 == 0x10) { idx = 3; flags |= 0x40; }
        if (e->i28 == 4) flags |= 0x40;
        if (e->i28 == 0x14) flags |= 0x20;
        if (d > 0) {
            V_00188140 lp(0.0f, e->f24, 0.0f, 1.0f);
            V_00188140 at;
            Xform(&lp, &m, &lp);
            Hit* h = &a->hit;
            at = lp;
            h->Spawn(WoundEffectTable[idx], -fwd, at);
            if (d == 2 || (e->i3C < 0xC && e->i28 < 0xC)) {
                V_00188140 lp2(0.0f, e->f38, 0.0f, 1.0f);
                Xform(&lp2, &m, &lp2);
                Hit* h2 = &a->hit;
                at = lp2;
                h2->Spawn(((int (*)(int))cMan_GetBloodEffect)(0), fwd, at);
                if (!Downed(a)) {
                    Hit* h = &a->hit;
                    if (!((unsigned char*)a)[0x2DF2]) h->b2D92 = 1;
                }
            }
        }
        return flags;
    }
    return 0;
}
static inline void merge_flush_func_00188140(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00188140 */

/* merge_units: begin func_00188760 */
#pragma push /* merge_units */
/* Return entry `index` of a global int table. */
int cMan_GetBloodEffect(int index)
{
    return WoundEffectTable[index];
}
static inline void merge_flush_func_00188760(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00188760 */

/* merge_units: begin func_00188780 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cHuman_CheckBullet: resolve a bullet hit on this actor - which body region it struck (hit volumes,
   or the aimed part for a player's own target), friendly-fire/miss chance, kill stats, then the
   combat event; records the region and node code back into the hit record. */
struct V_188780 { float x, y, z, w; } __attribute__((aligned(16)));
struct Ray_188780 { char pad0[0x10]; V_188780 dir; char pad20[0x10]; V_188780 from; };
struct HV_188780 { char pad0[0x24]; float f24; char pad28[0x18]; signed char ids[8]; signed char count; char pad49[3]; float f4C; } __attribute__((aligned(16)));
struct Ctrl_188780 { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsHuman_00188780(); };
struct Wpn_188780 { char pad0[0xBC]; signed char type; };
struct Actor_188780;
struct Hit_188780 {
    Actor_188780* src;      /* 0x0 */
    Ray_188780* ray;        /* 0x4 */
    Actor_188780* tgt;      /* 0x8 */
    char padC;
    unsigned char b0D;      /* 0xD */
    char padE[2];
    int part;               /* 0x10 */
    char pad14[4];
    Wpn_188780* wpn;        /* 0x18 */
    char pad1C[4];
    unsigned char b20;      /* 0x20 */
    char pad21[3];
    int armor;              /* 0x24 */
    float f28;              /* 0x28 */
    unsigned char b2C;      /* 0x2C */
    char pad2D[3];
    int loc;                /* 0x30 */
    float f34;              /* 0x34 */
    Actor_188780* victim;   /* 0x38 */
    int node;               /* 0x3C */
    float dmg;              /* 0x40 */
};
struct Actor_188780 {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD4(d) VPAD2(e)
    virtual int HandleCombatEvent(float dmg, Actor_188780* src, int loc, int type, int* armor, int flag, V_188780* hitPos);
    VPAD1(f)
    virtual unsigned char Stance();
    char pad4[0x10];
    unsigned char alive;    /* 0x14 */
    char pad15[0x58 - 0x15];
    Ctrl_188780* ctrl;      /* 0x58 */
    char pad5C[0x33A0 - 0x5C];
    int armorHP;            /* 0x33A0 */
    unsigned char dead;     /* 0x33A4 */
};
extern "C" {
extern float D_0048A2B8[];
extern signed char ActorNodeCodeTable[];
extern char g_Game[];
Actor_188780* cGobjController_GetTarget(Ctrl_188780* c);
void* cGameSystem_GetAgentData(void* a, int b);
void cAgentData_AddScore(void* a, int b, int c);
#if 0 /* merge_units */
int cHuman_BulletBlood(Actor_188780* a, V_188780* from, V_188780* dir, int mode, HV_188780* out);
#endif /* merge_units */
#define cHuman_BulletBlood(a0, a1, a2, a3, a4) (cHuman_BulletBlood((Actor_00188140 *)(a0), (V_00188140 *)(a1), (V_00188140 *)(a2), (a3), (HVQ *)(a4))) /* merge_units */



int cHuman_CheckBullet(Actor_188780* self, Hit_188780* h);
}

static inline bool IsHuman_00188780(Actor_188780* a) { bool r = 0; if (a->ctrl && a->ctrl->IsHuman_00188780()) r = 1; return r; }
static inline bool Dying_00188780(Actor_188780* a) { bool r; unsigned char s = a->Stance(); r = 1; if ((unsigned int)(s - 2) > 1) r = 0; return r; }
static inline int IsNullNV_00188780(int x) { return (x != 0) ^ 1; }
static inline void SetNode(Hit_188780* h, int id) { int j; for (j = 0; j < 21; j++) { if (ActorNodeCodeTable[j] == id) { h->node = j; break; } } }
/* damage types that count toward the shooter's hit stats: 0, 1, 7, 9, 10, 13 */
static inline bool Counts(unsigned char t)
{
    bool r = 0;
    if ((unsigned int)t < 14 && ((1 << t) & 0x2683))
        r = 1;
    return r;
}

int cHuman_CheckBullet(Actor_188780* self, Hit_188780* h)
{
    HV_188780 hv;
    bool miss;
    int part;
    bool a;
    /* loc/type/mode are int (tested as unsigned char) - the retail code assigns them with li and
       passes them to the int parameters below without re-masking */
    /* declaration order chosen for the retail register assignment */
    int type;
    int flags;
    unsigned char own;
    bool both;
    Ray_188780* ray;
    unsigned char aimed;
    int loc;
    Actor_188780* src;
    int mode;
    Ctrl_188780* sc;
    int dmg;
    int ne;
    ne = self != h->tgt;
    own = IsNullNV_00188780(ne);
    if (own)
        part = h->part;
    else
        part = -1;
    if (h->wpn)
        type = h->wpn->type;
    else
        type = 8;
    dmg = (int)h->dmg;
    ray = h->ray;
    sc = h->src ? h->src->ctrl : 0;
    mode = (unsigned char)ne;
    both = 0;
    a = 0;
    if (IsHuman_00188780(self) && sc)
        a = 1;
    if (a && sc->IsHuman_00188780())
        both = 1;
    if (!(unsigned short)dmg || self->dead || both || (unsigned char)type == 7)
        mode = 0;
    else if (self->armorHP <= 0)
        mode = 2;
    /* an NPC shooting at something other than its aim target misses by chance (HitInnocentNpcChance) */
    miss = 0;
    if (sc && !sc->IsHuman_00188780() && cGobjController_GetTarget(sc) != self) {
        if ((float)Libc_Rand() / 2147483648.0f > D_0048A2B8[0])
            miss = 1;
    }
    hv.f4C = h->f28;
    if (miss)
        flags = 0;
    else
        flags = cHuman_BulletBlood(self, &ray->from, &ray->dir, mode, &hv);
    loc = 0;
    if (flags & 0x40)
        loc = 2;
    else if (flags & 0x20)
        loc = 4;
    else if (flags & 0x80)
        loc = 3;
    else if (flags)
        loc = 1;
    aimed = sc && cGobjController_GetTarget(sc) == self && own;
    if (aimed) {
        int k = part & 3;
        if (k == 0)
            loc = 2;
        else if (k == 3)
            loc = 3;
        else
            loc = 1;
    }
    src = h->src;
    if ((unsigned char)loc && src && src->alive && !h->b20) {
        if (IsHuman_00188780(self)) {
            if (both) {
                dmg = 0;
                if ((unsigned char)type == 7)
                    type = 0;
            }
            if (!aimed)
                loc = 3;
        }
        {
            int t = (unsigned char)type;
            bool cnt = Counts(t);
            if (!Dying_00188780(self) && cnt) {
                if (IsHuman_00188780(src) && src->alive && !both && h->b2C) {
                    cAgentData_AddScore(cGameSystem_GetAgentData(g_Game, -1), 10, 1);
                    if (h->b0D)
                        cAgentData_AddScore(cGameSystem_GetAgentData(g_Game, -1), 12, 1);
                    if (t == 7 && (unsigned char)loc != 2)
                        cAgentData_AddScore(cGameSystem_GetAgentData(g_Game, -1), 6, 1);
                }
            }
        }
        self->HandleCombatEvent((float)dmg, src, loc, type, &h->armor, 0, 0);
    }
    if (flags && h->armor <= 0) {
        int i;
        h->node = -1;
        h->f34 = hv.f24;
        h->loc = (unsigned char)loc;
        h->victim = self;
        for (i = hv.count - 1; i >= 0; i--) {
            if (hv.ids[i] >= 0) {
                SetNode(h, hv.ids[i]);
                break;
            }
        }
    }
    return loc;
}
#undef cHuman_BulletBlood /* merge_units */
static inline void merge_flush_func_00188780(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00188780 */

/* merge_units: begin func_00188D30 */
#pragma push /* merge_units */
const float D_0048A2A8[2] = { 0.3f, 0.0f };
const float D_0048A2B0[2] = { 0.5f, 0.0f };
float cHuman_GetSubTargetAimAdjust(void* self, int n)
{
    int k = n & 3;
    if (k == 0) return (*(float*)D_0048A2A8);
    if (k == 1 || k == 2) return (*(float*)D_0048A2B0);
    return 1.0f;
}
static inline void merge_flush_func_00188D30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00188D30 */

/* merge_units: begin func_00188D80 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef __int128 Q128;

class cXform {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
    char pad04[0x40 - 0x04];
    Q128 translation;
    unsigned char needsUpdate;
    const Q128& GetTranslation() { if (needsUpdate) Update(); return translation; }
};

typedef signed char eBone;

class cHuman {
public:
    char pad00[0x2C];
    unsigned char mEnabled;
    unsigned char mActiveFlag;
    unsigned char mStreamingFlag;
    unsigned char mIsRenderable;
    char pad30[0x50 - 0x30];
    cXform* mXform;
    bool IsActive() const { return mActiveFlag && mEnabled; }
    bool IsStreaming() const { return mStreamingFlag; }
    bool NotStreaming() const { return !mStreamingFlag; } bool IsTargetable() const { bool r = false; if (IsActive() && NotStreaming()) r = true; return r; }
};

extern "C" {
extern eBone D_0048A2A0[4];
void* cSKM_GOBJ_GetSkeleton_void(const cHuman* h);
void cSkeleton_GetBoneToWorldTranslation(Q128* out, void* skel, int node);
}

/* 16-byte qword copy (lq/sq) */
static inline void V4Copy(void* d, const void* s) { __int128 t; asm { .set noreorder
 lq t, 0(s)
 .set reorder
 sq t, 0(d) } }
#pragma opt_propagation off
#pragma opt_rebuildlogicals off
/* cVector returned by value; the work happens in an inlined constructor so the hidden
   return pointer is `this` (kept in a volatile stack slot, re-read at each use). */
struct RV { float x, y, z, w; RV() {} inline RV(const cHuman* self, int subTarget); } __attribute__((aligned(16)));
inline RV::RV(const cHuman* self, int subTarget)
{
    Q128* volatile out = (Q128*)this;
    if (self->IsTargetable()) {
        eBone targetBone = D_0048A2A0[subTarget & 3];
        void* skel = cSKM_GOBJ_GetSkeleton_void(self); int node = ActorNodeCodeTable[(unsigned char)targetBone]; cSkeleton_GetBoneToWorldTranslation(out, skel, node);
        return;
    }
    { const Q128* s = &self->mXform->GetTranslation(); V4Copy(out, s); (void)out; }
}
extern "C" RV cHuman_GetTargetPosition(const cHuman* self, int subTarget)
{
    return RV(self, subTarget);
}
static inline void merge_flush_func_00188D80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00188D80 */
