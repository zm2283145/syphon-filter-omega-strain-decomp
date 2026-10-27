/*
 * main/Loader: range (2 files, 001C0700-001C0720)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001C0700 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */


/* Zero-initialise a three-word vector. */
Rel* std_vector_imp_cSkaNodePtr_1_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C0700(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C0700 */

/* merge_units: begin func_001C0720 */
#pragma push /* merge_units */
extern void std_tree_pair_cString16N_value_compare_cAllocator_pair_ctor_valuecompareR_cAllocatorR(void* self, int* a, int* b);

/* Calls std_tree_pair_cString16N_value_compare_cAllocator_pair_ctor_valuecompareR_cAllocatorR with two scratch outputs (discarded); returns self. */
void* cAssocArray_cString16N_3_int_ctor(void* self) {
    int second, first;
    std_tree_pair_cString16N_value_compare_cAllocator_pair_ctor_valuecompareR_cAllocatorR(self, &first, &second);
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C0720(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C0720 */
