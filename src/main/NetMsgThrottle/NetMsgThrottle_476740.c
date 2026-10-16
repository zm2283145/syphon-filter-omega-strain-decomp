#pragma cplusplus on
#include "types.h"
struct Msg476740 { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3]; unsigned char b24; char p25[0xB]; };
union Arg476740 { int i; float f; void* p; };
extern "C" {
extern char D_00588038[];
extern char D_004E1AE0[];
extern char D_004DCF10[];
void* GObj_IdentityB(void* id);
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
}
extern "C" int Script_ActivateBodyToss_2(Arg476740* args) {
    bool on;
void* target;
Msg476740 t;
Msg476740 m;
    on = args[1].i != 0;
    target = GObj_IdentityB(args[0].p);
    Event_Construct(&t, D_00588038);
    t.vtable = D_004E1AE0;
    t.b24 = on;
    t.b20 = 8;
    t.f1C = 0x40;
    Event_Construct(&m, D_00588038);
    m.vtable = D_004E1AE0;
    m.b24 = on;
    Event_Send(&m, target, 0);
    m.vtable = D_004DCF10;
    cMessage_dtor(&m, 0);
    t.vtable = D_004DCF10;
    cMessage_dtor(&t, 0);
    return 0;
}
