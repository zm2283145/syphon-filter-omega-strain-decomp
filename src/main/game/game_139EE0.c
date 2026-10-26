/*
 * main/game: 2 files, 00139EE0-00139F60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00139EE0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vector_release_dtor.h"

/* Destroy a vector through its allocator, optionally delete. */
extern "C" { char D_0049AE10[] = "allocator.hh"; }
DEFINE_VECTOR_RELEASE_DTOR(func_00139EE0, std_vector_deleter_cArray_int_clear, opDelete_cArrayP_int_bool_charP_etc, D_0049AE10)
#pragma pop /* merge_units */
/* merge_units: end func_00139EE0 */

/* merge_units: begin func_00139F60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_destroy_release.h"

/* Destroy and free an allocation under the allocator guard. */
DEFINE_GUARDED_DESTROY_RELEASE(opDelete_cArrayP_int_bool_charP_etc, func_0013A040)
#pragma pop /* merge_units */
/* merge_units: end func_00139F60 */
