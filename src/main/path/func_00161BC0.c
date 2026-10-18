#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"
/* NpcRoute_RequestLosChecks: post a line-of-sight request from the route point to a target node */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V() {} V(const V& o) { V* d = this; Q16(d, &o); } V& operator=(const V& o) { V* d = this; Q16(d, &o); return *this; } } __attribute__((aligned(16)));
static inline void VSub(V* r, V* a, V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
struct Svc { VPAD1(a) virtual void Post(void*); };
struct Node_1BC0 { char pad[0x64]; unsigned int flags; };
struct List_1BC0 { char pad[8]; Node_1BC0** items; };
struct Route_1BC0 { char pad0[0x450]; V pos; char pad460[0x482 - 0x460]; unsigned char crouch; };
extern "C" {
extern char D_004D9180[], D_004FFB50[], D_005435A0[], D_004EA0B0[], g_NpcRouteMgr[];
extern List_1BC0* D_004FFBE0;
extern unsigned char D_004ED9D0;
void Event_Construct(void*, void*);
void cMessage_dtor(void*, int);
Svc* Service_Lookup(void*, void*);
void Node_GetTranslation(V* out, Node_1BC0* n);
void NpcRoute_RequestLosChecks(Route_1BC0* r, int idx, unsigned int mask);
}
#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    MsgB() {}
    MsgB(void* t) { Event_Construct(this, t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct MsgLos : MsgB {
    void* a24; void* a28; int a2C; V pos; V dir; int a50; int a54; int n; unsigned char b5C;
    MsgLos(void* s, void* u, const V& p, const V& d) : MsgB(D_005435A0) {
        vtable = D_004D9180; a24 = s; a28 = u; a2C = 0; V* dp = &pos; Q16(dp, &p); dir = d; a50 = 0; a54 = 0; n = 4; b5C = 2; pos.w = 1.0f; dir.w = 0.0f; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgLos() { vtable = D_004D9180; }
} __attribute__((aligned(16)));
void NpcRoute_RequestLosChecks(Route_1BC0* r, int idx, unsigned int mask)
{
    V p = r->pos;
    if (!r->crouch) p.z += 4.5f;
    else p.z += 2.6f;
    Svc* svc = Service_Lookup(D_004FFB50, D_004EA0B0);
    Node_1BC0* n = D_004FFBE0->items[idx];
    V t;
    Node_GetTranslation(&t, n);
    VSub(&t, &t, &r->pos);
    if (mask & n->flags & 4) t.z -= 3.0f;
    {
        MsgLos m(Service_Lookup(D_004FFB50, g_NpcRouteMgr), (char*)r + 8, p, t);
        svc->Post(&m);
    }
    D_004ED9D0 = 1;
}
