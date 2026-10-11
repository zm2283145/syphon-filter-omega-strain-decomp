#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cAIWaypointReachedMsg_dtor, D_004DCCD0, D_004DCD50, cMessage_dtor)
