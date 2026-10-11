#include "types.h"
typedef struct { void* vtable; char base[0x18]; int size; char pad20[4]; unsigned char holster; char pad25[0xB]; } Msg_185630;
typedef struct { char pad[0x4C]; int classKey; char pad50[0x3524 - 0x50]; void* weapons; } G_185630;
extern int D_0049D010;
extern char D_004EF030[];
extern char D_004DA9B0[];
extern char D_004DCF10[];
extern signed char* D_005061D0;
extern void Event_Construct(Msg_185630* msg, void* name);
extern void cMessage_dtor(Msg_185630* msg, int flags);
extern void Global_ForceHolster(void* w);
void func_00185630(G_185630* g)
{
    Msg_185630 msg;
    Event_Construct(&msg, D_004EF030);
    msg.vtable = D_004DA9B0;
    msg.size = 0x40;
    msg.holster = *D_005061D0++ != 0;
    if (g && g->classKey == D_0049D010) Global_ForceHolster(g->weapons);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
