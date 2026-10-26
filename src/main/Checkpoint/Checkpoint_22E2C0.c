/*
 * main/Checkpoint: range (3 files, 0022E2C0-0022E420)
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

/* merge_units: begin func_0022E2C0 */
#pragma push /* merge_units */
#define PACK_BODY(e, b) 

DEFINE_MESSAGE_PACK(cRespawnMsg_v02, 12, D_004F7958, PACK_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_0022E2C0 */

/* merge_units: begin func_0022E320 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x10]; void* val; } Node22E320;
typedef struct { void* vt; int pad[8]; int f24; int pad2[1]; } Evt22E320;
typedef struct { int pad; int id; int id2; } Arg22E320;
extern "C" {
extern void Event_Construct(Evt22E320* e, void* type);
extern void MsgQueue_QueueClone(Evt22E320* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt22E320* e, int f);
extern char D_0055C7A0[];
extern void std_tree_pair_int_value_compare_find_intR(Node22E320** out, void* map, int* key);
extern void std_map_int_netSystemField_end(void* out, void* map);
extern void cAssocArray_int_netSystemField_Iterator_ctor(Node22E320** out, void* in);
extern char D_004DB890[];
extern char D_004F7940[];
extern unsigned char D_005721D0;
}
static inline int Eq22E320(Node22E320* a, Node22E320* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int cRespawnMsg_NetReceive(int a0, int a1, int a2, Arg22E320* arg) {
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
        std_tree_pair_int_value_compare_find_intR(it, D_0055C7A0, k);
        n = it[0];
        std_map_int_netSystemField_end(tmp, D_0055C7A0);
        cAssocArray_int_netSystemField_Iterator_ctor(end, tmp);
        if (Eq22E320(n, end[0]) ^ 1) MsgQueue_QueueClone(&e, n->val, 0, 0);
        e.vt = D_004DB890;
        cMessage_dtor(&e, 0);
    }
    return 0xC;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022E320(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022E320 */

/* merge_units: begin func_0022E420 */
#pragma push /* merge_units */
extern int NetRegisterMessageStart(void* reg);
extern int Event_UnpackHeader(void* desc);
extern int NetMsg_RegisterType(void* type, int version, void* factory);
extern char D_004F7950[];
extern void cNotifyCheckpointMsg_NetReceive(void);
unsigned char cNotifyCheckpointMsg_NetRegister(void* reg)
{
    long long file;
    unsigned char ok = 0;
    if (NetRegisterMessageStart(reg) == 0 && Event_UnpackHeader(&file) != 0 &&
        NetMsg_RegisterType(D_004F7950, 2, cNotifyCheckpointMsg_NetReceive) == 0)
        ok = 1;
    return ok;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022E420(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022E420 */
