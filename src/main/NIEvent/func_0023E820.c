#include "types.h"

typedef struct EventMsg24 {
    void* vtbl;
    char pad04[0x20];
    int unk24;     /* 0x24 */
    char pad28[8];
} EventMsg24;

extern char D_004F7C28[];
extern char D_004DC2F0[];
extern void Event_Construct(EventMsg24* msg, void* type);
extern void Event_Send(EventMsg24* msg, void* target, int flags);
extern void cMessage_dtor(EventMsg24* msg, int flags);

/* Builds a stack event message and sends it to target. */
void func_0023E820(void* target) {
    EventMsg24 msg;
    Event_Construct(&msg, D_004F7C28);
    msg.vtbl = D_004DC2F0;
    msg.unk24 = 0;
    Event_Send(&msg, target, 0);
    msg.vtbl = D_004DC2F0;
    cMessage_dtor(&msg, 0);
}
