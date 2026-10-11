#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"
#define NMC_UB(off) (*(unsigned char*)((char*)p + (off)) = *(unsigned char*)((char*)self + (off)))
#define NMC_F(off) (*(float*)((char*)p + (off)) = *(float*)((char*)self + (off)))
DEFINE_NET_MSG_CLONE(cNetSetFlagMsg_v01, 0x28, D_0049ED98, 0x2FCE, D_004DA9D0, NMC_B(0x24); NMC_B(0x25))