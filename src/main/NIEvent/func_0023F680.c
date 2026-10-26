/* Net receive handler: look up the object by id and (de)activate its event camera,
   then re-broadcast a toggle event when hosting. */
#pragma cplusplus on
#include "types.h"
#include "net_recv_guard.h"
#include "npc_auth.h"
typedef struct { void* vt; char p4[0x20]; unsigned char b24; char p25[0x3]; } EvF680;
typedef struct { char p0[0xC]; int id; char p10[0x50]; int kind; char p64[0xDC]; void* cam; } ObjF680;
typedef struct { char pad[0x10]; ObjF680* val; } NodeF680;
typedef struct { char q0[0x4]; int id; unsigned char off; } ArgF680;
extern "C" {
extern void Event_Construct(EvF680* e, void* type);
extern void Transport_Send(int target, EvF680* e, int a, int b);
extern void cMessage_dtor(EvF680* e, int f);
extern void cNIEventOBJ_ActivateCamera(void* c);
extern void cNIEventOBJ_DeactivateCamera(void* c);
extern char D_0055C7A0[];
extern void std_tree_pair_int_value_compare_find_intR(NodeF680** out, void* map, int* key);
extern void std_map_int_netSystemField_end(void* out, void* map);
extern void cAssocArray_int_netSystemField_Iterator_ctor(NodeF680** out, void* in);
extern char D_004DC2D0[];
extern char D_004F7C38[];
extern unsigned char D_005721D0;
}
static inline int EqF680(NodeF680* a, NodeF680* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int cNICameraMsg_NICameraCallback(int a0, int a1, int a2, ArgF680* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        int k[1];
        NodeF680* end[1];
        NodeF680* it[1];
        int tmp[1];
        NodeF680* n;
        ArgF680* a = arg;
        k[0] = a->id;
        std_tree_pair_int_value_compare_find_intR(it, D_0055C7A0, k);
        n = it[0];
        std_map_int_netSystemField_end(tmp, D_0055C7A0);
        cAssocArray_int_netSystemField_Iterator_ctor(end, tmp);
        if (EqF680(n, end[0]) ^ 1) {
            ObjF680* o = n->val;
            if (o) {
                if (!a->off) {
                    if (o->kind == 5 && o->cam) {
                        cNIEventOBJ_ActivateCamera(o->cam);
                        if (g_IsMultiplayer && NpcAuth_IsLocal()) {
                            EvF680 e;
                            Event_Construct(&e, D_004F7C38);
                            e.vt = D_004DC2D0;
                            e.b24 = 0;
                            Transport_Send(o->id, &e, -1, -1);
                            e.vt = D_004DC2D0;
                            cMessage_dtor(&e, 0);
                        }
                    }
                } else {
                    if (o->kind == 5 && o->cam) {
                        cNIEventOBJ_DeactivateCamera(o->cam);
                        if (g_IsMultiplayer && NpcAuth_IsLocal()) {
                            EvF680 e;
                            Event_Construct(&e, D_004F7C38);
                            e.vt = D_004DC2D0;
                            e.b24 = 1;
                            Transport_Send(o->id, &e, -1, -1);
                            e.vt = D_004DC2D0;
                            cMessage_dtor(&e, 0);
                        }
                    }
                }
            }
        }
    }
    return 0xC;
}
#pragma pop
