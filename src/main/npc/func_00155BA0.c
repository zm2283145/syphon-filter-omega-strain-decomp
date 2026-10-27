#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"
/* cNPC_AttackFromCover: attack-from-cover message handler - leave cover when out of ammo or
   out-gunned, keep the alert counter, pick a firing position on hits and restart, and ask for ammo. */
/* quadword copy (lq/sq): a 128-bit move C cannot express, the retail vector copy */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V() {} V(const V& o) { V* d = this; Q16(d, &o); } V& operator=(const V& o) { V* d = this; Q16(d, &o); return *this; } } __attribute__((aligned(16)));
struct M { V r[4]; V& T() { return r[3]; } } __attribute__((aligned(16)));
static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline int DiffNV(int a, int b) { return a ^ b; }
static inline int SameNV(int a, int b) { return (unsigned)DiffNV(a, b) < 1; }
struct Inv { char pad[0xA0]; unsigned char bA0; };
struct Obj { char pad0[0xC]; int serial; char pad10[0x3C]; int classKey; char pad50[0x34D4]; Inv* inv; };
struct Ai {
    V pos;
    char pad10[8];
    int node;               /* 0x18 */
    char pad1C[4];
    unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 1; unsigned char b4 : 1;
    char pad21[0x1F];
    Obj* obj;               /* 0x40 */
    int serial;             /* 0x44 */
    int IsValid() { unsigned char ok = 1; if (!IsNullNV(obj) && !SameNV(obj->serial, serial)) ok = 0; return ok; }
    Obj* Get() { return IsValid() ? obj : 0; }
};
struct GObj { VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e) virtual M GetMatrix(); char pad4[0x3208]; int f320C; char pad3210[0x314]; Inv* inv; };
/* retail copies the posture pair as one word (sh/sh to a temp, then lw/sw) */
struct Pair { short a, b; Pair(short x, short y) { a = x; b = y; } Pair& operator=(const Pair& o) { *(int*)this = *(const int*)&o; return *this; } };
/* Alert/CurrentNode/CoverNode are vtable slots 75/103/110 (names from use) */
struct Npc {
    VPAD32(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual int Busy();
    VPAD4(e) VPAD1(f) virtual void SetMovement(int a, int b);
    VPAD16(g) VPAD8(h) VPAD4(i) VPAD1(j) virtual void Alert(int a);
    VPAD16(k) VPAD8(l) VPAD2(m) VPAD1(n) virtual int CurrentNode();
    VPAD4(o) VPAD2(p) virtual int CoverNode(int a);
    char pad4[0x1C];
    float f20;              /* 0x20 */
    float f24;              /* 0x24 */
    char pad28[8];
    GObj* obj;              /* 0x30 */
    char pad34[0x10];
    char brain[0x28];       /* 0x44 */
    float aggression;       /* 0x6C */
    char pad70[0x34];
    int clipMin;            /* 0xA4 */
    int fA8;                /* 0xA8 */
    char padAC[0xC];
    float fB8;              /* 0xB8 */
    char padBC[0x24];
    int fE0;                /* 0xE0 */
    int fE4;                /* 0xE4 */
    int fE8;                /* 0xE8 */
    int fEC;                /* 0xEC */
    char padF0[0x20];
    Pair pair;              /* 0x110 */
    char pad114[0x2B];
    unsigned char f13F;     /* 0x13F */
    unsigned char f140;     /* 0x140 */
    char pad141[0x6B];
    Ai* target;             /* 0x1AC */
};
struct Ev { char pad[0x24]; signed char kind; char pad25[3]; int f28; int f2C; };
extern "C" {
extern int D_004EE550;
extern int D_004ED9B8;
extern int g_HumanActorClassKey[4];
extern char g_ActorActionMsgClass[], D_004E0840[];
int* cMessage_Name(Ev* ev);
Obj* cSafePtr_cGOBJ_opCast_cGOBJPtr(Obj** h);
int cWeapon_GetDamage(Inv* inv);
int cWeapon_GetClipAmmo(Inv* inv, int slot);
int cWeapon_CanReload(Inv* inv);
float cAITarget_GetAwarenessThreat(Ai* t, Obj* o);
int cNPC_SearchAvailable(Npc* self);
void cStateMachine_ChangeState(void* brain, int mode, int arg);
void cNPC_MoveToCoverNode(Npc* self);
void cNPC_MoveToAttackFromCoverNode(Npc* self);
void cMessage_ctor_cMessageNameR(void*, void*);
void QueueMessage_cMessageR_cSystemP_int(void*, void*, int);
void cMessage_dtor(void*, int);
unsigned char cNPC_AttackFromCover(Npc* self, Ev* ev);
}

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    MsgB(void* t) { cMessage_ctor_cMessageNameR(this, t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct MsgI : MsgB {
    int id; unsigned char sub; char pad29[3];
    MsgI(int i, unsigned char s) : MsgB(g_ActorActionMsgClass) { vtable = D_004E0840; id = i; sub = s; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgI() { vtable = D_004E0840; }
};

/* VU0 macro-mode vector ops (COP2), not expressible in C */
static inline void Sub(V* r, V* a, V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline float Len(V* a) { float r = 0.0f; int t; __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
static inline void QD(void* d0, const void* s0) { void* d = d0; __int128 q; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline unsigned char Engaged(Ai* ai) { unsigned char f = 0; if (ai->b0) { unsigned char b = ai->b2; if (b) f = 1; } return f; }
static inline void Offset(Npc* self, V* p) { { M m = self->obj->GetMatrix(); M* pm = &m; QD(p, &pm->r[3]); } Sub(p, p, &self->target->pos); }
static inline int* HumanKey() { return g_HumanActorClassKey; }
static inline bool IsKind(Ai* t, int* cls) { Obj* o = cSafePtr_cGOBJ_opCast_cGOBJPtr(&t->obj); int k = *cls; return o->classKey == k; }
static inline unsigned char Exposed(Npc* self)
{
    V d;
    unsigned char r = 0;
    int n = self->CoverNode(0);
    if (self->fB8 > 0.0f && self->target->b4 && n >= 0) {
        float len;
        Offset(self, &d);
        len = Len(&d);
        if (n == self->CurrentNode())
            r = 10.0f + len > self->fB8;
        else
            r = len < self->fB8;
    }
    return r;
}
static inline bool IsId(Obj* o, Ev* ev) { int s = o->serial; return ev->f28 == s; }
static inline float Area(Npc* s) { float b = s->f24; return s->f20 * b; }
static inline bool LowAmmo(Npc* self) { bool low = 1; Inv* inv = self->obj->inv; if (!inv->bA0 && !(cWeapon_GetClipAmmo(inv, 6) < self->clipMin)) low = 0; return low; }

unsigned char cNPC_AttackFromCover(Npc* self0, Ev* ev0)
{
    Npc* self; unsigned char handled; int t; Ev* ev; Inv* inv;
    self = self0;
    ev = ev0;
    handled = 0;
    inv = self->obj->inv;
    t = *cMessage_Name(ev);
    if (t == D_004EE550) {
        if ((unsigned char)ev->kind == 3) {
            int rating = 0;
            if (self->target->Get() && IsKind(self->target, HumanKey()))
                rating = cWeapon_GetDamage(self->target->Get()->inv);
            if ((LowAmmo(self) || Exposed(self)) && rating > 0) {
                if (self->pair.b != 2) {
                    cNPC_MoveToCoverNode(self);
                    self->pair = Pair(3, 2);
                }
            } else if (!(unsigned char)self->Busy()) {
                if (self->fA8 < self->clipMin && self->target->Get() && rating > 0) {
                    float e = cAITarget_GetAwarenessThreat(self->target, self->target->Get());
                    float k = self->aggression * (float)rating;
                    if (!(e <= k) && k * Area(self) - e < -1.0f) {
                        cNPC_MoveToCoverNode(self);
                        self->pair = Pair(3, 2);
                    }
                }
                if (Engaged(self->target)) {
                    self->fEC = 0;
                } else {
                    if (self->fEC > 4 && cNPC_SearchAvailable(self))
                        cStateMachine_ChangeState(self->brain, 5, 0);
                    if (self->fEC == 2 && cNPC_SearchAvailable(self))
                        self->Alert(0);
                    self->fEC++;
                }
            } else {
                self->fEC = 0;
            }
            self->fE8 = 30;
        } else if ((unsigned char)ev->kind == 7) {
            if (!(unsigned char)self->Busy() && !Engaged(self->target) && ev->f2C != 6 && ev->f2C != 9 &&
                self->target->Get() && IsId(self->target->Get(), ev)) {
                self->fE0 = -1;
                cNPC_MoveToAttackFromCoverNode(self);
                self->fEC = 0;
                self->fE8 = -1;
            }
        } else if ((unsigned char)ev->kind == 4) {
            if (Engaged(self->target) && self->obj->f320C != 26)
                self->fA8 = self->clipMin;
        } else if ((unsigned char)ev->kind == 5) {
            self->fE8 = 30;
        } else if ((unsigned char)ev->kind == 8) {
            if (self->aggression <= 0.5f) {
                cNPC_MoveToCoverNode(self);
                self->pair = Pair(3, 2);
            }
        } else if ((unsigned char)ev->kind == 0) {
            if (self->f13F != 3 && self->f140 != 3)
                cNPC_MoveToAttackFromCoverNode(self);
            self->pair = Pair(3, 3);
            if ((unsigned char)self->Busy())
                self->fE8 = -1;
            else
                self->fE8 = 30;
            self->fEC = 0;
        }
    } else {
        int t2 = *cMessage_Name(ev);
        if (t2 == D_004ED9B8) {
        if ((unsigned char)ev->kind == 6) {
            self->fE8 = 30;
        } else if ((unsigned char)ev->kind == 2) {
            if (self->pair.b != 3)
                cStateMachine_ChangeState(self->brain, self->pair.b, 0);
        } else if ((unsigned char)ev->kind == 1 || (unsigned char)ev->kind == 3) {
            if (LowAmmo(self) && cWeapon_CanReload(inv)) {
                MsgI m(60, 0);
                QueueMessage_cMessageR_cSystemP_int(&m, self->obj, 0);
            }
            self->pair = Pair(3, 3);
        }
        }
    }
    return handled;     /* never set: retail always returns 0 from s0 */
}
