/*
 * SFOGame/Source/path: 3 files, 00161930-00161BC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00161930 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * PathCursor constructor.
 */

#include "types.h"
#include "path_types.h"

PathCursor* cPath_ctor(PathCursor* self, int owner) {
    self->owner = owner;
    self->unk20 = 0;
    self->unk28 = 0;
    self->unk14 = -1;
    self->unk10 = -1;
    return self;
}
static inline void merge_flush_func_00161930(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00161930 */

/* merge_units: begin func_00161950 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cNodeRequest_Update: restart the route walk when dirty, then report the chosen node to the owner */
typedef struct Pt1SnObj { char pad0[0xC]; int serial; char pad10[0x58 - 0x10]; struct Pt1SnObj* owner; } Pt1SnObj;
typedef struct Pt1SnNode { char pad0[0x10]; int a; int b; } Pt1SnNode;
typedef struct Pt1SnMsg {
    void* vt;
    char pad4[0x20];
    unsigned char found;
    char pad25[3];
    int node;
    int node2;
} Pt1SnMsg;
typedef struct Pt1SnSelf {
    Pt1SnObj* owner;
    int ownerSerial;
    char pad8[0xD - 0x8];
    unsigned char dirty;
    unsigned char reported;
    char padF[0x10 - 0xF];
    char list[0x4];
    char sentinel[0x4];
    void* head;
    void* tail;
    char nodes[0x4];
    void* first;
    void* last;
    int count;
    char pad30[0x468 - 0x30];
    int mask;
    unsigned char mode;
    char pad46D[0x474 - 0x46D];
    unsigned char status;
    char pad475[3];
    int target;
    int target2;
    unsigned char reverse;
    unsigned char retry;
    unsigned char crouched;
} Pt1SnSelf;
extern char D_004ED9B8[];
extern char D_004D9760[];
extern "C" void cMessage_ctor_cMessageNameR(void* msg, void* name);
extern "C" void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate);
extern "C" void cMessage_dtor(void* msg, int flags);
extern "C" void cNodeRequest_AddNodesToEvaluate(Pt1SnSelf* self, int mode);
extern "C" Pt1SnNode* cPriorityQueue_cNodeIndex_Pop(void* list);
#if 0 /* merge_units */
extern "C" void cNodeRequest_SendLOSRequest(Pt1SnSelf* self, int id, int mask);
#endif /* merge_units */
struct Route_1BC0; /* merge_units */
extern "C" void cNodeRequest_SendLOSRequest(Route_1BC0* r, int idx, unsigned int mask); /* merge_units */
#define cNodeRequest_SendLOSRequest(a0, a1, a2) (cNodeRequest_SendLOSRequest((Route_1BC0 *)(a0), (a1), (unsigned int)(a2))) /* merge_units */


static inline Pt1SnObj* Pt1Sn_Owner(Pt1SnSelf* self)
{
    Pt1SnObj* t = self->owner;
    bool isNull = !t;
    bool ok = true;
    if (!isNull)
        if (t->serial != self->ownerSerial)
            ok = false;
    t = ok ? t : 0;
    Pt1SnObj* o=t->owner; return o == 0 ? t : o;
}

extern "C" unsigned char cNodeRequest_Update(Pt1SnSelf* self)
{
    unsigned char done = 0;
    if (self->dirty) {
        self->dirty = 0;
        self->head = self->nodes;
        self->tail = self->sentinel;
        self->first = self->nodes;
        self->last = self->sentinel;
        self->count = 0;
        if (!self->crouched)
            cNodeRequest_AddNodesToEvaluate(self, 2);
        else
            cNodeRequest_AddNodesToEvaluate(self, 0);
        self->target = -1;
        self->target2 = -1;
        self->status = 0;
        if (self->count) {
            if (!self->mode) {
                Pt1SnNode* n = cPriorityQueue_cNodeIndex_Pop(self->list);
                self->target = n->a;
                self->target2 = n->b;
            } else {
                cNodeRequest_SendLOSRequest(self, ((Pt1SnNode*)self->head)->a, self->mask);
            }
        }
    }
    if (self->status == 2)
        self->status = 0;
    if (self->retry) {
        if (!self->count)
            done = 1;
    } else if (self->target >= 0) {
        Pt1SnMsg m;
        int a;
        int b;
        self->reported = 1;
        b = self->target2;
        a = self->target;
        cMessage_ctor_cMessageNameR(&m, D_004ED9B8);
        m.node = a;
        m.node2 = b;
        m.vt = D_004D9760;
        m.found = 0;
        QueueMessage_cMessageR_cSystemP_int(&m, Pt1Sn_Owner(self), 1);
        m.vt = D_004D9760;
        cMessage_dtor(&m, 0);
        done = 1;
    } else if (!self->count) {
        Pt1SnMsg m;
        self->reported = 1;
        cMessage_ctor_cMessageNameR(&m, D_004ED9B8);
        m.vt = D_004D9760;
        m.found = 1;
        m.node = -1;
        QueueMessage_cMessageR_cSystemP_int(&m, Pt1Sn_Owner(self), 1);
        m.vt = D_004D9760;
        cMessage_dtor(&m, 0);
        done = 1;
    }
    return done;
}
#undef cNodeRequest_SendLOSRequest /* merge_units */
static inline void merge_flush_func_00161950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00161950 */

/* merge_units: begin func_00161BC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
#include "vslot_pad.h"
/* cNodeRequest_SendLOSRequest: post a line-of-sight request from the route point to a target node */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V() {} V(const V& o) { V* d = this; Q16(d, &o); } V& operator=(const V& o) { V* d = this; Q16(d, &o); return *this; } } __attribute__((aligned(16)));
static inline void VSub(V* r, V* a, V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
struct Svc { VPAD1(a) virtual void Post(void*); };
struct Node_1BC0 { char pad[0x64]; unsigned int flags; };
struct List_1BC0 { char pad[8]; Node_1BC0** items; };
struct Route_1BC0 { char pad0[0x450]; V pos; char pad460[0x482 - 0x460]; unsigned char crouch; };
extern "C" {
extern char D_004D9180[], g_Game[], g_LosRequestMsgClass[], g_LosCheckService[], g_NpcRouteMgr[];
extern List_1BC0* D_004FFBE0;
extern unsigned char D_004ED9D0;
#if 0 /* merge_units */
void cMessage_ctor_cMessageNameR(void*, void*);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cMessage_dtor(void*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((a0), (a1))) /* merge_units */

Svc* cSystemContainer_GetSystem(void*, void*);
void cNode_GetLoc(V* out, Node_1BC0* n);
void cNodeRequest_SendLOSRequest(Route_1BC0* r, int idx, unsigned int mask);
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
void cNodeRequest_SendLOSRequest(Route_1BC0* r, int idx, unsigned int mask)
{
    V p = r->pos;
    if (!r->crouch) p.z += 4.5f;
    else p.z += 2.6f;
    Svc* svc = cSystemContainer_GetSystem(g_Game, g_LosCheckService);
    Node_1BC0* n = D_004FFBE0->items[idx];
    V t;
    cNode_GetLoc(&t, n);
    VSub(&t, &t, &r->pos);
    if (mask & n->flags & 4) t.z -= 3.0f;
    {
        MsgLos m(cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr), (char*)r + 8, p, t);
        svc->Post(&m);
    }
    D_004ED9D0 = 1;
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_00161BC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00161BC0 */
