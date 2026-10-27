/*
 * SFOGame/Source/Generator: 1 file, 0021D6C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0021D6C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
typedef struct { char pad[0x10]; void* val; } Node21D6C0;
typedef struct { void* vt; char p4[0x20]; void* f24; signed char f28; char p29[3]; } Evt21D6C0;
typedef struct { int f0; int id; unsigned char kind; char p9[3]; int fC; unsigned short f10; } Arg21D6C0;
extern "C" {
extern void cMessage_ctor_cMessageNameR(Evt21D6C0* e, void* type);
extern void QueueMessage_cMessageR_cSystemP_int_int(Evt21D6C0* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt21D6C0* e, int f);
extern void* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
extern char D_0055C7A0[];
extern void std_tree_pair_int_value_compare_find_intR(Node21D6C0** out, void* map, int* key);
typedef struct { void* p; } It21D6C0;
extern It21D6C0 std_map_int_netSystemField_end(void* map);
extern void cAssocArray_int_netSystemField_Iterator_ctor(Node21D6C0** out, const It21D6C0& in);
extern char D_004A4A70[];
extern char D_004DB660[];
extern char D_004DB640[];
extern char D_004DB620[];
extern char D_004DB600[];
extern unsigned char D_005721D0;
}
static inline int Eq21D6C0(Node21D6C0* a, Node21D6C0* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
#pragma opt_lifetimes off
extern "C" int cGeneratorMessageBase_GeneratorMessageBaseCallback(int a0, int a1, int a2, Arg21D6C0* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        int k[1];
        Node21D6C0* end[1];
        Node21D6C0* it[1];
        Evt21D6C0* p;
        Arg21D6C0* a = arg;
        Node21D6C0* n;

        k[0] = a->id;
        std_tree_pair_int_value_compare_find_intR(it, D_0055C7A0, k);
        n = it[0];
        cAssocArray_int_netSystemField_Iterator_ctor(end, std_map_int_netSystemField_end(D_0055C7A0));
        if (Eq21D6C0(n, end[0]) ^ 1) {
            switch (a->kind) {
            case 0: {
                Evt21D6C0 e;
                int id;
                p = &e;
                cMessage_ctor_cMessageNameR(p, D_004A4A70);
                e.vt = D_004DB660;
                id = a->fC;
                p->f24 = nGobjManager_LookupGOBJ_cObjectIdR(&id);
                QueueMessage_cMessageR_cSystemP_int_int(p, n->val, 0, 0);
                e.vt = D_004DB660;
                cMessage_dtor(p, 0);
                break;
            }
            case 1: {
                Evt21D6C0 e;
                int id;
                p = &e;
                cMessage_ctor_cMessageNameR(p, D_004A4A70);
                e.vt = D_004DB660;
                id = a->fC;
                p->f24 = nGobjManager_LookupGOBJ_cObjectIdR(&id);
                e.vt = D_004DB640;
                QueueMessage_cMessageR_cSystemP_int_int(p, n->val, 0, 0);
                e.vt = D_004DB660;
                cMessage_dtor(p, 0);
                break;
            }
            case 2: {
                Evt21D6C0 e;
                int id;
                p = &e;
                cMessage_ctor_cMessageNameR(p, D_004A4A70);
                e.vt = D_004DB660;
                id = a->fC;
                p->f24 = nGobjManager_LookupGOBJ_cObjectIdR(&id);
                e.vt = D_004DB620;
                QueueMessage_cMessageR_cSystemP_int_int(p, n->val, 0, 0);
                e.vt = D_004DB660;
                cMessage_dtor(p, 0);
                break;
            }
            case 3: {
                Evt21D6C0 e;
                int id;
                p = &e;
                cMessage_ctor_cMessageNameR(p, D_004A4A70);
                e.vt = D_004DB660;
                id = a->fC;
                p->f24 = nGobjManager_LookupGOBJ_cObjectIdR(&id);
                e.vt = D_004DB600;
                e.f28 = a->f10;
                QueueMessage_cMessageR_cSystemP_int_int(p, n->val, 0, 0);
                e.vt = D_004DB660;
                cMessage_dtor(p, 0);
                break;
            }
            }
        }
    }
    return 0x14;
}
#pragma pop
static inline void merge_flush_func_0021D6C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021D6C0 */
