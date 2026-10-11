#include "types.h"
#include "message_pack.h"

#define PACK_BODY(e, b) MP_S(b, 8) = MP_S(e, 0x24); MP_I(b, 0xC) = MP_I(e, 0x28);

DEFINE_MESSAGE_PACK(cEndLevelMsg_v02, 16, D_004F53A0, PACK_BODY)
