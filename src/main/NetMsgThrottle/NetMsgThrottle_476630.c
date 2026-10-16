#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"
#define NMC_UB(off) (*(unsigned char*)((char*)p + (off)) = *(unsigned char*)((char*)self + (off)))
#define NMC_F(off) (*(float*)((char*)p + (off)) = *(float*)((char*)self + (off)))
extern "C" { char D_004C36D0[] = "activateBodyTossMsg.hh"; }
DEFINE_NET_MSG_CLONE(cActivateBodyTossMsg_v01, 0x28, D_004C36D0, 0x23, D_004E1AE0, NMC_UB(0x24))