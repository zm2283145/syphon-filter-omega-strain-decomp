/*
 * SFOGame/Source/NetGeneratorCreate: 2 files, 002D1100-002D11D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D1100 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"
#define MP_F(p, off) (*(float*)((char*)(p) + (off)))
#define PACK_BODY(e, b) MP_I(b, 0x8) = MP_I(e, 0x50); MP_I(b, 0xC) = MP_I(e, 0x54); MP_I(b, 0x10) = MP_I(e, 0x58); MP_F(b, 0x14) = MP_F(e, 0x40); MP_F(b, 0x18) = MP_F(e, 0x44); MP_F(b, 0x1C) = MP_F(e, 0x48); MP_F(b, 0x20) = MP_F(e, 0x30); MP_F(b, 0x24) = MP_F(e, 0x34); MP_F(b, 0x28) = MP_F(e, 0x38); MP_I(b, 0x2C) = MP_I(e, 0x5C); MP_I(b, 0x30) = MP_I(e, 0x60);
DEFINE_MESSAGE_PACK(cNetGeneratorCreateMsg_Pack, 0x34, D_0051F060, PACK_BODY)
static inline void merge_flush_func_002D1100(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D1100 */

/* merge_units: begin func_002D11D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_recv_guard.h"
typedef struct { int a; void* b; } Ent2D11D0;
typedef struct { void* vt; char p4[0x74]; } Evt2D11D0;
typedef struct { int kind; int id; } Arg2D11D0;
extern "C" {
extern void cNetGeneratorCreateMsg_ctor(Evt2D11D0* e, Arg2D11D0* a);
extern void QueueMessage_cMessageR_cSystemP_int_int(Evt2D11D0* e, void* obj, int a, int b);
extern void cMessage_dtor(Evt2D11D0* e, int f);
extern char D_0055C7A0[];
extern void** cNetObj_GetNetSystem(int);
extern Ent2D11D0* std_tree_pair_int_value_compare_find_or_insert(void* map, int* key);
extern char D_004DE240[];
extern unsigned char D_005721D0;
}
#pragma push
#pragma opt_propagation off
extern "C" int cNetGeneratorCreateMsg_GeneratorCreateCallback(int a0, int a1, int a2, Arg2D11D0* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Evt2D11D0 e;
        int k[1];
        Arg2D11D0* a = arg;
void* m = D_0055C7A0;
        cNetGeneratorCreateMsg_ctor(&e, a);
        if (cNetObj_GetNetSystem(a->id)) {
            k[0] = a->id;
            QueueMessage_cMessageR_cSystemP_int_int(&e, std_tree_pair_int_value_compare_find_or_insert(m, k)->b, 0, 0);
        }
        e.vt = D_004DE240;
        cMessage_dtor(&e, 0);
    }
    return 0x34;
}
#pragma pop
static inline void merge_flush_func_002D11D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D11D0 */
