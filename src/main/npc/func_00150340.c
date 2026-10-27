#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V() {} V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
  V(const V& o) { V* d = this; Q16(d, &o); } V& operator=(const V& o) { Q16(this, &o); return *this; } } __attribute__((aligned(16)));
struct M { V r[4]; V& T() { return r[3]; } } __attribute__((aligned(16)));

struct Obj { VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e) virtual struct M GetMtx(); char pad4[8]; int serial; };
struct Sub58 { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char Big(); };
struct Sub58Holder { char pad[0x58]; Sub58* s; };
static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline int DiffNV(int a, int b) { return a ^ b; }
static inline int SameNV(int a, int b) { return (unsigned)DiffNV(a, b) < 1; }
struct Hdl { Obj* obj; int serial;
    int IsValid() { unsigned char ok = 1; if (!IsNullNV(obj) && !SameNV(obj->serial, serial)) ok = 0; return ok; }
    Obj* Get() { return IsValid() ? obj : 0; } };
struct Ai { char pad0[0x20]; unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; char pad21[0x1F]; Obj* obj; int serial;
    int IsValid() { unsigned char ok = 1; if (!IsNullNV(obj) && !SameNV(obj->serial, serial)) ok = 0; return ok; }
    Obj* Get() { return IsValid() ? obj : 0; } };
struct Cnt { char pad[0xC]; int n; };
struct Gun { char pad[0x310]; unsigned char a, b; };
struct Owner {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e) virtual M GetMtx(); VPAD4(f) virtual unsigned char Cls();
    char pad4[0x3208];
    int mode;               /* 0x320C */
    char pad3210[0x104];
    Gun* gun;               /* 0x3314 */
    char pad3318[0xCC];
    unsigned char busy;     /* 0x33E4 */
    char pad33E5[0x13F];
    void* inv;              /* 0x3524 */
    char pad3528[0x5C];
    char* stats;            /* 0x3584 */
};
struct Npc {
    VPAD32(a) VPAD8(b) virtual int Busy(int);
    char pad4[0x1C];
    float reach;            /* 0x20 */
    char pad24[0xC];
    Owner* owner;           /* 0x30 */
    char pad34[0x44];
    float range;            /* 0x78 */
    char pad7C[8];
    float cool;             /* 0x84 */
    float cool2;            /* 0x88 */
    char pad8C[4];
    float spread;           /* 0x90 */
    float rate;             /* 0x94 */
    char pad98[0xC];
    int burstMax;           /* 0xA4 */
    int burst;              /* 0xA8 */
    char padAC[0x70];
    int team;               /* 0x11C */
    char pad120[0x10];
    int forced;             /* 0x130 */
    char pad134[0xA];
    unsigned char fireMode; /* 0x13E */
    char pad13F[2];
    unsigned char : 4;
    unsigned char lead : 1; /* 0x141 */
    char pad142[0x6A];
    Ai* ai;                 /* 0x1AC */
    char pad1B0[8];
    Cnt* cnt;               /* 0x1B8 */
    char pad1BC[0xC];
    Hdl h2;                 /* 0x1C8 */
};



typedef unsigned char (*VFnB)(void*);
typedef int (*VFnI)(void*, int);
typedef M (*VFnM)(void*);
#define VF(o, off, T) (*(T*)((char*)((Obj*)(o))->vt + (off)))

extern "C" {
extern float WorthShootingThreshold;
extern int g_NoneWord;
extern char g_ActorActionMsgClass[], D_004E0840[], D_004E0200[];
extern unsigned char g_IsMultiplayer;
struct GunDef { char pad[0x4C]; unsigned char ok; char pad4D[3]; unsigned char Ok() { return ok; } };
extern GunDef SecondaryStateTable[];
Obj* cSafePtr_cGOBJ_opCast_cGOBJPtr(Hdl*);
int cWeapon_IsFullyAutomatic(void*);
unsigned char cWeapon_GetEquipmentType(void*);
int cWeapon_ReadyToFire(void*, int);
int cWeapon_Ready(void*);
void cWeapon_FireIfReady(void*, int, int, int, int);
int Libc_Rand(void);
void cMessage_ctor_cMessageNameR(void*, void*);
void QueueMessage_cMessageR_cSystemP_int(void*, void*, int);
void cMessage_dtor(void*, int);
void cNPC_HandleWeaponFiring(Npc* self, float dt);
}

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX

struct MsgB {
    void* vtable; void* type; int pad8[6]; unsigned char kind; char pad21[3];
    MsgB(void* t) { cMessage_ctor_cMessageNameR(this, t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct Msg3B : MsgB {
    int id; unsigned char sub; char pad29[7];
    Msg3B() : MsgB(g_ActorActionMsgClass) { vtable = D_004E0840; id = 0x3B; sub = 0xB; }
    __declspec(weak) __declspec(MSG_DTOR) ~Msg3B() { vtable = D_004E0840; }
};
struct FireMsg : Msg3B {
    int serial; int team; unsigned char f38; char pad39[7];
    V pos; float yaw;
    FireMsg(Obj* tgt, int tm, V p, float y);
    __declspec(weak) __declspec(MSG_DTOR) ~FireMsg() {}
} __attribute__((aligned(16)));
static inline bool NotNull(void* p) { return p != 0; }
static inline bool Eq(int a, int b) { return a == b; }
static inline Obj* RefGet(Hdl* h) {
    unsigned char ok = 1;
    if (!(!NotNull(h->obj) || Eq(h->obj->serial, h->serial))) ok = 0;
    return ok ? h->obj : 0;
}
static inline float RandF() { return (float)Libc_Rand() / 2147483648.0f; }
static inline void Scale(V* v, float k) {
    int t;
    __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %2; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(v), "f"(k) : "memory");
}
static inline void Scale2(V* r, V* a, float k) { int t; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(r), "r"(a), "f"(k) : "memory"); }
static inline float Rad(float d) { return d * 0.017453292f; }
static inline void Sub(V* r, V* a, V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline void Add(V* r, V* a, V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline unsigned char GunReady(Gun* g) {
    unsigned char ok = 0;
    if (SecondaryStateTable[g->a].Ok() && SecondaryStateTable[g->b].Ok()) ok = 1;
    return ok;
}
static inline unsigned char HasGun(Owner* o) {
    if (o->gun) return GunReady(o->gun);
    return 0;
}
inline FireMsg::FireMsg(Obj* tgt, int tm, V p, float y) {
    vtable = D_004E0200;
    serial = *(tgt ? &tgt->serial : &g_NoneWord);
    team = tm;
    f38 = 0;
    pos = p;
    yaw = y;
}
static inline float Range(Npc* self) {
    float r = self->range;
    if (r < 0.0f) r = WorthShootingThreshold;
    return r;
}
static inline unsigned char InReach(Npc* self, void* inv) {
    if (cWeapon_GetEquipmentType(inv) == 1) return 1;
    float r = Range(self);
    if (self->ai->Get()) {
        Sub58* o = ((Sub58Holder*)cSafePtr_cGOBJ_opCast_cGOBJPtr((Hdl*)&self->ai->obj))->s;
        unsigned char big = 0;
        if (o && o->Big()) big = 1;
        if (!big) r *= 0.5f;
    }
    if (self->reach < r) return 0;
    return 1;
}

void cNPC_HandleWeaponFiring(Npc* self, float dt)
{
    Owner* own = self->owner;
    void* inv = own->inv;
    Obj* tgt = self->ai->Get();
    unsigned char fire = 0;

    if (self->burst <= 0 && self->cool <= 0.0f && self->owner->mode != 0x1A)
        self->burst = self->burstMax;

    if (self->forced > 0) {
        fire = 1;
    } else if (self->fireMode && self->burst > 0) {
        bool down;
        unsigned char c;
        c = self->owner->Cls();
        down = true;
        if (c != 3 && c != 2) down = false;
        if (!down) {
            if (self->fireMode == 2) {
                fire = 1;
            } else if (self->cnt->n > 0 && self->owner->mode == 0x1A && cWeapon_IsFullyAutomatic(inv)) {
                fire = 1;
            } else if (!self->Busy(1)) {
                Ai* ai = self->ai;
                unsigned char f = 0;
                if (ai->b0) { unsigned char b = ai->b2; if (b) f = 1; }
                if (f || (Range(self) < 0.01f && tgt)) {
                    if (cWeapon_GetEquipmentType(inv) != 1) {
                        float r = Range(self);
                        if (self->ai->Get()) {
                            Sub58* o = ((Sub58Holder*)cSafePtr_cGOBJ_opCast_cGOBJPtr((Hdl*)&self->ai->obj))->s;
                            unsigned char big = 0;
                            if (o && o->Big()) big = 1;
                            if (!big) r *= 0.5f;
                        }
                        if (!(self->reach < r)) fire = 1;
                    } else {
                        fire = 1;
                    }
                }
            }
        }
    }

    if (fire && cWeapon_Ready(inv) && self->cool2 <= 0.0f) {
        if (cWeapon_GetEquipmentType(inv) != 1) {
            if (cWeapon_ReadyToFire(inv, 0)) {
            if (HasGun(own)) {
                    FireMsg m(tgt, self->team, V(0.0f, 0.0f, 0.0f, 0.0f), 0.0f);
                    m.kind = 1;
                    QueueMessage_cMessageR_cSystemP_int(&m, self->owner, 0);
                } else {
                    cWeapon_FireIfReady(inv, 0, -1, 0, 0);
                }
            }
        } else {
            if (!own->busy) {
                if (self->h2.Get()) tgt = self->h2.Get();
                if (tgt) {
                    Obj* t = tgt;
                    float ry = RandF();
                    V off(RandF(), ry, 0.0f, 0.0f);
                    Scale(&off, self->spread);
                    V pos = t->GetMtx().T();
                    if (self->lead) {
                        Sub(&pos, &pos, &self->owner->GetMtx().T());
                        __int128 z = 0;
                        Scale2(&pos, &pos, 0.8f);
                        { V* b = &self->owner->GetMtx().T(); Add(&pos, &pos, b); }
                    }
                    Add(&pos, &pos, &off);
                    FireMsg m(0, self->team, pos, Rad(self->rate));
                    m.kind = 1;
                    QueueMessage_cMessageR_cSystemP_int(&m, self->owner, 0);
                }
            }
        }
    }

    if (cWeapon_Ready(inv)) {
        if (!(self->cool2 <= 0.0f)) self->cool2 -= dt;
        if (!(self->cool <= 0.0f)) self->cool -= dt;
    }

    if (g_IsMultiplayer) {
        char* s = self->owner->stats;
        if (s) s += 0x1C;
        unsigned short* p = (unsigned short*)s;
        if (p && fire) (*p)++;
    }
}

