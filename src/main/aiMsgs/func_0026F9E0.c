#include "types.h"
#include "ai_msg_pack.h"
extern int D_004FF108;
AIMSG_PACK_BEGIN(cAINewAwarenessMsg_v02, 0x10)
    AIMsg_PackBase(self, a1, type, a3, t0, len, buf);
    ((char*)buf)[0xC] = *(char*)&self->p28;
AIMSG_PACK_END(0x10, D_004FF108)

