/*
 * SFOGame/Source/netBackpackMsg: 3 files, 002814F0-00281500
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002814F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int D_005061B8;

int cNetBackpackMsg_GetMsgId(void) {
    return D_005061B8;
}
static inline void merge_flush_func_002814F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002814F0 */

/* merge_units: begin func_00281500 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_msg_clone.h"

/* Clone a network message. */
extern "C" { char D_004A9380[] = "netBackpackMsg.hh"; }
DEFINE_NET_MSG_CLONE(cNetBackpackMsg_Clone, 0x30, D_004A9380, 0x1C, D_004DCEF0,
                     NMC_B(0x24); NMC_W(0x28); NMC_W(0x2C))
static inline void merge_flush_func_00281500(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00281500 */

/* merge_units: begin func_00281620 */
#pragma push /* merge_units */
typedef struct { void* vtable; char data[0x2C]; } Visitor;

extern char D_005061B0[];
extern char D_004DCEF0[];
extern char D_004DCF10[];
extern void cMessage_ctor_cMessageNameR(Visitor* v, void* arg);
extern void cNetBackpackMsg_UnpackAndProcess(Visitor* v, void* target);
extern void cMessage_dtor(Visitor* v, int flags);

/* Constructs a temporary visitor on the stack, applies it to self and destroys it. */
void cNetBackpackMsg_NetReceive(void* self)
{
    Visitor v;
    cMessage_ctor_cMessageNameR(&v, D_005061B0);
    v.vtable = D_004DCEF0;
    cNetBackpackMsg_UnpackAndProcess(&v, self);
    v.vtable = D_004DCF10;
    cMessage_dtor(&v, 0);
}
static inline void merge_flush_func_00281620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00281620 */
