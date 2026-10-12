#include "types.h"
typedef struct { void* vtable; char pad[0x2C]; } Event001C7500;
extern char D_004F2CE8[];
extern void Message_GetScriptTypeKey();
extern void cStopAllQuipsMsg_dtor();
extern void cStopAllQuipsMsg_v01();
extern void cStopAllQuipsMsg_v04();
extern void cStopAllQuipsMsg_v05();
extern void func_002823E0();
void * const D_004DAC50[8] = { (void*)0x0, (void*)0x0, (void*)cStopAllQuipsMsg_dtor, (void*)cStopAllQuipsMsg_v01, (void*)func_002823E0, (void*)Message_GetScriptTypeKey, (void*)cStopAllQuipsMsg_v04, (void*)cStopAllQuipsMsg_v05 };
extern char D_004DCF10[];
extern void Event_Construct(Event001C7500* ev, void* desc);
extern void Global_StopAllQuips(int a);
extern void cMessage_dtor(Event001C7500* ev, int flags);
/* Build a temporary event, run Global_StopAllQuips(1) and destroy the event. */
void func_001C7500(void)
{
    Event001C7500 ev;
    Event_Construct(&ev, D_004F2CE8);
    ev.vtable = ((char*)D_004DAC50);
    Global_StopAllQuips(1);
    ev.vtable = D_004DCF10;
    cMessage_dtor(&ev, 0);
}
