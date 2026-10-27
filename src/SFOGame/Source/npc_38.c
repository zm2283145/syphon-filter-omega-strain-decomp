/*
 * SFOGame/Source/npc: 4 files, 00153150-00153860
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00153150 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"
/* cNPC_CarryBody: carry-body mode message handler: walk to the body,
 * pick it up (route to its region node or path to its head), then carry it
 * away; announces pick-up/put-down to the owner. */
/* lq/sq: 128-bit quadword moves have no C equivalent (asm). */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V() {} V(const V& o) { V* d = this; Q16(d, &o); } } __attribute__((aligned(16)));
struct M { V r0, r1, r2, r3; M() {} V& T() { return r3; } };
struct Route { char pad[0x5C]; int node; };
struct Region { char pad[0x78]; int node; };
struct Ctl {
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int Seen();
    virtual int IsA();
    virtual int IsB();
    VPAD32(d) VPAD32(e) VPAD8(f) VPAD2(g) VPAD1(h)
    virtual Region* GetRegion();
    char pad4[0x1B0 - 4];
    Route* route;
};
struct Obj {
    VPAD32(a) VPAD32(b)
    virtual unsigned char Life();
    char pad4[0x58 - 4];
    Ctl* ctrl;
};
struct Ai {
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d)
    virtual void Release();
    VPAD16(e) VPAD8(f) VPAD1(g)
    virtual float Delay(int a);
    char pad4[0x30 - 4];
    void* owner;
    char pad34[0x60 - 0x34];
    float delay;
    int timer;
    char pad68[0xE8 - 0x68];
    int state;
    int carryState;
    int region;
    int bodyId;
    char padF8[0x141 - 0xF8];
    unsigned char b141 : 6, flag6 : 1, b141_7 : 1;
    char pad142[0x1B0 - 0x142];
    void* path;
};
/* kind is read as a signed byte and compared as (unsigned char): with the quad-copy asm in this
   function MW keeps retail's lb + andi 0xff instead of narrowing to lbu */
struct Msg { char pad[0x24]; signed char kind; };
extern "C" {
extern int D_004EE550;
extern int D_004ED9B8;
extern int g_NpcRegionTable[];
extern signed char g_HeadNodeCode;
extern char g_ActorActionMsgClass[];
extern char D_004E0840[], D_004E01A0[];
int* cMessage_Name(void* ev);
unsigned char cPathNavigator_Request_int(void* path, int node);
unsigned char cPathNavigator_Request_cVectorR_int(void* path, V* pos, int region);
Obj* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
int cGOBJ_Team(Obj* o);
void* cSKM_GOBJ_GetSkeleton_void(Obj* o);
M cSkeleton_GetBoneToWorldMatrix(void* skel, signed char code);
void cMessage_ctor_cMessageNameR(void*, void*);
void QueueMessage_cMessageR_cSystemP_int(void*, void*, int);
void cMessage_dtor(void*, int);
unsigned char cNPC_CarryBody(Ai* self, Msg* msg);
}
#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    MsgB(void* t) { cMessage_ctor_cMessageNameR(this, t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct MsgI : MsgB {
    int id; unsigned char sub; char pad29[3];
    MsgI(int i, unsigned char s) : MsgB(g_ActorActionMsgClass) { vtable = D_004E0840; id = i; sub = s; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgI() { vtable = D_004E0840; }
};
struct MsgVal : MsgI {
    int val;
    MsgVal(int i, const volatile int& v) : MsgI(i, 5) { vtable = D_004E01A0; val = v; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgVal() {}
};

unsigned char cNPC_CarryBody(Ai* self0, Msg* msg0)
{
    bool release; Ai* self = self0; Msg* msg = msg0; int type; unsigned char handled;
    handled = 0;
    release = false;
    type = *cMessage_Name(msg);
    if (type == D_004EE550) {
        if ((unsigned char)msg->kind == 3) {
            if (self->carryState == 1) {
                self->carryState = 2;
                handled = cPathNavigator_Request_int(self->path, self->region);
                self->state = -1;
            } else {
                int id = self->bodyId;
                Obj* body = nGobjManager_LookupGOBJ_cObjectIdR(&id);
                if (body) {
                    self->state = 3;
                    handled = 1;
                    if (body->Life() == 3) {
                        int region = -1;
                        int node = region;
                        bool seen = false;
                        if (body->ctrl && body->ctrl->Seen())
                            seen = true;
                        if (seen) {
                            region = g_NpcRegionTable[cGOBJ_Team(body)];
                        } else if (body->ctrl->IsA() || body->ctrl->IsB()) {
                            Ctl* c = body->ctrl;
                            region = c->route->node;
                            Region* r = c->GetRegion();
                            if (r)
                                node = r->node;
                        }
                        V head = cSkeleton_GetBoneToWorldMatrix(cSKM_GOBJ_GetSkeleton_void(body), g_HeadNodeCode).T();
                        self->carryState = 0;
                        if (node >= 0)
                            cPathNavigator_Request_int(self->path, node);
                        else
                            handled = cPathNavigator_Request_cVectorR_int(self->path, &head, region);
                        self->state = -1;
                    }
                }
            }
            release = !handled;
        } else if ((unsigned char)msg->kind == 0) {
            self->state = 3;
            self->carryState = -1;
            float d = self->Delay(1);
            if (self->timer < 11) {
                self->delay = d;
                self->timer = 10;
                self->flag6 = 0;
            }
            handled = 1;
        } else if ((unsigned char)msg->kind == 1) {
            if (self->timer < 11)
                self->timer = 10;
            handled = 1;
        }
    } else {
      type = *cMessage_Name(msg);
      if (type == D_004ED9B8) {
        if ((unsigned char)msg->kind == 6) {
            if (self->carryState == 0) {
                self->carryState = 1;
                self->state = 1;
                volatile int id = self->bodyId; /* stack copy, as in retail */
                MsgVal m(43, id);
                m.kind = 1; QueueMessage_cMessageR_cSystemP_int(&m, self->owner, 0);
            } else if (self->carryState == 2) {
                volatile int id = self->bodyId; /* stack copy, as in retail */
                MsgVal m(44, id);
                m.kind = 1; QueueMessage_cMessageR_cSystemP_int(&m, self->owner, 0);
                self->Release();
            }
        } else if ((unsigned char)msg->kind == 1 || (unsigned char)msg->kind == 3) {
            if (self->carryState == 0 || self->carryState == 2)
                release = true;
        }
      }
    }
    if (release)
        self->Release();
    return handled;
}
static inline void merge_flush_func_00153150(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00153150 */

/* merge_units: begin func_001535D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

/* vtable slot 0x15 (shared stub): returns 0. */
int cGobjController_IsNetNPC(void) {
    return 0;
}
static inline void merge_flush_func_001535D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001535D0 */

/* merge_units: begin func_001535E0 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cNPC_AvoidGrenade: grenade-evasion mode message handler: on a
 * route-request event of kind 3 drop the mode unless the thrower is still
 * active, on kind 0 search a node away from the grenade and raise the alert
 * level, on kind 1 just raise it. Types as in cNPC_MoveToAttackFromCoverNode. */
struct V4 {
    __int128 q;
    V4() {}
};
struct Mat { V4 r[4]; Mat() {} };
class GObj {
public:
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) virtual void v58();
    virtual Mat GetMatrix();
};
class Thing {
public:
    VPAD32(a) VPAD8(b) VPAD4(c) virtual void v44();
    virtual V4 GetPos();
    char p4[0x2C - 4];
    unsigned char b2C; unsigned char b2D; unsigned char b2E;
};
struct Msg_35E0 { char pad[0x24]; signed char kind; };
class Npc_35E0 {
public:
    VPAD32(a) VPAD16(b) VPAD16(c) VPAD16(d)
    virtual float Alert(int level);
    char p4[0x30 - 4]; GObj* obj; char p34[0x44 - 0x34]; char brain[0x4C - 0x44]; int x4C;
    char p50[0x60 - 0x50]; float alertTime; int alertLevel; char p68[0xE8 - 0x68]; int xE8; char pEC[0xF4 - 0xEC];
    int threat; char pF8[0x13F - 0xF8]; unsigned char x13F; char p140;
    unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 1; unsigned char b4 : 1; unsigned char b5 : 1; unsigned char b6 : 1; unsigned char b7 : 1;
    char p142[0x1B0 - 0x142]; int region;
};
extern "C" {
extern char g_Game[];
extern char g_NpcRouteMgr[];
#if 0 /* merge_units */
Thing* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
#endif /* merge_units */
#define nGobjManager_LookupGOBJ_cObjectIdR(a0) ((Thing *)nGobjManager_LookupGOBJ_cObjectIdR((a0))) /* merge_units */

void* cSystemContainer_GetSystem(void* a, void* b);
int cPathSystem_IsRequestBeingProcessed(void* svc, GObj* id);
int cPathNavigator_GetGroupIndexForPatrolPath(int r);
unsigned char cPathSystem_RequestNodeIndexFromGroup(float d, void* svc, GObj* obj, void* e0, V4* pos, V4* tgt, int reg, int n, int k, long m);
void cNodePickerParameters_ctor_float_float_bool(float a, float b, void* out, int k);
void cStateMachine_ChangeState(void* brain, int event, int arg);
unsigned char cNPC_AvoidGrenade(Npc_35E0* self, Msg_35E0* msg);
}
/* volatile quad copy (lq/sq); retail keeps the address registers unfolded */
static inline void QCopy(V4* d, const V4* s) { __int128 x; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(x) : "r"(d), "r"(s) : "memory"); }
static inline bool Not(unsigned char x) { return !x; }
static inline bool Ready(Thing* t) { bool r = false; bool a = false; if (t->b2D && t->b2C) a = true; if (a && Not(t->b2E)) r = true; return r; }

extern "C" unsigned char cNPC_AvoidGrenade(Npc_35E0* self, Msg_35E0* msg)
{
    unsigned char handled = 0;
    int type = *cMessage_Name(msg);
    if (type == D_004EE550) {
        if ((unsigned char)msg->kind == 3) {
            int id = self->threat;
            Thing* o = nGobjManager_LookupGOBJ_cObjectIdR(&id);
            if (!o || !Ready(o)) {
                self->x4C = 0;
                cStateMachine_ChangeState(self->brain, 1, 0);
            }
            self->xE8 = 4;
        } else if ((unsigned char)msg->kind == 0) {
            int id = self->threat;
            Thing* o = nGobjManager_LookupGOBJ_cObjectIdR(&id);
            if (o) {
                char e0[0xC];
                V4 gp = o->GetPos();
                V4 pos;
                V4 tgt;
                void* svc = cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr);
                if (!cPathSystem_IsRequestBeingProcessed(svc, self->obj)) {
                    GObj* ob;
                    cNodePickerParameters_ctor_float_float_bool(0.0f, -10000.0f, e0, 0);
                    /* m.r[3] read as a 128-bit lq (no C spelling), stored through a C quad store */
                    { Mat m = self->obj->GetMatrix(); V4* d = &pos; Mat* pm = &m; V4* s = &pm->r[3]; __int128 x; asm { .set reorder; lq x, 0(s) } *(__int128*)d = x; }
                    QCopy(&tgt, &gp);
                    ob = self->obj;
                    cPathSystem_RequestNodeIndexFromGroup(10000.0f, svc, ob, e0, &pos, &tgt, cPathNavigator_GetGroupIndexForPatrolPath(self->region), 6, 2, -1);
                    self->x13F = 2;
                }
            }
            {
                float t = self->Alert(3);
                if (self->alertLevel < 11) {
                    self->alertTime = t;
                    self->alertLevel = 10;
                    self->b6 = 0;
                }
            }
            self->xE8 = 4;
            handled = 1;
        } else if ((unsigned char)msg->kind == 1) {
            if (self->alertLevel < 11)
                self->alertLevel = 10;
            handled = 1;
        }
    }
    return handled;
}
#undef nGobjManager_LookupGOBJ_cObjectIdR /* merge_units */
static inline void merge_flush_func_001535E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001535E0 */

/* merge_units: begin func_00153860 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma exceptions off

struct Ret_00153860 { int w[4]; Ret_00153860() {} };
struct VObj_00153860 {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual Ret_00153860 Get(); /* +0xE4 */
};

extern "C" Ret_00153860 cGOBJ_GetLosPosition(VObj_00153860* obj)
{
    return obj->Get();
}
static inline void merge_flush_func_00153860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00153860 */
