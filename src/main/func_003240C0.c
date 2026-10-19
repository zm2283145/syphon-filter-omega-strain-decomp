#include "types.h"
extern int func_002E9A10(void);
extern int Event_UnpackHeader(void* p);
extern int func_002E9A98(void* a, void* b, int c, int d);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern int D_0052ACF0;
extern int cNetRemoveHudObjectiveMsg_NetReceive();
unsigned char cNetRemoveHudObjectiveMsg_NetRegister(void) {
    int ok[2];
    int buf[2];
    unsigned char r = 0;
    if (func_002E9A10() == 0 && Event_UnpackHeader(buf) != 0 && func_002E9A98(buf, ok, 4, 1) == 0 &&
        NetMsg_RegisterType(&D_0052ACF0, 2, cNetRemoveHudObjectiveMsg_NetReceive) == 0) {
        r = 1;
    }
    return r;
}
