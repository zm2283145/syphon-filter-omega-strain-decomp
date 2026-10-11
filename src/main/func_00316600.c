#include "types.h"
#include "message_pack.h"
#define PACK_BODY(e, b) MP_I(b, 0x8) = MP_I(e, 0x2C); MP_I(b, 0x10) = MP_I(e, 0x28); MP_I(b, 0xC) = MP_I(e, 0x24);

DEFINE_MESSAGE_PACK(func_00316600, 20, D_0052ACA8, PACK_BODY)
