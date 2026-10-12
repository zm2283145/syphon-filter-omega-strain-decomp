#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"
#define NMC_UB(off) (*(unsigned char*)((char*)p + (off)) = *(unsigned char*)((char*)self + (off)))
#define NMC_F(off) (*(float*)((char*)p + (off)) = *(float*)((char*)self + (off)))
extern "C" { char D_004B86D0[] = "enableSuperJumpMsg.hh"; }
DEFINE_NET_MSG_CLONE(cEnableSuperJumpMsg_v01, 0x28, D_004B86D0, 0x23, D_004DE6F0, NMC_UB(0x24))