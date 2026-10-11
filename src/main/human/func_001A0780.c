#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cAIBodyMovedMsg_dtor, D_004DCC70, D_004DCD70, cMessage_dtor)
