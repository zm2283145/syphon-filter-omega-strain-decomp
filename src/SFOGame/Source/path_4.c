/*
 * SFOGame/Source/path: 1 file, 0015D3B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0015D3B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Accessors for a vector of 8-byte elements.
 */

#include "types.h"
#include "path_types.h"

/* end(): one past the last element. */
PathPair* std_vector_imp_tNodeLink_end_void_2(PathPairVec* v) {
    return v->data + v->count;
}

void std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* begin() */
PathPair* std_vector_imp_tNodeLink_begin_void_2(PathPairVec* v) {
    return v->data;
}
static inline void merge_flush_func_0015D3B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015D3B0 */
