#include "types.h"
#include "message_pack.h"

#define PACK_BODY(e, b) MP_I(b, 8) = MP_I(e, 0x24); MP_U(b, 0xC) = MP_U(e, 0x28);

DEFINE_MESSAGE_PACK_NOTYPE(func_00211680, 16, D_004F54C0, PACK_BODY)
