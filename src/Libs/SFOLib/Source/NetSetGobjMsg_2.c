/*
 * Libs/SFOLib/Source/NetSetGobjMsg: 3 files, 00431BC0-00431C50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00431BC0 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"
#define PACK_BODY(e, b) MP_U(b, 0x8) = MP_S(e, 0x24); MP_I(b, 0xC) = MP_I(e, 0x28); MP_I(b, 0x10) = MP_I(e, 0x2C);

DEFINE_MESSAGE_PACK(cNetSetGobjMsg_Pack, 20, D_00582748, PACK_BODY)
static inline void merge_flush_func_00431BC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00431BC0 */

/* merge_units: begin func_00431C50 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "message_clone.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "net_recv_guard.h"
#pragma pop

#pragma cplusplus on

extern "C" char D_004E0F00[];

struct Msg_0021C830 : ClonedMessageBase {
    int a24;
    char b28;
};

#define CLONE_BODY(p, s) p->vtable = D_004E0F00; p->a24 = s->a24; p->b28 = s->b28;

extern "C" {
char D_004BFC50[] = "NetTerrainActivation.hh";
}
DEFINE_MESSAGE_CLONE(cNetTerrainActivation_Clone, Msg_0021C830, 0x2C, D_004BFC50, 0x17, CLONE_BODY)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00431C50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00431C50 */

/* merge_units: begin func_00431D60 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { int kind; int id; short f8; short fA; } Pk431D60;
extern "C" {
extern unsigned char D_005721D0;
void* nGobjManager_LookupGOBJ_cObjectIdR(int*);
void cNetObjectMgr_TerrainActivation(void*);
void cNetObjectMgr_RemoveFromTerrainActivation(void*);
}
#pragma push
#pragma opt_propagation off
extern "C" int cNetTerrainActivation_NetTerrainActivationCallback(int a0, int a1, int a2, Pk431D60* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Pk431D60* p = arg;
        int id = p->id;
        void* o = nGobjManager_LookupGOBJ_cObjectIdR(&id);
        if (o) {
            if (p->fA == 0) cNetObjectMgr_TerrainActivation(o);
            else cNetObjectMgr_RemoveFromTerrainActivation(o);
        }
    }
    return 0xC;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00431D60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00431D60 */
