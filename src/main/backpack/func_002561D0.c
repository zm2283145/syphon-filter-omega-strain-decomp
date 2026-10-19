#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"
/* Backpack_Place: drop the backpack, pick its LOS region, ray-test downward and register it with the hit object */
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
extern void* g_HotboxTracker;
void Event_Construct(void*, void*);
void cMessage_dtor(void*, int);
Svc* Service_Lookup(void*, void*);
void* func_0013D9F0(void);
void* func_0013D770(void* a, void* w);
Region_61D0* World_GetPlayerZone(void* r, V* p);
Region_61D0* LosRegion_FindGlobal(V* p);
Ref_61D0* WeakRef_Capture(Ref_61D0* r, Pack_61D0* o);
void HandleVec_FindResolved(It_61D0* out, void* v, Ref_61D0* ref);
void func_002564E0(It_61D0* out, void* v);
int func_002564C0(It_61D0* a, It_61D0* b);
void HandleVec_PushBack(void* v, Ref_61D0* ref);
void HotboxWorld_UpdateBoxBounds(void* mgr, void* hb, Pack_61D0* p, int a);
void Backpack_Place(Pack_61D0* p, Mtx_61D0* m, int drop);
}
#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    MsgB() {}
    MsgB(void* t) { Event_Construct(this, t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct MsgRay : MsgB {
    int a24; int a28; HitInfo* info; V pos; V dir; Pack_61D0* src; void* tgt; int n; unsigned char b5C;
    MsgRay(HitInfo* i, const V& p, const V& d, Pack_61D0* s, void* t) : MsgB(g_LosRequestMsgClass) {
        vtable = D_004D9180; a24 = 0; a28 = 0; info = i; V* dp = &pos; Q16(dp, &p); dir = d; src = s; tgt = t; n = 0; b5C = 0; pos.w = 1.0f; dir.w = 0.0f; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgRay() { vtable = D_004D9180; }
} __attribute__((aligned(16)));
static inline bool Clear(Region_61D0* g) { return !(g->b2E != 0); }
void Backpack_Place(Pack_61D0* p, Mtx_61D0* m, int drop)
{
    p->link->Detach();
    if (drop) {
        void* w = g_LocalPlayer->world;
        void* r = func_0013D770(func_0013D9F0(), w);
        {
            V pos; { const V* s = &m->r3; V* d = &pos; Q16(d, s); }
            p->region = World_GetPlayerZone(r, &pos);
            if (!p->region) p->region = LosRegion_FindGlobal(&pos);
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
                Service_Lookup(g_Game, g_LosCheckService)->Post(&msg);
                if (hi.hit) {
                    Obj_61D0* o = *hi.s.obj;
                    if (o->cls == g_GameGobjClassWord && o->kind == 3) {
                        Ref_61D0 r1;
                        It_61D0 it;
                        It_61D0 end;
                        HandleVec_FindResolved(&it, o->packs, WeakRef_Capture(&r1, p));
                        func_002564E0(&end, o->packs);
                        if (func_002564C0(&it, &end)) {
                            Ref_61D0 r2;
                            HandleVec_PushBack(o->packs, WeakRef_Capture(&r2, p));
                        }
                    }
                }
            }
        }
    }
    if (p->hotbox) HotboxWorld_UpdateBoxBounds(g_HotboxTracker, p->hotbox, p, 0);
}
