#include "types.h"

/* Stack message object: vtable followed by the base message data. */
typedef struct Msg {
    void* vtable;
    char data[0x2C];
} Msg;

extern char D_004F7EA0[];
extern char D_004DC480[];        /* derived message vtable */
extern char D_004DCF10[]; /* base message vtable */
extern void Event_Construct(Msg* msg, void* name);
extern void func_00258860(Msg* msg, void* target);
extern void cMessage_dtor(Msg* msg, int flags);

/* Builds a temporary message, sends it to target, then destroys it. */
void func_00258B50(void* target) {
    Msg msg;
    Event_Construct(&msg, D_004F7EA0);
    msg.vtable = D_004DC480;
    func_00258860(&msg, target);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
