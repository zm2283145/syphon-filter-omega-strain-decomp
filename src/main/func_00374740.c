#pragma cplusplus on

#include "types.h"
#include "self_call_dtor.h"

DEFINE_SELF_CALL_DTOR(LightMgr_dtor, LightMgr_FreePools)
