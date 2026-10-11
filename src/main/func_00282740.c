#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"

/* Clone a network message. */
DEFINE_NET_MSG_CLONE(cBeamMsg_v01, 0x28, D_004A93C0, 0x19, D_004DCF30,
                     NMC_W(0x24))
