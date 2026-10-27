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
