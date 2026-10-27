/*
 * main/human: range (3 files, 001BAEF0-001BB100)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vector_init_range.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "int_tree_find.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "tree_find.h"
#pragma pop

/* merge_units: begin func_001BAEF0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct VRElem20 { float a; float b; unsigned char c; int d; int e; };
extern "C" {
char D_0049E960[] = "vector length error\n";
}
DEFINE_VECTOR_INIT_RANGE(std_vector_imp_cTimedEvent_init, VRElem20, 0x4CCCCC, D_0049E960, D_0049ED58, 0x5C)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001BAEF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001BAEF0 */

/* merge_units: begin func_001BB080 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Find an int key in a tree; end() when absent. */
DEFINE_INT_TREE_FIND(std_tree_pair_int_value_compare_find_intR)
#pragma pop /* merge_units */
/* merge_units: end func_001BB080 */

/* merge_units: begin func_001BB100 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Find a key in a tree; end() when absent. */
DEFINE_TREE_FIND(std_tree_pair_cString_value_compare_find_cStringR_2, std_basic_string_char_char_traits_char_compare_basicstringR)
#pragma pop /* merge_units */
/* merge_units: end func_001BB100 */
