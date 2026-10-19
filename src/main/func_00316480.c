#include "types.h"
typedef struct { int kind; int f4; int f8; int fC; int f10; } Pk316480;
typedef struct { void* vt; char p4[0x20]; int f24; int f28; int f2C; int p30; } Msg316480;
extern unsigned char D_005723C8, D_005721D0;
extern char D_0052ACB0[], D_004DE5D0[];
extern void Event_Construct(Msg316480* e, void* type);
extern void** NetMap_Lookup(int);
extern void MsgQueue_QueueClone(Msg316480*, void*, int, int);
extern void cMessage_dtor(Msg316480*, int);
#pragma push
#pragma opt_propagation off
int cNetScoreMsg_NetReceive(int a0, int a1, int a2, Pk316480* arg) {
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Msg316480 msg;
        void** obj;
        Pk316480* p = arg;
        Event_Construct(&msg, D_0052ACB0);
        msg.vt = D_004DE5D0;
        msg.f2C = p->f8;
        msg.f24 = p->fC;
        msg.f28 = p->f10;
        obj = NetMap_Lookup(p->f8);
        if (obj) MsgQueue_QueueClone(&msg, *obj, 0, 0);
        msg.vt = D_004DE5D0;
        cMessage_dtor(&msg, 0);
    }
    D_005723C8 = 0;
    return 0x14;
}
#pragma pop
