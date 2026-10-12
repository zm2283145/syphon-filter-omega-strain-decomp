#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"
#include "v4_asm_copy.h"

/* Clone a network message (16-byte vector at 0x30, float at 0x40). */
#define NMC_F(off) (*(float*)((char*)p + (off)) = *(float*)((char*)self + (off)))
extern "C" { char D_004A92D0[] = "netGrenadeMsg.hh"; }
DEFINE_NET_MSG_CLONE(cNetGrenadeMsg_v01, 0x50, D_004A92D0, 0x18, D_004DCDC0,
                     NMC_W(0x24);
                     { char* d = (char*)p + 0x30; char* s = (char*)self + 0x30; V4Copy(d, s); }
                     NMC_F(0x40))