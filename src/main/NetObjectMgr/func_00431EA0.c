#include "types.h"
#include "message_pack.h"
#define PACK_BODY(e, b) MP_H(b, 0x8) = MP_I(e, 0x24); MP_H(b, 0xA) = MP_U(e, 0x28); MP_I(e, 0x1C) = 0x40;
DEFINE_MESSAGE_PACK(cNetTerrainActivationMsg_v02, 12, D_00582758, PACK_BODY)
