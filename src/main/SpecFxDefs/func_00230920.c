#include "types.h"

typedef struct EventMsg {
    void* vtbl;
    char pad[0x2C];
} EventMsg;

extern char D_004F7C00[];
extern char D_004DBAC0[];
extern char D_004DCF10[];
extern void Event_Construct(EventMsg* msg, void* type);
extern void func_00230980(EventMsg* msg, void* target);
extern void cMessage_dtor(EventMsg* msg, int flags);

/* Builds a stack event message and dispatches it to target. */
void func_00230920(void* target) {
    EventMsg msg;
    Event_Construct(&msg, D_004F7C00);
    msg.vtbl = D_004DBAC0;
    func_00230980(&msg, target);
    msg.vtbl = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
