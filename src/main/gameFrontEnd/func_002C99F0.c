#include "types.h"

typedef struct FlagMsg {
    void* vtbl;
    char pad04[0x1C];
    unsigned char flag;  /* 0x20 */
    char pad21[0xF];
} FlagMsg;

extern char D_004FFB50[];
extern char D_004D97F0[];
extern void func_0020E860(FlagMsg* msg);
extern void Event_Send(FlagMsg* msg, void* target, int flags);
extern void cMessage_dtor(FlagMsg* msg, int flags);

/* Broadcasts a flagged message. */
void func_002C99F0(void) {
    FlagMsg msg;
    func_0020E860(&msg);
    msg.flag = 1;
    Event_Send(&msg, D_004FFB50, 1);
    msg.vtbl = D_004D97F0;
    cMessage_dtor(&msg, 0);
}
