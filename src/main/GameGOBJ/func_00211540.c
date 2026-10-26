#include "types.h"
typedef struct { int a; int b; } Desc00211540;
typedef struct { int a; char b; } Proto00211540;
extern int NetRegisterMessageStart(void* reg);
extern int Event_UnpackHeader(Desc00211540* d);
extern int NetMessageField(Desc00211540* d, void* field, int size, int count);
extern int NetMsg_RegisterType(void* type, int version, void* factory);
extern char D_004F54C0[];
extern void cNetLockElevatorMsg_NetLockElevatorMsgCallback(void);
unsigned char cNetLockElevatorMsg_InitNet(void* reg)
{
    Proto00211540 p;
    Desc00211540 d;
    unsigned char ok = 0;
    if (NetRegisterMessageStart(reg) == 0 && Event_UnpackHeader(&d) != 0 &&
        NetMessageField(&d, &p.a, 4, 1) == 0 &&
        NetMessageField(&d, &p.b, 1, 1) == 0 &&
        NetMsg_RegisterType(D_004F54C0, 2, cNetLockElevatorMsg_NetLockElevatorMsgCallback) == 0)
        ok = 1;
    return ok;
}