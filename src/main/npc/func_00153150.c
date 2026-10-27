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
