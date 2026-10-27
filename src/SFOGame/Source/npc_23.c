/*
 * SFOGame/Source/npc: 1 file, 0014D8F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0014D8F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int cNPC_DoAction(cNPC* npc, int a1, int a2, float f12);

/* vtable slot 0x52: RequestAction. */
int cNPC_RequestAction(cNPC* self, int a1, int a2) {
    return cNPC_DoAction(self, a1, a2, 0.0f);
}
static inline void merge_flush_func_0014D8F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014D8F0 */
