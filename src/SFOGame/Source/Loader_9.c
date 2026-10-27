/*
 * SFOGame/Source/Loader: 3 files, 001C0570-001C0610
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C0570 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "tree_node_free.h"
DEFINE_TREE_ROOT_DTOR(std_map_cString16N_2_cSkaAnimationBlendPtr_cAllocator_pair_dtor, std_tree_pair_cString16N_value_compare_cAllocator_pair_destroy_nodeP_2)
static inline void merge_flush_func_001C0570(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C0570 */

/* merge_units: begin func_001C05E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "Loader_types.h"

extern PtrVec* std_vector_imp_cSkaNodePtr_1_ctor(PtrVec* v);

/* Construct an empty vector that owns its elements. */
LoaderOwnedVec* cArray_cSkaNodePtr_ctor(LoaderOwnedVec* self) {
    std_vector_imp_cSkaNodePtr_1_ctor(&self->vec);
    self->owns = 1;
    return self;
}
static inline void merge_flush_func_001C05E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C05E0 */

/* merge_units: begin func_001C0610 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_cSkaNodePtr_dtor)
static inline void merge_flush_func_001C0610(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C0610 */
