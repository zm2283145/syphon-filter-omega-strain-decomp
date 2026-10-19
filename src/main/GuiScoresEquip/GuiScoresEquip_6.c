/*
 * main/GuiScoresEquip: 5 files, 0035F580-0035F900
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0035F580 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "string_compare_range.h"

/* String compare of a substring against a buffer. */
extern "C" { char D_004BB6A0[] = "string compare: pos > len"; }
DEFINE_STRING_COMPARE_RANGE(String_Compare_35F580, D_004BB6A0)
#pragma pop /* merge_units */
/* merge_units: end func_0035F580 */

/* merge_units: begin func_0035F6B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_release_dtor.h"

/* Destroy a vector through its allocator, optionally delete. */
DEFINE_VECTOR_RELEASE_DTOR(func_0035F6B0, func_001BFCB0, func_001BFAD0, D_0049ECD8)
#pragma pop /* merge_units */
/* merge_units: end func_0035F6B0 */

/* merge_units: begin func_0035F730 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_destroy_release.h"

/* Destroy and free an allocation under the allocator guard. */
DEFINE_GUARDED_DESTROY_RELEASE(func_0035F730, func_001AEFE0)
#pragma pop /* merge_units */
/* merge_units: end func_0035F730 */

/* merge_units: begin func_0035F810 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR(func_0035F810, func_001BFCA0)
#pragma pop /* merge_units */
/* merge_units: end func_0035F810 */

/* merge_units: begin func_0035F900 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiScoresEquip.cc. Functions are named by address
 * until real names are known.
 */


void func_0035F900(char* self) {
    *(int*)(self + 4) = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0035F900 */
