#include "types.h"
#include "message_pack.h"

#define PACK_BODY(e, b) MP_H(b, 8) = MP_I(e, 0x24); MP_I(b, 0xC) = MP_I(e, 0x28); MP_I(b, 0x10) = MP_I(e, 0x30); MP_I(b, 0x14) = MP_I(e, 0x2C); MP_I(e, 0x1C) = 0x40;

DEFINE_MESSAGE_PACK_NOTYPE(cGOBJTriggerEventMsg_Pack, 24, D_004F5470, PACK_BODY)
