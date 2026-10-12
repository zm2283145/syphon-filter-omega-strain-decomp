#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { char pad[0x10]; void* val; } Node0025E220;
typedef struct { void* vt; char p4[0x28]; int f2C; int f30; char p34[0x8]; } Evt0025E220;
typedef struct { char q0[0x4]; int a4; int a8; int aC; } Arg0025E220;
extern "C" {
extern void Event_Construct(Evt0025E220* e, void* type);
extern void MsgQueue_QueueClone(Evt0025E220* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt0025E220* e, int f);
extern char D_0055C7A0[];
extern void func_001BB080(Node0025E220** out, void* map, int* key);
extern void func_0021D360(void* out, void* map);
extern void func_0021D350(Node0025E220** out, void* in);
extern char D_004DC7F0[];
extern char D_004F80B8[];
extern unsigned char D_005721D0;
}
static inline int Eq0025E220(Node0025E220* a, Node0025E220* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int func_0025E220(int a0, int a1, int a2, Arg0025E220* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Evt0025E220 e;
        int k[1];
        Node0025E220* end[1];
        Node0025E220* it[1];
        int tmp[1];
        Node0025E220* n;
        Arg0025E220* a = arg;
        Event_Construct(&e, D_004F80B8);
        e.vt = D_004DC7F0;
        e.f2C = a->a8;
        e.f30 = a->aC;
        k[0] = a->a4;
        func_001BB080(it, D_0055C7A0, k);
        n = it[0];
        func_0021D360(tmp, D_0055C7A0);
        func_0021D350(end, tmp);
        if (Eq0025E220(n, end[0]) ^ 1) MsgQueue_QueueClone(&e, n->val, 0, 0);
        e.vt = D_004DC7F0;
        cMessage_dtor(&e, 0);
    }
    return 0x10;
}
#pragma pop
