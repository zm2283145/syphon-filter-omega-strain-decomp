#include "types.h"
#include "ai_msg_pack.h"
extern int D_004FF110;
AIMSG_PACK_BEGIN(cAIBodyMovedMsg_v02, 0x10)
    AIMsg_PackBase(self, a1, type, a3, t0, len, buf);
    ((unsigned char*)buf)[0xC] = *(unsigned char*)&self->p28;
AIMSG_PACK_END(0x10, D_004FF110)

