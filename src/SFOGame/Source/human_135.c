/*
 * SFOGame/Source/human: 5 files, 001BA590-001BA860
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001BA590 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"
#define NMC_UB(off) (*(unsigned char*)((char*)p + (off)) = *(unsigned char*)((char*)self + (off)))
#define NMC_F(off) (*(float*)((char*)p + (off)) = *(float*)((char*)self + (off)))
DEFINE_NET_MSG_CLONE(cNetUpdateStatsMsg_Clone_void, 0x2C, D_0049D8D0, 0x4222, D_004DA990, NMC_W(0x24); NMC_B(0x28); NMC_B(0x29))
static inline void merge_flush_func_001BA590(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001BA590 */

/* merge_units: begin func_001BA6B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "human_types.h"

/* Network stream cursor shared by message serializers. */
extern signed char* D_005061D0;
extern int D_004EF038;

/* Serialize: write the one-byte payload. */
void cNetForceHolsterMsg_Pack(FlagMsg* msg) {
    *D_005061D0 = msg->value;
    D_005061D0 = D_005061D0 + 1;
}

/* Message type id. */
int cNetForceHolsterMsg_v05(void) {
    return D_004EF038;
}
static inline void merge_flush_func_001BA6B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001BA6B0 */

/* merge_units: begin func_001BA6F0 */
#pragma push /* merge_units */
#pragma cplusplus on
DEFINE_NET_MSG_CLONE(cNetForceHolsterMsg_Clone, 0x28, D_0049D8D0, 0x4532, D_004DA9B0, NMC_UB(0x24))
static inline void merge_flush_func_001BA6F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001BA6F0 */

/* merge_units: begin func_001BA800 */
#pragma push /* merge_units */
extern int D_004EEEA0;

/* Serialize: write the second byte, then the first. */
void cNetSetFlagMsg_v04(ByteMsg* msg) {
    *D_005061D0 = msg->b1;
    D_005061D0 = D_005061D0 + 1;
    *D_005061D0 = msg->b0;
    D_005061D0 = D_005061D0 + 1;
}

/* Message type id. */
int cNetSetFlagMsg_v05(void) {
    return D_004EEEA0;
}
static inline void merge_flush_func_001BA800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001BA800 */

/* merge_units: begin func_001BA860 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" { char D_0049ED98[] = "human.cc"; }
DEFINE_NET_MSG_CLONE(cNetUpdateStatsMsg_Clone_void_2, 0x28, D_0049ED98, 0x2FCE, D_004DA9D0, NMC_B(0x24); NMC_B(0x25))
static inline void merge_flush_func_001BA860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001BA860 */
