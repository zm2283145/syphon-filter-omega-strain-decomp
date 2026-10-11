#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cNetForceHolsterMsg_dtor, D_004DA9B0, D_004DCF10, cMessage_dtor)
