#pragma cplusplus on

#include "types.h"
#include "vector_resize.h"

/* Resize a vector of 8-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem8, 8)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(func_001BE020, Elem8, func_001BF5A0, func_001BF440)
#pragma opt_common_subs reset
