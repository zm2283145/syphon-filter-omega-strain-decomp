#include "types.h"
typedef struct { void* vtable; char pad[0x18]; int flags; char pad2[4]; int target; char pad3[8]; } Msg_261C90;
typedef struct { char pad[0x10]; int id; char pad14[0x18]; unsigned char state; } S_261C90;
extern char g_cDisableMsgClass[];
extern char D_004E0860[];
extern void Event_Construct(Msg_261C90* m, void* type);
extern void func_003FF650(Msg_261C90* m, int id, int x);
extern void cMessage_dtor(Msg_261C90* m, int flags);
void cFireObj_v18(S_261C90* s)
{
    Msg_261C90 msg;
    Event_Construct(&msg, g_cDisableMsgClass);
    msg.vtable = D_004E0860;
    msg.target = -1;
    msg.flags = 0x40;
    func_003FF650(&msg, s->id, -1);
    s->state = 0;
    msg.vtable = D_004E0860;
    cMessage_dtor(&msg, 0);
}