#pragma cplusplus on
#include "types.h"
struct Msg_23BDC0 { void* vtable; char pad04[0x18]; int size; int pad20; int target; char pad28[0x8]; };
struct Obj_23BDC0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void Toggle(int x);
    char pad[0xC];
    int id;
};
extern "C" {
extern unsigned char D_005721C8;
void Event_Construct(Msg_23BDC0* msg, void* type);
void cMessage_dtor(Msg_23BDC0* msg, int flags);
extern char D_0055D498[];
extern char D_004E0860[];
void func_003FF650(Msg_23BDC0* msg, int id, int x);
}
extern "C" void cNIEventOBJ_v18(Obj_23BDC0* self)
{
    self->Toggle(-1);
    if (D_005721C8) {
        Msg_23BDC0 msg;
        Event_Construct(&msg, D_0055D498);
        msg.vtable = D_004E0860;
        msg.target = -1;
        msg.size = 0x40;
        func_003FF650(&msg, self->id, -1);
        msg.vtable = D_004E0860;
        cMessage_dtor(&msg, 0);
    }
}