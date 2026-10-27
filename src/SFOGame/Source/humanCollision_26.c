/*
 * SFOGame/Source/humanCollision: 1 file, 001EB800
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001EB800 */
#pragma push /* merge_units */
#include "types.h"
#include "humanCollision_types.h"

extern void std_vector_imp_cEdgeGroup_ctor(HumanColVec* v);
extern void std_vector_imp_cEdgeGroup_reserve(HumanColVec* v, int capacity); /* vector reserve (buffer A) */

/* Constructor for buffer A: empty vector, reserve *capacity, store the flag byte; returns v. */
HumanColVec* cArray_cEdgeGroup_ctor(HumanColVec* v, int* capacity, char flag)
{
    std_vector_imp_cEdgeGroup_ctor(v);
    std_vector_imp_cEdgeGroup_reserve(v, *capacity);
    v->flag0C = flag;
    return v;
}
static inline void merge_flush_func_001EB800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EB800 */
