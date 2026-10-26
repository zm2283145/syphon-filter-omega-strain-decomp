/*
 * main/NIEvent: range (2 files, 0023F920-0023F9A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "message_pack.h"
#pragma push
#pragma cplusplus on
#include "net_recv_guard.h"
#pragma pop

/* merge_units: begin func_0023F920 */
#pragma push /* merge_units */
#define PACK_PRE(e) MP_I(e, 0x1C) = 0x40;
#define PACK_BODY(e, b) MP_S(b, 8) = MP_S(e, 0x24);

DEFINE_MESSAGE_PACK_PRE(cNICameraMsg_Pack, 12, D_004F7C48, PACK_PRE, PACK_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_0023F920 */

/* merge_units: begin func_0023F9A0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x10]; void* val; } Node0023F9A0;
typedef struct { void* vt; char p4[0x20]; int f24; char p28[0x4]; } Evt0023F9A0;
typedef struct { char q0[0x4]; int a4; int a8; } Arg0023F9A0;
extern "C" {
extern void Event_Construct(Evt0023F9A0* e, void* type);
extern void MsgQueue_QueueClone(Evt0023F9A0* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt0023F9A0* e, int f);
extern char D_0055C7A0[];
extern void std_tree_pair_int_value_compare_find_intR(Node0023F9A0** out, void* map, int* key);
extern void std_map_int_netSystemField_end(void* out, void* map);
extern void cAssocArray_int_netSystemField_Iterator_ctor(Node0023F9A0** out, void* in);
extern char D_004DC2F0[];
extern char D_004F7C28[];
extern unsigned char D_005721D0;
}
static inline int Eq0023F9A0(Node0023F9A0* a, Node0023F9A0* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int cNIShuttle_NIShuttleCallback(int a0, int a1, int a2, Arg0023F9A0* arg) {
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
        std_tree_pair_int_value_compare_find_intR(it, D_0055C7A0, k);
        n = it[0];
        std_map_int_netSystemField_end(tmp, D_0055C7A0);
        cAssocArray_int_netSystemField_Iterator_ctor(end, tmp);
        if (Eq0023F9A0(n, end[0]) ^ 1) MsgQueue_QueueClone(&e, n->val, 0, 0);
        e.vt = D_004DC2F0;
        cMessage_dtor(&e, 0);
    }
    return 0xC;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023F9A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023F9A0 */
