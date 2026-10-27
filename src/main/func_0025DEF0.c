#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { char pad[0x10]; void* val; } Node0025DEF0;
typedef struct { void* vt; char p4[0x28]; int f2C; char p30[0xC]; } Evt0025DEF0;
typedef struct { char q0[0x4]; int a4; int a8; } Arg0025DEF0;
extern "C" {
extern void cMessage_ctor_cMessageNameR(Evt0025DEF0* e, void* type);
extern void QueueMessage_cMessageR_cSystemP_int_int(Evt0025DEF0* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt0025DEF0* e, int f);
extern char D_0055C7A0[];
extern void std_tree_pair_int_value_compare_find_intR(Node0025DEF0** out, void* map, int* key);
extern void std_map_int_netSystemField_end(void* out, void* map);
extern void cAssocArray_int_netSystemField_Iterator_ctor(Node0025DEF0** out, void* in);
extern char D_004DC7D0[];
extern char D_004F80A8[];
extern unsigned char D_005721D0;
}
static inline int Eq0025DEF0(Node0025DEF0* a, Node0025DEF0* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int cRestoreBodyMsg_RestoreBodyCallback(int a0, int a1, int a2, Arg0025DEF0* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Evt0025DEF0 e;
        int k[1];
        Node0025DEF0* end[1];
        Node0025DEF0* it[1];
        int tmp[1];
        Node0025DEF0* n;
        Arg0025DEF0* a = arg;
        cMessage_ctor_cMessageNameR(&e, D_004F80A8);
        e.vt = D_004DC7D0;
        e.f2C = a->a8;
        k[0] = a->a4;
        std_tree_pair_int_value_compare_find_intR(it, D_0055C7A0, k);
        n = it[0];
        std_map_int_netSystemField_end(tmp, D_0055C7A0);
        cAssocArray_int_netSystemField_Iterator_ctor(end, tmp);
        if (Eq0025DEF0(n, end[0]) ^ 1) QueueMessage_cMessageR_cSystemP_int_int(&e, n->val, 0, 0);
        e.vt = D_004DC7D0;
        cMessage_dtor(&e, 0);
    }
    return 0xC;
}
#pragma pop
