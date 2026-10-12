#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { int f0; int f4; signed char f8; char p9[3]; int fC; int f10; int f14; } Pk2D7190;
typedef struct { void* vt; char p4[0x20]; int f24; int f28; signed char f2C; char p2D[3]; int f30; int f34; int f38; } Msg2D7190;
extern "C" {
extern unsigned char D_005721D0;
extern unsigned char D_004FFBA0;
extern char D_0051F0A8[], D_004DE4D0[];
extern void Event_Construct(Msg2D7190* e, void* type);
extern void** NetMap_Lookup(int);
extern void func_002D63E0(void*, int, int, int, int);
extern void cMessage_dtor(Msg2D7190*, int);
}
#pragma push
#pragma opt_propagation off
extern "C" int func_002D7190(int a0, int a1, int a2, Pk2D7190* arg) {
    NetRecvGuard g;
    if (D_005721D0 && D_004FFBA0 != 0x14) {
        Msg2D7190 msg;
        void** obj;
        Pk2D7190* p = arg;
        Event_Construct(&msg, D_0051F0A8);
        msg.vt = D_004DE4D0;
        msg.f24 = p->f0;
        msg.f28 = p->f4;
        msg.f2C = p->f8;
        msg.f30 = p->fC;
        msg.f34 = p->f10;
        msg.f38 = p->f14;
        obj = NetMap_Lookup(p->f4);
        if (obj && *obj) func_002D63E0(*obj, p->f8, p->fC, p->f10, p->f14);
        msg.vt = D_004DE4D0;
        cMessage_dtor(&msg, 0);
    }
    return 0x18;
}
#pragma pop
