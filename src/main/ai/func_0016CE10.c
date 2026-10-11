#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cAIPickupableAwarenessMsg_dtor, D_004DCBD0, D_004DCD70, cMessage_dtor)
