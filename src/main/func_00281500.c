#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"

/* Clone a network message. */
DEFINE_NET_MSG_CLONE(cNetBackpackMsg_v01, 0x30, D_004A9380, 0x1C, D_004DCEF0,
                     NMC_B(0x24); NMC_W(0x28); NMC_W(0x2C))
