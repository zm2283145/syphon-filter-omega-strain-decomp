#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cAIWeaponFiredMsg_dtor, D_004DCBF0, D_004DCD70, cMessage_dtor)
