#pragma cplusplus on

#include "types.h"
#include "vector_resize.h"

/* Resize a vector of 4-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem4, 4)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(func_0032D870, Elem4, PtrVec_Insert, PtrVector_Erase)
#pragma opt_common_subs reset
