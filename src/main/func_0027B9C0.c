#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"
#include "v4_asm_copy.h"

/* Clone a network message (payload ends with a 16-byte vector at 0x40). */
#define NMC_UB(off) (*(unsigned char*)((char*)p + (off)) = *(unsigned char*)((char*)self + (off)))
extern "C" { char D_004A92A8[] = "netTaserMsg.hh"; }
DEFINE_NET_MSG_CLONE(cNetTaserMsg_v01, 0x50, D_004A92A8, 0x22, D_004DCDA0,
                     NMC_B(0x24); NMC_W(0x28); NMC_W(0x2C); NMC_UB(0x30); NMC_W(0x34);
                     { char* d = (char*)p + 0x40; char* s = (char*)self + 0x40; V4Copy(d, s); })