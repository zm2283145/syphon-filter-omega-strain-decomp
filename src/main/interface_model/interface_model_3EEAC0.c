/*
 * main/interface_model: 3 files, 003EEAC0-003EEB20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EEAC0 */
#pragma push /* merge_units */
#include "types.h"

extern void* std_basic_string_char_char_traits_char_compare_charP(void* obj);

/* Returns whether std_basic_string_char_char_traits_char_compare_charP yields null. */
int cString_opEq(void* obj) {
    return std_basic_string_char_char_traits_char_compare_charP(obj) == 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003EEAC0 */

/* merge_units: begin func_003EEAF0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int std_basic_string_char_char_traits_char_compare_charP(void* self);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_compare_charP(a0) ((int)std_basic_string_char_char_traits_char_compare_charP((a0))) /* merge_units */


/* Returns 1 if std_basic_string_char_char_traits_char_compare_charP returns 0. */
int std_opEq_basicstringR_charP(void* self)
{
    return std_basic_string_char_char_traits_char_compare_charP(self) == 0;
}
#undef std_basic_string_char_char_traits_char_compare_charP /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EEAF0 */

/* merge_units: begin func_003EEB20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* func_003EEB20(void* self) {
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003EEB20 */
