#include "types.h"
typedef struct { void* vtable; char pad[0x2C]; } Msg;
extern char D_00506260[];
extern char D_004DCF50[];
extern char D_004DCF10[];
extern void Event_Construct(Msg* m, void* type);
extern void func_00283910(Msg* m, void* target);
extern void cMessage_dtor(Msg* m, int flags);
/* Builds a temporary message, sends it to target, then destroys it. */
void func_002838B0(void* target)
{
    Msg msg;
    Event_Construct(&msg, D_00506260);
    msg.vtable = D_004DCF50;
    func_00283910(&msg, target);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
