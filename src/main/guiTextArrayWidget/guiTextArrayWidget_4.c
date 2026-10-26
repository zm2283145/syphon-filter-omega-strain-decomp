/*
 * main/guiTextArrayWidget: 2 files, 00427B30-00428000
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00427B30 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "ptrvec_insert.h"

extern "C" { char D_004BF830[] = "vector::insert length error\n"; }
DEFINE_PTRVEC_INSERT(Vector_Insert_427B30, 0x1800000, 0xC00000, D_004BF830, D_0049AE50, 0x5C, D_0049AF00, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_00427B30 */

/* merge_units: begin func_00428000 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_resize.h"

DEFINE_RESIZE_ELEMENT(Elem48_00428000, 48)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(std_vector_imp_tTextElement_resize, Elem48_00428000, std_vector_imp_tTextElement_insert, std_vector_imp_tTextElement_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_00428000 */
