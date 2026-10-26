/*
 * main/game: 2 files, 0013C2F0-0013C310
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013C2F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* cAssocArray_cString_cConsCommandPtr_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_map_cString_cConsCommandPtr_end_void(Iter* out, Tree* t) {
    out->p = &t->header;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013C2F0 */

/* merge_units: begin func_0013C310 */
#pragma push /* merge_units */
#include "short_string_compare.h"

/* Compare two strings. */
DEFINE_SHORT_STRING_COMPARE(std_basic_string_char_char_traits_char_compare_basicstringR)
#pragma pop /* merge_units */
/* merge_units: end func_0013C310 */
