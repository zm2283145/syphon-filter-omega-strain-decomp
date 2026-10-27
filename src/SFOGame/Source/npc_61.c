/*
 * SFOGame/Source/npc: 1 file, 0015B1F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0015B1F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

extern Iter* std_list_deleter_voidPtr_insert(Iter* out, Tree* t, Iter* hint, int value);

/* map insert(value): inserts with an end() hint, result iterator in out[1]. */
Iter* std_list_cEnabledListItemPtr_push_back(Tree* t, int value) {
    Iter it[2];

    it[0].p = &t->header;
    return std_list_deleter_voidPtr_insert(&it[1], t, &it[0], value);
}
static inline void merge_flush_func_0015B1F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015B1F0 */
