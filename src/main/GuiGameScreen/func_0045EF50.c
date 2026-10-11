#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"

/* Clone a network message. */
DEFINE_NET_MSG_CLONE(cDisplayClientInteractMsg_v01, 0x2C, D_004C2290, 0x78, D_004E1680, NMC_W(0x24); NMC_W(0x28))
