#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"

/* Clone a network message. */
extern "C" { char D_004A9548[] = "tank.hh"; }
DEFINE_NET_MSG_CLONE(cNetCreateTankMsg_Clone, 0x2C, D_004A9548, 0xA7, cNetCreateTankMsg_vtable,
                     NMC_W(0x24); NMC_W(0x28))
