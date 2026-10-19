/*
 * main/backpack: range (2 files, 002542E0-00254600)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_002542E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    V operator-(const V& b) const { V r; const V* tp = this; V* rp = &r; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(&b) : "memory"); return r; }
} __attribute__((aligned(16)));
struct Mtx { V r0, r1, r2, t; };
struct Sub {
    VPAD16(a) VPAD4(b)
    virtual void Sync();
    char pad4[0xC];
    Mtx m;
    unsigned char f50;
};
static inline const V& SubPos(Sub* o) { if (o->f50) o->Sync(); return o->m.t; }
struct Tgt { char pad[0xC]; int id; char pad10[0x1C]; unsigned char b2C; unsigned char b2D; unsigned char b2E; };
struct Hnd { Tgt* p; int id; };
struct Svc { virtual void v0(); virtual void Send(void* m); };
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct HitSub { VP v[3]; char pad30[0x10]; unsigned char b40; char b41; unsigned char b42; char pad43[0x1D]; int f60; int f64; void Init() { HitSub* q = this; VP* i = q->v; VP* e = q->v + 3; do { i++; } while (i != e); q->b40 = 0; q->b42 = 0; q->f60 = 0; q->f64 = 0; } };
struct HitRes { unsigned char hit; char pad1[0xF]; VP pos; HitSub s; char pad88[0x10]; HitRes() { HitRes* p = this; p->s.Init(); } };
struct Bp;
struct RayMsg { void* vt; char base[0x20]; int f24; int f28; HitRes* res; V start; V end; Bp* pl; void* cl; int f58; unsigned char b5C; };
struct Bp {
    VPAD32(a) VPAD8(b)
    virtual void OnHit(const V& d);
    char pad4[0x4C];
    Sub* sub;
    char pad54[0x2F4 - 0x54];
    unsigned char b2F4;
    Tgt* t2F8;
    int pad2FC;
    Hnd h;
};
extern "C" {
extern char g_Game[];
extern char g_LosCheckService[];
extern char g_LosRequestMsgClass[];
extern char D_004D9180[];
Svc* Service_Lookup(void* a, void* b);
void Event_Construct(void* m, void* type);
void cMessage_dtor(void* m, int flags);
}
static inline bool IdEq(Tgt* p, Hnd* h) { return p->id == h->id; }
static inline Tgt* HGet(Hnd* h) {
    bool ok = !h->p || IdEq(h->p, h);
    return ok ? h->p : 0;
}
static inline bool Not(unsigned char x) { return !x; }
static inline bool Ready(Tgt* t) { bool r = false; bool a = false; if (t->b2D && t->b2C) a = true; if (a && Not(t->b2E)) r = true; return r; }
extern "C" void cBackpack_v10(Bp* self)
{
    if (self->b2F4) {
        Tgt* t = self->t2F8;
        if (t && Ready(t)) {
            if (!HGet(&self->h) || !Ready(HGet(&self->h))) {
                HitRes res;
                V start = SubPos(self->sub);
                V dir(0.0f, 0.0f, -5.0f, 1.0f);
                RayMsg msg;
                RayMsg* m = &msg;
                Event_Construct(m, g_LosRequestMsgClass);
                m->vt = D_004D9180;
                m->f24 = 0;
                m->f28 = 0;
                m->res = &res;
                m->start = start;
                m->end = dir;
                m->pl = self;
                m->cl = 0;
                m->f58 = 0;
                m->b5C = 0;
                m->start.w = 1.0f;
                m->end.w = 0.0f;
                Service_Lookup(g_Game, g_LosCheckService)->Send(&msg);
                if (res.hit) {
                    V d = *(V*)&res.pos - start;
                    self->OnHit(d);
                }
                self->b2F4 = 0;
                msg.vt = D_004D9180;
                cMessage_dtor(&msg, 0);
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002542E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002542E0 */

/* merge_units: begin func_00254600 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ctl_00254600 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual int IsActive();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual int GetId();
};
struct CtlObj_00254600 { char pad[0x14]; unsigned char b14; };
struct Obj_00254600 { char pad0[0x58]; Ctl_00254600* ctl; };
struct Ev_00254600 { char pad[0x30]; int id; };
struct Msg_00254600 { void* vtable; char pad4[0x1C]; signed char b20; char pad21[3]; signed char b24; char pad25[3]; void* bp; int id; };
struct Bp_00254600 { char pad0[0xC]; int net; char pad10[0x2F3 - 0x10]; unsigned char b2F3; char pad2F4[0x308 - 0x2F4]; int owner; char pad30C[8]; float f314; };
extern "C" {
extern unsigned char g_IsMultiplayer;
extern int g_TriggerMsgKey;
extern char D_005061B0[];
extern char D_004DCEF0[];
extern char D_004DCF10[];
int* Event_GetType(void* ev);
Obj_00254600* Object_LookupById(int* id);
void Transport_Send(int target, Msg_00254600* msg, int a, int b);
void Player_HandlePickupTrigger(Ctl_00254600* c, Bp_00254600* b);
int Object_HandleMessage(Bp_00254600* b, Ev_00254600* ev);
}
extern "C" int cBackpack_v01(Bp_00254600* bp, Ev_00254600* ev)
{
    int t = *Event_GetType(ev);
    if (t == g_TriggerMsgKey) {
        int id = ev->id;
        Ctl_00254600* c = Object_LookupById(&id)->ctl;
        if (c && c->IsActive() && ((CtlObj_00254600*)c)->b14) {
            int who = c->GetId();
            if (bp->b2F3 || bp->owner == who) {
                if (bp->f314 < 0.0f) {
                    Player_HandlePickupTrigger(c, bp);
                }
            } else {
                if (g_IsMultiplayer) {
                    Msg_00254600 m;
                    Event_Construct(&m, D_005061B0);
                    m.id = who;
                    m.vtable = D_004DCEF0;
                    m.bp = bp;
                    m.b24 = 2;
                    m.b20 = 4;
                    Transport_Send(bp->net, &m, -1, bp->owner);
                    m.vtable = D_004DCF10;
                    cMessage_dtor(&m, 0);
                }
            }
        }
        return 1;
    }
    return Object_HandleMessage(bp, ev);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00254600(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00254600 */
