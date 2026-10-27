/*
 * SFOGame/Source/NetNPC: 2 files, 002D4E70-002D4FF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D4E70 */
#pragma push /* merge_units */
#include "types.h"
#include "cmessage.h"
typedef struct { CMSG_HEADER; int action; unsigned char on; char p29[7]; } Msg2D4E70;
typedef struct { char p0[5]; unsigned char ready; } Sub2D4E70;
typedef struct { char p0[0x30]; void* queue; char p34[0x1E0 - 0x34]; int active; Sub2D4E70* sub; } Self2D4E70;
typedef struct { char p0[0x2C]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char p2F[0x4C - 0x2F]; int team; } Obj2D4E70;
extern int D_004EA770;
extern char g_ActorActionMsgClass[], D_004E0840[];
extern int cAimWeapon_GetFireWeapon(Sub2D4E70*);
extern void cNetNPC_AimFire(Self2D4E70*, Obj2D4E70*);
extern void cNetNPC_AimNoFire(Self2D4E70*, Obj2D4E70*);
extern void QueueMessage_cMessageR_cSystemP_int_int(void*, void*, int, int);
void cNetNPC_AimFireWeapon(Self2D4E70* s, Obj2D4E70* o)
{
    if (o) {
        int b = o->b2D != 0 && o->b2C != 0 && !(o->b2E != 0);
        if (b || o->team == D_004EA770) {
            if (s->active && s->sub && s->sub->ready) {
                if (cAimWeapon_GetFireWeapon(s->sub)) { cNetNPC_AimFire(s, o); return; }
                else { cNetNPC_AimNoFire(s, o); return; }
            }
        }
    }
    {
        Msg2D4E70 m;
        cMessage_ctor_cMessageNameR(&m, g_ActorActionMsgClass);
        m.on = 0;
        m.vtable = D_004E0840;
        m.action = 0x3A;
        QueueMessage_cMessageR_cSystemP_int_int(&m, s->queue, 0, 0);
        m.vtable = D_004E0840;
        cMessage_dtor(&m, 0);
    }
    {
        Msg2D4E70 m;
        cMessage_ctor_cMessageNameR(&m, g_ActorActionMsgClass);
        m.on = 0;
        m.vtable = D_004E0840;
        m.action = 0x3F;
        QueueMessage_cMessageR_cSystemP_int_int(&m, s->queue, 0, 0);
        m.vtable = D_004E0840;
        cMessage_dtor(&m, 0);
    }
}
static inline void merge_flush_func_002D4E70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D4E70 */

/* merge_units: begin func_002D4FF0 */
#pragma push /* merge_units */
typedef struct { char p0[0x2C]; unsigned char b2C; unsigned char b2D; unsigned char b2E; } Obj2D4FF0;
typedef struct { char p0[0x5C]; int x5C; } Ctl2D4FF0;
typedef struct { char p0[0x2C]; int id; int val; unsigned char flag; } Ev2D4FF0;
typedef struct {
    char p0[0x30]; Obj2D4FF0* obj; char p34[0x1B0 - 0x34]; Ctl2D4FF0* ctl; char p1B4[0x1F0 - 0x1B4];
    char vec[0x1C]; int val; char p210[4]; unsigned char b0 : 1; unsigned char b1 : 1;
} Self2D4FF0;
extern int D_004ED9B8, g_CasEventMsgClass, D_0051F0C0;
extern int* cMessage_Name(Ev2D4FF0*);
extern void cNPC_HandleMessage(Self2D4FF0*, Ev2D4FF0*);
extern void cPathNavigator_Request_int_int_cVectorP(Ctl2D4FF0*, int, int, void*);
extern void cPathNavigator_ForceDestination(Ctl2D4FF0*, void*, int);
extern void cNetPathMsg_GetDestination(Ev2D4FF0*, void*);
int cNetNPC_HandleMessage(Self2D4FF0* s, Ev2D4FF0* e)
{
    int t = *cMessage_Name(e);
    if (t == D_004ED9B8 || (t = *cMessage_Name(e), t == g_CasEventMsgClass)) {
        cNPC_HandleMessage(s, e);
    } else if (t = *cMessage_Name(e), t == D_0051F0C0) {
        Obj2D4FF0* o;
        int b;
        s->val = e->val;
        if ((e->flag != 0) ^ 1) {
            cPathNavigator_Request_int_int_cVectorP(s->ctl, e->id, s->val, 0);
        } else {
            cNetPathMsg_GetDestination(e, s->vec);
            if (s->val >= 0) cPathNavigator_Request_int_int_cVectorP(s->ctl, e->id, s->val, s->vec);
            else cPathNavigator_ForceDestination(s->ctl, s->vec, s->ctl->x5C);
        }
        o = s->obj;
        b = o->b2D != 0 && o->b2C != 0 && !(o->b2E != 0);
        if (!b) s->b1 = 1;
    }
    return 1;
}
static inline void merge_flush_func_002D4FF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D4FF0 */
