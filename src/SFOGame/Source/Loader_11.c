/*
 * SFOGame/Source/Loader: 4 files, 001C0750-001C07C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C0750 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "tree_node_free.h"
DEFINE_TREE_ROOT_DTOR(std_map_cString16N_3_int_cAllocator_pair_dtor, std_tree_pair_cString16N_value_compare_cAllocator_pair_destroy_nodeP)
static inline void merge_flush_func_001C0750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C0750 */

/* merge_units: begin func_001C07C0 */
#pragma push /* merge_units */
#include "Loader_types.h"

Rel* std_vector_imp_charPtr_1_ctor(Rel* r); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */


#if 0 /* merge_units */
extern PtrVec* std_vector_imp_charPtr_1_ctor(PtrVec* v);
#endif /* merge_units */
#define std_vector_imp_charPtr_1_ctor(a0) ((PtrVec *)std_vector_imp_charPtr_1_ctor((Rel *)(a0))) /* merge_units */



/* Construct an empty vector that owns its elements. */
LoaderOwnedVec* cArray_charPtr_ctor(LoaderOwnedVec* self) {
    std_vector_imp_charPtr_1_ctor(&self->vec);
    self->owns = 1;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C07C0(void) {}
#undef std_vector_imp_charPtr_1_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C07C0 */

/* merge_units: begin func_001C07F0 */
#pragma push /* merge_units */
Rel* std_vector_imp_cString4_ctor(Rel* r); /* gsynth: defined below */
#if 0 /* merge_units */
extern PtrVec* std_vector_imp_cString4_ctor(PtrVec* v);
#endif /* merge_units */
#define std_vector_imp_cString4_ctor(a0) ((PtrVec *)std_vector_imp_cString4_ctor((Rel *)(a0))) /* merge_units */



/* Zero-initialise a three-word vector. */
Rel* std_vector_imp_charPtr_1_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Construct an empty vector that owns its elements. */
LoaderOwnedVec* cArray_cString4_ctor(LoaderOwnedVec* self) {
    std_vector_imp_cString4_ctor(&self->vec);
    self->owns = 1;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C07F0(void) {}
#undef std_vector_imp_cString4_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C07F0 */

/* merge_units: begin func_001C0840 */
#pragma push /* merge_units */
/* Zero-initialise a three-word vector. */
Rel* std_vector_imp_cString4_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C0840(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C0840 */
