/*
 * SFOGame/Source/GameGOBJ: 2 files, 00215E40-00215F30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00215E40 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_cGameGOBJPtr_dtor)
static inline void merge_flush_func_00215E40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00215E40 */

/* merge_units: begin func_00215F30 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

Rel* std_vector_cGameGOBJPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_00215F30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00215F30 */
