/*
 * SFOGame/Source/WaterFx: 1 file, 002B4CE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002B4CE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * List helpers.
 */

#include "types.h"
#include "WaterFx_types.h"

/* Address of the list sentinel (end()). */
WaterListLink* details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_7(WaterList* list) {
    return &list->head;
}

/* Initializes an empty list. */
WaterList* std_list_deleter_tNode_ctor(WaterList* list) {
    list->count = 0;
    list->head.prev = &list->head;
    list->head.next = &list->head;
    return list;
}
static inline void merge_flush_func_002B4CE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B4CE0 */
