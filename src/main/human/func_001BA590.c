#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"
#define NMC_UB(off) (*(unsigned char*)((char*)p + (off)) = *(unsigned char*)((char*)self + (off)))
#define NMC_F(off) (*(float*)((char*)p + (off)) = *(float*)((char*)self + (off)))
DEFINE_NET_MSG_CLONE(cNetUpdateStatsMsg_v01, 0x2C, D_0049D8D0, 0x4222, D_004DA990, NMC_W(0x24); NMC_B(0x28); NMC_B(0x29))