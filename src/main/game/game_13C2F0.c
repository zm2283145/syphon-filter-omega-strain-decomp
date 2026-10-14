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

Word* func_0013C2F0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0013C300(Iter* out, Tree* t) {
    out->p = &t->header;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013C2F0 */

/* merge_units: begin func_0013C310 */
#pragma push /* merge_units */
#include "short_string_compare.h"

/* Compare two strings. */
DEFINE_SHORT_STRING_COMPARE(func_0013C310)
#pragma pop /* merge_units */
/* merge_units: end func_0013C310 */
