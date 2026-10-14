/*
 * main/weapon: range (2 files, 00141880-00141CD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_00141880 */
#pragma push /* merge_units */
#pragma cplusplus on
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { QC(this, &o); }
} __attribute__((aligned(16)));
static inline V Sub(const V& a0, const V& b0) {
    V r;
    __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%1)" : : "r"(&a0), "r"(&r), "r"(&b0) : "memory");
    return r;
}
static inline void Normalize(V* v) {
    asm {
        lqc2 vf1, 0x0(v)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vrsqrt Q, vf0w, vf3w
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(v)
    }
}
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
    Query() { Query* s = this; WV* p = s->v; do { ++p; } while (p != s->v + 3); s->b40 = 0; s->b42 = 0; s->w60 = 0; s->w64 = 0; }
};
struct Hit { int w[4]; };
struct HV { char pad[0x4C]; float f4C; };
class Ctrl {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int Test();
};
class Actor;
class Actor {
public:
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual V GetPos();
    VPAD4(f) VPAD2(h)
    virtual void Hurt(float dmg, Actor* src, int kind, int type, int* p, int a, int b);
    VPAD1(g)
    virtual unsigned char State();
    char pad04[0x48];
    int w4C;
    char pad50[8];
    Ctrl* ctrl;
};
struct Slot { int a; int b; int id; int c; };
struct Self { Slot slots[8]; int pad80; unsigned char cur; char pad85[3]; Actor* actor; };
extern "C" {
extern void* D_004FFD30;
extern char D_004FFB50[];
extern char D_004EA0B0[];
extern unsigned char D_00489DA0;
extern int D_0049D010[];
}
static inline int Team() { int* p = D_0049D010; return *p; }
extern "C" {
char* WeaponDb_Get(void* db, int id);
void* Service_Lookup(void* a, void* b);
int LosMgr_TraceBullet(void* mgr, Hit* a, Query* b, V* c, const V& d, void* e1, void* e2, int g, unsigned char h, unsigned char i, int j, unsigned char k);
int func_001B8740(Actor* a);
void* Agent_GetSelected(void* a, int b);
void Stats_Add(void* a, int b, int c);
void Global_ShockToDeath(Actor* a, int b, int c, float d, float e);
void Actor_Ignite(Actor* a, int b, Actor* c, int d, int e, float f);
void Actor_GetHitVolumes(Actor* a, V* b, V* c, int d, HV* e);
}
static inline bool CtrlBusy(Actor* a) { bool r = false; if (a->ctrl && a->ctrl->Test()) r = true; return r; }
static inline bool Downed(Actor* a) { bool r; unsigned char s = a->State(); r = true; if (s != 3 && s != 2) r = false; return r; }
extern "C" void Melee_ApplyHit(Self* self, Actor* target, int heavy)
{
    int extra;
    if (self->cur != 5) return;
    unsigned char* w = (unsigned char*)WeaponDb_Get(D_004FFD30, ((Slot*)((char*)self + (self->cur << 4)))->id);
    unsigned char t = w[0xF0];
    if (t != 3 && t != 4 && t != 0xA) return;
    if (!D_00489DA0) return;
    if (CtrlBusy(target)) return;
    V from(self->actor->GetPos());
    V d(Sub(target->GetPos(), from));
    void* mgr = Service_Lookup(D_004FFB50, D_004EA0B0);
    Hit hit;
    Query q;
    if ((unsigned char)LosMgr_TraceBullet(mgr, &hit, &q, &from, d, 0, 0, 0, 0x58, 0, 0, 0)) return;
    int type = w[0xF0] == 4 ? 7 : 9;
    extra = *(int*)(w + 0xF8);
    if (w[0xF0] == 4) {
        if (Downed(target)) return;
        if (target->w4C != Team()) return;
        if (((unsigned char*)target)[0x346A]) return;
        if (CtrlBusy(self->actor) && ((unsigned char*)self->actor)[0x14] && !func_001B8740(target))
            Stats_Add(Agent_GetSelected(D_004FFB50, -1), 6, 1);
        Global_ShockToDeath(target, 0, 1, 0.5f, 10000.0f);
        return;
    }
    if (w[0xF0] == 0xA) {
        if (Downed(target)) return;
        if (target->w4C != Team()) return;
        Actor_Ignite(target, 1, self->actor, 0, 0, -1.0f);
        return;
    }
    float dmg = (float)*(int*)(w + 0x64);
    int kind = 3;
    if (heavy) {
        dmg = 100000.0f;
        kind = 2;
    } else if (target->w4C == Team()) {
        HV hv;
        Normalize(&d);
        d.w = 1.0f;
        hv.f4C = 1.0f;
        Actor_GetHitVolumes(target, &from, &d, 2, &hv);
    }
    target->Hurt(dmg, self->actor, kind, type, &extra, 0, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00141880(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00141880 */

/* merge_units: begin func_00141CD0 */
#pragma push /* merge_units */
#pragma cplusplus on
class R_1CD0 {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsLocal();
};
struct Ev_1CD0 { void* vt; char pad[0x20]; int id; char pad28[8]; };
struct Slot_1CD0 { int pad0; int id; int pad8; int count; };
struct Own_1CD0 { char pad[0x58]; R_1CD0* recv; char pad5C[4]; char equip[4]; };
struct W_1CD0 { char pad[0x13C]; int slot; };
struct S_1CD0 { int pad0; Slot_1CD0 slots[8]; unsigned char cur; char pad85[3]; Own_1CD0* own; char pad8C[0x63]; unsigned char busy; };
extern "C" {
extern unsigned char D_005721C8;
extern char D_004EA150[];
extern char D_004D91E0[];
#if 0 /* merge_units */
W_1CD0* WeaponDb_Get(void* db, int id);
#endif /* merge_units */
#define WeaponDb_Get(a0, a1) ((W_1CD0 *)WeaponDb_Get((a0), (a1))) /* merge_units */

void Equip_SetSlot(void* eq, int a, int slot);
void Event_Construct(Ev_1CD0* e, void* type);
void Event_Send(Ev_1CD0* e, void* target, int a);
void cMessage_dtor(Ev_1CD0* e, int f);
void WeaponInv_Cycle(S_1CD0* self, int a);
}
extern "C" void Inventory_ReleaseItem(S_1CD0* self)
{
    self->busy = 0;
    if (self->cur == 4 || self->cur == 5) {
        Slot_1CD0* s = &self->slots[self->cur];
        unsigned char local;
        R_1CD0* r;
        if (s->count > 0) {
            Equip_SetSlot(self->own->equip, 0, WeaponDb_Get(D_004FFD30, s->id)->slot);
            return;
        }
        local = 0;
        r = self->own->recv;
        if (r && r->IsLocal())
            local = 1;
        if (local && !D_005721C8) {
            int id = s->id;
            Ev_1CD0 e;
            Event_Construct(&e, D_004EA150);
            e.id = id;
            e.vt = D_004D91E0;
            Event_Send(&e, self->own->recv, 0);
            e.vt = D_004D91E0;
            cMessage_dtor(&e, 0);
        }
        s->id = -1;
        WeaponInv_Cycle(self, 1);
    }
}
#undef WeaponDb_Get /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00141CD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00141CD0 */
