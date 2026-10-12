#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { int f0; int f4; signed char f8; unsigned char f9; unsigned char fA; char pB; int fC; int f10; float f14; float f18; int f1C; } Pk2C50E0;
typedef struct { void* vt; char p4[0x24]; int f28; float f2C; float f30; char name[16]; int f44; unsigned char b48; unsigned char b49; char p4A[2]; } Msg2C50E0;
extern "C" {
extern unsigned char D_005721D0;
extern char D_0051EE48[], D_004DE0F0[];
extern void *D_004FFC2C;
extern void Event_Construct(Msg2C50E0* e, void* type);
extern char *func_003FDAE0(int);
extern char *strncpy(char *, const char *, unsigned int);
extern void func_00242E40(void *, int *, char *, int, float, float, unsigned char, unsigned char, int);
extern void func_00242B40(void *, int *, int, unsigned char, int);
extern void cMessage_dtor(Msg2C50E0*, int);
}
#pragma push
#pragma opt_propagation off
extern "C" int func_002C50E0(int a0, int a1, int a2, Pk2C50E0* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Msg2C50E0 msg;
        Pk2C50E0* p = arg;
        Msg2C50E0* m = &msg;
        Event_Construct(m, D_0051EE48);
        msg.vt = D_004DE0F0;
        msg.f28 = -1;
        msg.f28 = p->f10;
        msg.f2C = p->f14;
        msg.f30 = p->f18;
        msg.f44 = p->f1C;
        msg.b48 = p->f9;
        msg.b49 = p->fA;
        strncpy(m->name, func_003FDAE0(p->fC), 0x10);
        if (p->f8 == 0) {
            func_00242E40(D_004FFC2C, &msg.f28, msg.name, msg.f44, msg.f2C, msg.f30, msg.b48, msg.b49, 0);
        } else {
            func_00242B40(D_004FFC2C, &msg.f28, msg.f44, msg.b48, 0);
        }
        msg.vt = D_004DE0F0;
        cMessage_dtor(&msg, 0);
    }
    return 0x20;
}
#pragma pop


