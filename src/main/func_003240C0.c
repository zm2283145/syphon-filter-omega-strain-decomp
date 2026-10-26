#include "types.h"
extern int NetRegisterMessageStart(void);
extern int Event_UnpackHeader(void* p);
extern int NetMessageField(void* a, void* b, int c, int d);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern int D_0052ACF0;
extern int cNetRemoveHudObjectiveMsg_NetReceive();
unsigned char cNetRemoveHudObjectiveMsg_NetRegister(void) {
    int ok[2];
    int buf[2];
    unsigned char r = 0;
    if (NetRegisterMessageStart() == 0 && Event_UnpackHeader(buf) != 0 && NetMessageField(buf, ok, 4, 1) == 0 &&
        NetMsg_RegisterType(&D_0052ACF0, 2, cNetRemoveHudObjectiveMsg_NetReceive) == 0) {
        r = 1;
    }
    return r;
}
