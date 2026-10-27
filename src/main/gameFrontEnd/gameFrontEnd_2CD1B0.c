/*
 * main/gameFrontEnd: range (3 files, 002CD1B0-002CD6B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "string_replace_range_xd.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "short_string_assign.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "string_reserve.h"
#pragma pop

/* merge_units: begin func_002CD1B0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
char D_004AD0C0[] = "basic_string: out_of_range";
}
extern "C" {
char D_004AD0E0[] = "basic_string: length_error";
}
DEFINE_STRING_REPLACE_RANGE_XD(String_Replace_2CD1B0, D_004AD0C0, D_004AD0E0, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_0048C370, D_0048C378, Libc_Memmove, std_basic_string_char_char_traits_char_assign_charP_charP_intP, String_Dtor)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CD1B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CD1B0 */

/* merge_units: begin func_002CD620 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Assign one string to another. */
DEFINE_SHORT_STRING_ASSIGN(func_002CD620)
#pragma pop /* merge_units */
/* merge_units: end func_002CD620 */

/* merge_units: begin func_002CD6B0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
char D_004AD100[] = "basic_string::reserve length_error";
}
DEFINE_STRING_RESERVE(String_Reserve_2CD6B0, D_004AD100, D_0049ADE0, 0x5C, D_0049AE90, 0x64)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CD6B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CD6B0 */
