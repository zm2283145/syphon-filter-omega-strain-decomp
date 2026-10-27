/*
 * main/game: 2 files, 0013B500-0013B970
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013B500 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "string_replace_range_xd.h"

extern "C" { char D_0049AD10[] = "basic_string: out_of_range"; }
extern "C" { char D_0049AD30[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE_XD(std_basic_string_char_char_traits_char_do_replace, D_0049AD10, D_0049AD30, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_00489BE8, D_00489BF0, Libc_Memmove, std_basic_string_char_char_traits_char_assign_charP_charP_intP, String_Dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0013B500 */

/* merge_units: begin func_0013B970 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_reserve.h"

extern "C" { char D_0049AD50[] = "basic_string::reserve length_error"; }
DEFINE_STRING_RESERVE(std_basic_string_char_char_traits_char_reserve, D_0049AD50, D_0049ADE0, 0x5C, D_0049AE90, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_0013B970 */
