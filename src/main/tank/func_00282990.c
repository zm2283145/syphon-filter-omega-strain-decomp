#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"

/* Clone a network message. */
extern "C" { char D_004A9540[] = "tank.hh"; }
DEFINE_NET_MSG_CLONE(cNetUpdateTankMsg_Clone, 0x30, D_004A9540, 0xCD, D_004DCF50,
                     NMC_B(0x24); NMC_W(0x28); (*(float*)((char*)p + (0x2C)) = *(float*)((char*)self + (0x2C))))
