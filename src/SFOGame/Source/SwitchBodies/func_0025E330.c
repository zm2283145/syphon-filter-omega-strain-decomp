#include "types.h"
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(void* p);
extern int NetMessageField(void* a, void* b, int c, int d);
extern int NetRegisterMessage(void* t, int id, void* fn);
extern int D_004F80B0;
extern int cSwitchBodiesMsg_SwitchBodiesCallback();
unsigned char cSwitchBodiesMsg_InitNet(void) {
    int buf[2];
    int b[1];
    int a[1];
    int busy;
    unsigned char r = 0;
    busy = NetRegisterMessageStart();
    if (!busy && cMessage_RegisterFields(buf) && !busy && NetMessageField(buf, a, 4, 1) == 0 &&
        NetMessageField(buf, b, 4, 1) == 0 && NetRegisterMessage(&D_004F80B0, 2, cSwitchBodiesMsg_SwitchBodiesCallback) == 0) {
        r = 1;
    }
    return r;
}

