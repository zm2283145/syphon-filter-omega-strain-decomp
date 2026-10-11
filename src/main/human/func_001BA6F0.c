#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"
#define NMC_UB(off) (*(unsigned char*)((char*)p + (off)) = *(unsigned char*)((char*)self + (off)))
#define NMC_F(off) (*(float*)((char*)p + (off)) = *(float*)((char*)self + (off)))
DEFINE_NET_MSG_CLONE(cNetForceHolsterMsg_v01, 0x28, D_0049D8D0, 0x4532, D_004DA9B0, NMC_UB(0x24))