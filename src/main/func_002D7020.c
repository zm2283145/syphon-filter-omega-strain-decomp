#include "types.h"
typedef struct { int h0; int h4; unsigned char b8; int iC; int i10; char name[1]; } F6ObjNet;
extern int NetRegisterMessageStart(void);
extern int Event_UnpackHeader(F6ObjNet*);
extern int NetMessageField(F6ObjNet*, void*, int, int);
extern int NetMsg_RegisterType(void*, int, void*);
extern char D_0051F0A0[];
extern void cNetNPCMsgs_NetNPCMsgsCallback(void);
unsigned char cNetNPCMsgs_InitNet(void)
{
    F6ObjNet s;
    int err;
    unsigned char ok = 0;
    err = NetRegisterMessageStart();
    if (err == 0 && Event_UnpackHeader(&s) && err == 0
        && NetMessageField(&s, &s.b8, 1, 1) == 0 && NetMessageField(&s, &s.iC, 4, 1) == 0 && NetMessageField(&s, &s.i10, 4, 1) == 0 && NetMessageField(&s, s.name, 4, 1) == 0
        && NetMsg_RegisterType(D_0051F0A0, 2, cNetNPCMsgs_NetNPCMsgsCallback) == 0) {
        ok = 1;
    }
    return ok;
}