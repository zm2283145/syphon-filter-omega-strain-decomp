#include "types.h"
typedef struct { void* vtable; char pad4[0x18]; int flags; char pad20[4]; unsigned char enable; char pad25[0xB]; } Msg00326AF0;
extern char D_0052AF10[];
extern char D_004DE6F0[];
extern char D_004DCF10[];
extern void* GObj_IdentityB(int handle);
extern void Event_Construct(Msg00326AF0* ev, void* desc);
extern void Event_Send(Msg00326AF0* ev, void* target, int flags);
extern void cMessage_dtor(Msg00326AF0* ev, int flags);
/* Script: EnableSuperJump(obj, enable). */
int Script_EnableSuperJump_2(int* args)
{
    Msg00326AF0 ev;
    unsigned char enable = args[1] != 0;
    void* obj = GObj_IdentityB(args[0]);
    Event_Construct(&ev, D_0052AF10);
    ev.vtable = D_004DE6F0;
    ev.flags = 0x40;
    ev.enable = enable;
    Event_Send(&ev, obj, 0);
    ev.vtable = D_004DCF10;
    cMessage_dtor(&ev, 0);
    return 0;
}
