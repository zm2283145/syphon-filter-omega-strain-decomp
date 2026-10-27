#include "types.h"
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(void* p);
extern int NetMessageField(void* a, void* b, int c, int d);
extern int NetRegisterMessage(void* t, int id, void* fn);
extern int D_0052ACF0;
extern int cNetRemoveHudObjectiveMsg_NetRemoveHudObjectiveMsgCallback();
unsigned char cNetRemoveHudObjectiveMsg_InitNet(void) {
    int ok[2];
    int buf[2];
    unsigned char r = 0;
    if (NetRegisterMessageStart() == 0 && cMessage_RegisterFields(buf) != 0 && NetMessageField(buf, ok, 4, 1) == 0 &&
        NetRegisterMessage(&D_0052ACF0, 2, cNetRemoveHudObjectiveMsg_NetRemoveHudObjectiveMsgCallback) == 0) {
        r = 1;
    }
    return r;
}
