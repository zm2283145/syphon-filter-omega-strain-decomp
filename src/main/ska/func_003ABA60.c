#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Message destructor: restore vtable, run cMessage base, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(func_003ABA60, D_004DFBD0, cMessage_dtor)
