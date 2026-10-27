/*
 * SFOGame/Source/GuiNetMessages: 3 files, 00349730-00349B00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00349730 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "short_string_assign.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "string_reserve.h"
#pragma pop

#pragma cplusplus on

/* Assign one string to another. */
DEFINE_SHORT_STRING_ASSIGN(func_00349730)
static inline void merge_flush_func_00349730(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00349730 */

/* merge_units: begin func_003497C0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
char D_004BA450[] = "basic_string::reserve length_error";
}
DEFINE_STRING_RESERVE(String_Reserve_3497C0, D_004BA450, D_0049ADE0, 0x5C, D_0049AE90, 0x64)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003497C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003497C0 */

/* merge_units: begin func_00349B00 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(String_Dtor_349B00)
static inline void merge_flush_func_00349B00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00349B00 */
