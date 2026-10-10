#include "types.h"
typedef struct { void* vtable; char pad[0x18]; int flags; char pad2[4]; int value; char pad3[8]; } Msg;
typedef struct { char pad[0x30]; void* target; } S;
extern char D_004F7940[];
extern char D_004DB890[];
extern void Event_Construct(Msg* m, void* type);
extern void Event_Send(Msg* m, void* target, int immediate);
extern void cMessage_dtor(Msg* m, int flags);
/* Sends a respawn message to the object's target. */
void Global_ReSpawn(S* s)
{
    Msg msg;
    Event_Construct(&msg, D_004F7940);
    msg.value = 0;
    msg.vtable = D_004DB890;
    msg.flags = 0x40;
    Event_Send(&msg, s->target, 0);
    msg.vtable = D_004DB890;
    cMessage_dtor(&msg, 0);
}
