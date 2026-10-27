#include "types.h"
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(void* p);
extern int NetMessageField(void* a, void* b, int c, int d);
extern int NetRegisterMessage(void* t, int id, void* fn);
extern int D_004F80A0;
extern int cRestoreBodyMsg_RestoreBodyCallback();
unsigned char cRestoreBodyMsg_InitNet(void) {
    int a[2];
    int buf[2];
    int busy;
    unsigned char r = 0;
    busy = NetRegisterMessageStart();
    if (!busy && cMessage_RegisterFields(buf) && !busy && NetMessageField(buf, a, 4, 1) == 0 && NetRegisterMessage(&D_004F80A0, 2, cRestoreBodyMsg_RestoreBodyCallback) == 0) {
        r = 1;
    }
    return r;
}





