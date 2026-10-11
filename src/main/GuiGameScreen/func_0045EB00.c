#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cDisplayClientInteractMsg_dtor, D_004E1680, D_004DCF10, cMessage_dtor)
