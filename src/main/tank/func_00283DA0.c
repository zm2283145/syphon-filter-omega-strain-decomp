#include "types.h"
typedef struct { void* vtable; char pad[0x24]; int value; char pad2[4]; } Msg;
extern char D_00506248[];
extern char D_004DCF70[];
extern char D_004DCF10[];
extern void Event_Construct(Msg* m, void* type);
extern void func_00283E10(Msg* m, void* target);
extern void cMessage_dtor(Msg* m, int flags);
/* Builds a temporary message (value -1), sends it to target, then destroys it. */
void func_00283DA0(void* target)
{
    Msg msg;
    Event_Construct(&msg, D_00506248);
    msg.vtable = D_004DCF70;
    msg.value = -1;
    func_00283E10(&msg, target);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
