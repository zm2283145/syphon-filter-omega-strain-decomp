#include "types.h"
typedef struct { void* vtable; char pad[0x2C]; } Event001C7500;
extern char D_004F2CE8[];
extern char D_004DAC50[];
extern char D_004DCF10[];
extern void Event_Construct(Event001C7500* ev, void* desc);
extern void Global_StopAllQuips(int a);
extern void cMessage_dtor(Event001C7500* ev, int flags);
/* Build a temporary event, run Global_StopAllQuips(1) and destroy the event. */
void func_001C7500(void)
{
    Event001C7500 ev;
    Event_Construct(&ev, D_004F2CE8);
    ev.vtable = D_004DAC50;
    Global_StopAllQuips(1);
    ev.vtable = D_004DCF10;
    cMessage_dtor(&ev, 0);
}
