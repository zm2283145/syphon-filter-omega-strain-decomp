/*
 * main/npc: range (2 files, 0014D610-0014D670)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop
#include "types.h"

/* merge_units: begin func_0014D610 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cAIMessage_dtor, D_004D9340, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0014D610 */

/* merge_units: begin func_0014D670 */
#pragma push /* merge_units */
typedef struct { char pad[0x60]; float x60; } NpcB1;
int cNPC_GetTravelSpeed_void(NpcB1* n) {
    float f = n->x60;
    int r;
    if (f >= 0.0005f) {
        if (f < 0.25f) r = 1;
        else if (f > 0.75f) r = 3;
        else r = 2;
    } else r = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014D670(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014D670 */
