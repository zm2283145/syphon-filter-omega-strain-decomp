/*
 * main/guiTextArrayWidget: 3 files, 00428090-004281F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00428090 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vector_release_dtor.h"

/* Destroy a vector through its allocator, optionally delete. */
extern "C" { char D_004BF888[] = "allocator.hh"; }
DEFINE_VECTOR_RELEASE_DTOR(func_00428090, func_00428B10, func_00428110, D_004BF888)
#pragma pop /* merge_units */
/* merge_units: end func_00428090 */

/* merge_units: begin func_00428110 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_destroy_release.h"

/* Destroy and free an allocation under the allocator guard. */
DEFINE_GUARDED_DESTROY_RELEASE(func_00428110, func_00138350)
#pragma pop /* merge_units */
/* merge_units: end func_00428110 */

/* merge_units: begin func_004281F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_replace.h"

/* Replace a range of a string with another string. */
DEFINE_SHORT_STRING_REPLACE(func_004281F0)
#pragma pop /* merge_units */
/* merge_units: end func_004281F0 */
