/*
 * main/game: 2 files, 0013A040-0013A130
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013A040 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(func_0013A040)
#pragma pop /* merge_units */
/* merge_units: end func_0013A040 */

/* merge_units: begin func_0013A130 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vector_release_dtor.h"

/* Destroy a vector through its allocator, optionally delete. */
extern "C" { char D_0049AE00[] = "allocator.hh"; }
DEFINE_VECTOR_RELEASE_DTOR(func_0013A130, std_vector_deleter_cLosRequest_cCollisionModelList_Game_clear, opDelete_cLosRequestP_int_bool_charP_etc, D_0049AE00)
#pragma pop /* merge_units */
/* merge_units: end func_0013A130 */
