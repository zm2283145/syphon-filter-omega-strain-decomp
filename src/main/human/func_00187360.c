#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
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
extern int D_004FFC2C;
extern char D_0049D8F0[];
extern char D_004D9180[], D_004DAE30[], D_004DCC30[], D_004DCD70[], D_004E01E0[], D_004E0840[], D_004E08A0[];
extern char D_004EA0B0[], D_004EF0B0[], D_004EF250[], D_004EF730[], D_004EFF50[], D_004F0290[], D_004F05D0[], D_004F0910[];
extern char D_004FF2C0[], D_004FFB50[], D_005435A0[], D_0055D480[];
extern int g_MsgLibDamageRequestKey;
void Event_Construct(void*, void*);
void Event_Send(void*, void*, int);
void cMessage_dtor(void*, int);
Svc* Service_Lookup(void*, void*);
void SoundEvent_CtorFromPreset(void*, void*, Actor*);
void FileMan_Release(void*, int);
void Hud_ShowCallout(float, int, const int*, void*, int, float, int, int);
void Actor_Ignite(Actor*, float, int, int, int, int);
void Actor_ApplyContactDamage(Actor*, float, Actor*, unsigned char, unsigned char, int*, unsigned char, V*);
int Random_Next(void);
void PadRumble_Start(float, int, int, int, int);
int Actor_HandleCombatEvent(Actor* self, float dmg, Actor* src, unsigned char loc, unsigned char type, int* armor, unsigned char flag, V* hitPos);
}

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX

struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    MsgB() {}
    MsgB(void* t) { Event_Construct(this, t); }
    void SendF(void* to) { flags = 0x40; Event_Send(this, to, 0); }
    void SendK(void* to, unsigned char k) { kind = k; Event_Send(this, to, 0); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct MsgRay : MsgB {
    int a24; int a28; HitInfo* info; V pos; V dir; Actor* src; Actor* tgt; int n; unsigned char b5C;
    MsgRay(HitInfo* i, const V& p, V d, Actor* s, Actor* t) : MsgB(D_005435A0) {
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
    MsgI(int i, unsigned char s) : MsgB(D_0055D480) { vtable = D_004E0840; id = i; sub = s; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgI() { vtable = D_004E0840; }
};
struct MsgVal : MsgI {
    int val;
    MsgVal(const int& v) : MsgI(0x42, 2) { vtable = D_004E01E0; val = v; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgVal() {}
};
struct MsgWho : MsgB {
    Actor* who; int pad28[2];
    MsgWho(Actor* w) : MsgB(D_004FF2C0) { vtable = D_004DCD70; who = w; kind = 2; }
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

int Actor_HandleCombatEvent(Actor* self, float dmg, Actor* src, unsigned char loc, unsigned char type, int* armor, unsigned char flag, V* hitPos)
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
        Service_Lookup(D_004FFB50, D_004EA0B0)->Post(&m);
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
                Hud_ShowCallout(5.0f, D_004FFC2C, &self->serial, D_0049D8F0, -1, 0.0f, 0, 0);
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
    Actor_ApplyContactDamage(self, bodyDmg, src, loc, type, &arm, flag, hitPos);
    if (!self->alive && !flag) {
        MsgDmg m(dmg, src, type, loc);
        m.kind = 8;
        m.b2E = 0;
        if (!Dying(self) && (int)self->health <= dmg)
            m.flags = 0x40;
        Event_Send(&m, self, 0);
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
                    int r = (int)(5.0f * ((float)Random_Next() / (1.0f + m)));
                    int r2 = r + 5;
                    PadRumble_Start(0.033333335f * (float)r, 0, 1, 0, 1);
                    PadRumble_Start(0.033333335f * (float)r2, 0, 0, vol, 1);
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
        SoundEvent_CtorFromPreset(&e, snd1, self);
        e.kind = 1;
        Event_Send(&e, D_004FFB50, 1);
        e.vtable = D_004DAE30;
        FileMan_Release(&e.s114, -1);
        FileMan_Release(&e.s78, -1);
        cMessage_dtor(&e, 0);
    }
    if (snd2) {
        SEv e;
        SoundEvent_CtorFromPreset(&e, snd2, self);
        e.kind = 1;
        Event_Send(&e, D_004FFB50, 1);
        e.vtable = D_004DAE30;
        FileMan_Release(&e.s114, -1);
        FileMan_Release(&e.s78, -1);
        cMessage_dtor(&e, 0);
    }
    if (armor) *armor = arm;
    return self->Stance() == 3;
}
