#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
#include "vslot_pad.h"
typedef struct { int kind; int id; unsigned short h8; short pA; int fC; int f10; int f14; } Pk211700;
typedef struct { void* vt; char p4[0x14]; int f18; char p1C[8]; int f24; int f28; int f2C; int f30; char p34[4]; } Msg211700;
struct Obj211700 { VPAD8(a) VPAD2(b) virtual int Accept(Msg211700* m); };
extern "C" {
extern unsigned char D_005721D0;
extern char D_004F5440[], D_004DAF10[];
void cMessage_ctor5(Msg211700*, void*, Pk211700*);
void** NetMap_Lookup(int);
void* Object_LookupById(int*);
void MsgQueue_QueueClone(Msg211700*, void*, int, int);
void cMessage_dtor(Msg211700*, int);
}
#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" int func_00211700(int a0, int a1, int a2, Pk211700* arg) {
    NetRecvGuard g;
    Pk211700* p;
    p = arg;
    if (D_005721D0) {
        Msg211700 msg;
        void** obj;
        cMessage_ctor5(&msg, D_004F5440, p);
        msg.vt = D_004DAF10;
        msg.f24 = p->h8;
        msg.f28 = p->fC;
        msg.f2C = p->f14;
        msg.f30 = p->f10;
        obj = NetMap_Lookup(p->id);
        if (obj) {
            int id = msg.f2C;
            Obj211700* o = (Obj211700*)Object_LookupById(&id);
            if (o == 0 || (o != 0 && o->Accept(&msg))) MsgQueue_QueueClone(&msg, *obj, msg.f18, 0);
        }
        msg.vt = D_004DAF10;
        cMessage_dtor(&msg, 0);
    }
    return 0x18;
}
#pragma pop
