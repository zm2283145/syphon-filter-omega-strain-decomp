#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { char pad[0x10]; void* val; } Node21D240;
typedef struct { void* vt; char p4[0x20]; int f24; signed char f28; char p29[3]; } Evt21D240;
typedef struct { int kind; int id; signed char b8; char p9[3]; int fC; } Arg21D240;
extern "C" {
extern void Event_Construct(Evt21D240* e, void* type);
extern void MsgQueue_QueueClone(Evt21D240* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt21D240* e, int f);
extern char D_0055C7A0[];
extern void std_tree_pair_int_value_compare_find_intR(Node21D240** out, void* map, int* key);
extern void std_map_int_netSystemField_end(void* out, void* map);
extern void cAssocArray_int_netSystemField_Iterator_ctor(Node21D240** out, void* in);
extern char D_004DB5E0[];
extern char D_004A4A78[];
extern unsigned char D_005721D0;
}
static inline int Eq21D240(Node21D240* a, Node21D240* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int cGeneratorDataMessage_GeneratorDataMessageCallback(int a0, int a1, int a2, Arg21D240* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        int k[1];
        Node21D240* end[1];
        Node21D240* it[1];
        int tmp[1];
        Arg21D240* a = arg;
Node21D240* n;

        k[0] = a->id;
        std_tree_pair_int_value_compare_find_intR(it, D_0055C7A0, k);
        n = it[0];
        std_map_int_netSystemField_end(tmp, D_0055C7A0);
        cAssocArray_int_netSystemField_Iterator_ctor(end, tmp);
        if (Eq21D240(n, end[0]) ^ 1) {
            Evt21D240 e;
            Event_Construct(&e, D_004A4A78);
            e.vt = D_004DB5E0;
            e.f28 = a->b8;
            e.f24 = a->fC;
            MsgQueue_QueueClone(&e, n->val, 0, 0);
            e.vt = D_004DB5E0;
            cMessage_dtor(&e, 0);
        }
    }
    return 0x10;
}
#pragma pop
