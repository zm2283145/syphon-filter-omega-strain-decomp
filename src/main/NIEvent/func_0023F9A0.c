#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { char pad[0x10]; void* val; } Node0023F9A0;
typedef struct { void* vt; char p4[0x20]; int f24; char p28[0x4]; } Evt0023F9A0;
typedef struct { char q0[0x4]; int a4; int a8; } Arg0023F9A0;
extern "C" {
extern void Event_Construct(Evt0023F9A0* e, void* type);
extern void MsgQueue_QueueClone(Evt0023F9A0* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt0023F9A0* e, int f);
extern char D_0055C7A0[];
extern void func_001BB080(Node0023F9A0** out, void* map, int* key);
extern void func_0021D360(void* out, void* map);
extern void func_0021D350(Node0023F9A0** out, void* in);
extern char D_004DC2F0[];
extern char D_004F7C28[];
extern unsigned char D_005721D0;
}
static inline int Eq0023F9A0(Node0023F9A0* a, Node0023F9A0* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int func_0023F9A0(int a0, int a1, int a2, Arg0023F9A0* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Evt0023F9A0 e;
        int k[1];
        Node0023F9A0* end[1];
        Node0023F9A0* it[1];
        int tmp[1];
        Node0023F9A0* n;
        Arg0023F9A0* a = arg;
        Event_Construct(&e, D_004F7C28);
        e.vt = D_004DC2F0;
        e.f24 = a->a8;
        k[0] = a->a4;
        func_001BB080(it, D_0055C7A0, k);
        n = it[0];
        func_0021D360(tmp, D_0055C7A0);
        func_0021D350(end, tmp);
        if (Eq0023F9A0(n, end[0]) ^ 1) MsgQueue_QueueClone(&e, n->val, 0, 0);
        e.vt = D_004DC2F0;
        cMessage_dtor(&e, 0);
    }
    return 0xC;
}
#pragma pop
