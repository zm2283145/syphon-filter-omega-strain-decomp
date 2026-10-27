/*
 * SFOGame/Source/humanCollision: 4 files, 001EF890-001EFA30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001EF890 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_swap_vectordeleterR_vectordeleterR_13(PtrVec* a, PtrVec* b) {
    if (a != b) {
        int t;
        int* p;
        t = a->unk0;
        a->unk0 = b->unk0;
        b->unk0 = t;
        p = a->data;
        a->data = b->data;
        b->data = p;
        t = a->count;
        a->count = b->count;
        b->count = t;
    }
}
static inline void merge_flush_func_001EF890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EF890 */

/* merge_units: begin func_001EF8D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_release_dtor.h"

/* Destroy a vector through its allocator, optionally delete. */
extern "C" { char D_004A0538[] = "allocator.hh"; }
DEFINE_VECTOR_RELEASE_DTOR(std_vector_deleter_cEdgeGroup_dtor, std_vector_deleter_cEdgeGroup_clear, opDelete_cEdgeGroupP_int_bool_charP_etc, D_004A0538)
static inline void merge_flush_func_001EF8D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EF8D0 */

/* merge_units: begin func_001EF950 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_base_destroy_release.h"
DEFINE_GUARDED_BASE_DESTROY_RELEASE(opDelete_cEdgeGroupP_int_bool_charP_etc, cArray_cCollisionEdgePtr_dtor)
static inline void merge_flush_func_001EF950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EF950 */

/* merge_units: begin func_001EFA30 */
#pragma push /* merge_units */
#include "loose01_types.h"

void std_vector_deleter_cCollisionEdge_clear(PtrVec* v) {
    v->count = 0;
}
static inline void merge_flush_func_001EFA30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EFA30 */
