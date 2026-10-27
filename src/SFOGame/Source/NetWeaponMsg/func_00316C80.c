#include "types.h"
#include "message_pack.h"

#define PACK_BODY(e, b) MP_S(b, 8) = MP_S(e, 0x2C); MP_I(b, 0xC) = MP_I(e, 0x30); MP_U(b, 0x10) = MP_U(e, 0x34); MP_I(b, 0x14) = MP_I(e, 0x38);

DEFINE_MESSAGE_PACK(cNetWeaponMsg_Pack, 0x18, D_0052ACD0, PACK_BODY)