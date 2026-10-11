#include "types.h"
#include "ai_msg_pack.h"
extern int D_004FF0E8;
AIMSG_PACK_BEGIN(cAIDeactivatedMsg_v02, 0x8)
    Event_PackHeader(self, a1, type, a3, t0, len, buf);
AIMSG_PACK_END(0x8, D_004FF0E8)

