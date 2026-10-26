/*
 * main/mem: 7 files, 003559A0-00356530
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003559A0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "string_replace_range.h"

extern "C" { char D_004BB100[] = "basic_string: out_of_range"; }
extern "C" { char D_004BB120[] = "basic_string: length_error"; }
DEFINE_STRING_REPLACE_RANGE(func_003559A0, D_004BB100, D_004BB120, D_0049ADE0, 0x5C, D_0049AE90, 0x64, D_00492C70, D_00492C78, Libc_Memmove, String_Assign)
#pragma pop /* merge_units */
/* merge_units: end func_003559A0 */

/* merge_units: begin func_00355E90 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_assign.h"

/* Assign one string to another. */
DEFINE_SHORT_STRING_ASSIGN(func_00355E90)
#pragma pop /* merge_units */
/* merge_units: end func_00355E90 */

/* merge_units: begin func_00355F20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "string_reserve.h"

extern "C" { char D_004BB140[] = "basic_string::reserve length_error"; }
DEFINE_STRING_RESERVE(String_Reserve_355F20, D_004BB140, D_0049ADE0, 0x5C, D_0049AE90, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_00355F20 */

/* merge_units: begin func_00356260 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(String_Dtor_356260)
#pragma pop /* merge_units */
/* merge_units: end func_00356260 */

/* merge_units: begin func_00356350 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_00356350, func_00299500, D_004AA5C8)
#pragma pop /* merge_units */
/* merge_units: end func_00356350 */

/* merge_units: begin func_00356440 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_00356440, std_vector_deleter_tAchievementInfo_clear, D_004AA5B8)
#pragma pop /* merge_units */
/* merge_units: end func_00356440 */

/* merge_units: begin func_00356530 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_replace.h"

/* Replace a range of a string with another string. */
DEFINE_SHORT_STRING_REPLACE(func_00356530)
#pragma pop /* merge_units */
/* merge_units: end func_00356530 */
