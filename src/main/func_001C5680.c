#include "types.h"
typedef struct { void* vtable; char pad04[0x18]; int size; int pad20; int target; char pad28[0x8]; } Msg_1C5680;
typedef struct { char pad[0x10]; int id; char pad14[0x18]; unsigned char state; } S_1C5680;
extern unsigned char D_005721C8;
void Event_Construct(Msg_1C5680* msg, void* type);
void cMessage_dtor(Msg_1C5680* msg, int flags);
extern char D_0055D498[];
extern char D_004E0860[];
void func_003FF650(Msg_1C5680* msg, int id, int x);
void func_001C5680(S_1C5680* self)
{
    if (D_005721C8) {
        Msg_1C5680 msg;
        Event_Construct(&msg, D_0055D498);
        msg.vtable = D_004E0860;
        msg.target = -1;
        msg.size = 0x40;
        func_003FF650(&msg, self->id, -1);
        msg.vtable = D_004E0860;
        cMessage_dtor(&msg, 0);
    }
    self->state = 0;
}