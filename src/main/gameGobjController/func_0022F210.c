#include "types.h"

/* Message object (vtable, base data, parameters). */
typedef struct Msg {
    void* vtable;
    char base[0x1C];
    unsigned char flag;
    char pad[3];
    int value;
    char pad2[8];
} Msg;

extern char* D_005061D0; /* read cursor */
extern char D_004F7A08[];
extern char D_004DBA00[]; /* message vtable */
extern char D_004DCF10[]; /* base message vtable */
extern void Event_Construct(Msg* msg, void* name);
extern void Event_Send(Msg* msg, void* target, int flags);
extern void cMessage_dtor(Msg* msg, int flags);

/* Sends target a message carrying the next byte read from the D_005061D0 cursor. */
void func_0022F210(void* target) {
    Msg msg;
    Event_Construct(&msg, D_004F7A08);
    msg.vtable = D_004DBA00;
    msg.value = *D_005061D0++;
    msg.flag = 1;
    Event_Send(&msg, target, 0);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
