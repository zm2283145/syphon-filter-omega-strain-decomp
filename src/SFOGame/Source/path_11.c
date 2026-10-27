/*
 * SFOGame/Source/path: 3 files, 0015EF10-0015EF80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0015EF10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cPathMessage_dtor, D_004D9760, cMessage_dtor)
static inline void merge_flush_func_0015EF10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015EF10 */

/* merge_units: begin func_0015EF70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * List iterator dereference.
 */

#include "types.h"
#include "path_types.h"

int* cConstLListIterator_cPathSystemRequestPtr_opMul(PathListNode** it) {
    return &(*it)->value;
}
static inline void merge_flush_func_0015EF70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015EF70 */

/* merge_units: begin func_0015EF80 */
#pragma push /* merge_units */
#include "iter_return_copy.h"

/* Return the begin iterator. */
DEFINE_ITER_BEGIN(cLList_cPathSystemRequestPtr_Begin)
static inline void merge_flush_func_0015EF80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015EF80 */
