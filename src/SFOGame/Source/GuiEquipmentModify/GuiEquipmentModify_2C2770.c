/*
 * main/GuiEquipmentModify: 6 files, 002C2770-002C3080
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C2770 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "ptrvec_insert.h"

extern "C" { char D_004AC640[] = "vector::insert length error\n"; }
DEFINE_PTRVEC_INSERT(Vector_Insert_2C2770, 0x1800000, 0xC00000, D_004AC640, D_0049AE50, 0x5C, D_0049AF00, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_002C2770 */

/* merge_units: begin func_002C2C40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "ptrvec_reserve.h"

extern "C" { char D_004AC660[] = "vector::reserve length error\n"; }
DEFINE_PTRVEC_RESERVE(Vector_Reserve_2C2C40, 0x1800000, D_004AC660, D_0049AE50, 0x5C, D_0049AF00, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_002C2C40 */

/* merge_units: begin func_002C2E90 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_resize.h"

/* Resize a vector of 60-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem60, 60)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(func_002C2E90, Elem60, std_vector_imp_cSkaSliderValue_insert, std_vector_imp_cSkaSliderValue_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_002C2E90 */

/* merge_units: begin func_002C2F20 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Resize a vector of 8-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem8, 8)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(func_002C2F20, Elem8, std_vector_imp_cSkaSwitchValue_insert, std_vector_imp_cSkaSwitchValue_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_002C2F20 */

/* merge_units: begin func_002C2F90 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_002C2F90, func_001BFA20, D_0049ED38)
#pragma pop /* merge_units */
/* merge_units: end func_002C2F90 */

/* merge_units: begin func_002C3080 */
#pragma push /* merge_units */
#include "short_string_compare.h"

/* Compare two strings. */
DEFINE_SHORT_STRING_COMPARE(func_002C3080)
#pragma pop /* merge_units */
/* merge_units: end func_002C3080 */
