#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { char pad[0x10]; void* val; } Node0022E4F0;
typedef struct { void* vt; char p4[0x28]; } Evt0022E4F0;
typedef struct { char q0[0x4]; int a4; } Arg0022E4F0;
extern "C" {
extern void Event_Construct(Evt0022E4F0* e, void* type);
extern void MsgQueue_QueueClone(Evt0022E4F0* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt0022E4F0* e, int f);
extern char D_0055C7A0[];
extern void func_001BB080(Node0022E4F0** out, void* map, int* key);
extern void func_0021D360(void* out, void* map);
extern void func_0021D350(Node0022E4F0** out, void* in);
extern char D_004DB8B0[];
extern char D_004F7938[];
extern unsigned char D_005721D0;
}
static inline int Eq0022E4F0(Node0022E4F0* a, Node0022E4F0* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int func_0022E4F0(int a0, int a1, int a2, Arg0022E4F0* arg) {
    Arg0022E4F0* a = arg;
    NetRecvGuard g;
    if (D_005721D0) {
        Evt0022E4F0 e;
        int k[1];
        Node0022E4F0* end[1];
        Node0022E4F0* it[1];
        int tmp[1];
        Node0022E4F0* n;
        Event_Construct(&e, D_004F7938);
        e.vt = D_004DB8B0;
        k[0] = a->a4;
        func_001BB080(it, D_0055C7A0, k);
        n = it[0];
        func_0021D360(tmp, D_0055C7A0);
        func_0021D350(end, tmp);
        if (Eq0022E4F0(n, end[0]) ^ 1) MsgQueue_QueueClone(&e, n->val, 0, 0);
        e.vt = D_004DB8B0;
        cMessage_dtor(&e, 0);
    }
    return 0x8;
}
#pragma pop
