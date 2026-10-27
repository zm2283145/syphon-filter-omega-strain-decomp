/*
 * SFOGame/Source/backpack: 4 files, 00255F60-002561D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00255F60 */
#pragma push /* merge_units */
#include "types.h"

#pragma cplusplus on
struct Tgt {
    char pad0[0xC];
    int serial;
    char pad10[0x2C - 0x10];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x3468 - 0x2F];
    unsigned char b3468;
    unsigned char b3469;
    char pad346A[0x3528 - 0x346A];
    int inv;
};
struct Hnd {
    Tgt* target;
    int serial;
    Tgt* Get() { Tgt* t = target; bool ok = !t || t->serial == serial; return ok ? t : 0; }
};
struct Ctl { char pad[0x9C]; int mode; };
struct Obj {
    char pad0[0x60];
    unsigned char b60;
    char pad61[0x2FC - 0x61];
    Ctl* ctl;
    Hnd h;
};
extern "C" int ItemInv_Any(int);
static inline bool A(Tgt* t) { bool v = t->b2D && t->b2C && !t->b2E && t->b3468; return v; }
static inline bool B(Tgt* t) { bool v = t->b2D && t->b2C && !t->b2E && t->b3469; return v; }
extern "C" void Backpack_UpdateBoxPriority(Obj* o)
{
    if (o->ctl) {
        int m = 0;
        if (o->b60 == 1) {
            m = 5;
        } else if (o->h.Get()) {
            if (A(o->h.Get()) || B(o->h.Get()) || ItemInv_Any(o->h.Get()->inv))
                m = 0x14;
        }
        o->ctl->mode = m;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00255F60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00255F60 */

/* merge_units: begin func_00256120 */
#pragma push /* merge_units */
typedef struct { char pad[0x2FC]; int effect; char pad300[0x14]; int unk314; } Obj002579E0;
extern void* g_HotboxTracker;
extern void cHotboxMan_RemoveHotbox(void* mgr, int effect);
extern void nGobjManager_RemoveGOBJ(int effect);
extern void cSystem_ActualScheduleDelete(int effect, float time);
/* Stop and release the attached effect. */
void cBackpack_RemoveInteractBox(Obj002579E0* obj)
{
    if (obj->effect) {
        cHotboxMan_RemoveHotbox(g_HotboxTracker, obj->effect);
        nGobjManager_RemoveGOBJ(obj->effect);
        cSystem_ActualScheduleDelete(obj->effect, 0.1f);
        obj->effect = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00256120(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00256120 */

/* merge_units: begin func_00256180 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cBackpack link creation.
 */

#include "backpack_types.h"

#if 0 /* merge_units */
extern int g_HotboxTracker;
#endif /* merge_units */
#define g_HotboxTracker (*(int*)&g_HotboxTracker) /* merge_units */

extern BackpackLink* cHotboxMan_CreateInteractBox(int manager, cBackpack* backpack, int a2, int a3);

/* Creates the backpack's link object through manager g_HotboxTracker if it has none. */
void cBackpack_MakeInteractBox(cBackpack* backpack) {
    if (backpack->link == 0) {
        backpack->link = cHotboxMan_CreateInteractBox(g_HotboxTracker, backpack, 0, 1);
        backpack->link->owner = backpack->unk0C;
    }
}
#undef g_HotboxTracker /* merge_units */
static inline void merge_flush_func_00256180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00256180 */

/* merge_units: begin func_002561D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
#include "vslot_pad.h"
/* cBackpack_SetBodyLoc: drop the backpack, pick its LOS region, ray-test downward and register it with the hit object */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V() {} V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } V(const V& o) { V* d = this; Q16(d, &o); } V& operator=(const V& o) { V* d = this; Q16(d, &o); return *this; } } __attribute__((aligned(16)));
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct Obj_61D0;
struct HitSub { VP v[3]; char pad30[0x10]; unsigned char b40; char pad41; unsigned char b42; char pad43[0x1D]; int i60; Obj_61D0** obj; char pad68[0x18];
    /* empty walk over v[] mirrors the retail V[3] array-ctor loop on the materialized sub-object pointer */
    HitSub* Init() { HitSub* t = this; VP* q = t->v; do { q++; } while (q != t->v + 3); t->b40 = 0; t->b42 = 0; t->i60 = 0; t->obj = 0; return t; } };
struct HitInfo { unsigned char hit; char pad1[0x1F]; HitSub s; HitSub* Init() { HitInfo* t = this; return t->s.Init(); } } __attribute__((aligned(16)));
struct Mtx_61D0 { V r0; V r1; V r2; V r3; };
struct Region_61D0 { char pad[0x2C]; unsigned char b2C; unsigned char b2D; unsigned char b2E; };
struct Ref_61D0 { void* obj; int id; };
struct It_61D0 { void* p; };
struct Obj_61D0 { char pad[0x4C]; void* cls; char pad50[0x68 - 0x50]; int kind; char pad6C[0x84 - 0x6C]; char packs[0xC]; };
struct Link_61D0 { VPAD1(a) virtual void Detach(); };
struct Pack_61D0 { char pad[0x50]; Link_61D0* link; char pad54[0x2F4 - 0x54]; unsigned char blocked; char pad2F5[3]; Region_61D0* region; void* hotbox; };
struct Holder_61D0 { char pad[0x30]; void* world; };
struct Svc { VPAD1(a) virtual bool Post(void*); };
extern "C" {
extern char D_004D9180[], g_Game[], g_LosRequestMsgClass[], g_LosCheckService[];
extern void* g_GameGobjClassWord;
extern Holder_61D0* g_LocalPlayer;
void cMessage_ctor_cMessageNameR(void*, void*);
void cMessage_dtor(void*, int);
Svc* cSystemContainer_GetSystem(void*, void*);
void* GetSceneManager(void);
void* cSceneManager_GetSceneBelongingTo(void* a, void* w);
Region_61D0* cScene_FindBestSectorInActivation(void* r, V* p);
Region_61D0* nActivation_GetClosestTerrainPiece(V* p);
Ref_61D0* cSafePtr_cGOBJ_ctor_cGOBJP(Ref_61D0* r, Pack_61D0* o);
void cArray_cSafePtr_cGOBJ_Find(It_61D0* out, void* v, Ref_61D0* ref);
void cArray_cSafePtr_cGOBJ_End(It_61D0* out, void* v);
int func_002564C0(It_61D0* a, It_61D0* b);
void cArray_cSafePtr_cGOBJ_PushBackActual(void* v, Ref_61D0* ref);
void cHotboxMan_SetupInteractBoxDimensionsAndLocation(void* mgr, void* hb, Pack_61D0* p, int a);
void cBackpack_SetBodyLoc(Pack_61D0* p, Mtx_61D0* m, int drop);
}
#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    MsgB() {}
    MsgB(void* t) { cMessage_ctor_cMessageNameR(this, t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct MsgRay : MsgB {
    int a24; int a28; HitInfo* info; V pos; V dir; Pack_61D0* src; void* tgt; int n; unsigned char b5C;
    MsgRay(HitInfo* i, const V& p, const V& d, Pack_61D0* s, void* t) : MsgB(g_LosRequestMsgClass) {
        vtable = D_004D9180; a24 = 0; a28 = 0; info = i; V* dp = &pos; Q16(dp, &p); dir = d; src = s; tgt = t; n = 0; b5C = 0; pos.w = 1.0f; dir.w = 0.0f; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgRay() { vtable = D_004D9180; }
} __attribute__((aligned(16)));
static inline bool Clear(Region_61D0* g) { return !(g->b2E != 0); }
void cBackpack_SetBodyLoc(Pack_61D0* p, Mtx_61D0* m, int drop)
{
    p->link->Detach();
    if (drop) {
        void* w = g_LocalPlayer->world;
        void* r = cSceneManager_GetSceneBelongingTo(GetSceneManager(), w);
        {
            V pos; { const V* s = &m->r3; V* d = &pos; Q16(d, s); }
            p->region = cScene_FindBestSectorInActivation(r, &pos);
            if (!p->region) p->region = nActivation_GetClosestTerrainPiece(&pos);
        }
        {
            Region_61D0* g = p->region;
            bool a = 0;
            bool b = 0;
            if (g->b2D && g->b2C) b = 1;
            if (b && Clear(g)) a = 1;
            p->blocked = !(a & 0xFF);
        }
        {
            HitInfo hi;
            hi.Init();
            V from = m->r3;
            V dir(0.0f, 0.0f, -3.0f, 1.0f);
            {
                MsgRay msg(&hi, from, dir, p, 0);
                cSystemContainer_GetSystem(g_Game, g_LosCheckService)->Post(&msg);
                if (hi.hit) {
                    Obj_61D0* o = *hi.s.obj;
                    if (o->cls == g_GameGobjClassWord && o->kind == 3) {
                        Ref_61D0 r1;
                        It_61D0 it;
                        It_61D0 end;
                        cArray_cSafePtr_cGOBJ_Find(&it, o->packs, cSafePtr_cGOBJ_ctor_cGOBJP(&r1, p));
                        cArray_cSafePtr_cGOBJ_End(&end, o->packs);
                        if (func_002564C0(&it, &end)) {
                            Ref_61D0 r2;
                            cArray_cSafePtr_cGOBJ_PushBackActual(o->packs, cSafePtr_cGOBJ_ctor_cGOBJP(&r2, p));
                        }
                    }
                }
            }
        }
    }
    if (p->hotbox) cHotboxMan_SetupInteractBoxDimensionsAndLocation(g_HotboxTracker, p->hotbox, p, 0);
}
static inline void merge_flush_func_002561D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002561D0 */
