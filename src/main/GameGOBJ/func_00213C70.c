#include "types.h"
typedef struct { void* vt; char base[0x1C]; unsigned char action; char pad21[3]; int floor; unsigned char locked; char pad29[3]; } LiftMsg_f4;
typedef struct { char pad[0x10]; int transport; char pad14[0xF8]; int nfloors; int* locks; } Lift_f4;
extern char D_004F54C8[];
extern char D_004DAEF0[];
extern void Event_Construct(LiftMsg_f4*, void*);
extern void Transport_Send(int, LiftMsg_f4*, int, int);
extern void cMessage_dtor(LiftMsg_f4*, int);
#pragma opt_strength_reduction off
int Lift_PublishFloorLocks(Lift_f4* self, void* dest)
{
    LiftMsg_f4 msg;
    int i;
    for (i = 0; i != self->nfloors; i++) {
        if (self->locks[i] != 0) {
            Event_Construct(&msg, D_004F54C8);
            msg.vt = D_004DAEF0;
            msg.floor = i;
            msg.locked = 1;
            msg.action = 4;
            Transport_Send(self->transport, &msg, 0, (int)(void*)dest);
            msg.vt = D_004DAEF0;
            cMessage_dtor(&msg, 0);
        }
    }
    return 1;
}