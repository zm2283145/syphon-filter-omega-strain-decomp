#include "types.h"
typedef struct { void* vtable; char pad[0x20]; int value; char pad2[8]; } Msg;
typedef struct { int value; void* target; } S;
extern char D_00542B68[];
extern char D_004DFBD0[];
extern void Event_Construct(Msg* m, void* type);
extern void Event_Send(Msg* m, void* target, int immediate);
extern void cMessage_dtor(Msg* m, int flags);
/* Sends an immediate message carrying s->value to s->target. */
void func_003ACF60(S* s)
{
    Msg msg;
    int value = s->value;
    Event_Construct(&msg, D_00542B68);
    msg.value = value;
    msg.vtable = D_004DFBD0;
    Event_Send(&msg, s->target, 1);
    msg.vtable = D_004DFBD0;
    cMessage_dtor(&msg, 0);
}
