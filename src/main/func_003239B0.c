#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"

/* Clone a network message. */
DEFINE_NET_MSG_CLONE(cNetQuickChatMsg_v01, 0x2C, D_004B7CA0, 0x18, D_004DE630, NMC_W(0x24); NMC_W(0x28))
