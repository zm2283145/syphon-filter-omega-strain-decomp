/*
 * SFOGame/Source/Loader: 2 files, 001C4570-001C4650
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C4570 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "tree_node_free.h"
extern "C" { char D_0049F378[] = "allocator.hh"; }
DEFINE_TREE_NODE_FREE(std_tree_pair_cString16N_value_compare_cAllocator_pair_destroy_nodeP, D_0049F378)
static inline void merge_flush_func_001C4570(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C4570 */

/* merge_units: begin func_001C4650 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */


/* Construct an empty map with comparator byte *cmp. */
Map* std_tree_pair_cString16N_value_compare_cAllocator_pair_ctor_valuecompareR_cAllocatorR(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
static inline void merge_flush_func_001C4650(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C4650 */
