#include "types.h"
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


