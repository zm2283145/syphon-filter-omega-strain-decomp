/*
 * SFOGame/Source/npc: 4 files, 00151780-001519A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00151780 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc.
 */

#include "types.h"

char* cMatrix_GetAxis(char* base, int i) {
    return base + i * 16;
}
static inline void merge_flush_func_00151780(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00151780 */

/* merge_units: begin func_00151790 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
#include "vslot_pad.h"
/* cNPC_CheckLOSDestinationFromTarget: line-of-sight request from the route destination back to the NPC */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V() {} V(const V& o) { V* d = this; Q16(d, &o); } V& operator=(const V& o) { V* d = this; Q16(d, &o); return *this; } } __attribute__((aligned(16)));
static inline void VSub(V* r, V* a, V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
struct Svc { VPAD1(a) virtual bool Post(void*); };
struct PathNode_1790 { char pad[0x64]; unsigned int flags; };
struct Route_1790 { char pad0[0x58]; int node; char pad5C[0x74 - 0x5C]; V* dest; };
struct Npc_1790 { char pad0[0x68]; unsigned int flags; char pad6C[0x1AC - 0x6C]; V* pos; Route_1790* route; };
extern "C" {
extern char D_004D9180[], g_Game[], g_LosRequestMsgClass[], g_LosCheckService[];
void cMessage_ctor_cMessageNameR(void*, void*);
void cMessage_dtor(void*, int);
Svc* cSystemContainer_GetSystem(void*, void*);
PathNode_1790* cAIPathData_GetNode(int i);
unsigned char cNPC_CheckLOSDestinationFromTarget(Npc_1790* n);
}
#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    MsgB() {}
    MsgB(void* t) { cMessage_ctor_cMessageNameR(this, t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct MsgLos : MsgB {
    void* a24; void* a28; int a2C; V pos; V dir; int a50; int a54; int n; unsigned char b5C;
    MsgLos(void* s, void* u, const V& p, const V& d) : MsgB(g_LosRequestMsgClass) {
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
unsigned char cNPC_CheckLOSDestinationFromTarget(Npc_1790* n)
{
    unsigned char ok = 0;
    V from = *n->pos;
    V d;
    Q16b(&d, DestOf(n->route));
    VSub(&d, &d, &from);
    from.z += 4.5f;
    if (n->route->node >= 0 && (cAIPathData_GetNode(n->route->node)->flags & 4)) d.z -= 3.0f;
    if (!IsZeroXYZ(&d)) {
        Svc* svc = cSystemContainer_GetSystem(g_Game, g_LosCheckService);
        {
            MsgLos m(n, 0, from, d);
            ok = svc->Post(&m);
        }
        if (ok) n->flags |= 1;
    }
    return ok;
}
static inline void merge_flush_func_00151790(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00151790 */

/* merge_units: begin func_001519A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x44]; int state; } S1519A0;
extern int cNPC_Patrol(S1519A0*, int);
extern int cNPC_EnemySeen(S1519A0*, int);
extern int cNPC_TakeCover(S1519A0*, int);
extern int cNPC_AttackFromCover(S1519A0*, int);
extern int cNPC_Attack(S1519A0*, int);
extern int cNPC_SearchLook(S1519A0*, int);
extern int cNPC_Flee(S1519A0*, int);
extern int cNPC_ScriptControl(S1519A0*, int);
extern int cNPC_CarryBody(S1519A0*, int);
extern int cNPC_Follow_cMessageR(S1519A0*, int);
extern int cNPC_AvoidGrenade(S1519A0*, int);
unsigned char cNPC_Update(S1519A0* p, int a) {
    unsigned char r;
    switch (p->state) {
    case 0: r = cNPC_Patrol(p, a); break;
    case 1: r = cNPC_EnemySeen(p, a); break;
    case 2: r = cNPC_TakeCover(p, a); break;
    case 3: r = cNPC_AttackFromCover(p, a); break;
    case 4: r = cNPC_Attack(p, a); break;
    case 5: r = cNPC_SearchLook(p, a); break;
    case 6: r = cNPC_Flee(p, a); break;
    case 7: r = cNPC_ScriptControl(p, a); break;
    case 8: r = cNPC_CarryBody(p, a); break;
    case 9: r = cNPC_Follow_cMessageR(p, a); break;
    case 10: r = cNPC_AvoidGrenade(p, a); break;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001519A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001519A0 */

/* merge_units: begin func_00151A90 */
#pragma push /* merge_units */
typedef struct Msg_00151A90 {
    void* vtable;
    char base[0x1C];
    unsigned char b20;
    char pad21[3];
    int value;
    unsigned char b28;
    char pad29[7];
} Msg_00151A90;
typedef struct Tgt_00151A90 { char pad[0x320C]; int state; } Tgt_00151A90;
typedef struct Self_00151A90 { char pad[0x30]; Tgt_00151A90* target; char pad34[0x114 - 0x34]; int mode; } Self_00151A90;
typedef struct Ev_00151A90 { char pad[0x24]; int type; } Ev_00151A90;
extern char g_ActorActionMsgClass[];
extern char D_004E0840[];
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg_00151A90* msg, void* name);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

extern void QueueMessage_cMessageR_cSystemP_int(Msg_00151A90* msg, void* target, int flags);
#if 0 /* merge_units */
extern void cMessage_dtor(Msg_00151A90* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

int cNPC_HandleCASEvent(Self_00151A90* self, Ev_00151A90* ev)
{
    switch (ev->type) {
    case 6: {
        int v = self->mode == 4 ? 0x11 : 0x13;
        Msg_00151A90 msg;
        cMessage_ctor_cMessageNameR(&msg, g_ActorActionMsgClass);
        msg.value = v;
        msg.b28 = 0;
        msg.vtable = D_004E0840;
        { Tgt_00151A90* t = self->target;
        msg.b20 = 1;
        QueueMessage_cMessageR_cSystemP_int(&msg, t, 0); }
        msg.vtable = D_004E0840;
        cMessage_dtor(&msg, 0);
        break;
    }
    case 9:
        if (self->mode == 4) {
            Msg_00151A90 msg;
            cMessage_ctor_cMessageNameR(&msg, g_ActorActionMsgClass);
            msg.b28 = 0;
            msg.vtable = D_004E0840;
            msg.value = 0x11;
            { Tgt_00151A90* t = self->target;
            msg.b20 = 1;
            QueueMessage_cMessageR_cSystemP_int(&msg, t, 0); }
            msg.vtable = D_004E0840;
            cMessage_dtor(&msg, 0);
        }
        break;
    case 8:
        {
        int m = self->mode;
        if (m == 4) {
            Msg_00151A90 msg;
            cMessage_ctor_cMessageNameR(&msg, g_ActorActionMsgClass);
            msg.b28 = 0;
            msg.vtable = D_004E0840;
            msg.value = 0xF;
            { Tgt_00151A90* t = self->target;
            msg.b20 = 1;
            QueueMessage_cMessageR_cSystemP_int(&msg, t, 0); }
            msg.vtable = D_004E0840;
            cMessage_dtor(&msg, 0);
        } else if (m == 11) {
            Msg_00151A90 msg;
            cMessage_ctor_cMessageNameR(&msg, g_ActorActionMsgClass);
            msg.b28 = 0;
            msg.vtable = D_004E0840;
            msg.value = 0x10;
            { Tgt_00151A90* t = self->target;
            msg.b20 = 1;
            QueueMessage_cMessageR_cSystemP_int(&msg, t, 0); }
            msg.vtable = D_004E0840;
            cMessage_dtor(&msg, 0);
        } else if (m == 3) {
            if (self->target->state != 0x10) {
                Msg_00151A90 msg;
                cMessage_ctor_cMessageNameR(&msg, g_ActorActionMsgClass);
                msg.b28 = 0;
                msg.vtable = D_004E0840;
                msg.value = 0x1A;
                QueueMessage_cMessageR_cSystemP_int(&msg, self->target, 0);
                msg.vtable = D_004E0840;
                cMessage_dtor(&msg, 0);
            }
        }
        }
        break;
    default:
        return 0;
    }
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00151A90(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00151A90 */
