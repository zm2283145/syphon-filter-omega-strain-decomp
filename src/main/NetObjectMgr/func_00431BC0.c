#include "types.h"
#include "message_pack.h"
#define PACK_BODY(e, b) MP_U(b, 0x8) = MP_S(e, 0x24); MP_I(b, 0xC) = MP_I(e, 0x28); MP_I(b, 0x10) = MP_I(e, 0x2C);

DEFINE_MESSAGE_PACK(func_00431BC0, 20, D_00582748, PACK_BODY)
