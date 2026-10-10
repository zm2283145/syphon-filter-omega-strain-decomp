#include "types.h"
typedef struct { void* vtable; char pad4[0x18]; int flags; char pad20[4]; int target; char pad28[8]; } Msg003CC2D0;
typedef struct { char pad[0x64]; unsigned char busy; } Obj003CC2D0;
extern char D_0055D498[];
extern char D_004E0860[];
extern void Event_Construct(Msg003CC2D0* ev, void* desc);
extern void Event_Send(Msg003CC2D0* ev, void* target, int flags);
extern void cMessage_dtor(Msg003CC2D0* ev, int flags);
/* Clear the busy flag and send a message to the object. */
void SubScript_v18(Obj003CC2D0* obj)
{
    Msg003CC2D0 ev;
    obj->busy = 0;
    Event_Construct(&ev, D_0055D498);
    ev.vtable = D_004E0860;
    ev.target = -1;
    ev.flags = 0x40;
    Event_Send(&ev, obj, 0);
    ev.vtable = D_004E0860;
    cMessage_dtor(&ev, 0);
}
