#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"

/* Clone a network message. */
DEFINE_NET_MSG_CLONE(cNetCreateTankMsg_v01, 0x2C, D_004A9548, 0xA7, D_004DCF70,
                     NMC_W(0x24); NMC_W(0x28))
