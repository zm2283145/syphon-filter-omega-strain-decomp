/*
 * main/Checkpoint: range (3 files, 0022E490-0022E5E0)
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

/* merge_units: begin func_0022E490 */
#pragma push /* merge_units */
#define PACK_BODY(e, b) 

DEFINE_MESSAGE_PACK(cNotifyCheckpointMsg_v02, 8, D_004F7950, PACK_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_0022E490 */

/* merge_units: begin func_0022E4F0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x10]; void* val; } Node0022E4F0;
typedef struct { void* vt; char p4[0x28]; } Evt0022E4F0;
typedef struct { char q0[0x4]; int a4; } Arg0022E4F0;
extern "C" {
extern void Event_Construct(Evt0022E4F0* e, void* type);
extern void MsgQueue_QueueClone(Evt0022E4F0* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt0022E4F0* e, int f);
extern char D_0055C7A0[];
extern void func_001BB080(Node0022E4F0** out, void* map, int* key);
extern void func_0021D360(void* out, void* map);
extern void func_0021D350(Node0022E4F0** out, void* in);
extern char D_004DB8B0[];
extern char g_NotifyCheckpointMsgClass[];
extern unsigned char D_005721D0;
}
static inline int Eq0022E4F0(Node0022E4F0* a, Node0022E4F0* b) { return a == b; }
#pragma push
#pragma bool off
#pragma opt_propagation off
extern "C" int func_0022E4F0(int a0, int a1, int a2, Arg0022E4F0* arg) {
    Arg0022E4F0* a = arg;
    NetRecvGuard g;
    if (D_005721D0) {
        Evt0022E4F0 e;
        int k[1];
        Node0022E4F0* end[1];
        Node0022E4F0* it[1];
        int tmp[1];
        Node0022E4F0* n;
        Event_Construct(&e, g_NotifyCheckpointMsgClass);
        e.vt = D_004DB8B0;
        k[0] = a->a4;
        func_001BB080(it, D_0055C7A0, k);
        n = it[0];
        func_0021D360(tmp, D_0055C7A0);
        func_0021D350(end, tmp);
        if (Eq0022E4F0(n, end[0]) ^ 1) MsgQueue_QueueClone(&e, n->val, 0, 0);
        e.vt = D_004DB8B0;
        cMessage_dtor(&e, 0);
    }
    return 0x8;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022E4F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022E4F0 */

/* merge_units: begin func_0022E5E0 */
#pragma push /* merge_units */
typedef struct { int a; char name[0x40]; } Proto0022E5E0;
extern int func_002E9A10(void* reg);
extern int func_003C9C30(void* d);
extern int func_002E9A98(void* d, void* field, int size, int count);
extern int NetMsg_RegisterType(void* type, int version, void* factory);
extern char D_004F7948[];
extern void func_0022E710(void);
unsigned char func_0022E5E0(void* reg)
{
    struct { long long file; Proto0022E5E0 p; } L;
    unsigned char ok = 0;
    if (func_002E9A10(reg) == 0 && func_003C9C30(&L.file) != 0 &&
        func_002E9A98(&L.file, &L.p.a, 4, 1) == 0 &&
        func_002E9A98(&L.file, L.p.name, 0x40, 0x40) == 0 &&
        NetMsg_RegisterType(D_004F7948, 2, func_0022E710) == 0)
        ok = 1;
    return ok;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022E5E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022E5E0 */
