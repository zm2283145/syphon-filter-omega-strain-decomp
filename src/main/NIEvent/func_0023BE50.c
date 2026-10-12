#pragma cplusplus on
#include "types.h"
struct Msg_23BE50 { void* vtable; char pad04[0x18]; int size; int pad20; int target; char pad28[0x8]; };
struct Obj_23BE50 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void Toggle(int x);
    char pad[0xC];
    int id;
};
extern "C" {
extern unsigned char D_005721C8;
void Event_Construct(Msg_23BE50* msg, void* type);
void cMessage_dtor(Msg_23BE50* msg, int flags);
extern char g_cEnableMsgClass[];
extern char D_004E0880[];
void func_003FF930(Msg_23BE50* msg, int id);
}
extern "C" void cNIEventOBJ_v17(Obj_23BE50* self)
{
    self->Toggle(-1);
    if (D_005721C8) {
        Msg_23BE50 msg;
        Event_Construct(&msg, g_cEnableMsgClass);
        msg.vtable = D_004E0880;
        msg.target = -1;
        msg.size = 0x40;
        func_003FF930(&msg, self->id);
        msg.vtable = D_004E0880;
        cMessage_dtor(&msg, 0);
    }
}