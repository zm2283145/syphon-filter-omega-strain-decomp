/*
 * SFOGame/Source/npc: 1 file, 0014D4D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0014D4D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int cNPC_SetMoveMode(cNPC* npc, int a1, int a2);

/* vtable slot 0x53: StopMovement. */
int cNPC_StopMovement(cNPC* self, int a1, float f12) {
    int result;

    result = cNPC_SetMoveMode(self, 0, a1);
    self->unk07C = f12;
    self->unk168 = 0;
    return result;
}
static inline void merge_flush_func_0014D4D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014D4D0 */
