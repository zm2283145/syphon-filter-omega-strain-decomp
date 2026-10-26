#include "types.h"
extern int NetRegisterMessageStart(void);
extern int Event_UnpackHeader(void* p);
extern int NetMessageField(void* a, void* b, int c, int d);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern int D_004F80B0;
extern int cSwitchBodiesMsg_NetReceive();
unsigned char cSwitchBodiesMsg_NetRegister(void) {
    int buf[2];
    int b[1];
    int a[1];
    int busy;
    unsigned char r = 0;
    busy = NetRegisterMessageStart();
    if (!busy && Event_UnpackHeader(buf) && !busy && NetMessageField(buf, a, 4, 1) == 0 &&
        NetMessageField(buf, b, 4, 1) == 0 && NetMsg_RegisterType(&D_004F80B0, 2, cSwitchBodiesMsg_NetReceive) == 0) {
        r = 1;
    }
    return r;
}

