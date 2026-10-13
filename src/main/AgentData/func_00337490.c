#pragma cplusplus on

#include "types.h"
#include "vector_resize.h"

DEFINE_RESIZE_ELEMENT(Elem32_00337490, 32)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(AgentLevelVec_Resize, Elem32_00337490, AgentLevelVec_Insert, AgentLevelVec_Erase)
#pragma opt_common_subs reset
