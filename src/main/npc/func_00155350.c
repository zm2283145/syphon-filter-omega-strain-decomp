#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"
/* NpcAi_ModeAttack: attack-mode message handler - close in on / keep the target in range, approach
   or route to its node, ask for ammo, take cover on posture changes, and react to perception. */
/* quadword copy (lq/sq): a 128-bit move C cannot express, the retail vector copy */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V() {} V(const V& o) { V* d = this; Q16(d, &o); } V& operator=(const V& o) { V* d = this; Q16(d, &o); return *this; } } __attribute__((aligned(16)));
struct M { V r[4]; V& T() { return r[3]; } } __attribute__((aligned(16)));
static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline int DiffNV(int a, int b) { return a ^ b; }
static inline int SameNV(int a, int b) { return (unsigned)DiffNV(a, b) < 1; }
struct Ctl { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsHuman(); };
struct Obj { char pad0[0xC]; int serial; char pad10[0x48]; Ctl* ctrl; };
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
struct Route { char pad0[0x50]; int f50; char pad54[8]; int node; };
struct PNode { char pad[0x7C]; int node; };
struct Inv { char pad[0xA0]; unsigned char bA0; };
struct GObj { VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e) virtual M GetMatrix(); char pad4[0x3520]; Inv* inv; };
/* retail copies the posture pair as one word (sh/sh to a temp, then lw/sw) */
struct Pair { short a, b; Pair(short x, short y) { a = x; b = y; } Pair& operator=(const Pair& o) { *(int*)this = *(const int*)&o; return *this; } };
struct Npc {
    VPAD32(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual int Busy();
    VPAD4(e) VPAD1(f) virtual void SetMovement(int a, int b);
    char pad4[0x2C];
    GObj* obj;              /* 0x30 */
    char pad34[0x10];
    char brain[0x60];       /* 0x44 */
    int clipMin;            /* 0xA4 */
    char padA8[0x14];
    int bitsBC[8];          /* 0xBC */
    char padDC[4];
    int fE0;                /* 0xE0 */
    int fE4;                /* 0xE4 */
    int fE8;                /* 0xE8 */
    int fEC;                /* 0xEC */
    char padF0[0x20];
    Pair pair;              /* 0x110 */
    char pad114[0x2B];
    unsigned char f13F;     /* 0x13F */
    char pad140[0x18];
    unsigned char b158;     /* 0x158 */
    char pad159[0x53];
    Ai* target;             /* 0x1AC */
    Route* route;           /* 0x1B0 */
};
struct Ev { char pad[0x24]; signed char kind; char pad25[3]; int f28; };
extern "C" {
extern int D_004EE550;
extern int D_004ED9B8;
extern char g_Game[];
extern char g_NpcRouteMgr[];
extern char g_ActorActionMsgClass[], D_004E0840[];
int* Event_GetType(Ev* ev);
void* Service_Lookup(void* a, void* b);
int NpcRoute_IsHeadPending(void* svc, GObj* id);
void NpcPath_RequestRoute(Route* r, Ai* t, int node);
void NpcAi_ApproachSearch(Npc* self);
void NpcAi_RequestMode(void* brain, int mode, int arg);
void NpcAi_SetMovementState(Npc* self, int a, int b);
unsigned char NpcAttack_CombatPosture(Npc* self);
void NpcAi_CoverSearch(Npc* self);
int WeaponInv_GetClip(Inv* inv, int slot);
PNode* NpcPath_GetNode(int n);
void Event_Construct(void*, void*);
void Event_Send(void*, void*, int);
void cMessage_dtor(void*, int);
unsigned char NpcAi_ModeAttack(Npc* self, Ev* ev);
}

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    MsgB(void* t) { Event_Construct(this, t); }
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
static inline float LenSq(V* a) { float r = 0.0f; int t; __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
static inline void AskAmmo(Npc* self) { MsgI m(60, 0); Event_Send(&m, self->obj, 0); }
static inline void QD(void* d0, const void* s0) { void* d = d0; __int128 q; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline bool OnPNode(Npc* self, PNode* pn) { int tn = self->target->node; return pn->node == tn; }
static inline bool OnNode2(Route* r, Ai* t) { int tn = t->node; return r->node == tn; }
static inline bool OnNode(Npc* self) { int tn = self->target->node; return self->route->node == tn; }
static inline unsigned char Engaged(Ai* ai) { unsigned char f = 0; if (ai->b0) { unsigned char b = ai->b2; if (b) f = 1; } return f; }
static inline bool Visited(Npc* self, int i) { bool r = 1; if (i >= 0) r = (self->bitsBC[i / 32] >> (i & 31)) & 1; return r; }
static inline void Offset(Npc* self, V* p) { { M m = self->obj->GetMatrix(); M* pm = &m; QD(p, &pm->r[3]); } Sub(p, p, &self->target->pos); }

unsigned char NpcAi_ModeAttack(Npc* self0, Ev* ev0)
{
    V d2;
    V d3;
    V d5;
    Ev* ev; int t; Npc* self; bool low; unsigned char handled;
    self = self0;
    ev = ev0;
    handled = 0;
    t = *Event_GetType(ev);
    if (t == D_004EE550) {
        if ((unsigned char)ev->kind == 2) {
            if (self->target->b3 && Engaged(self->target)) {
                float len;
                Offset(self, &d2);
                len = Len(&d2);
                if ((unsigned char)self->Busy() && len < 30.0f && OnNode2(self->route, self->target))
                    NpcAi_SetMovementState(self, 0, 20);
            }
            handled = 1;
        } else if ((unsigned char)ev->kind == 3) {
            float len;
            Offset(self, &d3);
            len = Len(&d3);
            if (Engaged(self->target)) {
                if (!(unsigned char)self->Busy() && !(len <= 40.0f)) {
                    if (!Visited(self, self->target->node)) {
                        NpcAi_ApproachSearch(self);
                    } else if (OnNode(self)) {
                        if (self->target->Get()->ctrl && self->target->Get()->ctrl->IsHuman())
                            handled = 1;
                    } else {
                        handled = 1;
                    }
                }
            } else {
                if (!(unsigned char)self->Busy())
                    handled = 1;
                low = 1;
                {
                    Inv* inv = self->obj->inv;
                    if (!inv->bA0 && !(WeaponInv_GetClip(inv, 6) < self->clipMin))
                        low = 0;
                }
                if (low)
                    AskAmmo(self);
            }
            if (handled) {
                self->f13F = 4;
                if (Visited(self, self->target->node)) {
                    Ai* tg = self->target;
                    int node = tg->node;
                    if (self->b158) {
                        void* svc = Service_Lookup(g_Game, g_NpcRouteMgr);
                        if (node >= 0 && !NpcRoute_IsHeadPending(svc, self->obj))
                            NpcPath_RequestRoute(self->route, tg, node);
                    }
                } else {
                    NpcAi_ApproachSearch(self);
                }
            }
            self->fE8 = 40;
            handled = 1;
            self->fEC++;
        } else if ((unsigned char)ev->kind == 4) {
            self->fE8 = 1;
            if (Engaged(self->target))
                self->fEC = 0;
            handled = 1;
        } else if ((unsigned char)ev->kind == 8) {
            if (NpcAttack_CombatPosture(self) == 2) {
                NpcAi_CoverSearch(self);
                self->pair = Pair(4, 2);
            }
        } else if ((unsigned char)ev->kind == 7) {
            handled = 1;
            self->fE8 = 1;
        } else if ((unsigned char)ev->kind == 0) {
            if (self->target->b4)
                self->fE8 = 1;
            else
                self->fE8 = -1;
            self->fEC = 0;
            self->SetMovement(2, 20);
            handled = 1;
            self->fE0 = -1;
            self->fE4 = -1;
        } else if ((unsigned char)ev->kind == 0) {
            /* retail tests kind 0 a second time here (bnez), so this arm is unreachable */
            self->SetMovement(1, 20);
        }
    } else {
        int t2 = *Event_GetType(ev);
        if (t2 == D_004ED9B8) {
            if ((unsigned char)ev->kind == 5) {
                float l2;
                Offset(self, &d5);
                l2 = LenSq(&d5);
                if (Engaged(self->target) && (unsigned char)self->Busy() && l2 < 900.0f)
                    NpcAi_SetMovementState(self, 0, 20);
            } else if ((unsigned char)ev->kind == 1 || (unsigned char)ev->kind == 3) {
            } else if ((unsigned char)ev->kind == 2) {
                if (self->pair.a == 4 && self->pair.b != 4)
                    NpcAi_RequestMode(self->brain, self->pair.b, 0);
            } else if ((unsigned char)ev->kind == 7) {
                if (ev->f28 == 10) {
                    int n = self->route->f50;
                    if (n >= 0) { PNode* pn = NpcPath_GetNode(n); if (OnPNode(self, pn))
                        self->SetMovement(2, 20); }
                }
            }
        }
    }
    return handled;
}
