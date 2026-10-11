#pragma cplusplus on

#include "types.h"
#include "vector_resize.h"

/* Resize a vector of 60-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem60, 60)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(func_00345830, Elem60, AnimChannelVec_Grow, func_001BEB20)
#pragma opt_common_subs reset
