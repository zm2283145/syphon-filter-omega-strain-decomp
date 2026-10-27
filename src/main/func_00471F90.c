#pragma cplusplus on

#include "types.h"
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cNetMsgThrottle_sMsgTypeInfo_dtor, std_list_sMsgInfoPtr_dtor)
