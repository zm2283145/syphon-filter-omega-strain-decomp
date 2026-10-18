#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"
/* NpcAi_LosCheckFromDestination: line-of-sight request from the route destination back to the NPC */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V() {} V(const V& o) { V* d = this; Q16(d, &o); } V& operator=(const V& o) { V* d = this; Q16(d, &o); return *this; } } __attribute__((aligned(16)));
static inline void VSub(V* r, V* a, V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
struct Svc { VPAD1(a) virtual bool Post(void*); };
struct PathNode_1790 { char pad[0x64]; unsigned int flags; };
struct Route_1790 { char pad0[0x58]; int node; char pad5C[0x74 - 0x5C]; V* dest; };
struct Npc_1790 { char pad0[0x68]; unsigned int flags; char pad6C[0x1AC - 0x6C]; V* pos; Route_1790* route; };
extern "C" {
extern char D_004D9180[], D_004FFB50[], D_005435A0[], D_004EA0B0[];
void Event_Construct(void*, void*);
void cMessage_dtor(void*, int);
Svc* Service_Lookup(void*, void*);
PathNode_1790* NpcPath_GetNode(int i);
unsigned char NpcAi_LosCheckFromDestination(Npc_1790* n);
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
static inline int IsZeroXYZ(const V* v)
{
    int k, fl;
    unsigned char r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyz vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xE
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline void Q16b(void* d, const void* s) { __int128 q; asm volatile { lq q, 0(s); sq q, 0(d) } }
static inline V* DestOf(Route_1790* r) { return r->dest ? r->dest : 0; }
unsigned char NpcAi_LosCheckFromDestination(Npc_1790* n)
{
    unsigned char ok = 0;
    V from = *n->pos;
    V d;
    Q16b(&d, DestOf(n->route));
    VSub(&d, &d, &from);
    from.z += 4.5f;
    if (n->route->node >= 0 && (NpcPath_GetNode(n->route->node)->flags & 4)) d.z -= 3.0f;
    if (!IsZeroXYZ(&d)) {
        Svc* svc = Service_Lookup(D_004FFB50, D_004EA0B0);
        {
            MsgLos m(n, 0, from, d);
            ok = svc->Post(&m);
        }
        if (ok) n->flags |= 1;
    }
    return ok;
}
