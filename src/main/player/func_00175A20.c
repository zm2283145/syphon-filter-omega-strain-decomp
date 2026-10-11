#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cMaxActiveNpcCountMsg_dtor, D_004DAE70, D_004DCF10, cMessage_dtor)
