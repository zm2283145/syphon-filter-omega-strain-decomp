/*
 * main/Loader: range (2 files, 001C0500-001C0540)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "Loader_types.h"

/* merge_units: begin func_001C0500 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */


extern int std_basic_string_char_char_traits_char_ctor_basicstringR(LoaderObj* obj, int a1);

/* Initialise via std_basic_string_char_char_traits_char_ctor_basicstringR, then store a2 in unk0C. */
int std_make_pair_cString_cSkaAnimationSetP(LoaderObj* obj, int a1, int a2) {
    int result;

    result = std_basic_string_char_char_traits_char_ctor_basicstringR(obj, a1);
    obj->unk0C = a2;
    return result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C0500(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C0500 */

/* merge_units: begin func_001C0540 */
#pragma push /* merge_units */
extern void std_tree_pair_cString16N_value_compare_cAllocator_pair_ctor_valuecompareR_cAllocatorR_2(void* self, int* a, int* b);

/* Calls std_tree_pair_cString16N_value_compare_cAllocator_pair_ctor_valuecompareR_cAllocatorR_2 with two scratch outputs; returns self. */
void* cAssocArray_cString16N_2_cSkaAnimationBlendPtr_ctor(void* self)
{
    int b;
    int a;
    std_tree_pair_cString16N_value_compare_cAllocator_pair_ctor_valuecompareR_cAllocatorR_2(self, &a, &b);
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C0540(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C0540 */
