#pragma cplusplus on
#include "types.h"
#include "net_msg_clone.h"
#define NMC_UB(off) (*(unsigned char*)((char*)p + (off)) = *(unsigned char*)((char*)self + (off)))
#define NMC_F(off) (*(float*)((char*)p + (off)) = *(float*)((char*)self + (off)))
extern "C" { char D_004A6E38[] = "SpecFxDefs.cc"; }
DEFINE_NET_MSG_CLONE(cNetSpawnLightMsg_Clone, 0x30, D_004A6E38, 0x6D7, D_004DBAC0, NMC_W(0x24); NMC_F(0x28); NMC_F(0x2C))