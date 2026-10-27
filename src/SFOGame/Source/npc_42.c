/*
 * SFOGame/Source/npc: 1 file, 001564C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001564C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"
/* cNPC_TakeCover: take-cover message handler - settle into the cover node (crouch/peek by
   cover height), move to a better cover node when exposed, ask for ammo, and react to perception. */
/* quadword copy (lq/sq): a 128-bit move C cannot express, the retail vector copy */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V() {} V(const V& o) { V* d = this; Q16(d, &o); } V& operator=(const V& o) { V* d = this; Q16(d, &o); return *this; } } __attribute__((aligned(16)));
struct M { V r[4]; V& T() { return r[3]; } } __attribute__((aligned(16)));
struct Inv { char pad[0xA0]; unsigned char bA0; };
struct Ai {
    V pos;
    char pad10[0x10];
    unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 1; unsigned char b4 : 1;
};
struct GObj { VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e) virtual M GetMatrix(); char pad4[0x3208]; int f320C; char pad3210[0x314]; Inv* inv; };
struct Route { V pos; char pad10[0x30]; float f40; char pad44[0xC]; int f50; char pad54[4]; int f58; };
struct PNode { char pad[0x64]; int flags; };
/* retail copies the posture pair as one word (sh/sh to a temp, then lw/sw) */
struct Pair { short a, b; Pair(short x, short y) { a = x; b = y; } Pair& operator=(const Pair& o) { *(int*)this = *(const int*)&o; return *this; } };
struct Brain { char pad0[0xC]; unsigned char b0C; char pad0D[0x1F]; };
/* slot names from use */
struct Npc {
    VPAD32(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual int Busy();
    VPAD4(e) VPAD1(f) virtual void SetMovement(int a, int b);
    VPAD16(g) VPAD8(h) virtual void SetStance(int a, int b);
    VPAD4(i) virtual void Alert(int a);
    VPAD4(j) VPAD1(k) virtual int CoverHeight();
    VPAD16(l) VPAD4(m) VPAD1(n) virtual int CurrentNode();
    VPAD1(o) virtual void MoveToCover(int n);
    VPAD4(p) virtual int CoverNode(int a);
    char pad4[0x2C];
    GObj* obj;              /* 0x30 */
    char pad34[0x10];
    Brain brain;            /* 0x44 */
    char pad70[0x34];
    int clipMin;            /* 0xA4 */
    char padA8[0x10];
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
    unsigned char b141 : 1; /* 0x141 */
    char pad142[0x6A];
    Ai* target;             /* 0x1AC */
    Route* route;           /* 0x1B0 */
};
struct Ev { char pad[0x24]; signed char kind; char pad25[3]; int f28; };
extern "C" {
extern int D_004EE550;
extern int D_004ED9B8;
extern int D_00489E20[4];
extern char g_ActorActionMsgClass[], D_004E0840[];
int* cMessage_Name(Ev* ev);
int cWeapon_GetClipAmmo(Inv* inv, int slot);
int cWeapon_CanReload(Inv* inv);
int cWeapon_ReadyToFire(Inv* inv, int b);
int cHuman_IsHoldingGun(GObj* o);
float cPathNavigator_DistanceToDestination(Route* r);
unsigned char cAITarget_TestPointInViewCone(Ai* t, V* p, int x, int mode);
PNode* cAIPathData_GetNode(int n);
void cNPC_DoAction(Npc* self, int type, int prio, float f);
void cStateMachine_ChangeState(void* brain, int mode, int arg);
void cNPC_SetMoveMode(Npc* self, int a, int b);
void cNPC_MoveToCoverNode(Npc* self);
void cNPC_MoveToAttackFromCoverNode(Npc* self);
void cNPC_CheckLOSDestinationFromTarget(Npc* self);
void cMessage_ctor_cMessageNameR(void*, void*);
void QueueMessage_cMessageR_cSystemP_int(void*, void*, int);
void cMessage_dtor(void*, int);
unsigned char cNPC_TakeCover(Npc* self, Ev* ev);
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
static inline bool LowAmmo(Npc* self) { bool low = 1; Inv* inv = self->obj->inv; if (!inv->bA0 && !(cWeapon_GetClipAmmo(inv, 6) < self->clipMin)) low = 0; return low; }
/* cover-height thresholds: a native 128-bit copy (lq/sq by the compiler) of D_00489E20 */
struct F4 { union { __int128 q; float v[4]; }; };
static inline float CoverLimit(unsigned int h) { F4 t = *(F4*)D_00489E20; return t.v[h & 0xFF]; }
static inline void Peek(Npc* self, int n)
{
    if ((cAIPathData_GetNode(n)->flags & 4) && !self->b141)
        cNPC_DoAction(self, 1, 0, 0.0f);
}

unsigned char cNPC_TakeCover(Npc* self0, Ev* ev0)
{
    Npc* self; Ev* ev; unsigned char handled; GObj* obj; int t; Inv* inv;
    self = self0;
    ev = ev0;
    handled = 0;
    obj = self->obj;
    inv = obj->inv;
    t = *cMessage_Name(ev);
    if (t == D_004EE550) {
        if ((unsigned char)ev->kind == 2) {
            if ((unsigned char)self->Busy() == 1) {
                Route* r = self->route;
                if (r->f58 >= 0 && r->f58 == r->f50) {
                    if (cPathNavigator_DistanceToDestination(r) < 3.0f) {
                        self->SetStance(0, 0);
                    } else {
                        float lim = CoverLimit(self->CoverHeight());
                        if (self->route->f40 > lim && self->route->f40 < 1.0f + lim && obj->f320C != 2 &&
                            cAITarget_TestPointInViewCone(self->target, &self->route->pos, 0, 0)) {
                            Peek(self, self->route->f58);
                            cNPC_DoAction(self, 2, 0, 0.0f);
                        }
                    }
                }
            }
            if (!Engaged(self->target)) {
                if (Exposed(self)) {
                    if (self->CoverNode(0) == self->CurrentNode())
                        self->MoveToCover(self->CoverNode(1));
                    else
                        self->MoveToCover(self->CoverNode(0));
                } else if (self->fEC == 0) {
                    if (LowAmmo(self))
                        self->fEC = 1;
                    else
                        self->fEC = 2;
                }
            }
            if (self->fEC == 1 && cWeapon_CanReload(inv)) {
                {
                    MsgI m(60, 0);
                    QueueMessage_cMessageR_cSystemP_int(&m, self->obj, 0);
                }
                self->fEC = 2;
            }
            handled = 1;
        } else if ((unsigned char)ev->kind == 3) {
            self->fE8 = 30;
            if (!(unsigned char)self->Busy()) {
                Inv* w = obj->inv;
                if (cHuman_IsHoldingGun(self->obj) && cWeapon_ReadyToFire(w, 0)) {
                    cNPC_MoveToAttackFromCoverNode(self);
                    self->pair = Pair(2, 3);
                }
                if (Engaged(self->target))
                    self->fE0 = self->fE4 = -1;
            }
            handled = 1;
        } else if ((unsigned char)ev->kind == 4) {
            if (Engaged(self->target))
                self->SetStance(1, 0);
            handled = 1;
        } else if ((unsigned char)ev->kind == 5) {
            self->fE8 = 40;
        } else if ((unsigned char)ev->kind == 6) {
            if (ev->f28 && Engaged(self->target) && (unsigned char)self->Busy()) {
                cNPC_SetMoveMode(self, 0, 20);
                self->fE8 = 30;
            }
        } else if ((unsigned char)ev->kind == 0) {
            if (self->f13F != 2 && self->f140 != 2)
                cNPC_MoveToCoverNode(self);
            if ((unsigned char)self->Busy())
                self->fE8 = -1;
            else
                self->fE8 = 40;
            self->fEC = 0;
            handled = 1;
        } else if ((unsigned char)ev->kind == 1) {
            self->SetStance(1, 0);
            handled = 1;
        }
    } else {
        int t2 = *cMessage_Name(ev);
        if (t2 == D_004ED9B8) {
            if ((unsigned char)ev->kind == 5) {
                cNPC_CheckLOSDestinationFromTarget(self);
            } else if ((unsigned char)ev->kind == 6) {
                int n = ev->f28;
                if (n >= 0 && !self->brain.b0C)
                    Peek(self, n);
                self->SetStance(1, 0);
                self->fE8 = 40;
            } else if ((unsigned char)ev->kind == 1) {
                if (self->pair.b == 2)
                    cStateMachine_ChangeState(&self->brain, 4, 0);
            } else if ((unsigned char)ev->kind == 2) {
                if (self->pair.a == 2)
                    cStateMachine_ChangeState(&self->brain, self->pair.b, 0);
            } else if ((unsigned char)ev->kind == 3) {
                self->fE8 = 30;
            }
        }
    }
    return handled;
}
static inline void merge_flush_func_001564C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001564C0 */
