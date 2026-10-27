#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { char pad[0x10]; void* val; } Node0025E220;
typedef struct { void* vt; char p4[0x28]; int f2C; int f30; char p34[0x8]; } Evt0025E220;
typedef struct { char q0[0x4]; int a4; int a8; int aC; } Arg0025E220;
extern "C" {
extern void cMessage_ctor_cMessageNameR(Evt0025E220* e, void* type);
extern void QueueMessage_cMessageR_cSystemP_int_int(Evt0025E220* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt0025E220* e, int f);
extern char D_0055C7A0[];
extern void std_tree_pair_int_value_compare_find_intR(Node0025E220** out, void* map, int* key);
extern void std_map_int_netSystemField_end(void* out, void* map);
extern void cAssocArray_int_netSystemField_Iterator_ctor(Node0025E220** out, void* in);
extern char D_004DC7F0[];
extern char D_004F80B8[];
extern unsigned char D_005721D0;
}
static inline int Eq0025E220(Node0025E220* a, Node0025E220* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int cSwitchBodiesMsg_SwitchBodiesCallback(int a0, int a1, int a2, Arg0025E220* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Evt0025E220 e;
        int k[1];
        Node0025E220* end[1];
        Node0025E220* it[1];
        int tmp[1];
        Node0025E220* n;
        Arg0025E220* a = arg;
        cMessage_ctor_cMessageNameR(&e, D_004F80B8);
        e.vt = D_004DC7F0;
        e.f2C = a->a8;
        e.f30 = a->aC;
        k[0] = a->a4;
        std_tree_pair_int_value_compare_find_intR(it, D_0055C7A0, k);
        n = it[0];
        std_map_int_netSystemField_end(tmp, D_0055C7A0);
        cAssocArray_int_netSystemField_Iterator_ctor(end, tmp);
        if (Eq0025E220(n, end[0]) ^ 1) QueueMessage_cMessageR_cSystemP_int_int(&e, n->val, 0, 0);
        e.vt = D_004DC7F0;
        cMessage_dtor(&e, 0);
    }
    return 0x10;
}
#pragma pop
