#include "types.h"
typedef struct { void* vtable; char pad4[0x20]; int type; char pad28[8]; } Msg0023E720;
extern char D_004F7C28[];
extern char D_004DC2F0[];
extern void Event_Construct(Msg0023E720* ev, void* desc);
extern void Event_Send(Msg0023E720* ev, void* target, int flags);
extern void cMessage_dtor(Msg0023E720* ev, int flags);
/* Send a type-2 message to the target. */
void func_0023E720(void* target)
{
    Msg0023E720 ev;
    Event_Construct(&ev, D_004F7C28);
    ev.vtable = D_004DC2F0;
    ev.type = 2;
    Event_Send(&ev, target, 0);
    ev.vtable = D_004DC2F0;
    cMessage_dtor(&ev, 0);
}
