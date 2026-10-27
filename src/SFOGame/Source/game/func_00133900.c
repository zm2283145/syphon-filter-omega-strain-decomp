#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Message destructor: restore vtable, run cMessage base, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(cNextFrameMsg_dtor, D_004D9160, cMessage_dtor)
