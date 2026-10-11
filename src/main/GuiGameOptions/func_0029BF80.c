#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"

/* Clone a network message. */
DEFINE_NET_MSG_CLONE(cNetKickMsg_v01, 0x2C, D_004AA980, 0x8E, D_004DD5E0,
                     NMC_W(0x24); NMC_W(0x28))
