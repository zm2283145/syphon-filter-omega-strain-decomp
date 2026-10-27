/*
 * SFOGame/Source/ai: 1 file, 0016CEE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016CEE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * List append: inserts value before the list end.
 */

#include "types.h"

extern int std_list_deleter_voidPtr_insert(Iter*, List*, Iter*, int);

int std_list_cTargetAwarenessPtr_push_front(List* list, int value) {
    Iter pos;
    Iter result;

    pos.p = list->last;
    return std_list_deleter_voidPtr_insert(&result, list, &pos, value);
}
static inline void merge_flush_func_0016CEE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016CEE0 */
