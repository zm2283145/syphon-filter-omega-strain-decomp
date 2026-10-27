/*
 * SFOGame/Source/backpack: 6 files, 00253DD0-00254770
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00253DD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct InvSlot_253DD0 { int a; int b; int item; int c; };
struct Inv_253DD0 { InvSlot_253DD0 s[8]; };
struct Tables_253DD0 { char pad[0x3524]; Inv_253DD0* inv; };
struct World_253DD0 { char pad[0x30]; Tables_253DD0* t; };
struct BP_253DD0 { char pad0[0x2F0]; unsigned char b2F0; char pad2F1[2]; unsigned char b2F3; };
extern "C" {
extern World_253DD0* g_LocalPlayer;
void cBackpack_Clear(BP_253DD0* bp, int a);
int cWeapon_GetAmmo(Inv_253DD0* inv, unsigned char slot);
int cWeapon_GetClipAmmo(Inv_253DD0* inv, unsigned char slot);
void cWeapon_RemoveWeapon(Inv_253DD0* inv, unsigned char slot, int a, int b, int c);
void cBackpack_AddWeapon(BP_253DD0* bp, int item, int spare, int clip, int e);
void cBackpack_CheckForRemoval(BP_253DD0* bp);
}
static inline void Steal(BP_253DD0* bp, Inv_253DD0* inv, unsigned char slot)
{
    if (slot != 8) {
        int spare;
        int item = inv->s[slot].item;
        if (item > -1) {
            spare = cWeapon_GetAmmo(inv, slot);
            cBackpack_AddWeapon(bp, item, spare, cWeapon_GetClipAmmo(inv, slot), 0);
            cWeapon_RemoveWeapon(inv, slot, 0, 0, 0);
        }
    }
}
extern "C" void cBackpack_StealPlayerWeapons(BP_253DD0* bp, unsigned char a, unsigned char b, unsigned char c)
{
    Inv_253DD0* inv = g_LocalPlayer->t->inv;
    cBackpack_Clear(bp, 1);
    bp->b2F3 = 1;
    bp->b2F0 = 0;
    Steal(bp, inv, a);
    Steal(bp, inv, b);
    Steal(bp, inv, c);
    cBackpack_CheckForRemoval(bp);
}
static inline void merge_flush_func_00253DD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00253DD0 */

/* merge_units: begin func_00253FB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cBackpack virtual slot.
 */

#include "backpack_types.h"

extern BackpackWorld* g_WeaponDatabase;
extern char D_005716C0[];

char* cBackpack_GetBBox(void) {
    char* p = g_WeaponDatabase->unkB8;
    if (p != 0) {
        return p + 0x3E0;
    }
    return D_005716C0;
}
static inline void merge_flush_func_00253FB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00253FB0 */

/* merge_units: begin func_00253FE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
/* cBackpack_Render (draw): while the backpack is free (no ready holder, no
 * contents) it fades by its age, tracks the shared drop-marker position and
 * draws its model. Helpers follow cBackpack_v10 (backpack_2542E0.c) and
 * cGrenade_Render (grenade/cGrenade_Render.c). */
#pragma always_inline on
#pragma inline_depth(8)
struct V_3FE0 { float x, y, z, w; V_3FE0() {} } __attribute__((aligned(16)));
struct Sub_3FE0 {
    VPAD16(a) VPAD4(b)
    virtual void Sync();
    char pad4[0x4C];
    unsigned char f50;
};
struct Tgt_3FE0 { char pad[0xC]; int id; char pad10[0x1C]; unsigned char b2C; unsigned char b2D; unsigned char b2E; };
struct Hnd_3FE0 { Tgt_3FE0* p; int id; };
struct Item_3FE0 { char pad0[0xD0]; int obj; };
struct Bp_3FE0 {
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d)
    virtual V_3FE0 GetPos();
    char pad4[0x34];
    int x38;
    char pad3C[0x14];
    Sub_3FE0* sub;
    char pad54[0x60 - 0x54];
    Item_3FE0 items[3];
    char pad2DC[0x2E4 - 0x2DC];
    int hasItems;
    int nItems;
    char pad2EC[0x2F8 - 0x2EC];
    Tgt_3FE0* t2F8;
    int pad2FC;
    Hnd_3FE0 h;
    char pad308[0x314 - 0x308];
    float age;
};
struct Model_3FE0 { char pad[0x416]; signed char alpha; };
struct WeaponDb_3FE0 { char pad[0xB8]; Model_3FE0* backpack; };
extern "C" {
#if 0 /* merge_units */
extern WeaponDb_3FE0* g_WeaponDatabase;
#endif /* merge_units */
#define g_WeaponDatabase (*(WeaponDb_3FE0 **)&g_WeaponDatabase) /* merge_units */

extern float D_0048AF18;
extern V_3FE0 D_00535D40;
extern unsigned char D_00535D60;
extern unsigned char D_00535D61;
void gunList_GunRender(void* a, int b, void* c, int d);
}
static inline bool IdEq(Tgt_3FE0* p, Hnd_3FE0* h) { return p->id == h->id; }
static inline Tgt_3FE0* HGet(Hnd_3FE0* h) {
    bool ok = !h->p || IdEq(h->p, h);
    return ok ? h->p : 0;
}
static inline bool Not(unsigned char x) { return !x; }
static inline bool Ready(Tgt_3FE0* t) { bool r = false; bool a = false; if (t->b2D && t->b2C) a = true; if (a && Not(t->b2E)) r = true; return r; }
static inline unsigned char eq4_(V_3FE0* a, V_3FE0* b) {
    int k, f, r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf3, vf1, vf2
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        bne k, f, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
/* cvt.w.s+mfc1: a C (int) cast compiles to trunc.w.s */
static inline int F2I(float f) { int r; float t; asm { cvt.w.s t, f; mfc1 r, t } return r; }

extern "C" void cBackpack_Render(Bp_3FE0* self)
{
    Tgt_3FE0* t = self->t2F8;
    if (t && Ready(t)) {
        if (!HGet(&self->h) || !Ready(HGet(&self->h))) {
            int n = self->hasItems ? self->nItems : 0;
            int empty = n <= 0;
            int i;
            for (i = 0; empty && i < 3; i++) {
                if (self->items[i].obj)
                    empty = 0;
            }
            if (!empty) {
                WeaponDb_3FE0* w = g_WeaponDatabase;
                Model_3FE0* m = w->backpack;
                int a = -1;
                if (!(self->age <= 0.0f))
                    a = F2I(127.0f * ((D_0048AF18 - self->age) / D_0048AF18));
                m->alpha = a;
                {
                    V_3FE0 p = self->GetPos();
                    if ((eq4_(&D_00535D40, &p) != 0) ^ 1) {
                        /* 16-byte copy (lq/sq copy idiom); volatile asm, as the sibling cBackpack_v10 has, keeps MW from turning the Ready() flag tests into sltu forms */
                        { const V_3FE0* s = &p; V_3FE0* d = &D_00535D40; __int128 q; asm volatile { .set reorder; lq q, 0(s) } asm volatile { sq q, 0(d) } }
                        D_00535D60 = 1; D_00535D61 = 1;
                    }
                }
                {
                    Sub_3FE0* r = self->sub;
                    if (r->f50) r->Sync();
                    gunList_GunRender(m, self->x38, (void*)((int)r + 0x10), 0);
                }
            }
        }
    }
}
#undef g_WeaponDatabase /* merge_units */
static inline void merge_flush_func_00253FE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00253FE0 */

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
Svc* cSystemContainer_GetSystem(void* a, void* b);
void cMessage_ctor_cMessageNameR(void* m, void* type);
void cMessage_dtor(void* m, int flags);
}
static inline bool IdEq_002542E0(Tgt* p, Hnd* h) { return p->id == h->id; }
static inline Tgt* HGet_002542E0(Hnd* h) {
    bool ok = !h->p || IdEq_002542E0(h->p, h);
    return ok ? h->p : 0;
}
static inline bool Ready_002542E0(Tgt* t) { bool r = false; bool a = false; if (t->b2D && t->b2C) a = true; if (a && Not(t->b2E)) r = true; return r; }
extern "C" void cBackpack_v10(Bp* self)
{
    if (self->b2F4) {
        Tgt* t = self->t2F8;
        if (t && Ready_002542E0(t)) {
            if (!HGet_002542E0(&self->h) || !Ready_002542E0(HGet_002542E0(&self->h))) {
                HitRes res;
                V start = SubPos(self->sub);
                V dir(0.0f, 0.0f, -5.0f, 1.0f);
                RayMsg msg;
                RayMsg* m = &msg;
                cMessage_ctor_cMessageNameR(m, g_LosRequestMsgClass);
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
                cSystemContainer_GetSystem(g_Game, g_LosCheckService)->Send(&msg);
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
int* cMessage_Name(void* ev);
Obj_00254600* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
void cNetObj_SendMessage_int_cMessageR_int_int(int target, Msg_00254600* msg, int a, int b);
void cPlayer_BeginPickup(Ctl_00254600* c, Bp_00254600* b);
int cGOBJ_HandleMessage(Bp_00254600* b, Ev_00254600* ev);
}
extern "C" int cBackpack_HandleMessage(Bp_00254600* bp, Ev_00254600* ev)
{
    int t = *cMessage_Name(ev);
    if (t == g_TriggerMsgKey) {
        int id = ev->id;
        Ctl_00254600* c = nGobjManager_LookupGOBJ_cObjectIdR(&id)->ctl;
        if (c && c->IsActive() && ((CtlObj_00254600*)c)->b14) {
            int who = c->GetId();
            if (bp->b2F3 || bp->owner == who) {
                if (bp->f314 < 0.0f) {
                    cPlayer_BeginPickup(c, bp);
                }
            } else {
                if (g_IsMultiplayer) {
                    Msg_00254600 m;
                    cMessage_ctor_cMessageNameR(&m, D_005061B0);
                    m.id = who;
                    m.vtable = D_004DCEF0;
                    m.bp = bp;
                    m.b24 = 2;
                    m.b20 = 4;
                    cNetObj_SendMessage_int_cMessageR_int_int(bp->net, &m, -1, bp->owner);
                    m.vtable = D_004DCF10;
                    cMessage_dtor(&m, 0);
                }
            }
        }
        return 1;
    }
    return cGOBJ_HandleMessage(bp, ev);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00254600(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00254600 */

/* merge_units: begin func_00254770 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Tgt_00254770 { char pad[0xC]; int id; char pad10[0x3464 - 0x10]; int f3464; };
struct Hnd_00254770 { Tgt_00254770* p; int id; };
struct Vec { int cap; int count; void** items; };
struct Msg { void* vt; char pad4[0x1C]; signed char b20; char pad21[3]; signed char b24; char pad25[3]; void* bp; int id; };
struct Bp_00254770 { char pad0[0x2F3]; unsigned char b2F3; char pad2F4[0x2FC - 0x2F4]; void* fx; Hnd_00254770 h; int owner; };
extern "C" {
extern int D_00494178;
extern int D_005721A8;
extern void* g_HotboxTracker;
extern Vec* g_BackpackList;
int NetGetMyClientIndex(int*, int);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* src, int f);
void cHotboxMan_RemoveHotbox(void*, void*);
void nGobjManager_RemoveGOBJ(void*);
void cSystem_ActualScheduleDelete(void*, float);
void std_vector_pod_int_resize(Vec* v, int n, int* fill);
}
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
static inline int LocalId() { int r;int a=D_005721A8;if(g_IsMultiplayer) { if(D_00494178==-1)NetGetMyClientIndex(&D_00494178,a);r=D_00494178; }else { r=0; }return r; }
#pragma pop
static inline bool IdEq_00254770(Tgt_00254770* p, Hnd_00254770* h) { return p->id == h->id; }
static inline Tgt_00254770* HGet_00254770(Hnd_00254770* h) {
    bool ok = !h->p || IdEq_00254770(h->p, h);
    return ok ? h->p : 0;
}
#pragma opt_strength_reduction off
extern "C" void cBackpack_Remove(Bp_00254770* self)
{
    if (HGet_00254770(&self->h)) HGet_00254770(&self->h)->f3464 = 0;
    if (!self->b2F3 && g_IsMultiplayer) {
        if (self->owner == LocalId()) {
            Msg m;
            cMessage_ctor_cMessageNameR(&m, D_005061B0);
            m.vt = D_004DCEF0;
            m.bp = self;
            m.b24 = 1;
            m.id = -1;
            m.b20 = 4;
            QueueMessage_cMessageR_cSystemP_int(&m, self, 0);
            m.vt = D_004DCF10;
            cMessage_dtor(&m, 0);
        }
    }
    if (self->fx) {
        cHotboxMan_RemoveHotbox(g_HotboxTracker, self->fx);
        nGobjManager_RemoveGOBJ(self->fx);
        cSystem_ActualScheduleDelete(self->fx, 0.1f);
        self->fx = 0;
    }
    nGobjManager_RemoveGOBJ(self);
    {
        Vec* v = g_BackpackList;
        int i;
        int last = v->count - 1;
        int fill;
        for (i = 0; last >= i; i++) {
            void** e = &v->items[i];
            if (*e == self) {
                *e = v->items[last];
                last--;
            }
        }
        fill = 0;
        std_vector_pod_int_resize(v, last + 1, &fill);
    }
    cSystem_ActualScheduleDelete(self, 0.1f);
}
static inline void merge_flush_func_00254770(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00254770 */
