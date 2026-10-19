/*
 * main/GuiGameOptions: range (2 files, 0029C120-0029C590)
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
#include "string_reserve.h"
#pragma pop

/* merge_units: begin func_0029C120 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
char D_004AA9A0[] = "basic_string: out_of_range";
}
extern "C" {
char D_004AA9C0[] = "basic_string: length_error";
}
DEFINE_STRING_REPLACE_RANGE_XD(String_Replace_29C120, D_004AA9A0, D_004AA9C0, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_0048B910, D_0048B918, Libc_Memmove, String_Assign, String_Dtor)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029C120(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029C120 */

/* merge_units: begin func_0029C590 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
char D_004AA9E0[] = "basic_string::reserve length_error";
}
DEFINE_STRING_RESERVE(String_Reserve_29C590, D_004AA9E0, D_0049ADE0, 0x5C, D_0049AE90, 0x64)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029C590(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029C590 */
