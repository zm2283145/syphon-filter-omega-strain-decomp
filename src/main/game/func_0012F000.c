#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cNetAgentUpdateMsg_dtor, D_004D91A0, D_004DCF10, cMessage_dtor)
