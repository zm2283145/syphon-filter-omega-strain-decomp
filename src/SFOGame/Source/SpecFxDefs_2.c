/*
 * SFOGame/Source/SpecFxDefs: 2 files, 002304E0-002304F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002304E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cNetSpawnLightMsg class type accessor.
 */

#include "types.h"

extern int D_004F7C08;   /* cNetSpawnLightMsg class type id */

int cNetSpawnLightMsg_GetMsgId(void) {
    return D_004F7C08;
}
static inline void merge_flush_func_002304E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002304E0 */

/* merge_units: begin func_002304F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_msg_clone.h"
#define NMC_UB(off) (*(unsigned char*)((char*)p + (off)) = *(unsigned char*)((char*)self + (off)))
#define NMC_F(off) (*(float*)((char*)p + (off)) = *(float*)((char*)self + (off)))
extern "C" { char D_004A6E38[] = "SpecFxDefs.cc"; }
DEFINE_NET_MSG_CLONE(cNetSpawnLightMsg_Clone, 0x30, D_004A6E38, 0x6D7, D_004DBAC0, NMC_W(0x24); NMC_F(0x28); NMC_F(0x2C))
static inline void merge_flush_func_002304F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002304F0 */
