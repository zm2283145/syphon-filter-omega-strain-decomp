/*
 * main/game: 2 files, 0013C370-0013C4A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013C370 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "string_compare_range.h"

/* String compare of a substring against a buffer. */
extern "C" { char D_0049AD80[] = "string compare: pos > len"; }
DEFINE_STRING_COMPARE_RANGE(std_basic_string_char_char_traits_char_compare_uint_uint_charP_uint, D_0049AD80)
#pragma pop /* merge_units */
/* merge_units: end func_0013C370 */

/* merge_units: begin func_0013C4A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tree_find.h"

/* Find a key in a tree; end() when absent. */
DEFINE_TREE_FIND(std_tree_pair_cString_value_compare_find_cStringR, std_basic_string_char_char_traits_char_compare_basicstringR)
#pragma pop /* merge_units */
/* merge_units: end func_0013C4A0 */
