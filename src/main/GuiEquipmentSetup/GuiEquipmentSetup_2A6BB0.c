/*
 * main/GuiEquipmentSetup: range (4 files, 002A6BB0-002A6E40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A6BB0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "string_compare_range.h"

/* String compare of a substring against a buffer. */
extern "C" { char D_004AB300[] = "string compare: pos > len"; }
DEFINE_STRING_COMPARE_RANGE(String_Compare_2A6BB0, D_004AB300)
#pragma pop /* merge_units */
/* merge_units: end func_002A6BB0 */

/* merge_units: begin func_002A6CE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_release_dtor.h"

/* Destroy a vector through its allocator, optionally delete. */
DEFINE_VECTOR_RELEASE_DTOR(func_002A6CE0, func_001BFCB0, func_001BFAD0, D_0049ECD8)
#pragma pop /* merge_units */
/* merge_units: end func_002A6CE0 */

/* merge_units: begin func_002A6D60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_destroy_release.h"

/* Destroy and free an allocation under the allocator guard. */
DEFINE_GUARDED_DESTROY_RELEASE(func_002A6D60, func_001AEFE0)
#pragma pop /* merge_units */
/* merge_units: end func_002A6D60 */

/* merge_units: begin func_002A6E40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR(func_002A6E40, func_001BFCA0)
#pragma pop /* merge_units */
/* merge_units: end func_002A6E40 */
