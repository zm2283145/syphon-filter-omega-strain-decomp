/*
 * SFOGame/Source/npc: 2 files, 00148580-001485E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00148580 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cAIModeChangeMsg_dtor, D_004D92E0, cMessage_dtor)
static inline void merge_flush_func_00148580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00148580 */

/* merge_units: begin func_001485E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int Global_ResetNpc(cNPC* npc);

/* Script: ResetNpc(npc). */
int Script_ResetNpc(NpcScriptArgs* args) {
    Global_ResetNpc(args->npc);
    return 0;
}
static inline void merge_flush_func_001485E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001485E0 */
