#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Obj2399A0 { VPAD32(a) VPAD32(b) VPAD4(c) virtual void Enable(int on); };
struct Msg2399A0 { void* vtable; char base[0x20]; int f24; char p28[8]; };
struct Ev2399A0 { char p[8]; int kind; };
extern "C" {
extern char D_004F7C30[];
extern char D_004DBEB0[];
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
}
extern "C" void func_002399A0(Ev2399A0* ev, Obj2399A0* o) {
    switch (ev->kind) {
    case 0: {
        Msg2399A0 m;
        o->Enable(0);
        Event_Construct(&m, D_004F7C30);
        m.vtable = D_004DBEB0;
        m.f24 = 1;
        Event_Send(&m, o, 0);
        m.vtable = D_004DBEB0;
        cMessage_dtor(&m, 0);
        break;
    }
    case 3: {
        Msg2399A0 m;
        Event_Construct(&m, D_004F7C30);
        m.vtable = D_004DBEB0;
        m.f24 = 0;
        Event_Send(&m, o, 0);
        m.vtable = D_004DBEB0;
        cMessage_dtor(&m, 0);
        break;
    }
    }
}
