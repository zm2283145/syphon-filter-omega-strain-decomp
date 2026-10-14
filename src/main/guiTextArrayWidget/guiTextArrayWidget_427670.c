/*
 * main/guiTextArrayWidget: range (3 files, 00427670-00427A40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "short_string_assign.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "string_reserve.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "stream_string_dtor.h"
#pragma pop

/* merge_units: begin func_00427670 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Assign one string to another. */
DEFINE_SHORT_STRING_ASSIGN(func_00427670)
#pragma pop /* merge_units */
/* merge_units: end func_00427670 */

/* merge_units: begin func_00427700 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
char D_004BF800[] = "basic_string::reserve length_error";
}
DEFINE_STRING_RESERVE(func_00427700, D_004BF800, D_0049ADE0, 0x5C, D_0049AE90, 0x64)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00427700(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00427700 */

/* merge_units: begin func_00427A40 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(func_00427A40)
#pragma pop /* merge_units */
/* merge_units: end func_00427A40 */
