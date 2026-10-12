#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { char pad[0x10]; void* val; } Node0022E710;
typedef struct { void* vt; char p4[0x28]; } Evt0022E710;
typedef struct { char q0[0x4]; int a4; } Arg0022E710;
extern "C" {
extern void Event_Construct(Evt0022E710* e, void* type);
extern void MsgQueue_QueueClone(Evt0022E710* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt0022E710* e, int f);
extern char D_0055C7A0[];
extern void func_001BB080(Node0022E710** out, void* map, int* key);
extern void func_0021D360(void* out, void* map);
extern void func_0021D350(Node0022E710** out, void* in);
extern char D_004DB8D0[];
extern void cAddCheckpointMsg_ctor(Evt0022E710* e, Arg0022E710* a);
extern unsigned char D_005721D0;
}
static inline int Eq0022E710(Node0022E710* a, Node0022E710* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int func_0022E710(int a0, int a1, int a2, Arg0022E710* arg) {
    NetRecvGuard g;
    Arg0022E710* a; a = arg;
    if (D_005721D0) {
        Evt0022E710 e;
        int k[1];
        Node0022E710* end[1];
        Node0022E710* it[1];
        int tmp[1];
        Node0022E710* n;
        
        cAddCheckpointMsg_ctor(&e, a);
        k[0] = a->a4;
        func_001BB080(it, D_0055C7A0, k);
        n = it[0];
        func_0021D360(tmp, D_0055C7A0);
        func_0021D350(end, tmp);
        if (Eq0022E710(n, end[0]) ^ 1) MsgQueue_QueueClone(&e, n->val, 0, 0);
        e.vt = D_004DB8D0;
        cMessage_dtor(&e, 0);
    }
    return 0x4C;
}
#pragma pop
