/*
 * SFOGame/Source/GuiEquipmentSetup: 5 files, 002A6BB0-002A6F30
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
static inline void merge_flush_func_002A6BB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A6BB0 */

/* merge_units: begin func_002A6CE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_release_dtor.h"

/* Destroy a vector through its allocator, optionally delete. */
DEFINE_VECTOR_RELEASE_DTOR(func_002A6CE0, std_vector_deleter_cSkaSliderValue_clear, opDelete_cSkaSliderValueP_int_bool_charP_etc, D_0049ECD8)
static inline void merge_flush_func_002A6CE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A6CE0 */

/* merge_units: begin func_002A6D60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_destroy_release.h"

/* Destroy and free an allocation under the allocator guard. */
DEFINE_GUARDED_DESTROY_RELEASE(func_002A6D60, cSplinedMotion_Scalar0To1_dtor)
static inline void merge_flush_func_002A6D60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A6D60 */

/* merge_units: begin func_002A6E40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR(func_002A6E40, std_vector_deleter_cSkaSwitchValue_clear)
static inline void merge_flush_func_002A6E40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A6E40 */

/* merge_units: begin func_002A6F30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiEquipmentSetup.cc. Functions are named by address
 * until real names are known.
 */


void func_002A6F30(char* self) {
    *(int*)(self + 4) = 0;
}
static inline void merge_flush_func_002A6F30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A6F30 */
