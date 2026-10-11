#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"

#define NMC_UB(off) (*(unsigned char*)((char*)p + (off)) = *(unsigned char*)((char*)self + (off)))
/* Clone a network message. */
DEFINE_NET_MSG_CLONE(cNetAgentUpdateMsg_v01, 0x30, D_0049A890, 0xC68, D_004D91A0,
                     NMC_B(0x24); NMC_W(0x28); NMC_UB(0x2C); NMC_UB(0x2D))