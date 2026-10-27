/*
 * Libs/SFOLib/Source/NPCInfoObject: 1 file, 00434BB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00434BB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: NPCInfoObject.cc.
 */

#include "npc_types.h"

extern Iter* std_list_deleter_voidPtr_insert(Iter* out, Tree* t, Iter* hint, int value);

/* map insert(value): inserts with an end() hint, result iterator in it[1]. */
Iter* std_list_tNPCInfoPtr_push_back(Tree* t, int value) {
    Iter it[2];

    it[0].p = &t->header;
    return std_list_deleter_voidPtr_insert(&it[1], t, &it[0], value);
}
static inline void merge_flush_func_00434BB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00434BB0 */
