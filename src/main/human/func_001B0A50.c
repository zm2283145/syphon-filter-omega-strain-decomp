/* NpcAi_GroundActor: put an actor back on the ground: unless already
 * grounded (or dead/flagged), trace 100 units down to find the floor; when
 * asked to snap, teleport it to its current position (optionally lifted to
 * the given height when it sits below it), otherwise clear the physics
 * velocities; then land it. */
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"
/* lq/sq: 128-bit quadword moves have no C equivalent (asm). */
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void QZ(void* d) { __asm__ volatile("sq $0, 0x0(%0)" : : "r"(d) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
} __attribute__((aligned(16)));
struct M4 { V r[4]; V& T() { return r[3]; } };
/* Out-of-line copy of the empty destructor is weak and dropped by the link script (as in alloc_guard.h). */
#pragma define_section QUERY_DTOR ".dtors_drop" far_absolute RX
struct Query {
    struct WV { float x, y, z, w; } __attribute__((aligned(16))) v[3];
    char pad30[0x10];
    unsigned char b40;
    unsigned char b41;
    unsigned char b42;
    char pad43[0x1D];
    int w60;
    int w64;
    int pad68[2];
    __declspec(weak) __declspec(QUERY_DTOR) ~Query() {}
    Query() { Query* s = this; WV* p = s->v; do { ++p; } while (p != s->v + 3); s->b40 = 0; s->b42 = 0; s->w60 = 0; s->w64 = 0; }
};
struct Hit { int w[4]; };
struct Ctl { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsPlayer(); };
struct Phys { char p0[0x20]; int x20; char p24[0xDC - 0x24]; unsigned char sel; char pDD[0x2F0 - 0xDD]; V v2F0; V v300; V v310; V v320; V v330; };
struct Slot { char p0[0xB0]; int busy; };
struct Msg { void* vtable; char pad[0x20]; unsigned char b24; char pad3[0xB]; char data[0x40]; };
struct Act {
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d)
    virtual V GetPos2();
    virtual void v39();
    virtual M4 GetMtx();
    VPAD4(e) VPAD2(g) VPAD1(h)
    virtual unsigned char Life();
    VPAD1(f)
    virtual int Grounded();
    char p04[0x54]; Ctl* ctrl; char p5C[0x3210 - 0x5C]; int x3210; char p3214[0x3290 - 0x3214];
    Slot* slots[3]; char p329C[0x3310 - 0x329C]; Phys* phys;
};
extern "C" {
extern char g_Game[];
extern char g_LosCheckService[];
extern char g_TeleportMsgClass[], D_004D9360[];
void* Service_Lookup(void* a, void* b);
void* func_0014D460(Act* a);
void* func_0014D450(void* a);
void* func_0014D410(void* a);
void* func_001AE360(void* a);
void LosProvider_SeedRegion(void* p, void* r);
int LosMgr_TraceBullet(void* mgr, Hit* a, Query* b, const V& c, const V& d, void* e1, void* e2, int g, unsigned char h, unsigned char i, int j, unsigned char k);
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
void* Mtx_GetIdentity(void);
void Vec4_CopyAsPoint(V* out, const V* v);
void Mtx_SetRotationTranslation(void* data, void* m, V* v);
void Actor_LandFromAir(Act* a, int b);
void Actor_LandDead(Act* a, int b);
void NpcAi_GroundActor(Act* self, int snap, int above, float z);
}
static inline int& F3034(Act* a) { return *(int*)((char*)a + 0x3034); }
static inline int& F3038(Act* a) { return *(int*)((char*)a + 0x3038); }
static inline bool Has(Slot* s) { return s->busy != 0; }
static inline unsigned char UHas(Slot* s) { return s->busy != 0; }
static inline unsigned char UHas2(Slot* s) { return UHas(s); }
static inline bool Free(Slot* s) { return !(Has(s) != 0); }
static inline bool Free1(Slot* s) { return !(UHas2(s) != 0); }
static inline bool AllFree(Act* n) { bool r = 0; bool c = 0; if (Free1(n->slots[0]) && Free(n->slots[1])) c = 1; if (c && Free(n->slots[2])) r = 1; return r; }
static inline void SetPos(Msg* m, const V* p)
{
    void* id = Mtx_GetIdentity();
    V t;
    Vec4_CopyAsPoint(&t, p);
    void* d = m->data;
    asm { .set reorder } /* empty scheduling barrier: retail sets up the destination before the matrix argument */
    Mtx_SetRotationTranslation(d, id, &t);
}
static inline void Teleport(Act* self, V* pos)
{
    Msg msg;
    Msg* m = &msg;
    Event_Construct(m, g_TeleportMsgClass);
    m->vtable = D_004D9360;
    m->b24 = 0;
    SetPos(m, pos);
    Event_Send(m, self, 1);
    msg.vtable = D_004D9360;
    cMessage_dtor(&msg, 0);
}

void NpcAi_GroundActor(Act* self, int snap, int above, float z)
{
    if (self->phys && !self->phys->x20) {
        unsigned char ok = self->Grounded() != 0;
        if (!ok) {
            bool dead;
            unsigned char life = self->Life();
            dead = true;
            if (life != 3 && life != 2) dead = false;
            if (dead) {
                if (!((F3034(self) >> 1) & 1)) {
                    void* los = Service_Lookup(g_Game, g_LosCheckService);
                    void* reg = func_0014D410(func_0014D450(func_0014D460(self)));
                    if (reg) LosProvider_SeedRegion(func_001AE360(los), reg);
                    Hit hit;
                    Query q;
                    ok = (unsigned char)LosMgr_TraceBullet(los, &hit, &q, self->GetPos2(), V(0.0f, 0.0f, -100.0f, 0.0f), self, 0, 0, 0x40, 0x80, 0, 0);
                    if (!ok) F3038(self) |= 2;
                } else {
                    F3038(self) |= 2;
                }
            }
        }
        if (ok) {
            if (!snap) return;
            bool sel = false;
            if (self->phys && self->phys->sel) sel = true;
            if (!sel) return;
            bool dead;
            unsigned char life = self->Life();
            dead = true;
            if (life != 3 && life != 2) dead = false;
            if (dead) return;
            bool pl = false;
            if (self->ctrl && self->ctrl->IsPlayer()) pl = true;
            if (pl) return;
        }
        if (snap && AllFree(self)) {
            V pos = self->GetMtx().T();
            if (above) {
                if (pos.z < z - 0.5f) {
                    pos.z = z - 0.6f;
                    Teleport(self, &pos);
                }
            } else {
                pos.z = z;
                Teleport(self, &pos);
            }
        } else {
            if (self->phys) {
                Phys* p = *(Phys* volatile*)&self->phys; /* retail reloads the pointer here */
                QZ(&p->v330);
                QZ(&p->v320);
                QC(&p->v300, &p->v2F0);
                QZ(&p->v310);
            }
            if ((self->x3210 >> 10) & 1) Actor_LandFromAir(self, 0);
        }
        F3038(self) |= 1;
        Actor_LandDead(self, 1);
    }
}
