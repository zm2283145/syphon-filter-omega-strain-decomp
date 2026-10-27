#include "types.h"

/* Stack message object: vtable followed by the base message data. */
typedef struct Msg {
    void* vtable;
    char data[0x2C];
} Msg;

extern char D_0052ACD8[];
extern char D_004DE630[];        /* derived message vtable */
extern char D_004DCF10[]; /* base message vtable */
extern void cMessage_ctor_cMessageNameR(Msg* msg, void* name);
extern void cNetQuickChatMsg_UnpackAndProcess(Msg* msg, void* target);
extern void cMessage_dtor(Msg* msg, int flags);

/* Builds a temporary message, sends it to target, then destroys it. */
void func_00323EA0(void* target) {
    Msg msg;
    cMessage_ctor_cMessageNameR(&msg, D_0052ACD8);
    msg.vtable = D_004DE630;
    cNetQuickChatMsg_UnpackAndProcess(&msg, target);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
