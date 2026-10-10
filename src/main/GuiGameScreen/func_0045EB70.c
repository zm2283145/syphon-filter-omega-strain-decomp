#include "types.h"

typedef struct EventMsg {
    void* vtbl;
    char pad[0x2C];
} EventMsg;

extern char D_00586170[];
extern char D_004E16A0[];
extern char D_004DCF10[];
extern void Event_Construct(EventMsg* msg, void* type);
extern void func_0045EC60(void);
extern void cMessage_dtor(EventMsg* msg, int flags);

/* Constructs a temporary event message around a call to func_0045EC60. */
void func_0045EB70(void) {
    EventMsg msg;
    Event_Construct(&msg, D_00586170);
    msg.vtbl = D_004E16A0;
    func_0045EC60();
    msg.vtbl = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
