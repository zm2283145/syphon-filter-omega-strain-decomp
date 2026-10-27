#include "types.h"

typedef struct EventMsg {
    void* vtbl;
    char pad[0x2C];
} EventMsg;

extern char D_004F7C00[];
extern char D_004DBAC0[];
extern char D_004DCF10[];
extern void cMessage_ctor_cMessageNameR(EventMsg* msg, void* type);
extern void cNetSpawnLightMsg_UnpackAndProcess(EventMsg* msg, void* target);
extern void cMessage_dtor(EventMsg* msg, int flags);

/* Builds a stack event message and dispatches it to target. */
void cNetSpawnLightMsg_NetReceive(void* target) {
    EventMsg msg;
    cMessage_ctor_cMessageNameR(&msg, D_004F7C00);
    msg.vtbl = D_004DBAC0;
    cNetSpawnLightMsg_UnpackAndProcess(&msg, target);
    msg.vtbl = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
