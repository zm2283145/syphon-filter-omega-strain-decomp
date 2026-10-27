/*
 * Libs/SFOLib/Source/gameobj: 2 files, 003930F0-003931E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003930F0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_cTreeNode_cSkaSystemPtrPtr_dtor)
static inline void merge_flush_func_003930F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003930F0 */

/* merge_units: begin func_003931E0 */
#pragma push /* merge_units */
/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

void cArray_cTreeNode_cSkaSystemPtrPtr_Clear(PtrVec* v) {
    v->count = 0;
}
static inline void merge_flush_func_003931E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003931E0 */
