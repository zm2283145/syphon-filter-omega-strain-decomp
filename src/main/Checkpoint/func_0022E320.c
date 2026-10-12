#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { char pad[0x10]; void* val; } Node22E320;
typedef struct { void* vt; int pad[8]; int f24; int pad2[1]; } Evt22E320;
typedef struct { int pad; int id; int id2; } Arg22E320;
extern "C" {
extern void Event_Construct(Evt22E320* e, void* type);
extern void MsgQueue_QueueClone(Evt22E320* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt22E320* e, int f);
extern char D_0055C7A0[];
extern void func_001BB080(Node22E320** out, void* map, int* key);
extern void func_0021D360(void* out, void* map);
extern void func_0021D350(Node22E320** out, void* in);
extern char D_004DB890[];
extern char D_004F7940[];
extern unsigned char D_005721D0;
}
static inline int Eq22E320(Node22E320* a, Node22E320* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int func_0022E320(int a0, int a1, int a2, Arg22E320* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Evt22E320 e;
        int k[1];
Node22E320* end[1];
Node22E320* it[1];
int tmp[1];
        Node22E320* n;
        Arg22E320* a = arg;
        Event_Construct(&e, D_004F7940);
        e.vt = D_004DB890;
        e.f24 = a->id2;
        k[0] = a->id;
        func_001BB080(it, D_0055C7A0, k);
        n = it[0];
        func_0021D360(tmp, D_0055C7A0);
        func_0021D350(end, tmp);
        if (Eq22E320(n, end[0]) ^ 1) MsgQueue_QueueClone(&e, n->val, 0, 0);
        e.vt = D_004DB890;
        cMessage_dtor(&e, 0);
    }
    return 0xC;
}
#pragma pop
