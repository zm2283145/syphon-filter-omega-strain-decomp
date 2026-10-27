#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { char pad[0xC]; int fC; } Obj0042CCC0;
typedef struct { void* vt; char p4[0x18]; int f1C; char p20[0xC]; int f2C; } Ev2_0042CCC0;
typedef struct { char pad[0x10]; Obj0042CCC0* val; } Node0042CCC0;
typedef struct { void* vt; char p4[0x18]; int f1C; char p20[0xC]; int f2C; char p30[0xC]; } Evt0042CCC0;
typedef struct { char q0[0x4]; int a4; int a8; } Arg0042CCC0;
extern "C" {
extern void cMessage_ctor_cMessageNameR(Evt0042CCC0* e, void* type);
extern void QueueMessage_cMessageR_cSystemP_int_int(Evt0042CCC0* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt0042CCC0* e, int f);
extern char D_0055C7A0[];
extern void std_tree_pair_int_value_compare_find_intR(Node0042CCC0** out, void* map, int* key);
extern void std_map_int_netSystemField_end(void* out, void* map);
extern void cAssocArray_int_netSystemField_Iterator_ctor(Node0042CCC0** out, void* in);
extern char D_004E0EA0[];
extern char D_00582680[];
extern unsigned char D_005721D0;
}
static inline int Eq0042CCC0(Node0042CCC0* a, Node0042CCC0* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int cNetActivateAndControlMsg_ActivateAndControlCallback(int a0, int a1, int a2, Arg0042CCC0* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Evt0042CCC0 e;
        int k[1];
        Node0042CCC0* end[1];
        Node0042CCC0* it[1];
        int tmp[1];
        Node0042CCC0* n;
        Arg0042CCC0* a = arg;
        cMessage_ctor_cMessageNameR(&e, D_00582680);
        e.vt = D_004E0EA0;
        e.f2C = a->a8;
        k[0] = a->a4;
        std_tree_pair_int_value_compare_find_intR(it, D_0055C7A0, k);
        n = it[0];
        std_map_int_netSystemField_end(tmp, D_0055C7A0);
        cAssocArray_int_netSystemField_Iterator_ctor(end, tmp);
        if (Eq0042CCC0(n, end[0]) ^ 1) {
            Obj0042CCC0* o = n->val;
            if (o) {
                Ev2_0042CCC0 e2;
                int v = o->fC;
                cMessage_ctor_cMessageNameR((Evt0042CCC0*)&e2, D_00582680);
                e2.vt = D_004E0EA0;
                e2.f1C = 0x40;
                e2.f2C = v;
                QueueMessage_cMessageR_cSystemP_int_int((Evt0042CCC0*)&e2, o, 0, 0);
                e2.vt = D_004E0EA0;
                cMessage_dtor((Evt0042CCC0*)&e2, 0);
            }
        }
        e.vt = D_004E0EA0;
        cMessage_dtor(&e, 0);
    }
    return 0xC;
}
#pragma pop
