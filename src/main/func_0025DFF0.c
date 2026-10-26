#include "types.h"
extern int NetRegisterMessageStart(void);
extern int Event_UnpackHeader(void* p);
extern int NetMessageField(void* a, void* b, int c, int d);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern int D_004F80A0;
extern int cRestoreBodyMsg_NetReceive();
unsigned char cRestoreBodyMsg_NetRegister(void) {
    int a[2];
    int buf[2];
    int busy;
    unsigned char r = 0;
    busy = NetRegisterMessageStart();
    if (!busy && Event_UnpackHeader(buf) && !busy && NetMessageField(buf, a, 4, 1) == 0 && NetMsg_RegisterType(&D_004F80A0, 2, cRestoreBodyMsg_NetReceive) == 0) {
        r = 1;
    }
    return r;
}





