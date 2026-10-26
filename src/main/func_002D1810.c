#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { char pad[0x10]; void* val; } Node2D1810;
typedef struct { int a; void* b; } Ent2D1810;
typedef struct { void* vt; char p4[0x28]; int f2C; int f30; char p34[4]; } Evt2D1810;
typedef struct { int kind; int id; int f8; int fC; } Arg2D1810;
extern "C" {
extern void Event_Construct(Evt2D1810* e, void* type);
extern void MsgQueue_QueueClone(Evt2D1810* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt2D1810* e, int f);
extern char D_0055C7A0[];
extern void std_tree_pair_int_value_compare_find_intR(Node2D1810** out, void* map, int* key);
extern void std_map_int_netSystemField_end(void* out, void* map);
extern void cAssocArray_int_netSystemField_Iterator_ctor(Node2D1810** out, void* in);
extern Ent2D1810* NetRecvMap_Insert(void* map, int* key);
extern char D_004DE260[];
extern char D_0051F068[];
extern unsigned char D_005721D0;
}
static inline int Eq2D1810(Node2D1810* a, Node2D1810* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int cNetGeneratorDeleteMsg_GeneratorDeleteCallback(int a0, int a1, int a2, Arg2D1810* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Evt2D1810 e;
        int k[1];
Node2D1810* end[1];
int k2[1];
Node2D1810* it[1];
int tmp[1];
        Node2D1810* n;
        Arg2D1810* a = arg;
        void* m = D_0055C7A0;
        Event_Construct(&e, D_0051F068);
        e.vt = D_004DE260;
        e.f2C = a->f8;
        e.f30 = a->fC;
        k[0] = a->id;
        std_tree_pair_int_value_compare_find_intR(it, m, k);
        n = it[0];
        std_map_int_netSystemField_end(tmp, m);
        cAssocArray_int_netSystemField_Iterator_ctor(end, tmp);
        if (Eq2D1810(n, end[0]) ^ 1) {
            k2[0] = a->id;
            MsgQueue_QueueClone(&e, NetRecvMap_Insert(m, k2)->b, 0, 0);
        }
        e.vt = D_004DE260;
        cMessage_dtor(&e, 0);
    }
    return 0x10;
}
#pragma pop
