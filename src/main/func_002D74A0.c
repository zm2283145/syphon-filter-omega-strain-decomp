#include "types.h"
typedef struct { int h0; int h4; unsigned char b8; int iC; int i10; char name[16]; } F6ObjNet;
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(F6ObjNet*);
extern int NetMessageField(F6ObjNet*, void*, int, int);
extern int NetRegisterMessage(void*, int, void*);
extern char D_0051F0B8[];
extern void cNetObjectiveMsg_ObjectiveMsgCallback(void);
unsigned char cNetObjectiveMsg_InitNet(void)
{
    F6ObjNet s;
    int err;
    unsigned char ok = 0;
    err = NetRegisterMessageStart();
    if (err == 0 && cMessage_RegisterFields(&s) && err == 0
        && NetMessageField(&s, &s.iC, 4, 1) == 0
        && NetMessageField(&s, &s.b8, 1, 1) == 0
        && NetMessageField(&s, &s.i10, 4, 1) == 0
        && NetMessageField(&s, s.name, 1, 16) == 0
        && NetRegisterMessage(D_0051F0B8, 2, cNetObjectiveMsg_ObjectiveMsgCallback) == 0) {
        ok = 1;
    }
    return ok;
}