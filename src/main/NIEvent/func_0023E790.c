#include "types.h"
typedef struct { void* vtable; char pad04[0x1C]; char b20; char pad21[3]; int i24; char pad28[8]; } Msg0023E790;
extern char D_004F7C28[];
extern char D_004DC2F0[];
extern void Event_Construct(Msg0023E790* m, void* name);
extern void Event_Send(Msg0023E790* m, void* target, int a);
extern void cMessage_dtor(Msg0023E790* m, int flags);
void func_0023E790(void* target, int flag)
{
    Msg0023E790 m;
    Event_Construct(&m, D_004F7C28);
    m.vtable = D_004DC2F0;
    m.i24 = 1;
    if (!flag)
        m.b20 = 1;
    Event_Send(&m, target, 0);
    m.vtable = D_004DC2F0;
    cMessage_dtor(&m, 0);
}