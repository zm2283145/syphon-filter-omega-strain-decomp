/*
 * SFOGame/Source/npc: 1 file, 001495F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001495F0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x40]; float health; } D2_Actor5B;
typedef struct { char pad[0x30]; D2_Actor5B* actor; } D2_NPC5B;
extern void cGOBJ_SetHitpoints(D2_Actor5B* a, int v, int sync);
void cNPC_SetHitPoints(D2_NPC5B* self, int v) {
    D2_Actor5B* a = self->actor;
    if ((int)a->health > 0) {
        cGOBJ_SetHitpoints(a, v, 0);
    }
}
static inline void merge_flush_func_001495F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001495F0 */
