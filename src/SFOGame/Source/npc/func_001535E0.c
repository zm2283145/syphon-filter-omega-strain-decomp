#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
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
extern int D_004EE550;
int* cMessage_Name(void* ev);
Thing* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
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
