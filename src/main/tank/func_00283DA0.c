#include "types.h"
typedef struct { void* vtable; char pad[0x24]; int value; char pad2[4]; } Msg;
extern char g_NetCreateTankMsgKey[];
extern char cNetCreateTankMsg_vtable[];
extern char D_004DCF10[];
extern void Event_Construct(Msg* m, void* type);
extern void cNetCreateTankMsg_Apply(Msg* m, void* target);
extern void cMessage_dtor(Msg* m, int flags);
/* Builds a temporary message (value -1), sends it to target, then destroys it. */
void cNetCreateTankMsg_NetReceive(void* target)
{
    Msg msg;
    Event_Construct(&msg, g_NetCreateTankMsgKey);
    msg.vtable = cNetCreateTankMsg_vtable;
    msg.value = -1;
    cNetCreateTankMsg_Apply(&msg, target);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
