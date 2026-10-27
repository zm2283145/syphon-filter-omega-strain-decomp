#pragma cplusplus on
#include "types.h"
#include "node_world_q4.h"
extern "C" MtxQ4 g_IdentityMatrix;
extern "C" MtxQ4 cGOBJ_GetMatrix(OwnerQ4* o)
{
    NODE_WORLD_Q4_BODY(o, g_IdentityMatrix)
}