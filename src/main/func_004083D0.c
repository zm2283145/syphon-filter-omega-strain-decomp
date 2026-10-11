#include "types.h"
#include "message_pack.h"

#define PACK_BODY(e, b) MP_U(b, 8) = MP_U(e, 0x2E); MP_I(b, 0xC) = MP_I(MP_P(e, 0x28), 0xC); MP_H(b, 0x10) = MP_U(e, 0x2D); MP_H(b, 0x14) = MP_I(e, 0x24); MP_H(b, 0x12) = MP_U(e, 0x2C);

DEFINE_MESSAGE_PACK(cDamageMsg_v02, 0x18, D_005716F8, PACK_BODY)