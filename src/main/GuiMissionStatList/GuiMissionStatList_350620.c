/*
 * main/GuiMissionStatList: 5 files, 00350620-00350FD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00350620 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "string_replace_range.h"

extern "C" { char D_004BAB60[] = "basic_string: out_of_range"; }
extern "C" { char D_004BAB80[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE(func_00350620, D_004BAB60, D_004BAB80, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_00492BE0, D_00492BE8, Libc_Memmove, String_Assign)
#pragma pop /* merge_units */
/* merge_units: end func_00350620 */

/* merge_units: begin func_00350B10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_assign.h"

/* Assign one string to another. */
DEFINE_SHORT_STRING_ASSIGN(func_00350B10)
#pragma pop /* merge_units */
/* merge_units: end func_00350B10 */

/* merge_units: begin func_00350BA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_reserve.h"

extern "C" { char D_004BABA0[] = "basic_string::reserve length_error"; }
DEFINE_STRING_RESERVE(String_Reserve_350BA0, D_004BABA0, D_0049ADE0, 0x5C, D_0049AE90, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_00350BA0 */

/* merge_units: begin func_00350EE0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(String_Dtor_350EE0)
#pragma pop /* merge_units */
/* merge_units: end func_00350EE0 */

/* merge_units: begin func_00350FD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_resize.h"

DEFINE_RESIZE_ELEMENT(Elem350FD0, 0x5C)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(func_00350FD0, Elem350FD0, func_00351810, func_003515D0)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_00350FD0 */
