#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cStopAllQuipsMsg_dtor, D_004DAC50, D_004DCF10, cMessage_dtor)
