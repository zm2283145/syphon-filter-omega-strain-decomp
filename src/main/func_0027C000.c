#include "types.h"
typedef struct Msg {
    void* vtable;
    char base[0x20];
    int value;    /* 0x24 */
    char pad[0x28];
} Msg;
extern char D_00504068[];
extern char D_004DCDC0[];
extern char D_004DCF10[];
extern void Event_Construct(Msg* msg, void* name);
extern void func_0027C070(Msg* msg, void* target);
extern void cMessage_dtor(Msg* msg, int flags);
/* Builds a message on the stack and dispatches it to target. */
void func_0027C000(void* target)
{
    Msg msg;
    Event_Construct(&msg, D_00504068);
    msg.vtable = D_004DCDC0;
    msg.value = -1;
    func_0027C070(&msg, target);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
