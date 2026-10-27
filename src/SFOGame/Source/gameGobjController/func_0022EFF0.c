#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"

/* Clone a network message. */
extern "C" { char D_004A69C0[] = "gameGobjController.hh"; }
DEFINE_NET_MSG_CLONE(cTimerExpiredMsg_v01, 0x28, D_004A69C0, 0x2D, D_004DBA00, NMC_W(0x24))
