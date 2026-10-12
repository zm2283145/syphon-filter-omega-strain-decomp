#include "types.h"

/* Stack message object: vtable followed by the base message data. */
typedef struct Msg {
    void* vtable;
    char data[0x2C];
} Msg;

extern char D_00572400;
extern char D_00582740[];
/* message vtable */
extern void Message_GetScriptTypeKey();
extern void func_00429BA0();
extern void func_00431750();
extern void func_00431900();
void * const D_004E0EC0[8] = { (void*)0x0, (void*)0x0, (void*)func_00429BA0, (void*)func_00431750, (void*)func_00431900, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0 };
extern void Event_Construct(Msg* msg, void* name);
extern void Transport_Send(int target, Msg* msg, int a, int b);
extern void cMessage_dtor(Msg* msg, int flags);

/* Sets the D_00572400 flag and broadcasts a message built from D_00582740. */
void func_00429B30(void) {
    Msg msg;
    D_00572400 = 1;
    Event_Construct(&msg, D_00582740);
    msg.vtable = ((char*)D_004E0EC0);
    Transport_Send(0, &msg, -1, -1);
    msg.vtable = ((char*)D_004E0EC0);
    cMessage_dtor(&msg, 0);
}
