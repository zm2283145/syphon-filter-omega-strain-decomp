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


