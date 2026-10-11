#include "types.h"
#include "message_pack.h"

#define PACK_BODY(e, b) MP_I(b, 8) = MP_I(e, 0x24); MP_I(b, 0xC) = MP_I(e, 0x28); MP_I(b, 0x10) = MP_I(e, 0x2C); MP_I(b, 0x14) = MP_I(MP_P(e, 0x30), 0xC);

DEFINE_MESSAGE_PACK(cHotboxMsg_v02, 0x18, D_004EE6A0, PACK_BODY)