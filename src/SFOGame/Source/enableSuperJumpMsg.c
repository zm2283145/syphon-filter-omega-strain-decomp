/*
 * SFOGame/Source/enableSuperJumpMsg: 2 files, 003269D0-003269E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003269D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int D_0052AF18;

/* Message type id. */
int cEnableSuperJumpMsg_GetMsgId(void) {
    return D_0052AF18;
}
static inline void merge_flush_func_003269D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003269D0 */

/* merge_units: begin func_003269E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_msg_clone.h"
#define NMC_UB(off) (*(unsigned char*)((char*)p + (off)) = *(unsigned char*)((char*)self + (off)))
#define NMC_F(off) (*(float*)((char*)p + (off)) = *(float*)((char*)self + (off)))
extern "C" { char D_004B86D0[] = "enableSuperJumpMsg.hh"; }
DEFINE_NET_MSG_CLONE(cEnableSuperJumpMsg_Clone, 0x28, D_004B86D0, 0x23, D_004DE6F0, NMC_UB(0x24))
static inline void merge_flush_func_003269E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003269E0 */
