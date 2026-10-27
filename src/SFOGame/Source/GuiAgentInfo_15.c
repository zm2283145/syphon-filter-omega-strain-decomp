/*
 * SFOGame/Source/GuiAgentInfo: 1 file, 00365380
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00365380 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "string_replace_range.h"

extern "C" { char D_004BBA30[] = "basic_string: out_of_range"; }
extern "C" { char D_004BBA50[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE(func_00365380, D_004BBA30, D_004BBA50, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_00492F50, D_00492F58, Libc_Memmove, std_basic_string_char_char_traits_char_assign_charP_charP_intP)
static inline void merge_flush_func_00365380(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00365380 */
