#include "types.h"
#include "message_pack.h"

#define PACK_PRE(e) MP_I(e, 0x1C) = 0x40;
#define PACK_BODY(e, b) MP_I(b, 8) = MP_I(e, 0x24);

DEFINE_MESSAGE_PACK_PRE(func_0023FB30, 12, D_004F7C40, PACK_PRE, PACK_BODY)
